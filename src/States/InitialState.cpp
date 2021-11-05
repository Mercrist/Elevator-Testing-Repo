#include "InitialState.h"

InitialState::InitialState(Elevator* elevator){
    this->elev = elevator;
}

void InitialState::start(void)
{
    elev->set_load_weight(0);
    elev->set_door_status(false);
    elev->set_light_status(true);
    elev->set_floor(1);
    elev->set_current_temp(60);
    cout << "ELEVATOR " + to_string(elev->get_number()) + " INITIALIZED!" << endl;
}

bool InitialState::canRun(void){
    return run;
}

void InitialState::setRun(bool set){
    run = set;
}
