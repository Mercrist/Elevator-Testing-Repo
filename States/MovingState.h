#pragma once
#include "State.h" 

#define UP 1
#define DOWN 0
#define null 3

class MovingState : public State{ 
    private:
        string stateName = "Moving";
        bool run = false;
        int direction_lock = null; //up is 1, down is 0
        Elevator* elev;
        bool stopped = false;

        clock_t begin;
        double time_spent;

    public:
        MovingState(Elevator* elevator);
        void start(void);
        int get_nearest_floor(void);
        void set_direction(void);
        bool canRun(void); 
        void setRun(bool set);
        void move(void);
        void move_nearest(void); 
        void moving_timer(void);
        bool canMove(void);
        bool should_switch_direction(void);
        bool made_stop(void);
        void open(void);
        void close(void);


        string currentState(){return this->stateName;}
        ~MovingState(){};

};