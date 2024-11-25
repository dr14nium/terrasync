package com.drianium.terrasync.ui.map

import android.content.BroadcastReceiver
import android.content.Context
import android.content.Intent
import android.content.IntentFilter
import android.content.pm.ActivityInfo
import android.graphics.Bitmap
import android.location.LocationManager
import android.os.Build
import android.os.Bundle
import android.util.Log
import android.view.LayoutInflater
import android.view.MotionEvent
import android.view.View
import android.view.ViewGroup
import android.view.WindowInsetsController
import android.widget.EditText
import android.widget.ImageButton
import android.widget.ImageView
import android.widget.LinearLayout
import android.widget.SeekBar
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
import com.drianium.terrasync.R
import com.drianium.terrasync.databinding.ActivityMapBinding
import com.drianium.terrasync.helpers.isTouchOutsideView
import com.drianium.terrasync.model.GeoJsonFeature
import com.drianium.terrasync.model.SearchResult
import com.drianium.terrasync.network.ApiService
import com.google.android.material.bottomsheet.BottomSheetDialog
import com.mapbox.geojson.MultiPolygon
import com.mapbox.geojson.Point
import com.mapbox.maps.plugin.animation.CameraAnimationsPlugin
import com.mapbox.maps.plugin.animation.camera
import com.mapbox.maps.CameraOptions
import com.mapbox.maps.RenderedQueryOptions
import com.mapbox.maps.extension.style.layers.addLayer
import com.mapbox.maps.extension.style.layers.generated.fillLayer
import com.mapbox.maps.extension.style.layers.getLayer
import com.mapbox.maps.extension.style.sources.addSource
import com.mapbox.maps.extension.style.sources.generated.geoJsonSource
import com.mapbox.maps.plugin.animation.MapAnimationOptions.Companion.mapAnimationOptions
import com.mapbox.maps.plugin.annotation.annotations
import com.mapbox.maps.plugin.annotation.generated.PointAnnotationManager
import com.mapbox.maps.plugin.annotation.generated.PointAnnotationOptions
import com.mapbox.maps.plugin.annotation.generated.createPointAnnotationManager
import com.mapbox.maps.plugin.compass.compass
import com.mapbox.maps.plugin.gestures.addOnMapClickListener
import com.mapbox.maps.plugin.scalebar.scalebar
import com.mapbox.search.autocomplete.PlaceAutocomplete
import com.mapbox.search.autocomplete.PlaceAutocompleteSuggestion
import com.mapbox.search.ui.adapter.autocomplete.PlaceAutocompleteUiAdapter
import com.mapbox.search.ui.view.CommonSearchViewConfiguration
import com.mapbox.search.ui.view.SearchResultsView
import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.launch
import kotlinx.coroutines.withContext

class MapActivity : ComponentActivity() {

    private lateinit var binding: ActivityMapBinding
    private lateinit var searchResultsView: SearchResultsView
    private lateinit var queryEditText: EditText
    private lateinit var placeAutocompleteUiAdapter: PlaceAutocompleteUiAdapter
    private lateinit var fusedLocationClient: com.google.android.gms.location.FusedLocationProviderClient
    private lateinit var buttonGeolocation: ImageButton
    private var locationUpdatesInProgress = false
    private var pointAnnotationManager: PointAnnotationManager? = null
    private lateinit var gpsStatusReceiver: BroadcastReceiver
    private var geoLocationMarker: com.mapbox.maps.plugin.annotation.generated.PointAnnotation? = null
    private var lastActiveView: View? = null
    private val debounceHandler = android.os.Handler()
    private var searchRunnable: Runnable? = null
    private var currentPolygonId: String? = null

