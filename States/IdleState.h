#pragma once
#include "State.h"

/**
* @file   IdleState.h
*
* @brief  This is the elevator's default state. When the elevator is in this state, it is ready to go to the moving 
*         state in any moment. 
*
* @author Yariel Mercado
*/
class IdleState : public State{

    /**
    *
    * @brief  Class for the elevator's idle state; in charge of opening doors and turning lights on to receive or let off people.
    * 
    * @author Yariel Mercado
    */
    private:

        /* String used to identify what the current state name is. */
        string stateName = "Idle";

        /* Boolean that determines if the state can be ran. */
        bool run = true;

        /* Pointer to call the elevator. */
        Elevator* elev;

    public:

        IdleState(Elevator* elevator);

        void start(void);

        bool canRun(void); 

        void setRun(bool set);
       
        void load(int weight);

        void unload(int weight);

        void energySaving();

        /* Used to identify what the elevator's current state is. */
        string currentState(){return this->stateName;}

        /* Destructor for the state, eliminates its memory. */
        ~IdleState(){};

};