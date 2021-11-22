#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include "time.h"
#include "Elevator/Elevator.h"
using namespace std;

/**
* @file State.h
*
* @brief This file serves as an interface for the elevator states. 
*
* @author Yariel Mercado
*/
class State{

    /**
    *
    * @brief  duda
    * @author Yariel Mercado
    */
    public:
        /* String used to identify what the current state is. */
        virtual string currentState(void) = 0; 

        /* Boolean used to identify if a state can be ran. */
        virtual bool canRun(void) = 0; 

        /* Boolean used to duda. */
        virtual void setRun(bool set) = 0;  

        /* Boolean which lets each state initialize. */
        virtual void start() =  0; 

        /* Abstract distructor that must be inherited by the states in order to implement a distructor in each of them.  */
        virtual ~State() = 0;
};
