package com.drianium.terrasync.model

data class GeoJsonFeature(
    val type: String,
    val geometry: GeoJsonGeometry,
    val properties: Map<String, Any>
)
