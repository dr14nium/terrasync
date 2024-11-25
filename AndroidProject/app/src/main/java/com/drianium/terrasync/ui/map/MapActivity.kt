package com.drianium.terrasync

import android.content.pm.ActivityInfo
import android.graphics.Bitmap
import android.graphics.BitmapFactory
import android.os.Build
import android.os.Bundle
import android.util.Log
import android.view.LayoutInflater
import android.view.MotionEvent
import android.view.View
import android.view.ViewGroup
import android.view.WindowInsetsController
import android.widget.EditText
import android.widget.ImageView
import android.widget.TextView
import android.widget.Toast
import androidx.activity.ComponentActivity
import androidx.constraintlayout.widget.ConstraintLayout
import androidx.core.view.ViewCompat
import androidx.core.view.WindowCompat
import androidx.core.view.WindowInsetsCompat
import androidx.core.view.updateLayoutParams
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView
import com.drianium.terrasync.databinding.ActivityMapBinding
import com.drianium.terrasync.helpers.isTouchOutsideView
import com.drianium.terrasync.model.SearchResult
import com.drianium.terrasync.network.ApiService
import com.mapbox.geojson.Geometry
import com.mapbox.geojson.MultiPolygon
import com.mapbox.geojson.Point
import com.mapbox.geojson.Polygon
import com.mapbox.maps.Style
import com.mapbox.maps.plugin.animation.CameraAnimationsPlugin
import com.mapbox.maps.plugin.animation.camera
import com.mapbox.maps.CameraOptions
import com.mapbox.maps.extension.style.layers.addLayer
import com.mapbox.maps.extension.style.layers.generated.FillLayer
import com.mapbox.maps.extension.style.layers.generated.fillLayer
import com.mapbox.maps.extension.style.sources.addSource
import com.mapbox.maps.extension.style.sources.generated.GeoJsonSource
import com.mapbox.maps.extension.style.sources.generated.geoJsonSource
import com.mapbox.maps.plugin.annotation.annotations
import com.mapbox.maps.plugin.annotation.generated.PointAnnotationOptions
import com.mapbox.maps.plugin.annotation.generated.createPointAnnotationManager
import com.mapbox.maps.plugin.compass.compass
import com.mapbox.maps.plugin.scalebar.scalebar
import com.mapbox.maps.toCameraOptions
import com.mapbox.search.autocomplete.PlaceAutocomplete
import com.mapbox.search.autocomplete.PlaceAutocompleteOptions
import com.mapbox.search.autocomplete.PlaceAutocompleteSuggestion
import com.mapbox.search.autocomplete.PlaceAutocompleteType
import com.mapbox.search.ui.adapter.autocomplete.PlaceAutocompleteUiAdapter
import com.mapbox.search.ui.view.CommonSearchViewConfiguration
import com.mapbox.search.ui.view.SearchResultsView
import com.mapbox.search.ui.view.place.SearchPlace
import com.mapbox.search.ui.view.place.SearchPlaceBottomSheetView
import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.launch
import kotlinx.coroutines.withContext
import org.json.JSONObject

class MapActivity : ComponentActivity() {

    private lateinit var binding: ActivityMapBinding
    private lateinit var searchResultsView: SearchResultsView
    private lateinit var queryEditText: EditText
    private lateinit var placeAutocompleteUiAdapter: PlaceAutocompleteUiAdapter
    private var lastActiveView: View? = null
    private val debounceHandler = android.os.Handler()
    private var searchRunnable: Runnable? = null

    override fun dispatchTouchEvent(event: MotionEvent): Boolean {
        handleTouchOutside(event)
        return super.dispatchTouchEvent(event)
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setupActivity()
        setupMapView()
        setupQueryEditText()
        setupCustomCompass()
        setupTransparentSystemBars()
        initializePlaceAutocomplete()
    }

    private fun setupActivity() {
        requestedOrientation = ActivityInfo.SCREEN_ORIENTATION_PORTRAIT
        WindowCompat.setDecorFitsSystemWindows(window, false)
        binding = ActivityMapBinding.inflate(layoutInflater)
        setContentView(binding.root)
    }

