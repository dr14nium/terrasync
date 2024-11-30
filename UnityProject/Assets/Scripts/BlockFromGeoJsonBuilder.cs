using System.Collections.Generic;
using System.Linq;
using Newtonsoft.Json;
using UnityEngine;
using GeoJSON.Net.Feature;
using GeoJSON.Net.Geometry;
using UnityEngine.Networking;

public class BlockFromGeoJsonBuilder : MonoBehaviour
{
    public string apiUrl = "http://localhost:3000/getGeoJson";
    public WorldPositionAnchor worldPositionAnchor;
    public string objectNamePrefix = "Object";

    public bool createWireframe;
    public bool createFullMesh;

    public float wireframeThickness = 0.1f;
    public Color wireframeColor = Color.black;

    public bool create2DModel;
    public bool create3DModel;

    public bool useUniformHeight;
    public float uniformHeight = 10f;
    public string heightField = "height";
    public string objectCategoryField = "category";
    public List<ObjectMaterial> objectMaterials = new List<ObjectMaterial>();

    public Material singleMaterial;
    public bool useMultipleMaterials;

    public bool useMultipleColors;
    public string colorCategoryField = "category";
    public List<ObjectColor> objectColors = new List<ObjectColor>();

    private string cachedGeoJsonData = null;
    private Dictionary<string, Queue<GameObject>> objectPools = new Dictionary<string, Queue<GameObject>>();

    void Start()
    {
        StartCoroutine(FetchGeoJsonData());
    }

    public IEnumerator<object> FetchGeoJsonData()
    {
        if (!string.IsNullOrEmpty(cachedGeoJsonData))
        {
            GenerateObjects(cachedGeoJsonData);
            yield break;
        }

        UnityWebRequest request = UnityWebRequest.Get(apiUrl);
        yield return request.SendWebRequest();

        if (request.result != UnityWebRequest.Result.Success)
        {
            Debug.LogError("Failed to fetch GeoJSON data: " + request.error);
        }
        else
        {
            cachedGeoJsonData = request.downloadHandler.text;
            GenerateObjects(cachedGeoJsonData);
        }
    }

    private void GenerateObjects(string geoJsonText)
    {
        ClearObjects();

        var geoJson = JsonConvert.DeserializeObject<FeatureCollection>(geoJsonText);
        if (geoJson == null || geoJson.Features == null)
        {
            Debug.LogError("Failed to parse GeoJSON or no features found.");
            return;
        }

        var features = geoJson.Features.ToList();
        int totalCreated = 0;

        foreach (var feature in features)
        {
            if (feature.Geometry.Type == GeoJSON.Net.GeoJSONObjectType.Polygon)
            {
                Polygon polygon = feature.Geometry as Polygon;
                CreateObject(polygon, feature, totalCreated, 0);
                totalCreated++;
            }
            else if (feature.Geometry.Type == GeoJSON.Net.GeoJSONObjectType.MultiPolygon)
            {
                MultiPolygon multiPolygon = feature.Geometry as MultiPolygon;
                for (int j = 0; j < multiPolygon.Coordinates.Count; j++)
                {
                    CreateObject(multiPolygon.Coordinates[j], feature, totalCreated, j);
                    totalCreated++;
                }
            }
        }

        Debug.Log($"{totalCreated} objects generated successfully.");
    }

    private void CreateObject(Polygon geometry, Feature feature, int featureIndex, int polygonIndex)
    {
        string objectName = $"{objectNamePrefix}_{featureIndex}_{polygonIndex}";
        GameObject obj = GetFromPool(objectName);

        if (obj == null)
        {
            obj = new GameObject(objectName);
            obj.transform.SetParent(this.transform, false);

            var blockBuilder = obj.AddComponent<BlockFromPolygonBuilder>();
            blockBuilder.Initialize(
                geometry,
                feature.Properties,
                worldPositionAnchor,
                create3DModel ? heightField : "",
                createWireframe,
                wireframeColor,
                useUniformHeight,
                uniformHeight,
                create2DModel);

            blockBuilder.wireframeThickness = this.wireframeThickness;
            blockBuilder.Draw(createFullMesh);

            if (createFullMesh)
            {
                MeshRenderer meshRenderer = obj.AddComponent<MeshRenderer>();
                if (useMultipleMaterials)
                {
                    var categoryValue = feature.Properties.ContainsKey(objectCategoryField)
                        ? feature.Properties[objectCategoryField].ToString()
                        : null;
                    var matchingMaterial = objectMaterials.FirstOrDefault(m => m.objectCategory == categoryValue)?.material;
                    meshRenderer.material = matchingMaterial ?? singleMaterial;
                }
                else
                {
                    meshRenderer.material = singleMaterial;
                }

                var meshCollider = obj.AddComponent<MeshCollider>();
                meshCollider.convex = false;
            }
        }

        obj.SetActive(true);
        Debug.Log($"Created or reused object: {objectName}");
    }

    private GameObject GetFromPool(string objectName)
    {
        if (objectPools.TryGetValue(objectName, out var pool) && pool.Count > 0)
        {
            return pool.Dequeue();
        }
        return null;
    }

    private void ReturnToPool(string objectName, GameObject obj)
    {
        if (!objectPools.ContainsKey(objectName))
        {
            objectPools[objectName] = new Queue<GameObject>();
        }

        obj.SetActive(false);
        objectPools[objectName].Enqueue(obj);
    }

    public void ClearObjects()
    {
        foreach (Transform child in transform)
        {
            ReturnToPool(child.name, child.gameObject);
        }
        Debug.Log("All generated objects cleared.");
    }
}

[System.Serializable]
public class ObjectMaterial
{
    public string objectCategory;
    public Material material;
}

[System.Serializable]
public class ObjectColor
{
    public string objectCategory;
    public Color color;
}