    override fun dispatchTouchEvent(event: MotionEvent): Boolean {
        handleTouchOutside(event)
        return super.dispatchTouchEvent(event)
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setupActivity()

        // Inisialisasi tombol Layer
        setupLayerButton()

        // Inisialisasi FusedLocationProviderClient
        fusedLocationClient = com.google.android.gms.location.LocationServices.getFusedLocationProviderClient(this)

        // Bind tombol geolokasi
        buttonGeolocation = findViewById(R.id.buttonGeolocation)

        // Update state geolokasi saat activity dimulai
        updateGeolocationState()

        // Register GPS status receiver
        registerGpsStatusReceiver()

        // Tambahkan klik listener untuk tombol geolokasi
        buttonGeolocation.setOnClickListener {
            if (isGpsEnabled()) {
                if (locationUpdatesInProgress) {
                    stopLocationUpdates()
                } else {
                    startLocationUpdates()
                }
            } else {
                // Tampilkan dialog untuk mengaktifkan GPS
                promptEnableGpsWithDialog()
            }
        }

        setupMapView()
        setupQueryEditText()
        setupCustomCompass()
        setupTransparentSystemBars()
        initializePlaceAutocomplete()
    }

    override fun onDestroy() {
        super.onDestroy()
        unregisterReceiver(gpsStatusReceiver) // Unregister receiver to avoid memory leaks
    }

    private fun setupLayerButton() {
        val buttonLayer: ImageButton = findViewById(R.id.buttonLayer)
        var isBottomSheetVisible = false

        val bottomSheetDialog = BottomSheetDialog(this)
        val bottomSheetView = layoutInflater.inflate(R.layout.bottom_sheet_layer, null)
        bottomSheetDialog.setContentView(bottomSheetView)

        // Referensi outline view dan outline aktif
        val outlineLayer1 = bottomSheetView.findViewById<View>(R.id.outline_layer1)
        val outlineLayer2 = bottomSheetView.findViewById<View>(R.id.outline_layer2)
        val outlineLayer3 = bottomSheetView.findViewById<View>(R.id.outline_layer3)
        val activeOutlineLayer1 = bottomSheetView.findViewById<View>(R.id.active_outline_layer1)
        val activeOutlineLayer2 = bottomSheetView.findViewById<View>(R.id.active_outline_layer2)
        val activeOutlineLayer3 = bottomSheetView.findViewById<View>(R.id.active_outline_layer3)

        val layerOutlines = listOf(outlineLayer1, outlineLayer2, outlineLayer3)
        val activeOutlines = listOf(activeOutlineLayer1, activeOutlineLayer2, activeOutlineLayer3)

        // Referensi kontrol transparansi
        val transparencyControlGroup = bottomSheetView.findViewById<LinearLayout>(R.id.transparency_control_group)
        val transparencySlider = bottomSheetView.findViewById<SeekBar>(R.id.transparency_slider)

        // Array untuk menyimpan transparansi masing-masing layer
        val layerTransparency = mutableListOf(1.0f, 1.0f, 1.0f) // Default transparansi = 100% (1.0)

        // Fungsi untuk mengatur slider transparansi
        fun setupTransparencySlider(selectedIndex: Int) {
            val selectedView = layerOutlines[selectedIndex]
            if (selectedView?.isSelected == true) { // Cek apakah layer aktif
                // Tampilkan outline aktif
                activeOutlines.forEachIndexed { index, view ->
                    view.visibility = if (index == selectedIndex) View.VISIBLE else View.GONE
                }

                transparencyControlGroup.visibility = View.VISIBLE
                transparencySlider.progress = (layerTransparency[selectedIndex] * 100).toInt()

                transparencySlider.setOnSeekBarChangeListener(object : SeekBar.OnSeekBarChangeListener {
                    override fun onProgressChanged(seekBar: SeekBar?, progress: Int, fromUser: Boolean) {
                        if (fromUser) {
                            val transparency = progress / 100f
                            layerTransparency[selectedIndex] = transparency
                            updateLayerTransparency("Layer ${selectedIndex + 1}", transparency)
                        }
                    }

                    override fun onStartTrackingTouch(seekBar: SeekBar?) {}
                    override fun onStopTrackingTouch(seekBar: SeekBar?) {}
                })
            } else {
                // Sembunyikan semua outline aktif
                activeOutlines.forEach { it.visibility = View.GONE }
                transparencyControlGroup.visibility = View.GONE
            }
        }

        // Fungsi untuk toggle layer
        fun toggleLayer(selectedIndex: Int, tableName: String) {
            val selectedView = layerOutlines[selectedIndex]
            val isAlreadyActive = selectedView?.isSelected == true

            if (isAlreadyActive) {
                // Deaktivasi layer
                selectedView?.isSelected = false
                removeLayerFromMap(tableName) // Fungsi opsional untuk menghapus layer
                transparencyControlGroup.visibility = View.GONE
                Toast.makeText(this, "Layer ${selectedIndex + 1} Deactivated", Toast.LENGTH_SHORT).show()
            } else {
                // Aktivasi layer
                selectedView?.isSelected = true
                addGeoJsonLayer(tableName) // Tambahkan layer
                setupTransparencySlider(selectedIndex)
                Toast.makeText(this, "Layer ${selectedIndex + 1} Activated", Toast.LENGTH_SHORT).show()
            }
        }

        // Listener untuk setiap button layer
        bottomSheetView.findViewById<ImageView>(R.id.icon_layer1)?.apply {
            setOnClickListener {
                if (outlineLayer1.isSelected) {
                    setupTransparencySlider(0) // Klik biasa untuk transparansi
                }
            }
            setOnLongClickListener {
                toggleLayer(0, "BidangTanah") // Tahan lama untuk toggle
                true
            }
        }
        bottomSheetView.findViewById<ImageView>(R.id.icon_layer2)?.apply {
            setOnClickListener {
                if (outlineLayer2.isSelected) {
                    setupTransparencySlider(1) // Klik biasa untuk transparansi
                }
            }
            setOnLongClickListener {
                toggleLayer(1) // Tahan lama untuk toggle
                true
            }
        }
        bottomSheetView.findViewById<ImageView>(R.id.icon_layer3)?.apply {
            setOnClickListener {
                if (outlineLayer3.isSelected) {
                    setupTransparencySlider(2) // Klik biasa untuk transparansi
                }
            }
            setOnLongClickListener {
                toggleLayer(2) // Tahan lama untuk toggle
                true
            }
        }

        // Tampilkan atau sembunyikan BottomSheet
        buttonLayer.setOnClickListener {
            if (isBottomSheetVisible) {
                bottomSheetDialog.dismiss()
            } else {
                bottomSheetDialog.show()
            }
            isBottomSheetVisible = !isBottomSheetVisible
        }

        bottomSheetDialog.setOnDismissListener {
            isBottomSheetVisible = false
        }
    }

