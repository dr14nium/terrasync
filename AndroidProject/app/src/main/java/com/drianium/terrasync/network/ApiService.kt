package com.drianium.terrasync.network

import com.drianium.terrasync.model.GeoJsonFeature
import com.drianium.terrasync.model.GeoJsonResponse
import com.drianium.terrasync.model.SearchResult
import retrofit2.Response
import retrofit2.Retrofit
import retrofit2.converter.gson.GsonConverterFactory
import retrofit2.http.GET
import retrofit2.http.Path
import retrofit2.http.Query

interface ApiService {
    @GET("search")
    suspend fun searchPostgresPlace(@Query("query") query: String): Response<List<SearchResult>>

    // Endpoint to fetch all features as GeoJsonResponse
    @GET("geojson/{tableName}")
    suspend fun getAllFeatures(@Path("tableName") tableName: String): Response<GeoJsonResponse>

    // Endpoint to fetch a feature by ID
    @GET("geojson/{tableName}/{id}")
    suspend fun getFeatureById(
        @Path("tableName") tableName: String,
        @Path("id") id: String
    ): Response<GeoJsonFeature>

    companion object {
        private const val BASE_URL = "https://terrasync-server-458189808803.asia-southeast2.run.app/"

        fun create(): ApiService {
            return Retrofit.Builder()
                .baseUrl(BASE_URL)
                .addConverterFactory(GsonConverterFactory.create())
                .build()
                .create(ApiService::class.java)
        }
    }
}
