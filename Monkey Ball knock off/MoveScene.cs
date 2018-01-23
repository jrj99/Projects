using UnityEngine;
using System.Collections;

public class MoveScene : MonoBehaviour
{
    public int movementspeed = 10;
    void Update()
    {
        Vector3 eulerAngles = transform.eulerAngles;
        if (Input.GetKey(KeyCode.A))
        {
            if (eulerAngles.x > 45 && eulerAngles.x <= 180)
                eulerAngles.x = 45;
            else
                transform.Rotate(Vector3.right * movementspeed * Time.deltaTime);
        }

        

        if (Input.GetKey(KeyCode.D))
        {
            if (eulerAngles.x < 315 && eulerAngles.x > 180)
                eulerAngles.x = 315;
            else
                transform.Rotate(-Vector3.right * movementspeed * Time.deltaTime);
        }

        if (Input.GetKey(KeyCode.W))
        {
            if (eulerAngles.z > 45 && eulerAngles.z <= 180)
                eulerAngles.z = 45;
            else
                transform.Rotate(Vector3.forward * movementspeed * Time.deltaTime);
        }
        if (Input.GetKey(KeyCode.S))
        {
            if (eulerAngles.z < 315 && eulerAngles.z > 180)
                eulerAngles.z = 315;
            else
                transform.Rotate(-Vector3.forward * movementspeed * Time.deltaTime);
        }
    }
}
