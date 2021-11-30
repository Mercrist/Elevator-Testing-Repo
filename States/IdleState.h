#pragma once
#include "State.h"

/**
* @file   IdleState.h
*
* @brief  The elevator's default state. Allows the elevator to move, pick people up, unload people, and more.
*
* @author Yariel Mercado (Implementation & Revision)
* @author Ana Ribon (Documentation)
*/
class IdleState : public State{
    private:
        /* String used to identify the current state. */
        string stateName = "Idle";

        /* Boolean used to identify whether the current state can run or not. */
        bool run = true;

        /* The elevator attribute. */
        Elevator* elev;

        /* Whether the elevator is currently in energy saving mode or not */
        bool energySaving = false;

    public:
        IdleState(Elevator* elevator);

        void start(void);

        bool can_run(void); 

        void set_run(bool set);
       
        void load(int weight);

        void unload(int weight);

        void energy_saving();

        string current_state();

        ~IdleState();

};