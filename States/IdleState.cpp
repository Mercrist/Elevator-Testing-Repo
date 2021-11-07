#include "IdleState.h"

//MISSING MOVING STATE FUNCTIONALITIES

IdleState::IdleState(Elevator* elevator){
    this->elev = elevator;
}

void IdleState::start(void){
    elev->set_door_status(true);
    elev->set_light_status(true);
    cout << "ELEVATOR #" + to_string(elev->get_number()) + " ENTERING IDLE STATE!" << endl;

}

void IdleState::load(int weight){
    int toAdd = elev->get_load_weight() + weight;
    elev->set_load_weight(toAdd);
}

void IdleState::unload(int weight){
    if(weight > elev->get_max_load_weight()){ //goes into negative numbers
        cout << "Can't unload more weight than is currently present!" << endl;
        return;
    }
    int toUnload = elev->get_load_weight() - weight;
    elev->set_load_weight(toUnload);
}

void IdleState::energySaving(void){
    cout << "ELEVATOR " + to_string(elev->get_number()) + " HAS BEEN UNUSED FOR 30 SECONDS, ENTERING ENERGY SAVING MODE!" << endl;
    elev->set_door_status(false);
    if(elev->get_capacity() == 0){
        elev->set_light_status(false);
    }
}

bool IdleState::canRun(void){
    return run;
}

void IdleState::setRun(bool set){
    run = set;
}


