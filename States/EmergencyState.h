#pragma once
#include "State.h"

class EmergencyState : public State {

    private:
        string stateName = "Emergency";
        bool run = false;
        Elevator* elev;

    public:
        EmergencyState(Elevator* elevator);
        void start(void);
        bool canRun(void); 
        void setRun(bool set);

        void showWarning(void); //show a warning every time a user tries to us an elevator in emergency state
        void isWorking(void); //show a warning every time a user tries to us an elevator in emergency state
        void unload(int weight);

        string currentState(){return this->stateName;}
        ~EmergencyState(){};
};