#include "FSM.h"

FSM::FSM(Elevator* elevator)
{
    this->elev = elevator;
    initial_state = new InitialState(elev); 
    idle_state = new IdleState(elev);
    moving_state = new MovingState(elev);
    emergency_state = new EmergencyState(elev); 
    maintenance_state = new MaintenanceState(elev);
}

void FSM::setup(void) //dont initialize idle start here
{
    initial_state->start(); 
    currentStateName = idle_state->currentState();
}
 
//should go inside some mainloop
void FSM::energyUpdate(void)
{
    if(currentStateName.compare("Idle") == 0 && !toggle){ 
        begin = clock();
        time_spent = (double)(clock() - begin);

        while(true){ //15 second timer
            time_spent = (double)(clock() - begin);
            if(time_spent >= 15000.00) return;
        }

        idle_state->energySaving();
    }
}

void FSM::warning()
{
    cout << "CAN'T RUN ELEVATOR #" + to_string(elev->get_number()) + " FROM THE CURRENT STATE: " + currentStateName << endl;
}

void FSM::run(int command) //manages transitions
{
    switch(command){
        case 7: //load people (300 lbs)
            if(currentStateName.compare("Idle") == 0){
                idle_state->start();
                idle_state->load(300);
                toggle = true; //wont go into reset, means elevator was activated, reset timer

                if(elev->get_load_weight() > elev->get_max_load_weight() || elev->get_current_temp() > elev->get_max_temp()){ //EMERGENCY STATE
                    emergency_state->start();
                    currentStateName = emergency_state->currentState();

                    moving_state->start();
                    moving_state->move_nearest();
                    emergency_state->unload(elev->get_load_weight()); //empty elevator
                    elev->set_current_temp(65);
                    emergency_state->isWorking();
                    
                    idle_state->start();
                    currentStateName = idle_state->currentState();
                    toggle = false;
                    break;
                }

            }

            else warning();
            // currentStateName = idle_state->currentState();
            toggle = false;
            break;

        case 8: //unload people (300 lbs)
            if(currentStateName.compare("Idle") == 0){
                idle_state->start();
                idle_state->unload(300);
                toggle = true; //wont go into reset, means elevator was activated
            }

            else warning();
            toggle = false;
            break;

        case 9: //moving
            if(currentStateName.compare("Idle") == 0){
                currentStateName = moving_state->currentState();
                moving_state->start();
                moving_state->set_direction(); //direction lock
                
                int count = 1;
                while(moving_state->canMove()){
                    if(count == 2){ //FOR TESTING PURPOSES
                        elev->get_stopping_floors()->add(2);
                    }



                    moving_state->move();
                    count++;
                    elev->get_stopping_floors()->print();
                    //loading and unloading
                    if(moving_state->made_stop()){
                        idle_state->load(300); //not sure when to pick or leave people off while moving or how much 
                        idle_state->unload(300);
                        moving_state->close();

                        if(elev->get_load_weight() > elev->get_max_load_weight()){command = 7;} //emergency state, just call the function directly after you refactor
                    }

                    if(moving_state->should_switch_direction()){ //switch direction lock 
                        moving_state->set_direction();
                    }
                }
                idle_state->start();
                currentStateName = idle_state->currentState();
                toggle = false;
            }
            else warning();
            break;

        case 10: //lock maintenance state
            currentStateName = maintenance_state->currentState();
            maintenance_state->start();
            break;

        case 13: //unlock maintenance state
            maintenance_state->check("M");
            idle_state->start();
            currentStateName = idle_state->currentState();
            toggle = false;
            break;
    }
}

FSM::~FSM(void)
{
    delete elev;
    delete initial_state;
    delete idle_state;
    delete moving_state;
    delete emergency_state;
    delete maintenance_state;
}