    private fun setupMapView() {
        val mapView = binding.mapView
        val mapboxMap = mapView.mapboxMap

        mapboxMap.getStyle { style ->
            try {
                val markerBitmap = getBitmapFromVectorDrawable(R.drawable.ic_placemarker)
                style.addImage("marker-icon", markerBitmap)
                Log.d("MapActivity", "Marker icon added successfully.")
            } catch (e: Exception) {
                Log.e("MapActivity", "Failed to add marker icon: ${e.message}")
                Toast.makeText(this, "Failed to load marker icon", Toast.LENGTH_SHORT).show()
            }
        }

        mapView.scalebar.enabled = false
        mapView.compass.updateSettings { enabled = false }
    }

    private fun setupQueryEditText() {
        queryEditText = binding.root.findViewById(R.id.query_text)
        ViewCompat.setOnApplyWindowInsetsListener(queryEditText) { view, insets ->
            val statusBarHeight = insets.getInsets(WindowInsetsCompat.Type.systemBars()).top
            view.updateLayoutParams<ConstraintLayout.LayoutParams> {
                topMargin = statusBarHeight + 16
            }
            insets
        }

        queryEditText.setOnFocusChangeListener { _, hasFocus ->
            if (hasFocus) {
                showKeyboard(queryEditText)
                toggleSearchViews()
            }
        }

        queryEditText.setOnClickListener { toggleSearchViews() }
        queryEditText.addTextChangedListener(object : android.text.TextWatcher {
            override fun afterTextChanged(s: android.text.Editable?) {}
            override fun beforeTextChanged(s: CharSequence?, start: Int, count: Int, after: Int) {}
            override fun onTextChanged(s: CharSequence?, start: Int, before: Int, count: Int) {
                handleQueryTextChange(s)
            }
        })
    }

    private fun setupCustomCompass() {
        val customCompass: ImageView = binding.customCompass
        binding.mapView.mapboxMap.addOnCameraChangeListener {
            val bearing = binding.mapView.mapboxMap.cameraState.bearing
            customCompass.rotation = -bearing.toFloat()
        }
        customCompass.setOnClickListener { resetToNorth() }
    }

    private fun handleTouchOutside(event: MotionEvent) {
        val searchResultsVisible = binding.searchResultsView.visibility == View.VISIBLE
        val recyclerViewVisible = binding.suggestionsRecyclerView.visibility == View.VISIBLE

        val isOutsideSearchResults = isTouchOutsideView(binding.searchResultsView, event)
        val isOutsideRecyclerView = isTouchOutsideView(binding.suggestionsRecyclerView, event)

        if ((searchResultsVisible && isOutsideSearchResults) ||
            (recyclerViewVisible && isOutsideRecyclerView)) {
            binding.searchResultsView.visibility = View.INVISIBLE
            binding.suggestionsRecyclerView.visibility = View.INVISIBLE
            hideKeyboard()
            lastActiveView = null
        }
    }

    private fun toggleSearchViews() {
        if (!queryEditText.text.isNullOrEmpty()) {
            if (isNibQuery(queryEditText.text.toString().trim())) {
                binding.suggestionsRecyclerView.visibility = View.VISIBLE
                binding.searchResultsView.visibility = View.INVISIBLE
                lastActiveView = binding.suggestionsRecyclerView
            } else {
                binding.searchResultsView.visibility = View.VISIBLE
                binding.suggestionsRecyclerView.visibility = View.INVISIBLE
                lastActiveView = binding.searchResultsView
            }
        } else {
            binding.searchResultsView.visibility = View.INVISIBLE
            binding.suggestionsRecyclerView.visibility = View.INVISIBLE
            lastActiveView = null
        }
    }

    private fun handleQueryTextChange(s: CharSequence?) {
        val query = s?.toString()?.trim()
        Log.d("MapActivity", "Query text changed: $query")

        searchRunnable?.let { debounceHandler.removeCallbacks(it) }

        if (query.isNullOrEmpty()) {
            Log.d("MapActivity", "Query is empty, hiding all views")
            binding.searchResultsView.visibility = View.INVISIBLE
            binding.suggestionsRecyclerView.visibility = View.INVISIBLE
            lastActiveView = null
        } else if (isNibQuery(query)) {
            searchRunnable = Runnable {
                Log.d("MapActivity", "Debounced NIB query: $query")
                fetchPostgresSearchResults(query)
                binding.searchResultsView.visibility = View.INVISIBLE
                binding.suggestionsRecyclerView.visibility = View.VISIBLE
                lastActiveView = binding.suggestionsRecyclerView
            }
            debounceHandler.postDelayed(searchRunnable!!, 500)
        } else {
            CoroutineScope(Dispatchers.Main).launch {
                try {
                    placeAutocompleteUiAdapter.search(query)
                    binding.searchResultsView.visibility = View.VISIBLE
                    binding.suggestionsRecyclerView.visibility = View.INVISIBLE
                    lastActiveView = binding.searchResultsView
                } catch (e: Exception) {
                    Log.e("MapActivity", "Error updating suggestions: ${e.message}")
                }
            }
        }
    }

