#include "EmergencyState.h"

EmergencyState::EmergencyState(Elevator* elevator){
    this->elev = elevator;
}

void EmergencyState::start(void){
    elev->set_door_status(true);
    elev->set_light_status(true);
    cout << "ENTERING EMERGENCY STATE! NO COMMANDS WILL BE PROCESSED UNTIL THE ELEVATOR " + to_string(elev->get_number()) + " STABILIZES!" << endl;
}


void EmergencyState::unload(int weight){
    int toUnload = elev->get_load_weight() - weight;
    elev->set_load_weight(toUnload);
}

void EmergencyState::showWarning(void){
    cout << "CURRENTLY IN EMERGENCY STATE! NO COMMANDS WILL BE PROCESSED UNTIL THE ELEVATOR " + to_string(elev->get_number()) + " STABILIZES!" << endl;
    cout << "PARAMETERS MUST GO BACK TO THE MAXIMUM ALLOWED VALUES!" << endl;
    cout << "" << endl;
    cout << "PARAMETER DIFFERENCES:" << endl;
    cout << "-----------------------" << endl;

    if(elev->get_current_temp() > elev->get_max_temp()){
        cout << "TEMP IS " + to_string(elev->get_current_temp()) + "! MUST LOWER BY: " + to_string(elev->get_current_temp()-elev->get_max_temp()) + " DEGREES F!" << endl;
    }

    else if(elev->get_current_temp() <= elev->get_max_temp()){
        cout << "TEMP IS NORMAL!" << endl;
    }

    if(elev->get_capacity() > elev->get_max_load_weight()){
        cout << "CURRENT CAPACITY IS " + to_string(elev->get_current_temp()) + "! MUST LOWER BY: " + to_string(elev->get_capacity()-elev->get_max_load_weight()) + " POUNDS!" << endl;
    }

    else if(elev->get_capacity() <= elev->get_max_load_weight()){
        cout << "CAPACITY IS NORMAL!" << endl;
    }
    
}


void EmergencyState::isWorking(void){
    if(run) {cout << "ELEVATOR " + to_string(elev->get_number()) + " HAS STABILIZED! OPERATIONS RESUMING!" << endl;}

    else{
        showWarning();
    }
}

bool EmergencyState::canRun(void){
    return run;
}

void EmergencyState::setRun(bool set){
    run = set;
}


