#include "MaintenanceState.h"

MaintenanceState::MaintenanceState(Elevator* elevator){
    this->elev = elevator;
}

void MaintenanceState::start(void){
    elev->set_door_status(true);
    elev->set_light_status(true);
    cout << "ENTERING MAINTENANCE STATE! NO COMMANDS WILL BE PROCESSED UNTIL THE ELEVATOR " + to_string(elev->get_number()) + " HAS BEEN FIXED!" << endl;
    cout << "ENTER THE SPECIAL INPUT COMMAND IN ORDER TO COMPLETE MAINTENANCE!" << endl;
}

void MaintenanceState::showWarning(void){
    cout << "CURRENTLY IN MAINTENANCE STATE! NO COMMANDS WILL BE PROCESSED UNTIL THE ELEVATOR #" + to_string(elev->get_number()) + " HAS BEEN FIXED!" << endl;
    cout << "ENTER THE SPECIAL INPUT COMMAND IN ORDER TO COMPLETE MAINTENANCE!"<< endl;
}


void MaintenanceState::isWorking(void){
    if(run) {cout << "ELEVATOR " + to_string(elev->get_number()) + " HAS BEEN FIXED! OPERATIONS RESUMING!" << endl;}

    else{
        showWarning();
    }
}

void MaintenanceState::check(String input){
    if(command.compareTo(input) == 0){
        setRun(true);
        isWorking();
    }
}


bool MaintenanceState::canRun(void){
    return run;
}

void MaintenanceState::setRun(bool set){
    run = set;
}


