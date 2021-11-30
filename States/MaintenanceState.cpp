#include "MaintenanceState.h"

/**
* Contructor for the maintenance state, in which the elevator is called to start calling the other functions.
* @author Yariel Mercado
*/
MaintenanceState::MaintenanceState(Elevator* elevator){
    this->elev = elevator;
}

/**
* Turn the lights on and the doors open to initialize the state. 
*
* @param param1 void
* @return This void function does not return values. 
* @author Yariel Mercado
*/ 
void MaintenanceState::start(void){
    elev->set_door_status(true);
    elev->set_light_status(true);
    showWarning();
}

/**
* Show a warning that the elevator is under mantenance. 
*
* @param param1 void
* @return This void function does not return values. 
* @author Yariel Mercado
*/ 
void MaintenanceState::showWarning(void){
    cout << "CURRENTLY IN MAINTENANCE STATE! NO COMMANDS WILL BE PROCESSED UNTIL ELEVATOR #" + to_string(elev->get_number()) + " HAS BEEN FIXED!" << endl;
    cout << "ENTER THE SPECIAL INPUT COMMAND IN ORDER TO COMPLETE MAINTENANCE!"<< endl;
}

/**
* Show a warning that the maintenance process has ended.  
*
* @param param1 void
* @return This void funciton does not return values. 
* @author Yariel Mercado
*/ 
void MaintenanceState::isWorking(void){
    if(run) {cout << "ELEVATOR " + to_string(elev->get_number()) + " HAS BEEN FIXED! OPERATIONS RESUMING!" << endl;}

    else{
        showWarning();
    }
}

/**
* Determine if the input of Maintenance was received. 
*
* @param param1 interface input
* @return This void function does not return values. 
* @author Yariel Mercado
*/ 
void MaintenanceState::check(string input){
    if(command.compare(input) == 0){
        setRun(true);
        isWorking();
    }
}

/**
* Returns a boolean from the state's current run variable indicating wether the current state can be run in the FSM. 
*
* @param param1 void
* @return variable run as true 
* @author Yariel Mercado
*/ 
bool MaintenanceState::canRun(void){
    return run;
}

/**
* Receives a boolean and sets the state's current run variable to either true or false denoting wether the state can be run. 
*
* @param param1 boolean set 
* @return This void function does not return values. 
* @author Yariel Mercado
*/ 
void MaintenanceState::setRun(bool set){
    run = set;
}


