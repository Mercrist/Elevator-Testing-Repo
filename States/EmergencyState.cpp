#include "EmergencyState.h"

/**
* Contructor for the moving state. Initializes with the given elevator as a parameter.
*
* @param elevator The elevator being initialized in the current state.
*/
EmergencyState::EmergencyState(Elevator* elevator){
    this->elev = elevator;
}

/**
* Activates the state by opening the doors and turning the lights on, in order to stabilize the elevator.
*/ 
void EmergencyState::start(void){
    elev->open();
    elev->turn_lights_on();
    cout << "ENTERING EMERGENCY STATE! NO COMMANDS WILL BE PROCESSED UNTIL ELEVATOR #" + to_string(elev->get_number()) + " STABILIZES!" << endl;
    this->show_warning();
}

/**
* In order to stabilize the weight, the whole elevator must be emptied out. Thus the need for a custom unloading function.
*
* @param weight The weight to be unloaded, in pounds.
*/ 
void EmergencyState::unload(int weight){
    int toUnload = elev->get_load_weight() - weight;
    elev->set_load_weight(toUnload);
}

/**
* Prints a warning to the terminal, showcasing all of the parameter differences. Informs the elevator
* system manager of the elevator attributes that must stabilize.
*
*/ 
void EmergencyState::show_warning(void){
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
* Checks whether the parameters are within the alloted values. Else, displays a warning.
*
*/ 
void EmergencyState::is_working(void){
    if(elev->get_current_temp() <= elev->get_max_temp() && elev->get_load_weight() <= elev->get_max_load_weight()) 
    {
        cout << "ELEVATOR #" + to_string(elev->get_number()) + " HAS STABILIZED! OPERATIONS RESUMING!" << endl;
        this->run = true;
    }

    else{
        show_warning();
    }
}

/**
*  Returns a boolean indicating wether the current state can run. 
*
* @return A boolean, indicating whether the elevator can run or not.
*/ 
bool EmergencyState::can_run(void){
    return run;
}

/**
*  Receives a boolean and sets the state's current run attribute, denoting whether the state can be run. 
*
* @param set Sets the state's run attribute to the given boolean parameter.
*/ 
void EmergencyState::set_run(bool set){
    this->run = set;
}

/**
*  Identifies the current state's name. 
*
* @return The current state's name, as a string.
*/ 
string EmergencyState::current_state()
{
    return this->stateName;
}

/**
*  The state's destructor. The elevator is cleared out in the Finite State Machine.
*/ 
EmergencyState::~EmergencyState(){};