    private fun isNibQuery(query: String): Boolean {
        return query.matches(Regex("^nib\\s+\\d+$", RegexOption.IGNORE_CASE))
    }

    private fun getBitmapFromVectorDrawable(resourceId: Int): Bitmap {
        val drawable = resources.getDrawable(resourceId, theme)
        val bitmap = Bitmap.createBitmap(
            drawable.intrinsicWidth,
            drawable.intrinsicHeight,
            Bitmap.Config.ARGB_8888
        )
        val canvas = android.graphics.Canvas(bitmap)
        drawable.setBounds(0, 0, canvas.width, canvas.height)
        drawable.draw(canvas)
        return bitmap
    }

    private fun hideKeyboard() {
        val imm = getSystemService(android.view.inputmethod.InputMethodManager::class.java)
        val view = currentFocus ?: View(this)
        imm.hideSoftInputFromWindow(view.windowToken, 0)
    }

    private fun showKeyboard(view: View) {
        val imm = getSystemService(android.view.inputmethod.InputMethodManager::class.java)
        imm.showSoftInput(view, android.view.inputmethod.InputMethodManager.SHOW_IMPLICIT)
    }

    private fun fetchPostgresSearchResults(query: String) {
        val cleanQuery = query.removePrefix("nib").trim()

        CoroutineScope(Dispatchers.IO).launch {
            try {
                val response = ApiService.create().searchPostgresPlace(cleanQuery)
                if (response.isSuccessful) {
                    val results = response.body()
                    withContext(Dispatchers.Main) {
                        if (!results.isNullOrEmpty()) {
                            val currentBounds = getCurrentCoordinateBounds()
                            val filteredResults = results.filter { result ->
                                isWithinBounds(result, currentBounds)
                            }
                            if (filteredResults.isNotEmpty()) {
                                displaySearchSuggestions(filteredResults)
                                binding.searchResultsView.visibility = View.INVISIBLE
                            } else {
                                Toast.makeText(
                                    this@MapActivity,
                                    "No results within the current map view.",
                                    Toast.LENGTH_SHORT
                                ).show()
                            }
                        } else {
                            binding.suggestionsRecyclerView.visibility = View.INVISIBLE
                        }
                    }
                } else {
                    withContext(Dispatchers.Main) {
                        binding.suggestionsRecyclerView.visibility = View.INVISIBLE
                    }
                }
            } catch (e: Exception) {
                withContext(Dispatchers.Main) {
                    Log.e("MapActivity", "Error fetching PostGIS search results: ${e.message}")
                    binding.suggestionsRecyclerView.visibility = View.INVISIBLE
                }
            }
        }
    }

    private fun getCurrentCoordinateBounds(): com.mapbox.maps.CoordinateBounds {
        val mapboxMap = binding.mapView.mapboxMap
        val cameraState = mapboxMap.cameraState
        return mapboxMap.coordinateBoundsForCamera(cameraState.toCameraOptions())
    }

    private fun isWithinBounds(result: SearchResult, bounds: com.mapbox.maps.CoordinateBounds): Boolean {
        val centroid = Point.fromJson(result.centroid)
        val lon = centroid.longitude()
        val lat = centroid.latitude()

        return lon >= bounds.west() && lon <= bounds.east() &&
                lat >= bounds.south() && lat <= bounds.north()
    }

    private fun displaySearchSuggestions(results: List<SearchResult>) {
        val adapter = binding.suggestionsRecyclerView.adapter as? SuggestionsAdapter

        if (adapter == null) {
            val suggestionsAdapter = SuggestionsAdapter(
                results,
                { selectedResult -> displayPostgresResult(selectedResult) },
                binding.suggestionsRecyclerView
            )
            binding.suggestionsRecyclerView.layoutManager = LinearLayoutManager(this)
            binding.suggestionsRecyclerView.adapter = suggestionsAdapter
        } else {
            adapter.updateData(results)
        }

        binding.suggestionsRecyclerView.visibility = View.VISIBLE
    }

