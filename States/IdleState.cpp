#include "IdleState.h"

/**
* Contructor for the moving state. Initializes with the given elevator as a parameter.
*
* @param elevator The elevator being initialized in the current state.
*/
IdleState::IdleState(Elevator* elevator){
    this->elev = elevator;
}

/**
* Activates the elevator by opening its doors and turning the lights on, to recieve passengers.
*/ 
void IdleState::start(void){
    elev->open();
    elev->turn_lights_on();
    cout << "ELEVATOR #" + to_string(elev->get_number()) + " ENTERING IDLE STATE!" << endl;
}

/**
* Loads the weight passed as a parameter onto the elevator, if the doors are open and the lights are on.
* If the elevator was in enervy saving mode, exits it.
*
* @param weight The value of the weight to load onto the elevator, in pounds. 
*/ 
void IdleState::load(int weight){
    if(this->energySaving){
        elev->open();
        elev->turn_lights_on();
        energySaving = false;
    }

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
* Unloads the weight passed as a parameter onto the elevator. Won't unload more weight than it can,
* which acts as a safeguard against going into negative weights.
*
* @param weight The value of the weight to unload off the elevator, in pounds. 
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
* If the elevator has not received inputs from the user, the lights will turn off and the doors will close to conserve energy. 
*
*/ 
void IdleState::energy_saving(void){
    energySaving = true;
    cout << "ELEVATOR " + to_string(elev->get_number()) + " HAS BEEN UNUSED FOR 15 SECONDS, ENTERING ENERGY SAVING MODE!" << endl;
    elev->close();
    if(elev->get_capacity() == 0){
        elev->turn_lights_off();
    }
}

/**
*  Returns a boolean indicating wether the current state can run. 
*
* @return A boolean, indicating whether the elevator can run or not.
*/ 
bool IdleState::can_run(void){
    return run;
}

/**
*  Receives a boolean and sets the state's current run attribute, denoting whether the state can be run. 
*
* @param set Sets the state's run attribute to the given boolean parameter.
*/ 
void IdleState::set_run(bool set){
    this->run = set;
}

/**
*  Identifies the current state's name. 
*
* @return The current state's name, as a string.
*/ 
string IdleState::current_state()
{
    return this->stateName;
}

/**
*  The state's destructor. The elevator is cleared out in the Finite State Machine.
*/ 
IdleState::~IdleState(){};


