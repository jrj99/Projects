using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PickJuice : MonoBehaviour {
    public AudioClip JuiceSound;


    void OnTriggerEnter(Collider other)
    {
        AudioSource.PlayClipAtPoint(JuiceSound, transform.position);
        //print("picked up banna\n");
        //int score = int.Parse (bananaText.text) + 1;
        //bananaText.text = score.ToString();
        Destroy(gameObject);
    }
}
