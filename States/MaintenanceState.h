#pragma once
#include "State.h"

/**
* @file  MaintenanceState.h
*
* @brief This state will be called when received the request from the elevator's interface; in which the elevator will be prepared 
*        to not receive any kind of commands when the maintenance request is called.  
*        
* @author Yariel Mercado
*/
class MaintenanceState : public State{

    /**
    * @brief Class for the elevator's maintenance state. Which in in charge of not receiving any commands when the option in the 
    *        elevator's interface is chosen; when called the doors are going to get open and the ligts will be turned on.
    * 
    * @author Yariel Mercado
    */
    private:

        /* String used to identify what the current state name is. */
        string stateName = "Maintenance";

        /* Boolean that determines if the state can be ran. */
        bool run = false;

        /* String used to determine the placeholder to get the state initialized. */
        string command = "M"; 

        /* Pointer to call the elevator. */
        Elevator* elev;
    
    public: 

        MaintenanceState(Elevator* elevator);

        void start(void);

        bool canRun(void); 

        void setRun(bool set);
        
        void showWarning(void); 

        void isWorking(void); 
        
        void check(string input); 

        /* String used to identify what the elevato's current state is. */
        string currentState(){return this->stateName;}

        /* Destructor for the state, eliminates its memory. */
        ~MaintenanceState(){};
        
};