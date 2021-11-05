#pragma once
#include "State.h"

class InitialState : public State {

    private:
        string stateName = "Initial";
        bool run = true;
        Elevator* elev;

    public:
        InitialState(Elevator* elevator);
        void start(void);
        bool canRun(void); 
        void setRun(bool set);
        string currentState(){return this->stateName;}
        ~InitialState(){};
};