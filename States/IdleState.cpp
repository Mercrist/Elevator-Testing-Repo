#include "IdleState.h"

//MISSING MOVING STATE FUNCTIONALITIES

/**
* Contructor for the idle state, in which the elevator is called to start calling the other functions.
* @author Yariel Mercado
*/
IdleState::IdleState(Elevator* elevator){
    this->elev = elevator;
}

/**
* Function to state all the parameters in the correct values to initialize the state. 
*
* @param param1 void
* @return This void function does not return values. 
* @author Yariel Mercado
*/ 
void IdleState::start(void){
    elev->set_door_status(true);
    elev->set_light_status(true);
    cout << "ELEVATOR #" + to_string(elev->get_number()) + " ENTERING IDLE STATE!" << endl;

}

/**
* Function that receives a specific weight and adds it to the elevator's current one. 
*
* @param param1 integer value weight 
* @return This void function does not return values. 
* @author Yariel Mercado
*/ 
void IdleState::load(int weight){
    if(elev->is_door_open() && elev->is_light_on()){
        cout << "ELEVATOR #" + to_string(elev->get_number()) + " LOADING PEOPLE ON THE ELEVATOR!" << endl;
        int toAdd = elev->get_load_weight() + weight;
        elev->set_load_weight(toAdd);
    }
    else{
        cout << "ELEVATOR #" + to_string(elev->get_number()) + " IS CLOSED OR INACTIVE!" << endl;
    }
}

/**
* Function that receives a weight as input and substracts it from the current one. 
*
* @param param1 integer value weight
* @return This void function does not return values. 
* @author Yariel Mercado
*/ 
void IdleState::unload(int weight){
    if(weight > elev->get_max_load_weight()){
        cout << "CAN'T UNLOAD MORE WEIGHT THAN IS CURRENTLY PRESENT!" << endl;
        return;
    }

    if(elev->is_door_open() && elev->is_light_on()){
        cout << "ELEVATOR #" + to_string(elev->get_number()) + " UNLOADING PEOPLE OFF THE ELEVATOR!" << endl;
        int toUnload = elev->get_load_weight() - weight;
        elev->set_load_weight(toUnload);
    }

    else{
        cout << "ELEVATOR #" + to_string(elev->get_number()) + " IS CLOSED OR INACTIVE!" << endl;
    }
    
}

/**
* If the elevator has not received inputs from the user, the lights will turn off and the door will be closed to save energy. 
*
* @param param1 void
* @return This void function does not return values. 
* @author Yariel Mercado
*/ 
void IdleState::energySaving(void){
    cout << "ELEVATOR " + to_string(elev->get_number()) + " HAS BEEN UNUSED FOR 30 SECONDS, ENTERING ENERGY SAVING MODE!" << endl;
    elev->set_door_status(false);
    if(elev->get_capacity() == 0){
        elev->set_light_status(false);
    }
}

/**
* Returns a boolean from the state's current run variable indicating wether the current state can be run in the FSM. 
*
* @param param1 void
* @return a boolean variable run. 
* @author Yariel Mercado
*/ 
bool IdleState::canRun(void){
    return run;
}

/**
* Receives a boolean and sets the state's current run variable to either true or false denoting wether the state can be run. 
*
* @param param1 boolean variable set
* @return This void function does not return values. 
* @author Yariel Mercado
*/ 
void IdleState::setRun(bool set){
    run = set;
}


