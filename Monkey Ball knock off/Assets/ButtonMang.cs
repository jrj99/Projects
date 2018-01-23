using System.Collections;

using System.Collections.Generic;

using UnityEngine;

using UnityEngine.SceneManagement;





public class ButtonMang : MonoBehaviour
{



    // Use this for initialization

    public void StartGameBtn(string monkeyball)
    {

        SceneManager.LoadScene(monkeyball);

    }



    // Update is called once per frame

    void Update()
    {



    }

}
