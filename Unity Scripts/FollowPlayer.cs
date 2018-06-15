using UnityEngine;
using System.Collections;

public class FollowPlayer : MonoBehaviour
{
    public GameObject player;
    public GameObject world;
    private Vector3 playerOffset;
    public Vector3 temp = new Vector3 (0,0,0);
    int rotationtracker = 0;

    // Use this for initialization
    void Start()
    {
        playerOffset = transform.position - player.transform.position;
        transform.position = player.transform.position + playerOffset;
    }

    // Update is called once per frame
    void Update()
    {

        transform.position = player.transform.position + playerOffset;
        transform.LookAt(player.transform);
        if (Input.GetKey(KeyCode.LeftArrow))
        {
            //if (rotationtracker > 0)
                //rotationtracker = 0;
                transform.RotateAround(player.transform.position, player.transform.up, -3);
                rotationtracker = rotationtracker - 3;
            
        }
        else if (Input.GetKey(KeyCode.RightArrow))
        {
            //if (rotationtracker < 0)
                //rotationtracker = 0;

                transform.RotateAround(player.transform.position, player.transform.up, 3);
                rotationtracker = rotationtracker + 3;
            
        }
        //if (Input.GetKey(KeyCode.A))
        //transform.RotateAround(player.transform.position, player.transform.up, 5);
        //transform.position = player.transform.position + playerOffset;
        playerOffset = transform.position - player.transform.position;
    }
}
