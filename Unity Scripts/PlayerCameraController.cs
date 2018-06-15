

using UnityEngine;
using System.Collections;

public class PlayerCameraController : MonoBehaviour
{

    public GameObject player;
    private Vector3 offset;
    private float boardTiltMax = 15f; // Maximum angle to tilt the camera to fake the level tilting
    private Vector3 desiredPosition;
    private GameObject desiredPositionObject;

    private float rotationDamping = 10f;
    private float movementDamping = 150f;
    private float turnSpeed = 300f;

    private float turnAngle = 0.0f;

    // Use this for initialization
    void Start()
    {
        offset = transform.position - player.transform.position;
        desiredPosition = transform.position;
        desiredPositionObject = new GameObject("cameraFollow");
        DontDestroyOnLoad(desiredPositionObject);
        desiredPositionObject.transform.position = transform.position;

        // fine the player object
        //player = GameObject.Find("Sphere");

        if (player == null)
        {

            Debug.LogError("Could not find object \"Player\" ! Aborting GameCamera load.");
            DestroyImmediate(gameObject);
        }
    }

    void Update()
    {
        // Rotate the camera around the ball to adjust movement when A or D are pressed (left/right movement)
        turnAngle += Input.GetAxis("Horizontal") * turnSpeed * Time.deltaTime;
    }

    void LateUpdate()
    {
        // find the ZX direction from the player to the camera
        var heading = transform.position - player.transform.position;
        heading.y = 0f;
        var distance = heading.magnitude;
        var direction = heading / distance;

        // Find the right vector for the diretion
        var rotationVectorRight = Vector3.Cross(direction, Vector3.up);

        // Move the camera
        desiredPositionObject.transform.position = player.transform.position + offset;

        // Rotate around the players Y axis by the turn value
        desiredPositionObject.transform.RotateAround(player.transform.position, Vector3.up, turnAngle);

        // Deal with forward/backward board rotation
        //desiredPositionObject.transform.RotateAround(player.transform.position, rotationVectorRight, -Input.GetAxisRaw("Vertical") * boardTiltMax);

        // Ensure we're looking at the player before the roll rotation is applied
        desiredPositionObject.transform.LookAt(player.transform.position);

        // Apply the roll rotation
        desiredPositionObject.transform.RotateAround(desiredPositionObject.transform.position, direction, -Input.GetAxisRaw("Horizontal") * boardTiltMax);

        // Lerp the cameras position to match the target object
        transform.position = Vector3.Slerp(transform.position, desiredPositionObject.transform.position, Time.deltaTime * movementDamping);

        // Lerp the cameras rotation to match the target object
        transform.rotation = Quaternion.Lerp(transform.rotation,
                                              desiredPositionObject.transform.rotation,
                                              Time.deltaTime * rotationDamping);

        // Re-center the camera on the object to account for new roll rotation
        CenterCameraOnTarget();

    }

    private void CenterCameraOnTarget()
    {
        Plane plane = new Plane(transform.forward, player.transform.position);
        Ray ray = GetComponent<Camera>().ScreenPointToRay(new Vector3(Screen.width / 2, Screen.height / 2, 0.0f));
        float distance;
        plane.Raycast(ray, out distance);

        var point = ray.GetPoint(distance);
        var offset = player.transform.position - point;
        transform.position += offset;
    }
}
