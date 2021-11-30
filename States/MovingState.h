#pragma once
#include "State.h" 

#define UP 1
#define DOWN 0
#define null 3

/**
* @file MovingState.h
*
* @brief Class for the elevator's moving state. While in this state, the elevator will change from floors with the 
*        direction lock. 
*
* @author Yariel Mercado
*/
class MovingState : public State{ 

    /**
    *
    * @brief This State receives an array of requests (floors); then, like most elevators, the requests will
    *        not be met in order, they will be met depending on the current elevator's direction.  
    * 
    * @author Yariel Mercado
    */
    private:
        /* String used to identify what the current state name is. */
        string stateName = "Moving";

        /* Boolean used to identify what the current state is. */
        bool run = false;

        /* Integer value to get the direction lock setted to null, up is 1 and down is 0. */
        int direction_lock = null; //up is 1, down is 0

        /* Pointer to call the elevator. */
        Elevator* elev;

        /* Boolean used to identify if the elevator has stopped or is moving. */
        bool stopped = false;

        /* Using a library, getting a timer to start. */
        clock_t begin;

        /* Variable that returns a float value which is the time spent since the timer began. */
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
        
        /* Used to identify what the elevator's current state is. */
        string currentState(){return this->stateName;}

        /* Destructor for the state, eliminates its memory. */
        ~MovingState(){};

};