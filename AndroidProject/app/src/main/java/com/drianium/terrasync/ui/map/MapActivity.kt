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
import com.drianium.terrasync.utils.MapUtils.isTouchOutsideView
import com.drianium.terrasync.model.SearchResult
import com.drianium.terrasync.network.ApiService
import com.drianium.terrasync.utils.MapUtils
import com.google.android.material.bottomsheet.BottomSheetDialog
import com.google.gson.Gson
import com.google.gson.JsonElement
import com.mapbox.geojson.Feature
import com.mapbox.geojson.FeatureCollection
import com.mapbox.geojson.MultiPolygon
import com.mapbox.geojson.Point
import com.mapbox.maps.plugin.animation.CameraAnimationsPlugin
import com.mapbox.maps.plugin.animation.camera
import com.mapbox.maps.CameraOptions
import com.mapbox.maps.RenderedQueryGeometry
import com.mapbox.maps.RenderedQueryOptions
import com.mapbox.maps.Style
import com.mapbox.maps.extension.style.expressions.generated.Expression
import com.mapbox.maps.extension.style.expressions.generated.Expression.Companion.match
import com.mapbox.maps.extension.style.layers.Layer
import com.mapbox.maps.extension.style.layers.addLayer
import com.mapbox.maps.extension.style.layers.addPersistentLayer
import com.mapbox.maps.extension.style.layers.generated.FillLayer
import com.mapbox.maps.extension.style.layers.generated.LineLayer
import com.mapbox.maps.extension.style.layers.generated.fillLayer
import com.mapbox.maps.extension.style.layers.generated.lineLayer
import com.mapbox.maps.extension.style.layers.getLayer
import com.mapbox.maps.extension.style.layers.properties.generated.IconAnchor
import com.mapbox.maps.extension.style.layers.properties.generated.LineCap
import com.mapbox.maps.extension.style.layers.properties.generated.LineJoin
import com.mapbox.maps.extension.style.layers.properties.generated.Visibility
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
    private var infoPointManager: PointAnnotationManager? = null
    private var isBlueDotVisible = false

    override fun dispatchTouchEvent(event: MotionEvent): Boolean {
        handleTouchOutside(event)
        return super.dispatchTouchEvent(event)
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setupActivity()

        // Inisialisasi geoJsonCacheDir di sini
        geoJsonCacheDir = File(getExternalFilesDir(null), "geojson_cache")
        if (!geoJsonCacheDir.exists()) geoJsonCacheDir.mkdirs()

        // Inisialisasi tombol Layer
        setupLayerButton()

        // Pastikan cache diperbarui
        ensureGeoJsonCacheUpdated("BatasAdministrasi")
        ensureGeoJsonCacheUpdated("BidangTanah")
        ensureGeoJsonCacheUpdated("PolaRuang")

        // Aktifkan semua layer secara otomatis
        toggleLayer(0, "BatasAdministrasi") // Aktifkan layer BatasAdministrasi
        toggleLayer(1, "BidangTanah") // Aktifkan layer BidangTanah
        toggleLayer(2, "PolaRuang") // Aktifkan layer PolaRuang

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

            setLayerVisibility(tableName, true)
            setupTransparencySlider(selectedIndex, tableName)
            activeOutlines.forEachIndexed { index, view ->
                view.visibility = if (index == selectedIndex) View.VISIBLE else View.GONE
            }
            Log.d("MapActivity", "Layer $tableName shown.")
        }

        updateBlueDotVisibility()
    }

    private fun setLayerVisibility(tableName: String, visible: Boolean) {
        val mapboxMap = binding.mapView.getMapboxMap()
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

    private fun updateBlueDotVisibility(point: Point? = null) {
        val isAnyLayerActive = layerOutlines.any { it.isSelected }

        if (isAnyLayerActive && point != null) {
            addBlueDotLayer(point)
            isBlueDotVisible = true
            Log.d("MapActivity", "Blue dot displayed at ${point.latitude()}, ${point.longitude()}.")
        } else if (!isAnyLayerActive) {
            infoPointManager?.deleteAll()
            isBlueDotVisible = false
            Log.d("MapActivity", "Blue dot hidden as no layers are active.")
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
        val mapboxMap = binding.mapView.getMapboxMap()
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
        val layersConfig = mapOf(
            "BatasAdministrasi" to Pair("#FF0000", 0.0f), // Merah transparan (hanya outline)
            "BidangTanah" to Pair("#000000", 0.5f), // Hitam dengan opasitas 50%
            "PolaRuang" to null // Tidak perlu konfigurasi outline atau transparansi
        )

        for ((tableName, config) in layersConfig) {
            val sourceId = "source-$tableName"
            val layerId = "layer-$tableName"

            if (!style.styleLayerExists(layerId)) {
                if (tableName == "PolaRuang") {
                    // Pola Ruang: Fill 100% dengan ekspresi warna
                    style.addLayer(
                        fillLayer(layerId, sourceId) {
                            fillColor(getPolaRuangColorExpression()) // Ekspresi warna untuk Pola Ruang
                            fillOpacity(0.7) // Opasitas isi
                        }
                    )
                    Log.d("MapActivity", "FillLayer $layerId added with color expression for PolaRuang.")
                } else {
                    // Batas Administrasi dan Bidang Tanah: Outline dengan isi transparan
                    style.addLayer(
                        fillLayer(layerId, sourceId) {
                            fillOutlineColor(config?.first ?: "#000000") // Warna outline
                            fillOpacity(config?.second?.toDouble() ?: 1.0) // Opasitas isi
                            fillColor(Color.TRANSPARENT) // Isi transparan
                        }
                    )
                    Log.d("MapActivity", "FillLayer $layerId added with outline color.")
                }
            } else {
                Log.d("MapActivity", "Layer $layerId already exists, skipping.")
            }

            // Pastikan klik listener ditambahkan untuk layer ini
            setupMapClickListener(tableName)
        }
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
        val mapboxMap = binding.mapView.getMapboxMap()

        try {
            val featureCollection = FeatureCollection.fromJson(geoJsonString)

            if (featureCollection.features().isNullOrEmpty()) {
                Log.e("MapActivity", "GeoJSON for $tableName has no valid features.")
                return
            }

            mapboxMap.getStyle { style ->
                val sourceId = "source-$tableName"

                if (!style.styleSourceExists(sourceId)) {
                    style.addSource(geoJsonSource(sourceId) {
                        featureCollection(featureCollection)
                    })
                    Log.d("MapActivity", "Source $sourceId added.")
                } else {
                    Log.d("MapActivity", "Source $sourceId already exists, skipping.")
                }
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

    private fun addBlueDotLayer(point: Point) {
        // Initialize the PointAnnotationManager if it hasn't been done yet
        if (infoPointManager == null) {
            infoPointManager = binding.mapView.annotations.createPointAnnotationManager()
        }

        // Clear existing annotations to update the dot position
        infoPointManager?.deleteAll()

        // Set the anchor offset for the icon
        val iconOffset = listOf(0.0, -1.0) // Center horizontally (0), move bottom vertically (-1)

        // Create a new point annotation for the blue dot
        val pointAnnotationOptions = PointAnnotationOptions()
            .withPoint(point)
            .withIconImage("blue-dot-icon") // Ensure this icon is added to the map style
            .withIconSize(1.5) // Adjust the size as needed
            .withIconAnchor(IconAnchor.BOTTOM) // Pin the anchor point to the bottom of the image
            .withIconOffset(iconOffset) // Apply the offset for fine-tuning

        // Add the point annotation to the map
        infoPointManager?.create(pointAnnotationOptions)
    }

    private fun handleMapClick(point: Point) {
        val mapboxMap = binding.mapView.getMapboxMap()
        val screenCoordinate = mapboxMap.pixelForCoordinate(point)

        val activeLayers = listOf("layer-BatasAdministrasi", "layer-BidangTanah", "layer-PolaRuang")
            .filter { layerId ->
                binding.mapView.mapboxMap.getStyle()?.styleLayerExists(layerId) == true
            }

        if (activeLayers.isEmpty()) {
            Log.w("MapActivity", "No active layers found for querying.")
            Toast.makeText(this, "Tidak ada layer aktif!", Toast.LENGTH_SHORT).show()
            return
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
                        Log.d("MapActivity", "Features found in $layerId: ${features.size}")
                    } else {
                        deferredResult.complete(emptyList())
                        Log.e("MapActivity", "Error querying features for $layerId: ${result.error}")
                    }
                }

                val features = deferredResult.await()
                if (features.isNotEmpty()) {
                    queryResults.add(layerId to features)
                }
            }

            if (queryResults.isNotEmpty()) {
                Log.d("MapActivity", "Query results: ${queryResults.size} layers with features.")
                showFeaturesInBottomSheet(queryResults)
                updateBlueDotVisibility(point)
            } else {
                Log.w("MapActivity", "No features found at clicked point.")
                Toast.makeText(this@MapActivity, "Tidak ada fitur yang ditemukan!", Toast.LENGTH_SHORT).show()
            }
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
                "NJOP BUMI" to "NJOP",
                "RANGENILAI" to "Nilai Tanah (Rp)"
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
                if (njopValue != null) {
                    val njopInMillions = (njopValue * 1_000_000).toLong()
                    "Rp${String.format("%,d", njopInMillions)}" // Format dengan ribuan
                } else {
                    "Invalid Value"
                }
            }
            "RANGENILAI" -> {
                // Format nilai dengan "Rp" dan hapus kutipan
                val formattedValue = value.removeSurrounding("\"").toDoubleOrNull()
                if (formattedValue != null) {
                    "Rp${String.format("%,.0f", formattedValue)}"
                } else {
                    "Invalid Value"
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

                // Tambahkan ikon titik biru
                val blueDotBitmap = getBitmapFromVectorDrawable(R.drawable.ic_blue_dot)
                style.addImage("blue-dot-icon", blueDotBitmap)
                Log.d("MapActivity", "Blue dot icon added successfully.")

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