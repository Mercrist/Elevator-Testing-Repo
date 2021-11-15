#include "Elevator.h"

//Constructor
Elevator::Elevator(int num)
{
    eid = num;
    max_load_weight = ELEVATOR_MAX_WEIGHT;
    max_temp = ELEVATOR_MAX_TEMP;
    capacity = ELEVATOR_CAPACITY;
    floor = 1;
}

//booleans
bool Elevator::is_door_open(void)
{
    return door_status;
}

bool Elevator::is_light_on(void)
{
    return light_status;
}

//setters
void Elevator::set_door_status(bool inputDoorST)
{
    this->door_status = inputDoorST;
}

void Elevator::set_load_weight(int inputLoad)
{
    this->load_weight = inputLoad; 
}

void Elevator::set_floor(int inputFloor)
{
    this->floor = inputFloor;
}

void Elevator::set_light_status(bool inputLight)
{
    this->light_status = inputLight;
}

void Elevator::set_max_temp(int inputTemp)
{
    this->max_temp = inputTemp;
}

void Elevator::set_current_temp(int inputTemp)
{
    this->current_temp = inputTemp;
}

void Elevator::set_max_load_weight(int inputLoad)
{
    this->max_load_weight = inputLoad;
}

void Elevator::set_max_floor(int inputFloor)
{
    this->max_floor = inputFloor;
}

// void Elevator::set_state(State* nextState)
// {
//     this->elevator_state = nextState;
// }

void Elevator::set_number(int num)
{
    eid = num;         
}

void Elevator::set_stopping_floors(Set* floors)
{
    stoppingFloors = floors;
}

//getters


uint8_t Elevator::get_number(void)
{
    return eid;
}


uint8_t Elevator::get_capacity(void)
{
    return capacity;
}

uint8_t Elevator::get_floor(void)
{
    return floor;
}

uint8_t Elevator::get_max_floor(void)
{
    return max_floor;
}

uint16_t Elevator::get_load_weight(void)
{
    return load_weight;
}

uint16_t Elevator::get_max_load_weight(void)
{
    return max_load_weight;
}

uint8_t Elevator::get_current_temp(void)
{
    return current_temp;
}

uint8_t Elevator::get_max_temp(void)
{
    return max_temp;
}

// String Elevator::get_state_name(void)
// {
//     return elevator_state->currentState();
// }

// State* Elevator::get_state(void)
// {
//     return elevator_state;
// }

// void Elevator::run_state(void)
// {
//     elevator_state->start(this);
// }

void Elevator::open(void)
{
    set_door_status(true);
}

void Elevator::close()
{
    set_door_status(false);
}

Elevator::~Elevator()
{
    delete stoppingFloors;
}