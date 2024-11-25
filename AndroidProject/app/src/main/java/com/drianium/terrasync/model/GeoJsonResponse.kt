package com.drianium.terrasync.model

data class GeoJsonResponse(
    val type: String,
    val features: List<GeoJsonFeature>
)
