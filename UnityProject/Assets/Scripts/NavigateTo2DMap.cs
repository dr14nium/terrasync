using UnityEngine;

public class NavigateTo2DMap : MonoBehaviour
{
    public void Open2DMapActivity()
    {
        AndroidJavaClass unityPlayer = new AndroidJavaClass("com.unity3d.player.UnityPlayer");
        AndroidJavaObject currentActivity = unityPlayer.GetStatic<AndroidJavaObject>("currentActivity");

        AndroidJavaObject intent = new AndroidJavaObject("android.content.Intent", currentActivity, new AndroidJavaClass("com.geoclarity.ar"));
        
        currentActivity.Call("startActivity", intent);
    }
}