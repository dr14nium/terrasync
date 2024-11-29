package com.drianium.terrasync.ui.map

import android.content.BroadcastReceiver
import android.content.Context
import android.content.Intent
import android.content.IntentFilter
import android.content.pm.ActivityInfo
import android.graphics.Bitmap
import android.graphics.Color
import android.location.LocationManager
import android.os.Build
import android.os.Bundle
import android.util.Log
import android.view.Gravity
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
import androidx.core.content.ContextCompat
import androidx.core.view.ViewCompat
import androidx.core.view.WindowCompat
import androidx.core.view.WindowInsetsCompat
import androidx.core.view.updateLayoutParams
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView
import com.drianium.terrasync.R
import com.drianium.terrasync.databinding.ActivityMapBinding
import com.drianium.terrasync.utils.MapUtils.isTouchOutsideView
import com.drianium.terrasync.model.SearchResult
import com.drianium.terrasync.network.ApiService
import com.drianium.terrasync.utils.MapUtils
import com.google.android.material.bottomsheet.BottomSheetDialog
import com.google.gson.Gson
import com.google.gson.JsonElement
import com.mapbox.geojson.Feature
import com.mapbox.geojson.FeatureCollection
import com.mapbox.geojson.LineString
import com.mapbox.geojson.MultiPolygon
import com.mapbox.geojson.Point
import com.mapbox.geojson.Polygon
import com.mapbox.maps.plugin.animation.CameraAnimationsPlugin
import com.mapbox.maps.plugin.animation.camera
import com.mapbox.maps.CameraOptions
import com.mapbox.maps.RenderedQueryGeometry
import com.mapbox.maps.RenderedQueryOptions
import com.mapbox.maps.Style
import com.mapbox.maps.extension.style.expressions.generated.Expression
import com.mapbox.maps.extension.style.expressions.generated.Expression.Companion.match
import com.mapbox.maps.extension.style.layers.addLayer
import com.mapbox.maps.extension.style.layers.addLayerAbove
import com.mapbox.maps.extension.style.layers.generated.FillLayer
import com.mapbox.maps.extension.style.layers.generated.LineLayer
import com.mapbox.maps.extension.style.layers.generated.SymbolLayer
import com.mapbox.maps.extension.style.layers.generated.fillLayer
import com.mapbox.maps.extension.style.layers.getLayer
import com.mapbox.maps.extension.style.layers.properties.PropertyValue
import com.mapbox.maps.extension.style.layers.properties.generated.IconAnchor
import com.mapbox.maps.extension.style.layers.properties.generated.Visibility
import com.mapbox.maps.extension.style.sources.addSource
import com.mapbox.maps.extension.style.sources.generated.GeoJsonSource
import com.mapbox.maps.extension.style.sources.generated.geoJsonSource
import com.mapbox.maps.extension.style.sources.getSourceAs
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
import kotlinx.coroutines.CompletableDeferred
import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.launch
import kotlinx.coroutines.withContext
import org.json.JSONException
import org.json.JSONObject
import java.io.File

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
    private lateinit var geoJsonCacheDir: File
    private lateinit var layerOutlines: List<View>
    private lateinit var activeOutlines: List<View>
    private lateinit var transparencyControlGroup: LinearLayout
    private lateinit var transparencySlider: SeekBar
    private val layerTransparency = mutableListOf(1.0f, 1.0f, 1.0f) // Default transparency = 100% (1.0)
    private var currentActiveBasemap: Int = 0 // Indeks basemap yang sedang aktif (default: 0)
    private var lastClickedPoint: Point? = null
    private lateinit var panelRuler: View
    private lateinit var rulerAttributesContainer: LinearLayout
    private var rulerPoints = mutableListOf<Point>()
    private var measurementMode: Boolean = false // Tracks if measurement mode is active


    override fun dispatchTouchEvent(event: MotionEvent): Boolean {
        handleTouchOutside(event)
        return super.dispatchTouchEvent(event)
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setupActivity() // Initialize activity layout and bindings

        // Ensure all required views are initialized before usage
        initializeViews()

        // Initialize geoJsonCacheDir
        geoJsonCacheDir = File(getExternalFilesDir(null), "geojson_cache")
        if (!geoJsonCacheDir.exists()) geoJsonCacheDir.mkdirs()

        // Initialize buttons and their related functionality
        setupRulerButton()
        setupBasemapButton()
        setupLayerButton()

        // Ensure cache is updated
        ensureGeoJsonCacheUpdated("BatasAdministrasi")
        ensureGeoJsonCacheUpdated("BidangTanah")
        ensureGeoJsonCacheUpdated("PolaRuang")

        // Activate all layers automatically
        toggleLayer(0, "BatasAdministrasi") // Activate BatasAdministrasi
        toggleLayer(1, "BidangTanah") // Activate BidangTanah
        toggleLayer(2, "PolaRuang") // Activate PolaRuang

        // Initialize location services and GPS receiver
        fusedLocationClient = com.google.android.gms.location.LocationServices.getFusedLocationProviderClient(this)

        buttonGeolocation = findViewById(R.id.buttonGeolocation)
        updateGeolocationState()
        registerGpsStatusReceiver()

        // Set up geolocation button click listener
        buttonGeolocation.setOnClickListener {
            if (isGpsEnabled()) {
                if (locationUpdatesInProgress) {
                    stopLocationUpdates()
                } else {
                    startLocationUpdates()
                }
            } else {
                promptEnableGpsWithDialog()
            }
        }

        // Additional setups
        setupMapView()
        setupQueryEditText()
        setupCustomCompass()
        setupTransparentSystemBars()
        initializePlaceAutocomplete()
        updateButtonStates() // Set button states on launch
    }

    // New function to initialize views
    private fun initializeViews() {
        panelRuler = findViewById(R.id.panel_ruler)
        rulerAttributesContainer = findViewById(R.id.ruler_attributes_container)
        // Add initialization for other views if needed
    }

    override fun onDestroy() {
        super.onDestroy()
        unregisterReceiver(gpsStatusReceiver) // Unregister receiver to avoid memory leaks
    }

    private fun updateButtonStates() {
        val isClickable = !measurementMode
        findViewById<ImageButton>(R.id.buttonLayer).isEnabled = isClickable
        findViewById<ImageButton>(R.id.buttonBasemap).isEnabled = isClickable
    }


    private fun setupRulerButton() {
        val buttonRuler: ImageButton = findViewById(R.id.buttonRuler)

        buttonRuler.setOnClickListener {
            if (panelRuler.visibility == View.GONE) {
                panelRuler.visibility = View.VISIBLE
                buttonRuler.isSelected = true // Highlight button when active
                measurementMode = true // Enable measurement mode
            } else {
                panelRuler.visibility = View.GONE
                buttonRuler.isSelected = false // Reset button highlight
                measurementMode = false // Disable measurement mode
                resetRuler()
            }

            // Perbarui status tombol berdasarkan mode pengukuran
            updateButtonStates()

            // Update blue dot visibility whenever the measurement mode changes
            binding.mapView.mapboxMap.getStyle { style ->
                updateBlueDotVisibility(style)
            }
        }

        // Listen to map clicks
        binding.mapView.mapboxMap.addOnMapClickListener { point ->
            if (measurementMode) {
                handleRulerPoint(point) // Perform measurement task
            } else {
                handleMapClick(point) // Perform normal map click actions
            }
            true
        }
    }

    private fun handleRulerPoint(point: Point) {
        if (rulerPoints.isNotEmpty() && isPolygonClosed()) {
            // Reset jika poligon sudah tertutup dan user mulai mengukur dari titik baru
            resetRuler()
        }

        if (rulerPoints.isNotEmpty()) {
            val tempPoints = rulerPoints.toMutableList()
            tempPoints.add(point)

            // Cek apakah titik baru menutup poligon
            if (isPolygonClosed(tempPoints)) {
                val firstPoint = rulerPoints.first()
                rulerPoints.add(firstPoint) // Tambahkan titik awal untuk menutup poligon
                updatePointsLayer()
                updateLinesLayer()
                updatePolygonLayer()
                updateDistanceView()
                updateAreaView()
                Log.d("MapActivity", "Polygon closed by snapping the last point to the first point.")
            } else {
                // Tambahkan titik baru ke daftar
                rulerPoints.add(point)
                updatePointsLayer()
                if (rulerPoints.size > 1) {
                    updateLinesLayer()
                    updateDistanceView()
                }
            }
        } else {
            // Titik pertama
            rulerPoints.add(point)
            updatePointsLayer()
        }
    }

    private fun updatePointsLayer() {
        binding.mapView.mapboxMap.getStyle { style ->
            val sourceId = "measurement-points-source"
            val featureCollection = FeatureCollection.fromFeatures(
                rulerPoints.map { Feature.fromGeometry(it) }
            )

            val existingSource = style.getSourceAs<GeoJsonSource>(sourceId)
            if (existingSource != null) {
                existingSource.featureCollection(featureCollection)
            } else {
                style.addSource(geoJsonSource(sourceId) {
                    featureCollection(featureCollection)
                })
            }
        }
    }

    private fun updateLinesLayer() {
        binding.mapView.mapboxMap.getStyle { style ->
            val sourceId = "measurement-lines-source"
            val lineString = LineString.fromLngLats(rulerPoints)

            val existingSource = style.getSourceAs<GeoJsonSource>(sourceId)
            if (existingSource != null) {
                existingSource.feature(Feature.fromGeometry(lineString))
            } else {
                style.addSource(geoJsonSource(sourceId) {
                    feature(Feature.fromGeometry(lineString))
                })
            }
        }
    }

    private fun updatePolygonLayer() {
        if (rulerPoints.size < 3) return

        // Pastikan poligon tertutup
        val closedPoints = if (rulerPoints.first() != rulerPoints.last()) {
            rulerPoints + rulerPoints.first() // Tambahkan titik awal sebagai titik terakhir
        } else {
            rulerPoints
        }

        binding.mapView.mapboxMap.getStyle { style ->
            val sourceId = "measurement-polygon-source"
            val polygon = Polygon.fromLngLats(listOf(closedPoints))

            val existingSource = style.getSourceAs<GeoJsonSource>(sourceId)
            if (existingSource != null) {
                existingSource.feature(Feature.fromGeometry(polygon))
            } else {
                style.addSource(geoJsonSource(sourceId) {
                    feature(Feature.fromGeometry(polygon))
                })
            }
        }
    }

    private fun resetRuler() {
        // Bersihkan semua data pengukuran
        rulerPoints.clear()
        rulerAttributesContainer.removeAllViews()

        binding.mapView.mapboxMap.getStyle { style ->
            // Reset semua sumber GeoJSON untuk titik, garis, dan poligon
            listOf(
                "measurement-points-source",
                "measurement-lines-source",
                "measurement-polygon-source"
            ).forEach { sourceId ->
                style.getSourceAs<GeoJsonSource>(sourceId)?.featureCollection(
                    FeatureCollection.fromFeatures(emptyList())
                )
            }
        }
        Log.d("MapActivity", "Ruler reset. All measurement data cleared.")
    }

    private fun updateDistanceView() {
        val totalDistance = calculateTotalDistance(rulerPoints)

        val existingView = rulerAttributesContainer.findViewWithTag<View>("distance")
        if (existingView != null) {
            val valueTextView = existingView.findViewById<TextView>(R.id.value_text_view)
            valueTextView.text = getString(R.string.distance_value, totalDistance)
        } else {
            val distanceView = LayoutInflater.from(this).inflate(
                R.layout.item_ruler_attribute, rulerAttributesContainer, false
            )
            distanceView.tag = "distance"
            val keyTextView = distanceView.findViewById<TextView>(R.id.key_text_view)
            val valueTextView = distanceView.findViewById<TextView>(R.id.value_text_view)

            keyTextView.text = getString(R.string.distance_label)
            valueTextView.text = getString(R.string.distance_value, totalDistance)

            rulerAttributesContainer.addView(distanceView)
        }
    }

    private fun updateAreaView() {
        val area = calculatePolygonArea(rulerPoints)

        val existingView = rulerAttributesContainer.findViewWithTag<View>("area")
        if (existingView != null) {
            val valueTextView = existingView.findViewById<TextView>(R.id.value_text_view)
            valueTextView.text = getString(R.string.area_value, area)
        } else {
            val areaView = LayoutInflater.from(this).inflate(
                R.layout.item_ruler_attribute, rulerAttributesContainer, false
            )
            areaView.tag = "area"
            val keyTextView = areaView.findViewById<TextView>(R.id.key_text_view)
            val valueTextView = areaView.findViewById<TextView>(R.id.value_text_view)

            keyTextView.text = getString(R.string.area_label)
            valueTextView.text = getString(R.string.area_value, area)

            rulerAttributesContainer.addView(areaView)
        }
    }

    private fun setupMeasurementLayers(style: Style) {
        // Tambahkan ikon ic_red_dot ke gaya jika belum ada
        if (!style.hasStyleImage("red-dot-icon")) {
            val redDotBitmap = getBitmapFromVectorDrawable(R.drawable.ic_red_dot)
            style.addImage("red-dot-icon", redDotBitmap)
            Log.d("MapActivity", "Red dot icon added.")
        }

        // Ensure the GeoJson sources for points, lines, and polygons exist
        if (!style.styleSourceExists("measurement-points-source")) {
            style.addSource(geoJsonSource("measurement-points-source"))
        }
        if (!style.styleSourceExists("measurement-lines-source")) {
            style.addSource(geoJsonSource("measurement-lines-source"))
        }
        if (!style.styleSourceExists("measurement-polygon-source")) {
            style.addSource(geoJsonSource("measurement-polygon-source"))
        }

        // Add or update the SymbolLayer for points
        if (!style.styleLayerExists("measurement-points-layer")) {
            style.addLayer(
                SymbolLayer("measurement-points-layer", "measurement-points-source").apply {
                    iconImage("red-dot-icon") // Gunakan ikon red dot
                    iconSize(1.0)
                    iconAllowOverlap(true)
                    iconIgnorePlacement(true)
                    iconAnchor(IconAnchor.BOTTOM) // Tambahkan anchor ke bawah
                    iconOffset(listOf(0.0, 0.0)) // Offset sesuai dengan blue-dot-icon
                }
            )
        }

        // Add or update the LineLayer for lines
        if (!style.styleLayerExists("measurement-lines-layer")) {
            style.addLayer(
                LineLayer("measurement-lines-layer", "measurement-lines-source").apply {
                    lineColor("#FF0000") // Red lines for measurement
                    lineWidth(2.0)
                }
            )
        }

        // Add or update the FillLayer for polygons
        if (!style.styleLayerExists("measurement-polygon-layer")) {
            style.addLayer(
                FillLayer("measurement-polygon-layer", "measurement-polygon-source").apply {
                    fillColor("#FF5733") // Semi-transparent orange fill
                    fillOpacity(0.5)
                }
            )
        }

        // Ensure measurement layers are on top
        moveMeasurementLayersToTop(style)
    }

    private fun moveMeasurementLayersToTop(style: Style) {
        val measurementLayers = listOf(
            "measurement-points-layer",
            "measurement-lines-layer",
            "measurement-polygon-layer"
        )

        for (layerId in measurementLayers) {
            if (style.styleLayerExists(layerId)) {
                style.moveStyleLayer(layerId, null) // Moves the layer to the top
            }
        }
    }

    // Perbarui isPolygonClosed untuk menerima parameter opsional
    private fun isPolygonClosed(points: List<Point> = rulerPoints): Boolean {
        if (points.size < 3) return false
        val firstPoint = points.first()
        val lastPoint = points.last()
        val threshold = 5.0 / 111139.0 // approx 5 m
        return Math.abs(firstPoint.latitude() - lastPoint.latitude()) < threshold &&
                Math.abs(firstPoint.longitude() - lastPoint.longitude()) < threshold
    }

    private fun calculateTotalDistance(points: List<Point>): Double {
        var distance = 0.0
        for (i in 0 until points.size - 1) {
            distance += calculateDistance(points[i], points[i + 1])
        }
        return distance
    }

    private fun calculateDistance(start: Point, end: Point): Double {
        val earthRadius = 6371000.0 // meters
        val dLat = Math.toRadians(end.latitude() - start.latitude())
        val dLon = Math.toRadians(end.longitude() - start.longitude())
        val a = Math.sin(dLat / 2) * Math.sin(dLat / 2) +
                Math.cos(Math.toRadians(start.latitude())) * Math.cos(Math.toRadians(end.latitude())) *
                Math.sin(dLon / 2) * Math.sin(dLon / 2)
        val c = 2 * Math.atan2(Math.sqrt(a), Math.sqrt(1 - a))
        return earthRadius * c
    }

    private fun calculatePolygonArea(points: List<Point>): Double {
        if (points.size < 3) return 0.0
        val earthRadius = 6371000.0 // meters
        var area = 0.0
        for (i in points.indices) {
            val p1 = points[i]
            val p2 = points[(i + 1) % points.size]
            area += Math.toRadians(p2.longitude() - p1.longitude()) *
                    (2 + Math.sin(Math.toRadians(p1.latitude())) + Math.sin(Math.toRadians(p2.latitude())))
        }
        area = Math.abs(area * earthRadius * earthRadius / 2.0)
        return area
    }

    private fun setupBasemapButton() {
        val buttonBasemap: ImageButton = findViewById(R.id.buttonBasemap)
        var isBottomSheetVisible = false

        val bottomSheetDialog = BottomSheetDialog(this)
        val bottomSheetView = layoutInflater.inflate(R.layout.bottom_sheet_basemap, null)
        bottomSheetDialog.setContentView(bottomSheetView)

        // Referensi outline aktif
        val activeOutlineBasemap1 = bottomSheetView.findViewById<View>(R.id.active_outline_basemap1)
        val activeOutlineBasemap2 = bottomSheetView.findViewById<View>(R.id.active_outline_basemap2)
        val activeOutlineBasemap3 = bottomSheetView.findViewById<View>(R.id.active_outline_basemap3)

        // Referensi ikon basemap
        val iconBasemap1 = bottomSheetView.findViewById<ImageView>(R.id.icon_basemap1)
        val iconBasemap2 = bottomSheetView.findViewById<ImageView>(R.id.icon_basemap2)
        val iconBasemap3 = bottomSheetView.findViewById<ImageView>(R.id.icon_basemap3)

        // Simpan referensi outline ke dalam list
        val activeOutlines = listOf(activeOutlineBasemap1, activeOutlineBasemap2, activeOutlineBasemap3)

        // Basemap ID sesuai urutan (disesuaikan dengan Style Mapbox Anda)
        val basemapStyles = listOf(
            "mapbox://styles/mapbox/streets-v12",
            "mapbox://styles/mapbox/light-v11",
            "mapbox://styles/mapbox/satellite-v9"
        )

        // Status aktif (default aktif untuk basemap pertama)
        var currentActiveBasemap = 0
        activeOutlines[currentActiveBasemap].visibility = View.VISIBLE

        // Listener untuk setiap basemap
        iconBasemap1.setOnClickListener {
            switchBasemap(0, basemapStyles, activeOutlines)
        }

        iconBasemap2.setOnClickListener {
            switchBasemap(1, basemapStyles, activeOutlines)
        }

        iconBasemap3.setOnClickListener {
            switchBasemap(2, basemapStyles, activeOutlines)
        }

        // Tampilkan atau sembunyikan BottomSheet
        buttonBasemap.setOnClickListener {
            if (isBottomSheetVisible) {
                bottomSheetDialog.dismiss()
            } else {
                bottomSheetDialog.show()
            }
            isBottomSheetVisible = !isBottomSheetVisible
            // Perbarui state tombol berdasarkan visibilitas bottom sheet
            updateButtonState(buttonBasemap, isBottomSheetVisible)
        }

        bottomSheetDialog.setOnDismissListener {
            isBottomSheetVisible = false
            // Perbarui state tombol ketika bottom sheet ditutup
            updateButtonState(buttonBasemap, isBottomSheetVisible)
        }
    }

    private fun switchBasemap(selectedIndex: Int, basemapStyles: List<String>, activeOutlines: List<View>) {
        if (selectedIndex == currentActiveBasemap) return

        if (selectedIndex < basemapStyles.size) {
            val selectedStyle = basemapStyles[selectedIndex]

            initializePointAnnotationManager()

            binding.mapView.mapboxMap.loadStyleUri(selectedStyle) { style ->
                // Tambahkan ulang ikon untuk blue dot dan marker
                addIconsToStyle(style)

                // Jika geoLocationMarker sudah ada, tambahkan kembali
                geoLocationMarker?.let { marker ->
                    pointAnnotationManager?.create(
                        PointAnnotationOptions()
                            .withPoint(marker.point!!)
                            .withIconImage("geolocation-icon") // Ikon biru
                    )
                }

                // Jika marker pink untuk selectPlace sudah ada, tambahkan kembali
                pointAnnotationManager?.annotations?.forEach { annotation ->
                    if (annotation.iconImage == "marker-icon") {
                        pointAnnotationManager?.create(
                            PointAnnotationOptions()
                                .withPoint(annotation.point)
                                .withIconImage("marker-icon") // Ikon pink
                        )
                    }
                }

                // Tambahkan ulang blue dot jika ada
                lastClickedPoint?.let { point ->
                    addOrMoveBlueDot(style, point)
                }

                // Perbarui layer dan data geojson
                ensureGeoJsonCacheUpdated("BatasAdministrasi")
                ensureGeoJsonCacheUpdated("BidangTanah")
                ensureGeoJsonCacheUpdated("PolaRuang")

                addLayersToMap(style)
                reloadActiveLayers()

                // Perbarui tampilan basemap aktif
                activeOutlines.forEachIndexed { index, view ->
                    view.visibility = if (index == selectedIndex) View.VISIBLE else View.GONE
                }

                currentActiveBasemap = selectedIndex
            }
        }
    }

    private fun addIconsToStyle(style: Style) {
        try {
            val blueDotBitmap = getBitmapFromVectorDrawable(R.drawable.ic_blue_dot)
            val pinkMarkerBitmap = getBitmapFromVectorDrawable(R.drawable.ic_placemarker_pink)
            val blueGeolocationBitmap = getBitmapFromVectorDrawable(R.drawable.ic_placemarker_blue)
            val redDotBitmap = getBitmapFromVectorDrawable(R.drawable.ic_red_dot) // Tambahkan red dot

            // Tambahkan ikon untuk blue dot
            if (!style.hasStyleImage("blue-dot-icon")) {
                style.addImage("blue-dot-icon", blueDotBitmap)
            }

            // Tambahkan ikon untuk marker pink
            if (!style.hasStyleImage("marker-icon")) {
                style.addImage("marker-icon", pinkMarkerBitmap)
            }

            // Tambahkan ikon untuk marker geolokasi
            if (!style.hasStyleImage("geolocation-icon")) {
                style.addImage("geolocation-icon", blueGeolocationBitmap)
            }

            // Tambahkan ikon untuk red dot
            if (!style.hasStyleImage("red-dot-icon")) {
                style.addImage("red-dot-icon", redDotBitmap)
            }

            Log.d("MapActivity", "Icons added successfully.")
        } catch (e: Exception) {
            Log.e("MapActivity", "Failed to add icons: ${e.message}")
        }
    }

    private fun initializePointAnnotationManager() {
        if (pointAnnotationManager == null) {
            pointAnnotationManager = binding.mapView.annotations.createPointAnnotationManager()
        }
    }

    private fun reloadActiveLayers() {
        val mapboxMap = binding.mapView.mapboxMap
        mapboxMap.getStyle { style ->
            layerOutlines.forEachIndexed { index, view ->
                val tableName = when (index) {
                    0 -> "BatasAdministrasi"
                    1 -> "BidangTanah"
                    2 -> "PolaRuang"
                    else -> return@forEachIndexed
                }
                if (view.isSelected) {
                    val cachedData = MapUtils.readGeoJsonFromCache(geoJsonCacheDir, "layer-$tableName.geojson")
                    if (!cachedData.isNullOrEmpty()) {
                        loadGeoJsonToMap(tableName, cachedData)
                    }
                    setLayerVisibility(tableName, true) // Pastikan layer terlihat
                }
            }
        }
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

        layerOutlines = listOf(outlineLayer1, outlineLayer2, outlineLayer3)
        activeOutlines = listOf(activeOutlineLayer1, activeOutlineLayer2, activeOutlineLayer3)

        // Referensi kontrol transparansi
        transparencyControlGroup = bottomSheetView.findViewById<LinearLayout>(R.id.transparency_control_group)
        transparencySlider = bottomSheetView.findViewById<SeekBar>(R.id.transparency_slider)

        // Array untuk menyimpan transparansi masing-masing layer
        val layerTransparency = mutableListOf(1.0f, 1.0f, 1.0f) // Default transparansi = 100% (1.0)

        // Listener untuk setiap button layer
        bottomSheetView.findViewById<ImageView>(R.id.icon_layer1)?.apply {
            setOnClickListener {
                if (outlineLayer1.isSelected) {
                    setupTransparencySlider(0, "BatasAdministrasi") // Tambahkan tableName
                }
            }
            setOnLongClickListener {
                toggleLayer(0, "BatasAdministrasi") // Tambahkan tableName
                true
            }
        }

        bottomSheetView.findViewById<ImageView>(R.id.icon_layer2)?.apply {
            setOnClickListener {
                if (outlineLayer2.isSelected) {
                    setupTransparencySlider(1, "BidangTanah") // Tambahkan tableName
                }
            }
            setOnLongClickListener {
                toggleLayer(1, "BidangTanah") // Tambahkan tableName
                true
            }
        }

        bottomSheetView.findViewById<ImageView>(R.id.icon_layer3)?.apply {
            setOnClickListener {
                if (outlineLayer3.isSelected) {
                    setupTransparencySlider(2, "PolaRuang") // Tambahkan tableName
                }
            }
            setOnLongClickListener {
                toggleLayer(2, "PolaRuang") // Tambahkan tableName
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
            // Update button state based on bottom sheet visibility
            updateButtonState(buttonLayer, isBottomSheetVisible)
        }

        bottomSheetDialog.setOnDismissListener {
            isBottomSheetVisible = false
            // Update button state when bottom sheet is dismissed
            updateButtonState(buttonLayer, isBottomSheetVisible)
        }
    }

    private fun toggleLayer(selectedIndex: Int, tableName: String) {
        val selectedView = layerOutlines[selectedIndex]
        val isAlreadyActive = selectedView?.isSelected == true

        if (isAlreadyActive) {
            // Sembunyikan layer jika sudah aktif
            selectedView?.isSelected = false
            setLayerVisibility(tableName, false)
            activeOutlines[selectedIndex]?.visibility = View.GONE
            transparencyControlGroup.visibility = View.GONE
            Log.d("MapActivity", "Layer $tableName hidden.")
        } else {
            // Tampilkan layer jika belum aktif
            selectedView?.isSelected = true

            // Pastikan sumber layer dimuat sebelum ditampilkan
            val cachedData = MapUtils.readGeoJsonFromCache(geoJsonCacheDir, "layer-$tableName.geojson")
            if (cachedData.isNullOrEmpty()) {
                Log.e("MapActivity", "Cached GeoJSON for $tableName is empty or null.")
                return
            } else {
                loadGeoJsonToMap(tableName, cachedData)
                Log.d("MapActivity", "Layer $tableName successfully loaded and made visible.")
            }

            // Set visibilitas layer ke true
            setLayerVisibility(tableName, true) // Pastikan layer ditampilkan
            setupTransparencySlider(selectedIndex, tableName)
            activeOutlines.forEachIndexed { index, view ->
                view.visibility = if (index == selectedIndex) View.VISIBLE else View.GONE
            }
            Log.d("MapActivity", "Layer $tableName shown.")
        }
    }

    private fun setLayerVisibility(tableName: String, visible: Boolean) {
        val mapboxMap = binding.mapView.mapboxMap
        mapboxMap.getStyle { style ->
            val layerId = "layer-$tableName"
            val layer = style.getLayer(layerId)
            if (layer != null) {
                layer.visibility(if (visible) Visibility.VISIBLE else Visibility.NONE)
                Log.d("MapActivity", "Layer $layerId visibility set to ${if (visible) "VISIBLE" else "NONE"}.")
            } else {
                Log.e("MapActivity", "Layer $layerId not found when setting visibility.")
            }
        }
    }

    private fun setupTransparencySlider(selectedIndex: Int, tableName: String) {
        val selectedView = layerOutlines[selectedIndex]
        if (selectedView.isSelected) { // Check if the layer is active
            // Show active outline
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
                        updateLayerTransparency(tableName, transparency) // Update transparency
                    }
                }

                override fun onStartTrackingTouch(seekBar: SeekBar?) {}
                override fun onStopTrackingTouch(seekBar: SeekBar?) {}
            })
        } else {
            // Hide all active outlines
            activeOutlines.forEach { it.visibility = View.GONE }
            transparencyControlGroup.visibility = View.GONE
        }
    }

    // Function to update the button state
    private fun updateButtonState(button: ImageButton, isActive: Boolean) {
        button.isSelected = isActive // Set the button as selected or not
        // No need to change isEnabled, just change the appearance based on the selector
    }

    // Fungsi untuk memperbarui transparansi layer
    private fun updateLayerTransparency(tableName: String, transparency: Float) {
        val mapboxMap = binding.mapView.mapboxMap
        mapboxMap.getStyle { style ->
            val layerId = "layer-$tableName"
            val layer = style.getLayer(layerId)
            if (layer != null && layer is FillLayer) {
                layer.fillOpacity(transparency.toDouble())
                Log.d("MapActivity", "Transparency of $layerId updated to $transparency.")
            } else {
                Log.e("MapActivity", "Layer $layerId not found or not a FillLayer.")
            }
        }
    }

    private fun ensureGeoJsonCacheUpdated(tableName: String) {
        val cacheFileName = "layer-$tableName.geojson"
        val cacheFile = File(geoJsonCacheDir, cacheFileName)

        CoroutineScope(Dispatchers.IO).launch {
            val shouldUpdateCache = !cacheFile.exists() || cacheFile.length() == 0L

            if (shouldUpdateCache) {
                val response = ApiService.create().getAllFeatures(tableName)
                if (response.isSuccessful) {
                    val geoJsonData = response.body()
                    if (geoJsonData != null && geoJsonData.features.isNotEmpty()) {
                        val geoJsonString = Gson().toJson(geoJsonData)
                        if (isValidGeoJson(geoJsonString)) {
                            MapUtils.writeGeoJsonToCache(geoJsonCacheDir, cacheFileName, geoJsonString)
                            Log.d("MapActivity", "Cache updated for $tableName.")
                        } else {
                            Log.e("MapActivity", "Invalid GeoJSON received for $tableName.")
                        }
                    } else {
                        Log.e("MapActivity", "No features found in GeoJSON response for $tableName.")
                    }
                } else {
                    Log.e("MapActivity", "Failed to fetch GeoJSON for $tableName: ${response.errorBody()?.string()}")
                }
            } else {
                Log.d("MapActivity", "Cache is up-to-date for $tableName.")
            }
        }
    }

    // Function to validate GeoJSON format
    private fun isValidGeoJson(geoJson: String): Boolean {
        return try {
            val jsonObject = JSONObject(geoJson)
            jsonObject.has("type") && jsonObject.has("features")
        } catch (e: JSONException) {
            false
        }
    }

    private fun addLayersToMap(style: Style) {
        val layersConfig = listOf(
            "PolaRuang" to null,
            "BidangTanah" to Pair("#000000", 1.0f),
            "BatasAdministrasi" to Pair("#FF0000", 1.0f)
        )

        for ((tableName, config) in layersConfig) {
            val sourceId = "source-$tableName"
            val layerId = "layer-$tableName"

            if (!style.styleLayerExists(layerId)) {
                val layer = when (tableName) {
                    "PolaRuang" -> fillLayer(layerId, sourceId) {
                        fillColor(getPolaRuangColorExpression()) // Ekspresi warna untuk Pola Ruang
                        fillOpacity(1.0) // Opasitas isi
                    }
                    else -> fillLayer(layerId, sourceId) {
                        fillOutlineColor(config?.first ?: "#000000") // Warna outline
                        fillOpacity(config?.second?.toDouble() ?: 1.0) // Opasitas isi
                        fillColor(Color.TRANSPARENT) // Isi transparan
                    }
                }

                // Menambahkan layer dengan urutan yang benar
                when (tableName) {
                    "PolaRuang" -> {
                        style.addLayer(layer) // Pola Ruang di paling bawah
                    }
                    "BidangTanah" -> {
                        style.addLayerAbove(layer, "layer-PolaRuang") // Bidang Tanah di atas Pola Ruang
                    }
                    "BatasAdministrasi" -> {
                        style.addLayerAbove(layer, "layer-BidangTanah") // Batas Administrasi di atas Bidang Tanah
                    }
                }
                Log.d("MapActivity", "Layer $layerId added successfully.")
            } else {
                Log.d("MapActivity", "Layer $layerId already exists, skipping.")
            }

            // Pastikan klik listener ditambahkan untuk layer ini
            setupMapClickListener(tableName)
        }

        // Tambahkan blue-dot-layer di atas semua layer
        addBlueDotLayer(style)

        // Tambahkan lapisan pengukuran di atas blue dot
        setupMeasurementLayers(style)
    }

    private fun getPolaRuangColorExpression(): Expression {
        return match {
            toString { get("namobj") }
            stop { literal("Badan Air"); color(Color.rgb(151, 219, 242)) }
            stop { literal("Badan Jalan"); color(Color.rgb(235, 30, 30)) }
            stop { literal("Cagar Budaya"); color(Color.rgb(255, 55, 205)) }
            stop { literal("Jalur Hijau"); color(Color.rgb(15, 245, 0)) }
            stop { literal("Pemakaman"); color(Color.rgb(90, 255, 0)) }
            stop { literal("Perdagangan dan Jasa Skala Kota"); color(Color.rgb(255, 100, 100)) }
            stop { literal("Perdagangan dan Jasa Skala WP"); color(Color.rgb(255, 165, 165)) }
            stop { literal("Perlindungan Setempat"); color(Color.rgb(5, 215, 215)) }
            stop { literal("Perumahan Kepadatan Sedang"); color(Color.rgb(255, 240, 5)) }
            stop { literal("Perumahan Kepadatan Tinggi"); color(Color.rgb(255, 220, 0)) }
            stop { literal("SPU Skala Kecamatan"); color(Color.rgb(155, 50, 155)) }
            stop { literal("SPU Skala Kelurahan"); color(Color.rgb(185, 75, 185)) }
            stop { literal("SPU Skala Kota"); color(Color.rgb(125, 25, 125)) }
            stop { literal("Taman Kecamatan"); color(Color.rgb(70, 135, 0)) }
            stop { literal("Taman Kelurahan"); color(Color.rgb(75, 165, 0)) }
            stop { literal("Taman Kota"); color(Color.rgb(65, 105, 0)) }
            stop { literal("Taman RW"); color(Color.rgb(80, 195, 0)) }
            stop { literal("Transportasi"); color(Color.rgb(215, 55, 0)) }
            color(Color.BLACK) // Default: Hitam
        }
    }


    private fun loadGeoJsonToMap(tableName: String, geoJsonString: String) {
        val mapboxMap = binding.mapView.mapboxMap

        try {
            val featureCollection = FeatureCollection.fromJson(geoJsonString)

            if (featureCollection.features().isNullOrEmpty()) {
                Log.e("MapActivity", "GeoJSON for $tableName has no valid features.")
                return
            }

            mapboxMap.getStyle { style ->
                val sourceId = "source-$tableName"

                // Hapus sumber lama jika ada
                if (style.styleSourceExists(sourceId)) {
                    style.removeStyleSource(sourceId)
                }

                style.addSource(geoJsonSource(sourceId) {
                    featureCollection(featureCollection)
                })
                Log.d("MapActivity", "Source $sourceId added.")
            }
        } catch (e: Exception) {
            Log.e("MapActivity", "Failed to load GeoJSON for $tableName: ${e.message}")
        }
    }

    private fun setupMapClickListener(tableName: String) {
        val layerId = "layer-$tableName" // Gunakan ID layer yang sesuai
        binding.mapView.mapboxMap.addOnMapClickListener { point ->
            Log.d("MapActivity", "Map clicked at point: $point for layer: $layerId")
            handleMapClick(point) // Hanya kirimkan Point
            true
        }
    }

    private fun handleMapClick(point: Point) {
        val mapboxMap = binding.mapView.mapboxMap
        val screenCoordinate = mapboxMap.pixelForCoordinate(point)

        mapboxMap.getStyle { style ->
            val source = style.getSourceAs<GeoJsonSource>("blue-dot-source")
            if (source != null) {
                source.geometry(point)
                Log.d("MapActivity", "Blue dot moved to $point")
            }

            // Query fitur di lokasi yang diklik
            val activeLayers = listOf("layer-BatasAdministrasi", "layer-BidangTanah", "layer-PolaRuang")
                .filter { layerId ->
                    style.styleLayerExists(layerId)
                }

            if (activeLayers.isEmpty()) {
                Toast.makeText(this, "Tidak ada layer aktif!", Toast.LENGTH_SHORT).show()
                return@getStyle
            }

            CoroutineScope(Dispatchers.Main).launch {
                val queryResults = mutableListOf<Pair<String, List<Feature>>>()

                activeLayers.forEach { layerId ->
                    val deferredResult = CompletableDeferred<List<Feature>>()

                    mapboxMap.queryRenderedFeatures(
                        RenderedQueryGeometry(screenCoordinate),
                        RenderedQueryOptions(listOf(layerId), null)
                    ) { result ->
                        if (result.isValue) {
                            val features = result.value?.mapNotNull { it.queriedFeature?.feature } ?: emptyList()
                            deferredResult.complete(features)
                        } else {
                            deferredResult.complete(emptyList())
                        }
                    }

                    val features = deferredResult.await()
                    if (features.isNotEmpty()) {
                        queryResults.add(layerId to features)
                    }
                }

                if (queryResults.isNotEmpty()) {
                    showFeaturesInBottomSheet(queryResults)
                } else {
                    Toast.makeText(this@MapActivity, "Tidak ada fitur yang ditemukan!", Toast.LENGTH_SHORT).show()
                }
            }
        }
    }

    private fun addBlueDotLayer(style: Style) {
        val sourceId = "blue-dot-source"
        val layerId = "blue-dot-layer"

        // Pastikan sumber ada
        val existingSource = style.getSourceAs<GeoJsonSource>(sourceId)
        if (existingSource == null) {
            style.addSource(geoJsonSource(sourceId) {
                geometry(Point.fromLngLat(0.0, 0.0)) // Placeholder geometry
            })
            Log.d("MapActivity", "Blue dot source added.")
        }

        // Tambahkan layer jika belum ada
        if (!style.styleLayerExists(layerId)) {
            style.addLayer(
                SymbolLayer(layerId, sourceId).apply {
                    iconImage("blue-dot-icon")
                    iconAllowOverlap(true)
                    iconIgnorePlacement(true)
                    iconAnchor(IconAnchor.BOTTOM) // Mengubah anchor ke bawah
                    iconOffset(listOf(0.0, 0.0)) // Gunakan Double, bukan Float
                }
            )
            Log.d("MapActivity", "Blue dot layer added with BOTTOM anchor.")
        } else {
            Log.d("MapActivity", "Blue dot layer already exists.")
        }
    }

    private fun addOrMoveBlueDot(style: Style, point: Point) {
        val sourceId = "blue-dot-source"
        val layerId = "blue-dot-layer"

        // Update GeoJSON source
        val existingSource = style.getSourceAs<GeoJsonSource>(sourceId)
        if (existingSource != null) {
            existingSource.geometry(point)
            Log.d("MapActivity", "Blue dot source updated at $point")
        } else {
            style.addSource(geoJsonSource(sourceId) {
                geometry(point)
            })
            Log.d("MapActivity", "Blue dot source added at $point")
        }

        // Add layer if not exists
        if (!style.styleLayerExists(layerId)) {
            style.addLayer(
                SymbolLayer(layerId, sourceId).apply {
                    iconImage("blue-dot-icon")
                    iconAllowOverlap(true)
                    iconIgnorePlacement(true)
                    iconAnchor(IconAnchor.BOTTOM)
                    iconOffset(listOf(0.0, 0.0))
                }
            )
            Log.d("MapActivity", "Blue dot layer added with BOTTOM anchor.")
        }

        // Update blue dot visibility based on measurementMode
        updateBlueDotVisibility(style)
    }

    private fun updateBlueDotVisibility(style: Style) {
        val layerId = "blue-dot-layer"
        if (style.styleLayerExists(layerId)) {
            val visibility = if (measurementMode) Visibility.NONE else Visibility.VISIBLE
            style.getLayer(layerId)?.visibility(visibility)
            Log.d("MapActivity", "Blue dot visibility set to $visibility")
        }
    }


    private suspend fun showFeaturesInBottomSheet(queryResults: List<Pair<String, List<Feature>>>) {
        withContext(Dispatchers.Main) {
            val bottomSheetDialog = BottomSheetDialog(this@MapActivity)
            val bottomSheetView = layoutInflater.inflate(R.layout.bottom_sheet_feature, null)
            bottomSheetDialog.setContentView(bottomSheetView)

            val attributeContainer = bottomSheetView.findViewById<LinearLayout>(R.id.attribute_container)
            attributeContainer.removeAllViews()

            queryResults.forEach { (layerId, features) ->
                // Tambahkan judul layer
                val layerTitle = TextView(this@MapActivity).apply {
                    text = formatLayerTitle(layerId) // Gunakan fungsi pemformatan
                    textSize = 16f
                    setPadding(0, 8, 0, 8)
                    setTypeface(typeface, android.graphics.Typeface.BOLD) // Teks bold
                    setTextColor(ContextCompat.getColor(this@MapActivity, R.color.primary))
                }
                attributeContainer.addView(layerTitle)

                // Konfigurasi key yang ingin ditampilkan per layer
                val keyMappings = getKeyMappingsForLayer(layerId)

                // Tambahkan atribut fitur sesuai keyMappings
                features.forEach { feature ->
                    val properties = feature.properties()
                    if (properties != null) {
                        keyMappings.forEach { (originalKey, displayKey) ->
                            val propertyValue = properties[originalKey]?.asString
                            if (propertyValue == null) return@forEach // Ganti continue dengan return@forEach
                            val formattedValue = formatValueForKey(originalKey, propertyValue)

                            val attributeView = LayoutInflater.from(this@MapActivity)
                                .inflate(R.layout.item_attribute, attributeContainer, false)
                            val keyTextView = attributeView.findViewById<TextView>(R.id.key_text_view)
                            val valueTextView = attributeView.findViewById<TextView>(R.id.value_text_view)

                            keyTextView.text = displayKey
                            valueTextView.text = formattedValue
                            attributeContainer.addView(attributeView)
                        }
                    } else {
                        Log.w("MapActivity", "Feature in $layerId has no properties.")
                    }
                }

                // Tambahkan garis pemisah setelah setiap layer
                val divider = View(this@MapActivity).apply {
                    layoutParams = LinearLayout.LayoutParams(
                        LinearLayout.LayoutParams.MATCH_PARENT,
                        2 // Ketebalan garis (2dp)
                    ).apply {
                        setMargins(0, 8, 0, 8) // Margin atas dan bawah
                    }
                    setBackgroundColor(android.graphics.Color.LTGRAY) // Warna garis
                }
                attributeContainer.addView(divider)
            }

            bottomSheetDialog.show()
        }
    }

    // Fungsi untuk mendapatkan key mappings berdasarkan layer
    private fun getKeyMappingsForLayer(layerId: String): Map<String, String> {
        return when (layerId) {
            "layer-BatasAdministrasi" -> mapOf(
                "wadmkd" to "Desa"
            )
            "layer-BidangTanah" -> mapOf(
                "NIB" to "NIB",
                "TIPEHAK" to "Hak Atas Tanah",
                "LUAS BUMI" to "Luas",
                "NJOP BUMI" to "Nilai Jual Objek Pajak",
                "RANGENILAI" to "Nilai Tanah"
            )
            "layer-PolaRuang" -> mapOf(
                "namobj" to "Zona",
                "kodzon" to "Kode Zona",
                "kodszon" to "Kode Sub Zona",
                "cagbud" to "Kawasan"
            )
            else -> emptyMap()
        }
    }

    // Fungsi untuk memformat nilai atribut berdasarkan key
    private fun formatValueForKey(key: String, value: String): String {
        return when (key) {
            "LUAS BUMI" -> "$value m²" // Kuadrat diwakili dengan Unicode superscript 2
            "NJOP BUMI" -> {
                // Konversi NJOP ke format jutaan dan tambahkan "Rp"
                val njopValue = value.toDoubleOrNull()
                if (njopValue != null && njopValue >= 0) {
                    val njopInMillions = (njopValue * 1_000_000).toLong()
                    "Rp${String.format("%,d", njopInMillions)}"
                } else {
                    "Data Tidak Tersedia" // Tampilkan pesan khusus untuk nilai tidak valid
                }
            }
            "RANGENILAI" -> {
                val cleanedValue = value.removeSurrounding("\"").trim() // Bersihkan tanda kutip dan spasi
                return when {
                    cleanedValue.startsWith(">") -> {
                        // Jika format menggunakan ">", ambil nilai setelah ">"
                        val greaterValue = cleanedValue.removePrefix(">").trim().replace(".", "").toDoubleOrNull()
                        if (greaterValue != null) {
                            "> Rp${String.format("%,.0f", greaterValue)}"
                        } else {
                            "Data Tidak Valid"
                        }
                    }
                    cleanedValue.contains("-") -> {
                        // Jika format adalah rentang (mengandung "-"), proses sebagai rentang
                        val range = cleanedValue.split("-")
                        if (range.size == 2) {
                            val start = range[0].trim().replace(".", "").toDoubleOrNull()
                            val end = range[1].trim().replace(".", "").toDoubleOrNull()
                            if (start != null && end != null) {
                                "Rp${String.format("%,.0f", start)} - Rp${String.format("%,.0f", end)}"
                            } else {
                                "Data Tidak Valid"
                            }
                        } else {
                            "Format Tidak Valid"
                        }
                    }
                    else -> {
                        // Jika bukan rentang atau tidak diawali ">", coba konversi sebagai nilai tunggal
                        val singleValue = cleanedValue.replace(".", "").toDoubleOrNull()
                        if (singleValue != null) {
                            "Rp${String.format("%,.0f", singleValue)}"
                        } else {
                            "Format Tidak Valid"
                        }
                    }
                }
            }
            else -> value.removeSurrounding("\"") // Hilangkan tanda kutip pada string
        }
    }

    private fun formatLayerTitle(layerId: String): String {
        return when (layerId) {
            "layer-BatasAdministrasi" -> "Batas Administrasi"
            "layer-PolaRuang" -> "Pola Ruang"
            "layer-BidangTanah" -> "Batas Tanah"
            else -> layerId // Jika tidak dikenal, tampilkan ID asli
        }
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
                    val mapboxMap = binding.mapView.mapboxMap
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
                // Tambahkan ikon blue dot
                addIconsToStyle(style)

                // Tambahkan blue dot jika ada lokasi terakhir
                lastClickedPoint?.let { point ->
                    addOrMoveBlueDot(style, point)
                }

                setupMeasurementLayers(style)

                // Tambahkan ikon marker placeautocomplete
                val markerBitmap = getBitmapFromVectorDrawable(R.drawable.ic_placemarker_pink)
                style.addImage("marker-icon", markerBitmap)

                // Tambahkan ikon geolokasi
                val geolocationBitmap = getBitmapFromVectorDrawable(R.drawable.ic_placemarker_blue)
                style.addImage("geolocation-icon", geolocationBitmap)
                Log.d("MapActivity", "Icons added successfully.")

                // Tambahkan layer untuk setiap kategori
                addLayersToMap(style)
                Log.d("MapActivity", "Layers added successfully.")
            } catch (e: Exception) {
                Log.e("MapActivity", "Failed to add blue dot icon: ${e.message}")
                Log.e("MapActivity", "Failed to add icons: ${e.message}")
                Log.e("MapActivity", "Error adding layers: ${e.message}")
                Toast.makeText(this, "Failed to load icons and layers", Toast.LENGTH_SHORT).show()
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
                val centroid = Point.fromJson(result.centroid)

                // Hapus polygon sebelumnya jika ada
                currentPolygonId?.let { existingPolygonId ->
                    if (style.styleLayerExists("layer-$existingPolygonId")) {
                        style.removeStyleLayer("layer-$existingPolygonId")
                    }
                    if (style.styleSourceExists("source-$existingPolygonId")) {
                        style.removeStyleSource("source-$existingPolygonId")
                    }
                }

                // Tambahkan sumber dan layer baru
                val sourceId = "source-${result.id}"
                val layerId = "layer-${result.id}"

                if (!style.styleSourceExists(sourceId)) {
                    style.addSource(
                        geoJsonSource(sourceId) {
                            geometry(MultiPolygon.fromJson(geometryJson))
                        }
                    )
                }

                if (!style.styleLayerExists(layerId)) {
                    style.addLayer(
                        fillLayer(layerId, sourceId) {
                            fillColor("#FF5733")
                            fillOpacity(0.5)
                        }
                    )
                }

                // Pusatkan kamera pada centroid
                binding.mapView.camera.flyTo(
                    CameraOptions.Builder()
                        .center(centroid)
                        .zoom(20.0)
                        .build(),
                    mapAnimationOptions { duration(2000) }
                )

                currentPolygonId = result.id.toString()
                Log.d("MapActivity", "Displayed result for ${result.name}")
            } catch (e: Exception) {
                Log.e("MapActivity", "Error displaying result: ${result.name}", e)
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
            window.setDecorFitsSystemWindows(false)
            val controller = window.insetsController
            controller?.setSystemBarsAppearance(
                WindowInsetsController.APPEARANCE_LIGHT_STATUS_BARS,
                WindowInsetsController.APPEARANCE_LIGHT_STATUS_BARS
            )
            window.statusBarColor = Color.TRANSPARENT
            window.navigationBarColor = Color.TRANSPARENT
        } else {
            @Suppress("DEPRECATION")
            window.decorView.systemUiVisibility = (
                    View.SYSTEM_UI_FLAG_LAYOUT_STABLE
                            or View.SYSTEM_UI_FLAG_LAYOUT_FULLSCREEN
                            or View.SYSTEM_UI_FLAG_LAYOUT_HIDE_NAVIGATION
                            or View.SYSTEM_UI_FLAG_LIGHT_STATUS_BAR
                    )
            @Suppress("DEPRECATION")
            window.statusBarColor = Color.TRANSPARENT
            @Suppress("DEPRECATION")
            window.navigationBarColor = Color.TRANSPARENT
        }
    }

    companion object {
        private const val REQUEST_ENABLE_GPS = 1001
        private const val LOCATION_PERMISSION_REQUEST_CODE = 1002
    }
}