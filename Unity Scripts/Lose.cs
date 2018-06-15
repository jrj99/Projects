using UnityEngine;
using System.Collections;
using UnityEngine.SceneManagement;

public class Lose : MonoBehaviour
{
    public AudioClip LoseLevel;
    void OnCollisionEnter()
    {
        AudioSource.PlayClipAtPoint(LoseLevel, transform.position);
        //audio.Play();
        Invoke("Reload", 1.0f);

    }

    void Reload()
    {
        SceneManager.LoadScene(SceneManager.GetActiveScene().buildIndex);
        //Application.LoadLevel(Application.loadedLevel);
    }
}
