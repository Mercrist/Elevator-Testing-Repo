#include "Elevator.h"

//Constructor
Elevator::Elevator(int num)
{
    eid = num;
    maxLoad = ELEVATOR_MAX_WEIGHT;
    maxTemp = ELEVATOR_MAX_TEMP;
    capacity = ELEVATOR_CAPACITY;
    floor = 1;
}

//setters
void Elevator::set_door_status(bool inputDoorST)
{
    this->doorStatus = inputDoorST;
}

void Elevator::set_load_weight(int inputLoad)
{
    this->loadWeight = inputLoad; 
}

void Elevator::set_floor(int inputFloor)
{
    this->floor = inputFloor;
}

void Elevator::set_light_status(bool inputLight)
{
    this->lightStatus = inputLight;
}

void Elevator::set_max_temp(int inputTemp)
{
    this->maxTemp = inputTemp;
}

void Elevator::set_current_temp(int inputTemp)
{
    this->currentTemp = inputTemp;
}

void Elevator::set_max_load_weight(int inputLoad)
{
    this->maxLoad = inputLoad;
}

void Elevator::set_max_floor(int inputFloor)
{
    this->maxFloor = inputFloor;
}


void Elevator::set_number(int num)
{
    this->eid = num;         
}

void Elevator::set_stopping_floors(Set* floors)
{
    this->stoppingFloors = floors;
}

//getters
bool Elevator::is_door_open(void)
{
    return doorStatus;
}

bool Elevator::is_light_on(void)
{
    return lightStatus;
}

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
    return maxFloor;
}

uint16_t Elevator::get_load_weight(void)
{
    return loadWeight;
}

uint16_t Elevator::get_max_load_weight(void)
{
    return maxLoad;
}

uint8_t Elevator::get_current_temp(void)
{
    return currentTemp;
}

uint8_t Elevator::get_max_temp(void)
{
    return maxTemp;
}

Set* Elevator::get_stopping_floors(void)
{
    return stoppingFloors;
}

//commands
void Elevator::open(void)
{
    set_door_status(true);
}

void Elevator::close()
{
    set_door_status(false);
}

void Elevator::turn_lights_on()
{
    set_light_status(true);
}

void Elevator::turn_lights_off()
{
    set_light_status(false);
}

Elevator::~Elevator()
{
    delete stoppingFloors;
}