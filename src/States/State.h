#pragma once
#include "Arduino.h"
#include "Elevator.h"


class State{

    public:
        virtual string currentState(void) = 0; 
        virtual bool canRun(void) = 0; //whether we can run the current state
        virtual void setRun(bool set) = 0;  
        virtual void start() =  0; //acts as an initializer of sorts for the state
        virtual ~State() = 0;
};