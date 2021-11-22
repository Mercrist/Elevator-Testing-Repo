#include "EmergencyState.h"

/**
* Contructor for the emergency state, in which the elevator is called to start calling the other functions.
* @author Yariel Mercado
*/
EmergencyState::EmergencyState(Elevator* elevator){
    this->elev = elevator;
}

/**
* Function to state all the parameters in the correct values to initialize the state. 
*
* @param param1 void
* @return This void function does not return values. 
* @author Yariel Mercado
*/ 
void EmergencyState::start(void){
    elev->set_door_status(true);
    elev->set_light_status(true);
    cout << "ENTERING EMERGENCY STATE! NO COMMANDS WILL BE PROCESSED UNTIL ELEVATOR #" + to_string(elev->get_number()) + " STABILIZES!" << endl;
    showWarning();
}

/**
* Function that receives a weight as input and substracts it from the current one.
*
* @param param1 integer value weight
* @return This void function does not return values. 
* @author Yariel Mercado
*/ 
void EmergencyState::unload(int weight){
    int toUnload = elev->get_load_weight() - weight;
    elev->set_load_weight(toUnload);
}

/**
* Show a warning that the elevator is entering to the emergency state becuase of its parameters. 
*
* @param param1 void
* @return This void function does not return values. 
* @author Yariel Mercado
*/ 
void EmergencyState::showWarning(void){
    cout << "PARAMETERS MUST GO BACK TO THE MAXIMUM ALLOWED VALUES!" << endl;
    cout << "" << endl;
    cout << "PARAMETER DIFFERENCES:" << endl;
    cout << "----------------------" << endl;

    if(elev->get_current_temp() > elev->get_max_temp()){
        cout << "TEMP IS " + to_string(elev->get_current_temp()) + " DEGREES F! MUST LOWER BY: " + to_string(elev->get_current_temp()-elev->get_max_temp()) + " DEGREES F!" << endl;
    }

    else if(elev->get_current_temp() <= elev->get_max_temp()){
        cout << "TEMP IS NORMAL!" << endl;
    }

    if(elev->get_load_weight() > elev->get_max_load_weight()){
        cout << "CURRENT CAPACITY IS " + to_string(elev->get_load_weight()) + " POUNDS! MUST LOWER BY: " + to_string(elev->get_load_weight()-elev->get_max_load_weight()) + " POUNDS!" << endl;
    }

    else if(elev->get_load_weight() <= elev->get_max_load_weight()){
        cout << "CAPACITY IS NORMAL!" << endl;
    }
    
}

/**
* When the parameters are fixed a warning that they have been stabilized is printed. 
*
* @param param1 void
* @return This void function does not return values. 
* @author Yariel Mercado
*/ 
void EmergencyState::isWorking(void){
    if(elev->get_current_temp() <= elev->get_max_temp() && elev->get_load_weight() <= elev->get_max_load_weight()) 
    {
        cout << "ELEVATOR #" + to_string(elev->get_number()) + " HAS STABILIZED! OPERATIONS RESUMING!" << endl;
    }

    else{
        showWarning();
    }
}

/**
* Returns a boolean from the state's current run variable indicating wether the current state can be run in the FSM. 
*
* @param param1 void
* @return a boolean variable run as true 
* @author Yariel Mercado
*/ 
bool EmergencyState::canRun(void){
    return run;
}

/**
* Receives a boolean and sets the state's current run variable to either true or false denoting wether the state can be run. 
*
* @param param1 void
* @return This void function does not return values. 
* @author Yariel Mercado
*/ 
void EmergencyState::setRun(bool set){
    run = set;
}