    // Fungsi untuk memperbarui transparansi layer
    private fun updateLayerTransparency(tableName: String, transparency: Float) {
        val mapboxMap = binding.mapView.getMapboxMap()
        mapboxMap.getStyle { style ->
            val layerId = "layer-$tableName"
            if (style.styleLayerExists(layerId)) {
                style.getLayer(layerId)?.setProperties(
                    fillOpacity(transparency)
                )
            }
        }
    }

    private fun addGeoJsonLayer(tableName: String) {
        CoroutineScope(Dispatchers.IO).launch {
            try {
                val response = ApiService.create().getAllFeatures(tableName)
                if (response.isSuccessful) {
                    val geoJsonResponse = response.body()

                    if (geoJsonResponse != null && geoJsonResponse.features.isNotEmpty()) {
                        withContext(Dispatchers.Main) {
                            val mapboxMap = binding.mapView.getMapboxMap()
                            val style = mapboxMap.getStyle { currentStyle ->
                                val sourceId = "source-$tableName"
                                val layerId = "layer-$tableName"

                                // Tambahkan sumber GeoJSON
                                if (!currentStyle.styleSourceExists(sourceId)) {
                                    currentStyle.addSource(
                                        geoJsonSource(sourceId) {
                                            geometry(geoJsonResponse.features.map { feature ->
                                                MultiPolygon.fromJson(feature.geometry.toString())
                                            })
                                        }
                                    )
                                }

                                // Tambahkan layer
                                if (!currentStyle.styleLayerExists(layerId)) {
                                    currentStyle.addLayer(
                                        fillLayer(layerId, sourceId) {
                                            fillColor("#FF5733") // Warna layer
                                            fillOpacity(0.5)    // Transparansi default
                                        }
                                    )
                                }
                            }
                        }
                    } else {
                        Log.e("MapActivity", "GeoJSON response is empty or null.")
                    }
                } else {
                    Log.e("MapActivity", "Failed to fetch GeoJSON: ${response.errorBody()?.string()}")
                }
            } catch (e: Exception) {
                Log.e("MapActivity", "Error loading GeoJSON: ${e.message}")
            }
        }
    }

