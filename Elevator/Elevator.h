/*

 * 
 * 
 */

#pragma once
#include "Set.h"

// Elevator parameters
#define ELEVATOR_MAX_TEMP   120   // Maximum temperature an elevator car can reach
#define ELEVATOR_CAPACITY   10    // The max amount of people that can be stored
#define ELEVATOR_MAX_WEIGHT 1200  // The maximum allowed weight

class Elevator 
{

private:
        int eid; 
        bool door_status;
        bool light_status; 
        int floor;
        int max_floor;
        int current_temp;
        int max_temp;
        int capacity; 
        int load_weight; 
        int max_load_weight; //in lbs
        // State* elevator_state;
        Set* stoppingFloors;

public:

        // Constructors
        Elevator(int num);

        //booleans
        bool is_door_open(void);

        bool is_light_on(void);

        //setters
        void set_door_status(bool inputDoorST);

        void set_load_weight(int inputLoad); //increases load weight

        void set_floor(int inputFloor);

        void set_light_status(bool inputLight);

        void set_max_temp(int inputTemp);

        void set_current_temp(int inputTemp);

        void set_max_load_weight(int inputLoad);
    
        void set_max_floor(int inputFloor);

        // void set_state(State* nexState);

        void set_number(int num);

        void set_stopping_floors(Set* floors);

        //getters

        uint8_t get_number(void);
        
        uint8_t get_capacity(void);

        uint8_t get_floor(void);

        uint8_t get_max_floor(void);

        uint16_t get_load_weight(void);

        uint16_t get_max_load_weight(void);

        uint8_t get_current_temp(void);

        uint8_t get_max_temp(void);

        Set* get_stopping_floors(void){return stoppingFloors;}

        void open(void);
        void close(void);

        // String get_state_name(void);

        // State* get_state(void);

        // void run_state(void); //run the current state
        
        ~Elevator();
};