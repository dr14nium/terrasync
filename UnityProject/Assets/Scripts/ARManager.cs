using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.XR.ARFoundation;
using Google.XR.ARCoreExtensions;
using UnityEngine.XR.ARSubsystems;
using UnityEngine.UI;

#if UNITY_ANDROID
using UnityEngine.Android; // Tambahkan ini untuk menggunakan Permission API Android
#endif

public class ARManager : MonoBehaviour
{
    public static ARManager Instance;

    [Header("AR Components")]
    public ARSessionOrigin SessionOrigin;
    public ARSession Session;
    public ARCoreExtensions ARCoreExtensions;
    public AREarthManager EarthManager;
    public ARAnchorManager AnchorManager;
    public ARRaycastManager RaycastManager;
    public ARPlaneManager PlaneManager;

    [Header("UI Elements")]
    public Text PositionText;

    [Header("Origin Settings")]
    public GameObject origin; // Menggunakan WorldPositionAnchor
    
    private WorldPositionAnchor _worldPositionAnchor;
    private double Latitude;
    private double Longitude;

    [Header("Popups")]
    public GameObject GPSDisabledPopup;
    public Button ActivateGPSButton;
    public Button ExitAppButton;

    public GameObject VPSNotAvailablePopup;
    public Button ContinueWithoutVPSButton;

    public ARGeospatialAnchor _currentAnchor = null;
    private GameObject _currentActiveObject = null;
    private bool _isARInitialized = false;
    private bool _isPositionUpdatedShown = false;
    private bool _isPlaneDetectedShown = false;
    private bool _gpsActive = false;
    private bool _vpsChecked = false;

    public GameObject CurrentActiveObject
    {
        get { return _currentActiveObject; }
        set
        {
            ToggleActiveObject(_currentActiveObject, false);
            _currentActiveObject = value;
            ToggleActiveObject(_currentActiveObject, true);
        }
    }

    private void ToggleActiveObject(GameObject obj, bool isActive)
    {
        if (obj != null)
        {
            obj.SetActive(isActive);
        }
    }

    private void Awake()
    {
        SetupSingleton();
        ValidateComponents();
        InitializeWorldPositionAnchor();
        SetupUI();
    }

    private void SetupSingleton()
    {
        if (Instance == null)
        {
            Instance = this;
        }
        else
        {
            Destroy(gameObject);
        }
    }

    private void ValidateComponents()
    {
        var components = new Dictionary<string, Object>
        {
            { "ARSessionOrigin", SessionOrigin },
            { "ARSession", Session },
            { "ARCoreExtensions", ARCoreExtensions },
            { "AREarthManager", EarthManager },
            { "ARAnchorManager", AnchorManager },
            { "ARPlaneManager", PlaneManager },
            { "PositionText", PositionText }
        };

        foreach (var component in components)
        {
            if (component.Value == null)
            {
                ShowSnackBar($"{component.Key} not found.", true);
            }
        }
    }

    private void ShowSnackBar(string message, bool important = false)
    {
        if (SnackBarManager.Instance != null)
        {
            SnackBarManager.Instance.ShowSnackBar(message, important);
        }
        else
        {
            Debug.LogWarning("SnackBarManager is not available.");
        }
    }

    private void InitializeWorldPositionAnchor()
    {
        if (origin != null)
        {
            _worldPositionAnchor = origin.GetComponent<WorldPositionAnchor>();
            if (_worldPositionAnchor != null)
            {
                Latitude = _worldPositionAnchor.referenceLat;
                Longitude = _worldPositionAnchor.referenceLon;
            }
            else
            {
                Debug.LogError("Origin does not contain WorldPositionAnchor component.");
            }
        }
        else
        {
            Debug.LogError("Origin GameObject is not assigned.");
        }
    }

    private void SetupUI()
    {
        ActivateGPSButton.onClick.AddListener(ActivateGPS);
        ExitAppButton.onClick.AddListener(ExitApplication);
        ContinueWithoutVPSButton.onClick.AddListener(ContinueWithoutVPS);
        PositionText.gameObject.SetActive(false); // Hide PositionText at start
    }

