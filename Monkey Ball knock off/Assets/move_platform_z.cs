using UnityEngine;
using System.Collections;

public class move_platform_z : MonoBehaviour
{
    private Vector3 pos1;
    private Vector3 pos2;
    public float speed;
    public GameObject player;


    void Start()
    {
        pos1 = new Vector3(transform.position.x, transform.position.y, transform.position.z);
        pos2 = new Vector3(transform.position.x, transform.position.y, transform.position.z - 4);
        speed = 0.5f;
    }

    void Update()
    {
        //transform.position = new Vector3(transform.position.x, transform.position.y, Mathf.PingPong(Time.time, 3));
        transform.position = Vector3.Lerp(pos1, pos2, Mathf.PingPong(Time.time * speed, 1.0f));
    }

}