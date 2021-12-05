#pragma once
#include "Set.h"

/* Elevator Parameter Macros */
#define ELEVATOR_MAX_TEMP   120   // Maximum temperature an elevator car can reach
#define ELEVATOR_CAPACITY   10    // The max amount of people that can be stored
#define ELEVATOR_MAX_WEIGHT 1200  // The maximum allowed weight

/**
* @file Elevator.h
*
* @brief The elevator class. Contains its attributes, commands, and more.
*
* @author Yariel Mercado (Implementation & Documentation)
* @author Osvaldo Aquino (Implementation)
*/
class Elevator {
    private:
        /* The elevator's ID. */
        int eid; 
        /* Boolean determining whether a door is open or closed. */
        bool doorStatus;
        /* Boolean determining whether the elevator lights are on or off. */
        bool lightStatus; 
        /* The elevator's current floor. */
        int floor;
        /* The last and highest floor in the elevator's building. */
        int maxFloor;
        /* The elevator's current temperature, in fahrenheit. */
        int currentTemp;
        /* The elevator's maximum allowable temperature, in fahrenheit. */
        int maxTemp;
        /* The amount of people the elevator is carrying. */
        int capacity; 
        /* The elevator's current weight, in pounds. */
        int loadWeight; 
        /* The elevator's maximum allowable weight, in pounds. */
        int maxLoad; 
        /* Set containing the elevator's requested floors. */
        Set* stoppingFloors;

    public:
        Elevator(int num);
        ~Elevator();

        /* Setters */

        void set_door_status(bool inputDoorST);

        void set_load_weight(int inputLoad); 

        void set_floor(int inputFloor);

        void set_light_status(bool inputLight);

        void set_max_temp(int inputTemp);

        void set_current_temp(int inputTemp);

        void set_max_load_weight(int inputLoad);
    
        void set_max_floor(int inputFloor);

        void set_stopping_floors(Set* floors);

        /* Getters */
        
        bool is_door_open(void);

        bool is_light_on(void);

        int get_number(void);
        
        int get_capacity(void);

        int get_floor(void);

        int get_max_floor(void);

        int get_load_weight(void);

        int get_max_load_weight(void);

        int get_current_temp(void);

        int get_max_temp(void);

        Set* get_stopping_floors(void);

        /* Specific actions */

        void open(void);

        void close(void);

        void turn_lights_on();

        void turn_lights_off();
};