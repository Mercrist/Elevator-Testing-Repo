/*
 * TODO : DOCUMENT
 * 
 * 
 */
#pragma once
#include "AllStates.h"

#define null              0
#define INITIAL_STATE     1
#define IDLE_STATE        2
#define MOVING_STATE      3
#define EMERGENCY_STATE   4
#define MAINTENANCE_STATE 5

#define LOAD_COMMAND                 7
#define UNLOAD_COMMAND               8
#define MOVE_COMMAND                 9
#define MAINTENANCE_COMMAND          10
#define FIX_MAINTENANCE_COMMAND      13





class FSM {
    private:
        
        /* duda */
        InitialState* initial_state; 
        IdleState* idle_state;
        MovingState* moving_state;
        EmergencyState* emergency_state; 
        MaintenanceState* maintenance_state;

        /* Pointer that calls the elevator. */
        Elevator* elev;

        int curr_state = null; //keeps track of the current state

        clock_t begin;

        double time_spent;

        bool toggle = false; //for energy saving


    public:
        FSM(Elevator* elevator); //initialize elevators

        void setup(void); //put elevs in initial state

        void run(int command); //run each elevator
        
        void energyUpdate();

        void warning();

        void emergencyToggle();

        void movingLoop();

        ~FSM(); //end FSM
};