    private fun removeLayerFromMap(tableName: String) {
        val mapboxMap = binding.mapView.getMapboxMap()
        mapboxMap.getStyle { style ->
            val sourceId = "source-$tableName"
            val layerId = "layer-$tableName"

            if (style.styleLayerExists(layerId)) {
                style.removeStyleLayer(layerId)
            }
            if (style.styleSourceExists(sourceId)) {
                style.removeStyleSource(sourceId)
            }
        }
    }

    private fun setupMapClickListener(tableName: String) {
        binding.mapView.mapboxMap.addOnMapClickListener { point ->
            handleMapClick(point, tableName)
            true
        }
    }

    private fun handleMapClick(point: Point, tableName: String) {
        CoroutineScope(Dispatchers.IO).launch {
            try {
                val sourceId = "source-$tableName"
                val mapboxMap = binding.mapView.getMapboxMap()

                // Query fitur berdasarkan klik pengguna
                val features = mapboxMap.queryRenderedFeatures(
                    screenCoordinate = binding.mapView.pixelForCoordinate(point),
                    options = RenderedQueryOptions(
                        layerIds = listOf("layer-$tableName"),
                        filter = null
                    )
                )

                if (features.isNotEmpty()) {
                    val featureId = features[0].getStringProperty("id") // Ambil ID dari properti
                    showFeatureDetails(tableName, featureId)
                } else {
                    withContext(Dispatchers.Main) {
                        Toast.makeText(this@MapActivity, "No feature found!", Toast.LENGTH_SHORT).show()
                    }
                }
            } catch (e: Exception) {
                Log.e("MapActivity", "Error querying features: ${e.message}")
            }
        }
    }

    private suspend fun showFeatureDetails(tableName: String, featureId: String) {
        withContext(Dispatchers.Main) {
            // Panggil API untuk mendapatkan atribut fitur
            val response = ApiService.create().getFeatureById(tableName, featureId)
            if (response.isSuccessful) {
                val feature = response.body()
                if (feature != null) {
                    displayFeatureInBottomSheet(feature)
                } else {
                    Toast.makeText(this@MapActivity, "Feature details not found", Toast.LENGTH_SHORT).show()
                }
            } else {
                Log.e("MapActivity", "Failed to fetch feature details: ${response.errorBody()?.string()}")
            }
        }
    }

    private fun displayFeatureInBottomSheet(feature: GeoJsonFeature) {
        val bottomSheetDialog = BottomSheetDialog(this)
        val bottomSheetView = layoutInflater.inflate(R.layout.bottom_sheet_feature, null)
        bottomSheetDialog.setContentView(bottomSheetView)

        // Ambil referensi elemen UI dalam BottomSheet
        val attributeContainer = bottomSheetView.findViewById<LinearLayout>(R.id.attribute_container)

        // Tambahkan atribut ke dalam container
        feature.properties.forEach { (key, value) ->
            val attributeView = LayoutInflater.from(this).inflate(R.layout.item_attribute, attributeContainer, false)
            val keyTextView = attributeView.findViewById<TextView>(R.id.key_text_view)
            val valueTextView = attributeView.findViewById<TextView>(R.id.value_text_view)

            keyTextView.text = key
            valueTextView.text = value.toString()
            attributeContainer.addView(attributeView)
        }

        bottomSheetDialog.show()
    }


    private fun setupActivity() {
        requestedOrientation = ActivityInfo.SCREEN_ORIENTATION_PORTRAIT
        WindowCompat.setDecorFitsSystemWindows(window, false)
        binding = ActivityMapBinding.inflate(layoutInflater)
        setContentView(binding.root)
    }

    // Check if GPS is enabled
    private fun isGpsEnabled(): Boolean {
        val locationManager = getSystemService(LOCATION_SERVICE) as LocationManager
        return locationManager.isProviderEnabled(LocationManager.GPS_PROVIDER)
    }

