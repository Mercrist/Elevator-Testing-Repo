#include "InitialState.h"

/**
* Contructor for the initial state, in which the elevator is called to start calling the other functions.
* @author Yariel Mercado
*/
InitialState::InitialState(Elevator* elevator){
    this->elev = elevator;
}

/**
* Function to state all the parameters in the correct values to initialize the state. 
*
* @param param1 void
* @return This void function does not return values. 
* @author Yariel Mercado
*/ 
void InitialState::start(void)
{
    elev->set_load_weight(0);
    elev->set_door_status(false);
    elev->set_light_status(true);
    elev->set_floor(1);
    elev->set_current_temp(60);
    cout << "ELEVATOR #" + to_string(elev->get_number()) + " INITIALIZED!" << endl;
}

/**
* Returns a boolean from the state's current run variable indicating wether the current state can be run in the FSM.  
*
* @param param1 void
* @return the boolean variable run. 
* @author Yariel Mercado
*/ 
bool InitialState::canRun(void){
    return run;
}

/**
*  Receives a boolean and sets the state's current run variable to either true or false denoting wether the state can be run. 
*
* @param param1 boolean variable set
* @return This void function does not return values. 
* @author Yariel Mercado
*/ 
void InitialState::setRun(bool set){
    run = set;
}
