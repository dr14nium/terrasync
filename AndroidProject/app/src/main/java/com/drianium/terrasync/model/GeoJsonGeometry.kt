package com.drianium.terrasync.model

data class GeoJsonGeometry(
    val type: String,
    val coordinates: List<List<List<List<Double>>>>
)