    private void OnEnable()
    {
        PlaneManager.planesChanged += OnPlanesChanged;
        StartCoroutine(CheckAndStartLocationService());
    }

    private void OnDisable()
    {
        Input.location.Stop();
        PlaneManager.planesChanged -= OnPlanesChanged;
    }

    private IEnumerator CheckAndStartLocationService()
    {
#if UNITY_ANDROID
        if (!Permission.HasUserAuthorizedPermission(Permission.FineLocation))
        {
            Permission.RequestUserPermission(Permission.FineLocation);
            yield return new WaitForSeconds(1);
        }

        if (!Input.location.isEnabledByUser)
        {
            ShowPopup(GPSDisabledPopup, true);
            DisableAR();
            yield break;
        }
#endif
        Input.location.Start();
        while (Input.location.status == LocationServiceStatus.Initializing)
        {
            yield return null;
        }

        if (Input.location.status == LocationServiceStatus.Running)
        {
            _gpsActive = true;
            ShowPopup(GPSDisabledPopup, false);
            ShowSnackBar("Location Service is running.", true);
            InitializeAR();
        }
        else
        {
            ShowSnackBar("Failed to start Location Service.", true);
        }
    }

    private void ShowPopup(GameObject popup, bool show)
    {
        if (popup != null)
        {
            popup.SetActive(show);
        }
    }

    private void InitializeAR()
    {
        if (_gpsActive && !_isARInitialized)
        {
            _isARInitialized = true;
            Session.enabled = true;
            PlaneManager.enabled = true;
            RaycastManager.enabled = true;
            ShowSnackBar("AR Session initialized.", true);
            StartCoroutine(CheckVPSAvailabilityWithDelay());
        }
    }

    private IEnumerator CheckVPSAvailabilityWithDelay()
    {
        yield return new WaitForSeconds(Random.Range(15f, 30f));

        if (EarthManager.EarthTrackingState != TrackingState.Tracking)
        {
            ShowPopup(VPSNotAvailablePopup, true);
            _vpsChecked = true;
        }
    }

    private void DisableAR()
    {
        Session.enabled = false;
        PlaneManager.enabled = false;
        _isARInitialized = false;
    }

    private void Update()
    {
        if (_gpsActive && _isARInitialized)
        {
            if (_vpsChecked && EarthManager.EarthTrackingState != TrackingState.Tracking)
            {
                ShowPopup(VPSNotAvailablePopup, true);
            }

            UpdatePositionText();

            if (EarthManager.EarthTrackingState == TrackingState.Tracking && _currentAnchor == null)
            {
                CreateGeospatialAnchor(Latitude, Longitude);
            }
        }
    }

    private void UpdatePositionText()
    {
        if (ARSession.state != ARSessionState.SessionTracking)
        {
            PositionText.text = "AR session is not tracking.";
            return;
        }

        if (EarthManager.EarthTrackingState != TrackingState.Tracking)
        {
            PositionText.text = "Earth tracking is not available.";
            return;
        }

        var pose = EarthManager.CameraGeospatialPose;
        string positionText = string.Format(
            "Latitude/Longitude: {0}, {1}\n" +
            "Horizontal Accuracy: {2}m\n" +
            "Altitude: {3}m\n" +
            "Vertical Accuracy: {4}m\n" +
            "Orientation Yaw Accuracy: {5}°",
            pose.Latitude.ToString("F6"),
            pose.Longitude.ToString("F6"),
            pose.HorizontalAccuracy.ToString("F6"),
            pose.Altitude.ToString("F2"),
            pose.VerticalAccuracy.ToString("F2"),
            pose.OrientationYawAccuracy.ToString("F1"));

        PositionText.text = positionText;

        if (!_isPositionUpdatedShown)
        {
            PositionText.gameObject.SetActive(true);
            ShowSnackBar("Position updated.", true);
            _isPositionUpdatedShown = true;
        }
    }

