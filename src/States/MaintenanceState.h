#pragma once
#include "State.h"

class MaintenanceState : public State{
    
    private:
        string stateName = "Maintenance";
        bool run = false;
        string command = "M"; //placeholder
        Elevator* elev;
    
    public: 
        MaintenanceState(Elevator* elevator);
        void start(void);
        bool canRun(void); 
        void setRun(bool set);
        
        void showWarning(void); //show a warning every time a user tries to us an elevator in maintenance state
        void isWorking(void); //show a warning every time a user tries to us an elevator in maintenance state
        void check(string input); //checks if the current command entered unlocks maintanence
        string currentState(){return this->stateName;}
        ~MaintenanceState(){};
        
};