    // Update geolocation button state
    private fun updateGeolocationState() {
        when {
            !isGpsEnabled() -> {
                // GPS tidak aktif, tetap izinkan klik tombol dan ganti ikon
                buttonGeolocation.isEnabled = true
                buttonGeolocation.setImageResource(R.drawable.ic_geolocation_inactive)
            }
            locationUpdatesInProgress -> {
                // Proses pembaruan lokasi sedang berjalan
                buttonGeolocation.isEnabled = true
                buttonGeolocation.setImageResource(R.drawable.ic_geolocation_active)
            }
            else -> {
                // GPS aktif, tetapi pembaruan lokasi tidak berjalan
                buttonGeolocation.isEnabled = true
                buttonGeolocation.setImageResource(R.drawable.ic_geolocation_default)
            }
        }
    }

    // Start location updates (Only Once)
    private fun startLocationUpdates() {
        if (checkLocationPermission()) {
            locationUpdatesInProgress = true
            updateGeolocationState()
            Toast.makeText(this, "Updating location...", Toast.LENGTH_SHORT).show()

            // Get the user's location and display it on the map
            updateUserLocationOnMap()
        } else {
            requestLocationPermission()
        }
    }

    private fun checkLocationPermission(): Boolean {
        val fineLocationPermission = android.Manifest.permission.ACCESS_FINE_LOCATION
        val coarseLocationPermission = android.Manifest.permission.ACCESS_COARSE_LOCATION
        return checkSelfPermission(fineLocationPermission) == android.content.pm.PackageManager.PERMISSION_GRANTED ||
                checkSelfPermission(coarseLocationPermission) == android.content.pm.PackageManager.PERMISSION_GRANTED
    }

    private fun requestLocationPermission() {
        requestPermissions(
            arrayOf(
                android.Manifest.permission.ACCESS_FINE_LOCATION,
                android.Manifest.permission.ACCESS_COARSE_LOCATION
            ),
            LOCATION_PERMISSION_REQUEST_CODE
        )
    }

    @Suppress("deprecation")
    override fun onRequestPermissionsResult(
        requestCode: Int,
        permissions: Array<String>,
        grantResults: IntArray
    ) {
        if (requestCode == LOCATION_PERMISSION_REQUEST_CODE) {
            if (grantResults.isNotEmpty() && grantResults[0] == android.content.pm.PackageManager.PERMISSION_GRANTED) {
                // Permission granted
                startLocationUpdates()
            } else {
                // Permission denied
                Toast.makeText(
                    this,
                    "Location permission is required to access your location.",
                    Toast.LENGTH_SHORT
                ).show()
            }
        }
    }

    // Stop location updates and reset the button to default state
    private fun stopLocationUpdates() {
        locationUpdatesInProgress = false
        updateGeolocationState()
        Toast.makeText(this, "Location update process completed.", Toast.LENGTH_SHORT).show()
    }

    // Register a BroadcastReceiver to listen for GPS status changes
    private fun registerGpsStatusReceiver() {
        gpsStatusReceiver = object : BroadcastReceiver() {
            override fun onReceive(context: Context, intent: Intent) {
                if (intent.action == LocationManager.PROVIDERS_CHANGED_ACTION) {
                    updateGeolocationState()
                }
            }
        }

        val filter = IntentFilter(LocationManager.PROVIDERS_CHANGED_ACTION)

        // Tambahkan parameter RECEIVER_NOT_EXPORTED untuk Android 12+
        registerReceiver(gpsStatusReceiver, filter, Context.RECEIVER_NOT_EXPORTED)
    }

