#pragma once
#include "State.h"

class IdleState : public State{
    private:
        string stateName = "Idle";
        bool run = true;
        Elevator* elev;

    public:
        IdleState(Elevator* elevator);
        void start(void);
        bool canRun(void); 
        void setRun(bool set);
        
        void load(int weight);
        void unload(int weight);
        void energySaving();
        string currentState(){return this->stateName;}
        ~IdleState(){};

};