using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Pause : MonoBehaviour {

    public Transform canvas;
    private bool pauseVisible;

    // Use this for initialization
    void Start () {
        canvas.gameObject.SetActive(false);
    }

    // Update is called once per frame
    void Update () {
        //checks if pause button is pressed
        if (Input.GetKeyDown(KeyCode.P))
        {
            if (pauseVisible)
            {
                pauseVisible = false;
                Time.timeScale = 1.0f;
                canvas.gameObject.SetActive(false);
            }
            else    //pauses game and brings up UI
            {
                pauseVisible = true;
                canvas.gameObject.SetActive(true);
                Time.timeScale = 0.0f;
            }
        }
    }
}