    private fun promptEnableGpsWithDialog() {
        val locationRequest = com.google.android.gms.location.LocationRequest.create().apply {
            priority = com.google.android.gms.location.Priority.PRIORITY_HIGH_ACCURACY
        }

        val builder = com.google.android.gms.location.LocationSettingsRequest.Builder()
            .addLocationRequest(locationRequest)

        val settingsClient = com.google.android.gms.location.LocationServices.getSettingsClient(this)
        val task = settingsClient.checkLocationSettings(builder.build())

        task.addOnSuccessListener {
            // GPS sudah aktif
            Toast.makeText(this, "GPS is already enabled.", Toast.LENGTH_SHORT).show()
        }

        task.addOnFailureListener { exception ->
            if (exception is com.google.android.gms.common.api.ResolvableApiException) {
                try {
                    // Tampilkan dialog untuk mengaktifkan GPS
                    exception.startResolutionForResult(this, REQUEST_ENABLE_GPS)
                } catch (sendEx: android.content.IntentSender.SendIntentException) {
                    Log.e("MapActivity", "Error displaying GPS enable dialog: ${sendEx.message}")
                }
            } else {
                Log.e("MapActivity", "Unable to enable GPS: ${exception.message}")
            }
        }
    }

    private fun updateUserLocationOnMap() {
        val locationRequest = com.google.android.gms.location.LocationRequest.create().apply {
            interval = 1000 // 1-second interval
            fastestInterval = 500 // Fastest interval of 500ms
            priority = com.google.android.gms.location.Priority.PRIORITY_HIGH_ACCURACY
        }

        val locationCallback = object : com.google.android.gms.location.LocationCallback() {
            private val startTime = System.currentTimeMillis()
            private val targetZoomLevel = 15.0 // Zoom level yang diinginkan

            override fun onLocationResult(locationResult: com.google.android.gms.location.LocationResult) {
                val currentTime = System.currentTimeMillis()

                val location = locationResult.lastLocation
                if (location != null) {
                    val userLocation = Point.fromLngLat(location.longitude, location.latitude)
                    val mapboxMap = binding.mapView.getMapboxMap()
                    val cameraPlugin = binding.mapView.camera // Plugin animasi kamera
                    val currentZoom = mapboxMap.cameraState.zoom

                    // Perbarui posisi marker geolokasi
                    val pointAnnotationManager = binding.mapView.annotations.createPointAnnotationManager()
                    if (geoLocationMarker == null) {
                        geoLocationMarker = pointAnnotationManager.create(
                            PointAnnotationOptions()
                                .withPoint(userLocation)
                                .withIconImage("geolocation-icon") // Gunakan ikon geolokasi
                        )
                    } else {
                        geoLocationMarker?.geometry = userLocation
                        pointAnnotationManager.update(geoLocationMarker!!)
                    }

                    Log.d("MapActivity", "Updated to location: ${location.latitude}, ${location.longitude}")

                    // Hanya lakukan animasi zoom jika zoom saat ini lebih kecil dari target
                    if (currentZoom < targetZoomLevel) {
                        cameraPlugin.flyTo(
                            CameraOptions.Builder()
                                .center(userLocation)
                                .zoom(targetZoomLevel)
                                .build(),
                            mapAnimationOptions {
                                duration(2000) // Durasi animasi dalam milidetik (2 detik)
                            }
                        )
                    } else {
                        // Animasi hanya untuk memusatkan kamera tanpa mengubah zoom
                        cameraPlugin.flyTo(
                            CameraOptions.Builder()
                                .center(userLocation)
                                .build(),
                            mapAnimationOptions {
                                duration(1500) // Durasi animasi (1,5 detik)
                            }
                        )
                    }
                }

                // Stop updates setelah 1 detik atau jika lokasi berhasil diperbarui
                if ((currentTime - startTime) > 1000 && location != null) {
                    fusedLocationClient.removeLocationUpdates(this)
                    stopLocationUpdates() // Reset state
                }
            }
        }

        fusedLocationClient.requestLocationUpdates(locationRequest, locationCallback, mainLooper)
    }

    override fun onActivityResult(requestCode: Int, resultCode: Int, data: Intent?) {
        super.onActivityResult(requestCode, resultCode, data)
        if (requestCode == REQUEST_ENABLE_GPS) {
            if (resultCode == RESULT_OK) {
                // GPS berhasil diaktifkan
                Toast.makeText(this, "GPS enabled successfully!", Toast.LENGTH_SHORT).show()
                updateGeolocationState()
            } else {
                // Pengguna menolak mengaktifkan GPS
                Toast.makeText(this, "GPS not enabled. Please enable GPS for full functionality.", Toast.LENGTH_SHORT).show()
            }
        }
    }


