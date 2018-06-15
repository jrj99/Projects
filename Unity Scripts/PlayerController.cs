using UnityEngine;
using System.Collections;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class PlayerController : MonoBehaviour
{
    public Text countText;
    int count;

    private float speed = 500;
    public bool grounded = true;
    private bool powered = false;
    float timer;
    float powerUpTimeLimit = 5.0f;           //how long the speed power up lasts


    public GameObject camera;
    private Rigidbody rb;
    private Vector3 temp;


    void Start()
    {
        rb = GetComponent<Rigidbody>();
        count = 0;
        setCount();
    }
    void FixedUpdate()
    {

        if (powered == true)
            powerUpTimer();

        if (Input.GetKey("escape"))   //quits application if escape is presssed
            Application.Quit();

        float movementHorizontal;
        if (grounded == false)
            movementHorizontal = Input.GetAxis("Horizontal");
        else
            movementHorizontal = 0.0f;
        float movementVertical = Input.GetAxis("Vertical");

        Vector3 movementVector = new Vector3(movementHorizontal, 0.0f, movementVertical);
        movementVector = camera.transform.TransformDirection(movementVector);
        movementVector.x = movementVector.x * speed;
        movementVector.z = movementVector.z * speed;

        if ((rb != null))
        {
            Debug.Log(speed);
            rb.AddForce(movementVector * Time.deltaTime);

            //lets the player character jump
            if (!grounded && rb.velocity.y == 0)
            {
                grounded = true;
            }
            if (Input.GetKeyDown(KeyCode.Space) && grounded == true)
            {
                Vector3 jump = new Vector3(0.0f, 200.0f, 0.0f);
                rb.AddForce(jump);
                grounded = false;
            }
        }
        

    }
    void OnTriggerEnter(Collider other)
    {

        if (other.gameObject.CompareTag("Pick Up"))
        {
            other.gameObject.SetActive(false);
            count = count + 1;
            setCount();
        }
        if (other.gameObject.tag == "juice2")
        {

            timer = 0f;
            Debug.Log("Power up on");
            speed = 2000;
            powered = true;

        }
        if (other.gameObject.tag == "powerdown")
        {

            timer = 0f;

            speed = 200;
            powered = true;

        }
        if (other.gameObject.tag == "Enemy")
        {
            Debug.Log("destroying player");
            Destroy(GetComponent<Rigidbody>());
            int sceneBuildIndex = SceneManager.GetActiveScene().buildIndex;
            SceneManager.LoadScene((sceneBuildIndex), LoadSceneMode.Single);
        }
    }


    void OnCollisionEnter(Collision other)
    {
        if (other.gameObject.tag == "moving")
        {
            //rb.MovePosition(other.transform.position + transform.forward * Time.deltaTime); 
            transform.parent = other.transform;
            transform.localScale = new Vector3(0.35f, 0.35f, 0.35f);
        }
    }
    void OnCollisionExit(Collision other)
    {
        if (other.gameObject.tag == "moving")
        {
            transform.parent = null;
            //transform.localScale = new Vector3(0.7f, 0.7f, 0.7f);

        }

    }
    void powerUpTimer()
    {
        timer += Time.deltaTime;
        if(timer > powerUpTimeLimit)
        {
            timer = 0f;
            powered = false;
            speed = 500;
            Debug.Log("Power up Wore off");
        }
    }
    void setCount()
    {
        countText.text = "Score: " + count.ToString();
    }


}