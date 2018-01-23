using UnityEngine;
using System.Collections;
using UnityEngine.SceneManagement;

public class EndLevel : MonoBehaviour
{
    public AudioClip endLevel;
    public GameObject player;
    int sceneBuildIndex;

    void OnTriggerEnter(Collider other)
    {
        AudioSource.PlayClipAtPoint(endLevel, transform.position);
        Invoke("Restart", 1);
        //GameObject alert = Instantiate(complete, new Vector3(0.5f, 0.5f, 0), transform.rotation) as GameObject;

    }

    void Restart()
    {
        Destroy(player.GetComponent<Rigidbody>());
        sceneBuildIndex = SceneManager.GetActiveScene().buildIndex;
        SceneManager.LoadScene((sceneBuildIndex + 1), LoadSceneMode.Single);
    }
}