    private fun setupMapView() {
        val mapView = binding.mapView
        val mapboxMap = mapView.mapboxMap

        mapboxMap.getStyle { style ->
            try {
                // Tambahkan ikon marker placeautocomplete
                val markerBitmap = getBitmapFromVectorDrawable(R.drawable.ic_placemarker_pink)
                style.addImage("marker-icon", markerBitmap)

                // Tambahkan ikon geolokasi
                val geolocationBitmap = getBitmapFromVectorDrawable(R.drawable.ic_placemarker_blue)
                style.addImage("geolocation-icon", geolocationBitmap)

                Log.d("MapActivity", "Icons added successfully.")
            } catch (e: Exception) {
                Log.e("MapActivity", "Failed to add icons: ${e.message}")
                Toast.makeText(this, "Failed to load icons", Toast.LENGTH_SHORT).show()
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
                            // Tampilkan hasil pencarian
                            displaySearchSuggestions(results)
                            // Hapus pemanggilan displayPostgresResult di sini
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
                { selectedResult ->
                    // Panggil displayPostgresResult hanya saat pengguna memilih hasil
                    displayPostgresResult(selectedResult)
                },
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
        binding.mapView.mapboxMap.getStyle { style ->
            try {
                val geometryJson = result.geometry
                val centroidJson = result.centroid
                val centroid = Point.fromJson(centroidJson)

                if (centroid == null) {
                    Log.e("MapActivity", "Centroid is null for result: ${result.name}")
                    return@getStyle
                }

                // Hapus polygon sebelumnya jika ada
                currentPolygonId?.let { existingPolygonId ->
                    // Menghapus layer dan source dengan ID yang benar
                    if (style.styleLayerExists("layer-$existingPolygonId")) {
                        style.removeStyleLayer("layer-$existingPolygonId")
                    }
                    if (style.styleSourceExists("source-$existingPolygonId")) {
                        style.removeStyleSource("source-$existingPolygonId")
                    }
                }

                // Simpan ID polygon baru
                currentPolygonId = result.id.toString() // Pastikan result.id adalah String

                // Tambahkan sumber dan layer baru untuk polygon
                val geoJsonSourceId = "source-${result.id}"
                val fillLayerId = "layer-${result.id}"

                if (!style.styleSourceExists(geoJsonSourceId)) {
                    style.addSource(
                        geoJsonSource(geoJsonSourceId) {
                            geometry(MultiPolygon.fromJson(geometryJson))
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

                // Pusatkan kamera pada centroid
                val cameraPlugin = binding.mapView.camera
                cameraPlugin.flyTo(
                    CameraOptions.Builder()
                        .center(centroid)
                        .zoom(20.0)
                        .build(),
                    mapAnimationOptions {
                        duration(2000) // Durasi animasi dalam milidetik
                    }
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

            // Initialize the PointAnnotationManager if it hasn't been done yet
            if (pointAnnotationManager == null) {
                pointAnnotationManager = binding.mapView.annotations.createPointAnnotationManager()
            }

            // Select the place from the autocomplete suggestion
            placeAutocomplete.select(suggestion)
                .onValue { result ->
                    val coordinate = result.coordinate
                    if (coordinate == null) {
                        Log.e("MapActivity", "Coordinate is null for suggestion: ${suggestion.name}")
                        return@onValue
                    }

                    val cameraPlugin = binding.mapView.camera

                    // Fly to the selected coordinate
                    cameraPlugin.flyTo(
                        CameraOptions.Builder()
                            .center(coordinate)
                            .zoom(17.0)
                            .build(),
                        mapAnimationOptions {
                            duration(2000) // Duration of the animation in milliseconds
                        }
                    )

                    // Clear existing markers before adding a new one
                    pointAnnotationManager?.deleteAll()

                    // Create a new marker
                    val marker = PointAnnotationOptions()
                        .withPoint(coordinate)
                        .withIconImage("marker-icon")

                    pointAnnotationManager?.create(marker)
                    Log.d("MapActivity", "Marker added successfully at $coordinate")

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

    companion object {
        private const val REQUEST_ENABLE_GPS = 1001
        private const val LOCATION_PERMISSION_REQUEST_CODE = 1002
    }
}