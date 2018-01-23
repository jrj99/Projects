

using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;

public class Enemy : MonoBehaviour {

    private float speed = 500;
    public GameObject Player;       //put player here
    public Transform target;
    private Rigidbody rb;
    private Vector3 playerDirection;
    private UnityEngine.AI.NavMeshAgent navComponent;
    private bool inrange = true;


    // Use this for initialization
    void Start () {
        rb = GetComponent<Rigidbody>();
        InvokeRepeating("UpdateTarget",0f,0.1f);
        navComponent = GetComponent<UnityEngine.AI.NavMeshAgent>();
    }

    
    void UpdateTarget()
    {
        target = GameObject.FindGameObjectWithTag("Player").transform;
    }
    
    // Update is called once per frame

    void Update () {
        //faces enemy towards player
        if( inrange == true)
        {
            navComponent.SetDestination(target.position);
        }
        
    }
}

