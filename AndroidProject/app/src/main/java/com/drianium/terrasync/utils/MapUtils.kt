package com.drianium.terrasync.utils

import android.util.Log
import android.view.MotionEvent
import android.view.View
import com.drianium.terrasync.model.GeoJsonResponse
import com.google.gson.JsonObject
import com.mapbox.geojson.Point
import com.mapbox.maps.plugin.annotation.generated.PointAnnotationOptions
import org.json.JSONArray
import org.json.JSONException
import org.json.JSONObject
import java.io.File

object MapUtils {

    // Function to check if touch is outside the view
    fun isTouchOutsideView(view: View, event: MotionEvent): Boolean {
        if (view.visibility != View.VISIBLE) return true
        val location = IntArray(2)
        view.getLocationOnScreen(location)
        val x = event.rawX.toInt()
        val y = event.rawY.toInt()
        return !(x >= location[0] && x <= location[0] + view.width &&
                y >= location[1] && y <= location[1] + view.height)
    }

    // Function to clear cache (entire directory or specific file)
    fun clearCache(cacheDir: File, cacheFileName: String? = null) {
        if (cacheFileName != null) {
            val cacheFile = File(cacheDir, cacheFileName)
            if (cacheFile.exists()) {
                cacheFile.delete()
                Log.d("MapUtils", "Cache file $cacheFileName deleted.")
            }
        } else {
            cacheDir.listFiles()?.forEach {
                it.delete()
            }
            Log.d("MapUtils", "All cache files deleted.")
        }
    }

    // Function to check cache validity based on time
    fun isCacheValid(cacheDir: File, cacheFileName: String, maxAgeMillis: Long): Boolean {
        val file = File(cacheDir, cacheFileName)
        return if (file.exists()) {
            val lastModified = file.lastModified()
            System.currentTimeMillis() - lastModified <= maxAgeMillis
        } else {
            false
        }
    }

    // Function to create PointAnnotation
    fun createPointAnnotation(lat: Double, lng: Double, iconId: String): PointAnnotationOptions {
        return PointAnnotationOptions()
            .withPoint(Point.fromLngLat(lng, lat))
            .withIconImage(iconId)
    }

    // Function to calculate bounding box from a set of points
    fun calculateBoundingBox(points: List<Point>): Pair<Point, Point> {
        val minLng = points.minOf { it.longitude() }
        val minLat = points.minOf { it.latitude() }
        val maxLng = points.maxOf { it.longitude() }
        val maxLat = points.maxOf { it.latitude() }
        return Pair(Point.fromLngLat(minLng, minLat), Point.fromLngLat(maxLng, maxLat))
    }

    // Function to format GeoJSON properties into a string
    fun formatGeoJsonProperties(properties: JsonObject): String {
        val formattedProperties = StringBuilder()
        properties.entrySet().forEach { entry ->
            formattedProperties.append("${entry.key}: ${entry.value.asString}\n")
        }
        return formattedProperties.toString()
    }

    // Function to validate GeoJSON response
    fun isValidGeoJson(geoJson: String): Boolean {
        return try {
            val jsonObject = JSONObject(geoJson)
            jsonObject.has("type") && jsonObject.has("features")
        } catch (e: JSONException) {
            Log.e("MapUtils", "Invalid GeoJSON format: ${e.message}")
            false
        }
    }

    fun writeGeoJsonToCache(cacheDir: File, fileName: String, data: String) {
        try {
            val file = File(cacheDir, fileName)
            file.writeText(data)
            Log.d("MapUtils", "GeoJSON cached at ${file.absolutePath}")
        } catch (e: Exception) {
            Log.e("MapUtils", "Failed to write GeoJSON to cache: ${e.message}")
        }
    }

    fun readGeoJsonFromCache(cacheDir: File, fileName: String): String? {
        return try {
            val file = File(cacheDir, fileName)
            if (file.exists()) {
                val data = file.readText()
                // Validate if data is a valid JSON
                if (data.trim().startsWith("{") && data.trim().endsWith("}")) {
                    data
                } else {
                    Log.e("MapUtils", "Invalid JSON format in cache: $fileName")
                    null
                }
            } else null
        } catch (e: Exception) {
            Log.e("MapUtils", "Failed to read GeoJSON from cache: ${e.message}")
            null
        }
    }

    fun clearCache(cacheDir: File) {
        cacheDir.listFiles()?.forEach { it.delete() }
        Log.d("MapUtils", "Cache cleared in directory ${cacheDir.absolutePath}")
    }
}
