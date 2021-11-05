/*
 * TODO : DOCUMENT
 * 
 * 
 */
#pragma once
#include "AllStates.h"


class FSM {
    private:
        //states
        InitialState* initial_state; 
        IdleState* idle_state;
        MovingState* moving_state;
        EmergencyState* emergency_state; 
        MaintenanceState* maintenance_state;

        Elevator* elev;
        string currentStateName = ""; //keeps track of the current state

        clock_t begin;
        double time_spent;
        bool toggle = false; //for energy saving


    public:
        FSM(Elevator* elevator); //initialize elevators
        void setup(void); //put elevs in initial state
        void run(int command); //run each elevator
        void energyUpdate();
        ~FSM(); //end FSM
};

