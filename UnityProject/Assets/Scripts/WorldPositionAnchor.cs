using System;
using UnityEngine;

public class WorldPositionAnchor : MonoBehaviour
{
    [Tooltip("Reference Latitude for the coordinate system origin.")]
    public double referenceLat = -7.786170591154554;

    [Tooltip("Reference Longitude for the coordinate system origin.")]
    public double referenceLon = 110.41113960021086;

    // Constants for WGS84 ellipsoid model
    private const double WGS84_a = 6378137.0;  // Semi-major axis
    private const double WGS84_f = 1 / 298.257223563;  // Flattening
    private const double WGS84_b = WGS84_a * (1 - WGS84_f);  // Semi-minor axis

    public Vector2d Coordinates
    {
        get
        {
            return WorldPositionToLatLon(new Vector2d(transform.position.x, transform.position.z));
        }
        set
        {
            var worldPosition = LatLonToWorldPosition(value.x, value.y);
            transform.position = new Vector3((float)worldPosition.x, transform.position.y, (float)worldPosition.y);
        }
    }

    // Convert Lat/Lon to World Position using WGS84 ellipsoid model
    public Vector2d LatLonToWorldPosition(double lat, double lon)
    {
        // Convert lat/lon to radians
        double latRad = lat * Math.PI / 180;
        double lonRad = lon * Math.PI / 180;
        double refLatRad = referenceLat * Math.PI / 180;
        double refLonRad = referenceLon * Math.PI / 180;

        // Compute radii of curvature
        double N = WGS84_a / Math.Sqrt(1 - (2 * WGS84_f - Math.Pow(WGS84_f, 2)) * Math.Sin(refLatRad) * Math.Sin(refLatRad));

        // Compute offsets in meters
        double latOffset = (latRad - refLatRad) * N;
        double lonOffset = (lonRad - refLonRad) * N * Math.Cos(refLatRad);

        return new Vector2d(lonOffset, latOffset);
    }

    // Convert World Position to Lat/Lon using WGS84 ellipsoid model
    public Vector2d WorldPositionToLatLon(Vector2d position)
    {
        double refLatRad = referenceLat * Math.PI / 180;
        double N = WGS84_a / Math.Sqrt(1 - (2 * WGS84_f - Math.Pow(WGS84_f, 2)) * Math.Sin(refLatRad) * Math.Sin(refLatRad));

        // Convert world offsets back to lat/lon
        double latOffset = position.y / N;
        double lonOffset = position.x / (N * Math.Cos(refLatRad));

        // Convert radians to degrees
        double lat = referenceLat + latOffset * (180 / Math.PI);
        double lon = referenceLon + lonOffset * (180 / Math.PI);

        return new Vector2d(lat, lon);
    }

    void OnDrawGizmos()
    {
        Gizmos.color = Color.white;
        Gizmos.DrawSphere(transform.position, 1);
        Gizmos.DrawIcon(transform.position, "BuildSettings.Web", true);
    }
}

// Custom struct to handle 2D vector with double precision
public struct Vector2d
{
    public double x;
    public double y;

    public Vector2d(double x, double y)
    {
        this.x = x;
        this.y = y;
    }

    public static Vector2d operator +(Vector2d a, Vector2d b)
    {
        return new Vector2d(a.x + b.x, a.y + b.y);
    }

    public static Vector2d operator -(Vector2d a, Vector2d b)
    {
        return new Vector2d(a.x - b.x, a.y - b.y);
    }
}