    private fun displayPostgresResult(result: SearchResult) {
        binding.mapView.getMapboxMap().getStyle { style ->
            try {
                val geometryJson = result.geometry
                val centroidJson = result.centroid
                val centroid = Point.fromJson(centroidJson)
                val multiPolygon = MultiPolygon.fromJson(geometryJson)

                val geoJsonSourceId = "source-${result.id}"
                val fillLayerId = "layer-${result.id}"

                if (!style.styleSourceExists(geoJsonSourceId)) {
                    style.addSource(
                        geoJsonSource(geoJsonSourceId) {
                            geometry(multiPolygon)
                        }
                    )
                }

                if (!style.styleLayerExists(fillLayerId)) {
                    style.addLayer(
                        fillLayer(fillLayerId, geoJsonSourceId) {
                            fillColor("#FF5733")
                            fillOpacity(0.5)
                        }
                    )
                }

                binding.mapView.getMapboxMap().setCamera(
                    CameraOptions.Builder()
                        .center(centroid)
                        .zoom(20.0)
                        .build()
                )

                Log.d("MapActivity", "Added MultiPolygon and centered on: ${result.name} with NIB: ${result.nib}")
            } catch (e: Exception) {
                Log.e("MapActivity", "Error processing geometry for result: ${result.name}", e)
            }
        }
    }

    class SuggestionsAdapter(
        private var results: List<SearchResult>,
        private val onClick: (SearchResult) -> Unit,
        private val recyclerView: RecyclerView
    ) : RecyclerView.Adapter<SuggestionsAdapter.ViewHolder>() {

        inner class ViewHolder(view: View) : RecyclerView.ViewHolder(view) {
            private val nameTextView: TextView = view.findViewById(R.id.result_village)
            private val nibTextView: TextView = view.findViewById(R.id.result_nib)

            fun bind(result: SearchResult) {
                nameTextView.text = result.name
                nibTextView.text = "NIB ${result.nib}"
                itemView.setOnClickListener {
                    onClick(result)
                    recyclerView.visibility = View.GONE
                }
            }
        }

        override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): ViewHolder {
            val view = LayoutInflater.from(parent.context)
                .inflate(R.layout.item_search_result, parent, false)
            return ViewHolder(view)
        }

        override fun onBindViewHolder(holder: ViewHolder, position: Int) {
            holder.bind(results[position])
        }

        override fun getItemCount(): Int = results.size

