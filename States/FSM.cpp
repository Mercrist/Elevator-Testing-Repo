#include "FSM.h"

/**
* Contructor for the idle state, in which the elevator is called to start calling the other functions.
* @author Yariel Mercado
*/
FSM::FSM(Elevator* elevator)
{
    this->elev = elevator;
    initial_state = new InitialState(elev); 
    idle_state = new IdleState(elev);
    moving_state = new MovingState(elev);
    emergency_state = new EmergencyState(elev); 
    maintenance_state = new MaintenanceState(elev);
}

/**
* Function to state all the parameters in the correct values to initialize the state. 
*
* @param param1 void
* @return This void function does not return values. 
* @author Yariel Mercado
*/ 
void FSM::setup(void) //dont initialize idle start here
{
    initial_state->start(); 
    curr_state = IDLE_STATE;
}

/**
* Function to state all the parameters in the correct values to initialize the state. 
*
* @param param1 void
* @return This void function does not return values. 
* @author Yariel Mercado
*/  
//should go inside some mainloop
void FSM::energyUpdate(void)
{
    if(curr_state == IDLE_STATE){ 
        begin = clock();
        time_spent = (double)(clock() - begin);

        while(true){ //15 second timer
            time_spent = (double)(clock() - begin);
            if(time_spent >= 15000.00) return;
        }

        idle_state->energySaving();
    }
}

/**
* Function to state all the parameters in the correct values to initialize the state. 
*
* @param param1 void
* @return This void function does not return values. 
* @author Yariel Mercado
*/ 
void FSM::emergencyToggle()
{
    emergency_state->start();
    curr_state = EMERGENCY_STATE;

    moving_state->start();
    moving_state->move_nearest();
    emergency_state->unload(elev->get_load_weight()); //empty elevator
    elev->set_current_temp(65);
    emergency_state->isWorking();

    idle_state->start();
    curr_state = IDLE_STATE;
    toggle = false;
}

/**
* Function to state all the parameters in the correct values to initialize the state. 
*
* @param param1 void
* @return This void function does not return values. 
* @author Yariel Mercado
*/ 
void FSM::movingLoop()
{
    moving_state->start();
    moving_state->set_direction(); //direction lock
                
    int count = 1;
    while(moving_state->canMove()){
        if(count == 4){ //FOR TESTING PURPOSES
            elev->get_stopping_floors()->add(4);
        }

        count++;
        moving_state->move();
        elev->get_stopping_floors()->print();
        cout << "\n";
        //loading and unloading
        if(moving_state->made_stop()){
            idle_state->load(300); //not sure when to pick or leave people off while moving or how much 
            idle_state->unload(300);
            elev->close();

            if(elev->get_load_weight() > elev->get_max_load_weight()){
                emergencyToggle();
                return;
            }
        }

        if(moving_state->should_switch_direction()){ //switch direction lock 
            moving_state->set_direction();
        }
    }

    idle_state->start();
    curr_state = IDLE_STATE;
    toggle = false;
}

/**
* Function to state all the parameters in the correct values to initialize the state. 
*
* @param param1 void
* @return This void function does not return values. 
* @author Yariel Mercado
*/ 
void FSM::warning()
{
    string state; 
    switch(curr_state){
        case 1:
            state = initial_state->currentState();
            break;
            
        case 2:
            state = idle_state->currentState();
            break;

        case 3:
            state = moving_state->currentState();
            break; 

        case 4:
            state = emergency_state->currentState();
            break;

        case 5:
            state = maintenance_state->currentState();
            break;

        default: 
            state = "no set state";
            break;

    }
    cout << "CAN'T RUN ELEVATOR #" + to_string(elev->get_number()) + " FROM THE CURRENT STATE: " + state << endl;
}

/**
* Function to state all the parameters in the correct values to initialize the state. 
*
* @param param1 void
* @return This void function does not return values. 
* @author Yariel Mercado
*/ 
void FSM::run(int command) //manages transitions
{
    switch(command){
        case 7: //load people (300 lbs)
            if(curr_state == IDLE_STATE){
                idle_state->start();
                idle_state->load(300);
                toggle = true; //wont go into reset, means elevator was activated, reset timer

                if(elev->get_load_weight() > elev->get_max_load_weight() || elev->get_current_temp() > elev->get_max_temp()){ //EMERGENCY STATE
                    emergencyToggle();
                    break;
                }

            }

            else warning();
            // currentStateName = idle_state->currentState();
            toggle = false;
            break;

        case 8: //unload people (300 lbs)
            if(curr_state == IDLE_STATE){
                idle_state->start();
                idle_state->unload(300);
                toggle = true; //wont go into reset, means elevator was activated
            }

            else warning();
            toggle = false;
            break;

        case 9: //moving
            if(curr_state ==  IDLE_STATE){
                curr_state = MOVING_STATE;
                movingLoop();
                
            }
            else warning();
            break;

        case 10: //lock maintenance state
            curr_state = MAINTENANCE_STATE;
            maintenance_state->start();
            break;

        case 13: //unlock maintenance state
            maintenance_state->check("M");
            idle_state->start();
            curr_state = IDLE_STATE;
            toggle = false;
            break;
    }
}

/**
* Function to state all the parameters in the correct values to initialize the state. 
*
* @param param1 void
* @return This void function does not return values. 
* @author Yariel Mercado
*/ 
FSM::~FSM(void)
{
    delete elev;
    delete initial_state;
    delete idle_state;
    delete moving_state;
    delete emergency_state;
    delete maintenance_state;
}