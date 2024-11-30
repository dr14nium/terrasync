using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using TMPro;

[System.Serializable]
public class KeyInfo
{
    public string displayText;  // Text to display before the key's value
    public string key;          // Key from the feature info to display
}

public class ObjectInfoManager : MonoBehaviour
{
    public static ObjectInfoManager Instance;

    [Header("UI Elements")]
    public GameObject ObjectInformationPanel;  // Panel yang menampung semua informasi objek
    public Transform ContentParent;            // Tempat RowPrefab menjadi child
    public GameObject RowPrefab;               // Prefab baris yang berisi 3 teks (Label, :, Value)
    public Button CloseButton;

    private int currentObjectID;               // ID dari object yang aktif

    private void Awake()
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

    private void OnEnable()
    {
        CloseButton.onClick.AddListener(HideObjectInformation);
    }

    private void OnDisable()
    {
        CloseButton.onClick.RemoveListener(HideObjectInformation);
    }

    // Fungsi untuk menampilkan informasi objek berdasarkan KeyInfo yang sesuai dengan prefab yang aktif
    public void ShowObjectInformation(FeatureAttributes featureAttributes)
    {
        if (MeasurementManager.Instance != null && MeasurementManager.Instance.IsMeasuring())
        {
            Debug.Log("[OBJECT_INFO_MANAGER] Measurement mode is active, skipping object information display.");
            return;  // Jangan tampilkan Object Information jika Measurement Mode aktif
        }

        if (ObjectInformationPanel != null && ContentParent != null && RowPrefab != null)
        {
            // Bersihkan informasi sebelumnya
            foreach (Transform child in ContentParent)
            {
                Destroy(child.gameObject);
            }

            // Dapatkan KeyInfo dari LayerManager berdasarkan prefab yang aktif
            List<KeyInfo> currentInfoKeys = GetCurrentPrefabKeyInfo();

            if (currentInfoKeys == null || currentInfoKeys.Count == 0)
            {
                Debug.LogWarning("No keys available for display in UI.");
                return;
            }

            // Menampilkan informasi baru dari KeyInfo
            foreach (var keyInfo in currentInfoKeys)
            {
                GameObject rowInstance = Instantiate(RowPrefab, ContentParent); // Instansiasi rowPrefab

                TextMeshProUGUI[] texts = rowInstance.GetComponentsInChildren<TextMeshProUGUI>(); // Ambil semua komponen TextMeshProUGUI dari prefab

                if (texts.Length == 3)
                {
                    TextMeshProUGUI labelText = texts[0];  // LabelText di prefab
                    TextMeshProUGUI colonText = texts[1];  // ColonText di prefab
                    TextMeshProUGUI valueText = texts[2];  // ValueText di prefab

                    labelText.text = keyInfo.displayText;    // Label (display text)
                    colonText.text = ":";                    // Colon ":"
                    valueText.text = featureAttributes.GetAttributeValue(keyInfo.key); // ValueText dari Key
                }
            }

            // Simpan ID dari object yang aktif
            currentObjectID = int.Parse(featureAttributes.GetAttributeValue("id")); // Asumsikan id disimpan di featureAttributes

            // Aktifkan panel informasi objek
            ObjectInformationPanel.SetActive(true);
        }
    }

    // Mendapatkan KeyInfo dari LayerManager berdasarkan object aktif di ARManager
    private List<KeyInfo> GetCurrentPrefabKeyInfo()
    {
        GameObject currentActiveObject = ARManager.Instance.CurrentActiveObject;

        if (currentActiveObject == null)
        {
            Debug.LogWarning("No active object found in ARManager.");
            return null;
        }

        // Ambil KeyInfo yang terkait dengan prefab aktif
        string prefabName = currentActiveObject.name;
        return LayerManager.Instance.GetKeyInfoForPrefab(prefabName);
    }

    // Menyembunyikan panel informasi objek
    public void HideObjectInformation()
    {
        if (ObjectInformationPanel != null)
        {
            ObjectInformationPanel.SetActive(false);
        }
    }
}