        fun updateData(newResults: List<SearchResult>) {
            results = newResults
            notifyDataSetChanged()
        }
    }

    private fun initializePlaceAutocomplete() {
        val placeAutocomplete = PlaceAutocomplete.create()

        searchResultsView = binding.root.findViewById(R.id.search_results_view)

        searchResultsView.initialize(
            SearchResultsView.Configuration(
                commonConfiguration = CommonSearchViewConfiguration()
            )
        )
        Log.d("MapActivity", "SearchResultsView initialized successfully")

        queryEditText = binding.root.findViewById(R.id.query_text)

        queryEditText.setOnEditorActionListener { _, actionId, _ ->
            if (actionId == android.view.inputmethod.EditorInfo.IME_ACTION_SEARCH) {
                val query = queryEditText.text.toString().trim()
                if (query.isNotEmpty()) {
                    if (isNibQuery(query)) {
                        fetchPostgresSearchResults(query)
                        searchResultsView.visibility = View.GONE
                    } else {
                        CoroutineScope(Dispatchers.Main).launch {
                            try {
                                placeAutocompleteUiAdapter.search(query)
                                searchResultsView.visibility = View.VISIBLE
                            } catch (e: Exception) {
                                Log.e("MapActivity", "Error during Mapbox search: ${e.message}", e)
                            }
                        }
                    }
                }
                true
            } else {
                false
            }
        }

        placeAutocompleteUiAdapter = PlaceAutocompleteUiAdapter(
            view = searchResultsView,
            placeAutocomplete = placeAutocomplete
        )

        placeAutocompleteUiAdapter.addSearchListener(object : PlaceAutocompleteUiAdapter.SearchListener {
            override fun onSuggestionsShown(suggestions: List<PlaceAutocompleteSuggestion>) {
                binding.searchResultsView.visibility = View.VISIBLE
                binding.suggestionsRecyclerView.visibility = View.INVISIBLE
            }

            override fun onSuggestionSelected(suggestion: PlaceAutocompleteSuggestion) {
                CoroutineScope(Dispatchers.Main).launch {
                    selectPlace(suggestion)
                }
                binding.searchResultsView.visibility = View.INVISIBLE
            }

            override fun onPopulateQueryClick(suggestion: PlaceAutocompleteSuggestion) {
                queryEditText.setText(suggestion.name)
            }

            override fun onError(e: Exception) {
                Log.e("MapActivity", "Error during search: ${e.message}", e)
                Toast.makeText(this@MapActivity, "Error: ${e.message}", Toast.LENGTH_SHORT).show()
            }
        })
    }

    private suspend fun selectPlace(suggestion: PlaceAutocompleteSuggestion) {
        withContext(Dispatchers.Main) {
            val placeAutocomplete = PlaceAutocomplete.create()

            CoroutineScope(Dispatchers.Main).launch {
                val boundingBox = com.mapbox.geojson.BoundingBox.fromLngLats(
                    110.36257834518699, -7.763782784422548,
                    110.39452639851251, -7.797307640490622
                )

                val options = PlaceAutocompleteOptions(
                    types = listOf(PlaceAutocompleteType.AdministrativeUnit.Place),
                    limit = 10
                )

                val suggestions = placeAutocomplete.suggestions(
                    query = "search query",
                    options = options
                )

                suggestions.onValue { result ->
                    Log.d("PlaceAutocomplete", "Found ${result.size} results with specific types")
                }.onError { error ->
                    Log.e("PlaceAutocomplete", "Error: ${error.message}")
                }
            }

            placeAutocomplete.select(suggestion)
                .onValue { result ->
                    val coordinate = result.coordinate
                    Log.d("MapActivity", "Selected place at: $coordinate")

                    binding.mapView.mapboxMap.setCamera(
                        CameraOptions.Builder()
                            .center(coordinate)
                            .zoom(17.0)
                            .build()
                    )

                    binding.mapView.mapboxMap.getStyle { style ->
                        val annotationPlugin = binding.mapView.annotations
                        val pointAnnotationManager = annotationPlugin.createPointAnnotationManager()

                        val marker = PointAnnotationOptions()
                            .withPoint(Point.fromLngLat(coordinate.longitude(), coordinate.latitude()))
                            .withIconImage("marker-icon")

                        pointAnnotationManager.deleteAll()
                        pointAnnotationManager.create(marker)
                        Log.d("MapActivity", "Marker added successfully at $coordinate")
                    }

                    searchResultsView.visibility = View.GONE

                }
                .onError { error ->
                    Log.e("MapActivity", "Error selecting place: ${error.message}", error)
                    Toast.makeText(this@MapActivity, "Error selecting place: ${error.message}", Toast.LENGTH_SHORT).show()
                }
        }
    }

    private fun resetToNorth() {
        val mapView = binding.mapView
        val cameraPlugin: CameraAnimationsPlugin = mapView.camera
        val currentZoom = mapView.mapboxMap.cameraState.zoom
        val currentCenter = mapView.mapboxMap.cameraState.center

        cameraPlugin.flyTo(
            CameraOptions.Builder()
                .center(currentCenter)
                .zoom(currentZoom)
                .bearing(0.0)
                .build()
        )
    }

    private fun setupTransparentSystemBars() {
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.R) {
            val controller = window.insetsController
            controller?.setSystemBarsAppearance(
                WindowInsetsController.APPEARANCE_LIGHT_STATUS_BARS,
                WindowInsetsController.APPEARANCE_LIGHT_STATUS_BARS
            )
            window.statusBarColor = android.graphics.Color.TRANSPARENT
            window.navigationBarColor = android.graphics.Color.TRANSPARENT
        } else {
            window.decorView.systemUiVisibility = (
                    View.SYSTEM_UI_FLAG_LAYOUT_STABLE
                            or View.SYSTEM_UI_FLAG_LAYOUT_FULLSCREEN
                            or View.SYSTEM_UI_FLAG_LAYOUT_HIDE_NAVIGATION
                            or View.SYSTEM_UI_FLAG_LIGHT_STATUS_BAR
                    )
            window.statusBarColor = android.graphics.Color.TRANSPARENT
            window.navigationBarColor = android.graphics.Color.TRANSPARENT
        }
    }
}