package com.drianium.terrasync.model

data class SearchResult(
    val id: Int,
    val geometry: String,
    val centroid: String,
    val type: String,
    val name: String,
    val nib: String,
    val tipehak: String
)
