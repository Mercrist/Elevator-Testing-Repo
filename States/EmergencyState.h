#pragma once
#include "State.h"

/**
* @file EmergencyState.h
*
* @brief This state is designed to not receive commands when the elevator parameters are not. When the elevator is fixed 
*        and the temperature and weight are between its parameters, the elevator will return to the Idle State. 
*        
* @author Yariel Mercado
*/
class EmergencyState : public State {

    /**
    * @brief Class for the emergency state. Which is in charge of not receiving any commands when the elevator is not within its parameters. 
    *  
    * @author Yariel Mercado
    */
    private:

        /* String used to identify what the current state name is. */
        string stateName = "Emergency";

        /* Boolean that determines if the state can be ran. */
        bool run = false;

        /* Pointer to call the elevator. */
        Elevator* elev;

    public:

        EmergencyState(Elevator* elevator);

        void start(void);

        bool canRun(void); 

        void setRun(bool set);

        void showWarning(void); 

        void isWorking(void); 

        void unload(int weight);

        /* String used to identify what the elevator's current state is. */
        string currentState(){return this->stateName;}

        /* Destructor for the state, eliminates its memory.  */
        ~EmergencyState(){};
};