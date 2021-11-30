#pragma once
#include "State.h"

/**
* @file  InitialState.h
*
* @brief The elevator's first state, before going idle.
*
* @author Yariel Mercado (Implementation & Revision)
* @author Ana Ribon (Documentation)
*/
class InitialState : public State {
    private:
        /* String used to identify the current state. */
        string stateName = "Initial";

        /* Boolean used to identify whether the current state can run or not. */
        bool run = true;

        /* The elevator attribute. */
        Elevator* elev;

    public:
        InitialState(Elevator* elevator);

        void start(void);

        bool can_run(void); 

        void set_run(bool set);

        string current_state();
        
        ~InitialState();
};