    private void OnPlanesChanged(ARPlanesChangedEventArgs args)
    {
        if (!_isPlaneDetectedShown && args.added.Count > 0)
        {
            ShowSnackBar("Plane detected.", true);
            _isPlaneDetectedShown = true;

            Vector3 hitPosition = GetRaycastHitPositionOnPlane();

            if (hitPosition != Vector3.zero)
            {
                Vector3 updatedPosition = UpdateHorizontalPositionWithLatLong(hitPosition);
                InstantiateObjectAtPosition(updatedPosition);
            }
        }
    }

    private Vector3 GetRaycastHitPositionOnPlane()
    {
        List<ARRaycastHit> hits = new List<ARRaycastHit>();
        Ray ray = new Ray(Camera.main.transform.position, Camera.main.transform.forward);

        if (RaycastManager.Raycast(ray, hits, TrackableType.PlaneWithinBounds))
        {
            return hits[0].pose.position;
        }

        return Vector3.zero;
    }

    private Vector3 UpdateHorizontalPositionWithLatLong(Vector3 planeHitPosition)
    {
        Vector2d worldPosition = _worldPositionAnchor.LatLonToWorldPosition(Latitude, Longitude);

        return new Vector3((float)worldPosition.x, planeHitPosition.y, (float)worldPosition.y);
    }

    private void InstantiateObjectAtPosition(Vector3 position)
    {
        if (_currentActiveObject != null)
        {
            Destroy(_currentActiveObject);
        }

        // Mengambil prefab yang aktif dari LayerManager
        GameObject objectPrefab = LayerManager.Instance.CurrentActiveObject;

        if (objectPrefab != null)
        {
            GameObject newObject = Instantiate(objectPrefab, position, Quaternion.identity);
            _currentActiveObject = newObject;
        }
        else
        {
            Debug.LogError("No active prefab in LayerManager to instantiate.");
        }
    }

    private void CreateGeospatialAnchor(double latitude, double longitude)
    {
        var earthState = EarthManager.EarthState;
        if (earthState != EarthState.Enabled)
        {
            ShowSnackBar("Earth state is not enabled.", true);
            Debug.LogError("Earth state is not enabled.");
            return;
        }

        ResolveAnchorOnTerrainPromise promise = AnchorManager.ResolveAnchorOnTerrainAsync(latitude, longitude, 0, Quaternion.identity);
        StartCoroutine(CheckTerrainPromise(promise));
    }

    private IEnumerator CheckTerrainPromise(ResolveAnchorOnTerrainPromise promise)
    {
        yield return new WaitUntil(() => promise.State != PromiseState.Pending);

        if (promise.State == PromiseState.Done)
        {
            var result = promise.Result;
            if (result.TerrainAnchorState == TerrainAnchorState.Success)
            {
                _currentAnchor = result.Anchor;
                if (_currentAnchor != null)
                {
                    LayerManager.Instance.InstantiateDefaultObject();
                    ShowSnackBar("Anchor created and default object instantiated.", true);
                }
            }
            else
            {
                ShowSnackBar("Failed to create terrain anchor.", true);
            }
        }
    }

    private void ActivateGPS()
    {
#if UNITY_ANDROID
        using (AndroidJavaClass unityPlayer = new AndroidJavaClass("com.unity3d.player.UnityPlayer"))
        {
            AndroidJavaObject currentActivity = unityPlayer.GetStatic<AndroidJavaObject>("currentActivity");
            AndroidJavaObject intent = new AndroidJavaObject("android.content.Intent", "android.settings.LOCATION_SOURCE_SETTINGS");
            currentActivity.Call("startActivity", intent);
        }
#endif
        ShowPopup(GPSDisabledPopup, false);
        StartCoroutine(CheckAndStartLocationService());
    }

    private void ExitApplication()
    {
        Application.Quit();
    }

    private void ContinueWithoutVPS()
    {
        ShowPopup(VPSNotAvailablePopup, false);
    }
}