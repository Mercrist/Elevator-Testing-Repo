#pragma once
#include "State.h"

/**
* @file  InitialState.h
*
* @brief This state is in charge of preparing everything for the Elevator to start functioning.
*
* @author Yariel Mercado
*/
class InitialState : public State {

    /**
    * @brief This class sets the door closed, turns on the light, and the weight and temperature are set with 
    *        beginning values to get the elevator to start working. 
    * 
    * @author Yariel Mercado
    */
    private:

        /* String used to identify what the current state name is. */
        string stateName = "Initial";

        /* Boolean that determines if the state can be ran. */
        bool run = true;

        /* Pointer to call the elevator. */
        Elevator* elev;

    public:

        InitialState(Elevator* elevator);

        void start(void);

        bool canRun(void); 

        void setRun(bool set);

        /* String used to identify what the elevator's current state is. */
        string currentState(){return this->stateName;}

        /* Destructor for the state, eliminates its memory. */
        ~InitialState(){};
};