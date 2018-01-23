using UnityEngine;
using System.Collections;

public class PickPear : MonoBehaviour
{
    public AudioClip PearSound;
    public GUIText bananaText;

    void OnTriggerEnter(Collider other)
    {
        AudioSource.PlayClipAtPoint(PearSound, transform.position);
        print("picked up banna\n");
        //int score = int.Parse (bananaText.text) + 1;
        //bananaText.text = score.ToString();
        Destroy(gameObject);
    }
}