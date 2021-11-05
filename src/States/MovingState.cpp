#include "MovingState.h"

//MISSING MOVING STATE FUNCTIONALITIES

MovingState::MovingState(Elevator* elevator){
    this->elev = elevator;
}

void MovingState::start(){
    elev->set_door_status(false);
    elev->set_light_status(true);
}

int MovingState::get_nearest_floor()
{
    Set* stoppingFloors = elev->get_stopping_floors();

    if(stoppingFloors->size() < 1){
        cout << "ELEV #" + to_string(elev->get_number()) + " CAN'T CHANGE FLOORS!" << endl;
        return -1; //SWITCH TO IDLE
    }

    if(stoppingFloors->size() == 1) return stoppingFloors->get(0); 

    int nearestDifference = 40; 
    int go_to_floor;
    
    for(int i = 0; i < stoppingFloors->size(); i++) //get the nearest floor 
    {
        int currentStopping = stoppingFloors->get(i);
        if(abs(currentStopping - elev->get_floor()) <= nearestDifference && currentStopping != elev->get_floor()){
            nearestDifference = abs(currentStopping - elev->get_floor());
            go_to_floor = currentStopping;
        }
    }
    return go_to_floor;
}

void MovingState::set_direction(void)
{
    uint8_t floor = get_nearest_floor();

    if(floor == -1){
        cout << "ELEVATOR #" + to_string(elev->get_number()) + " HAS NO REQUESTED FLOORS!" << endl;
        run = false;
        return;
    }


    if(floor <= elev->get_max_floor()){ 
        this->toFloor = floor;

        if(elev->get_floor() < this->toFloor){ //direction lock
            direction_lock = UP;
        }

        else if (elev->get_floor() > this->toFloor){
            direction_lock = DOWN;
        }

        cout << "ELEVATOR " + to_string(elev->get_number()) + " EN ROUTE TO FLOOR# " + to_string(toFloor) + "!" << endl;
        run = true;
    }

    else{ 
        cout << "FLOOR #" + to_string(floor) + " DOESNT EXIST!" << endl;
        run = false;
    }

}


void MovingState::moving_timer(void)
{
    begin = clock();
    time_spent = (double)(clock() - begin);

    cout << "ELEVATOR #" + to_string(elev->get_number()) + " TRANSITIONING TO ANOTHER FLOOR!"<< endl;

    while(time_spent != 3000.0){ //3 second timer
        time_spent = (double)(clock() - begin);
    }
}

void MovingState::move_nearest(void) //moves to the nearest floor in the building
{
    int currentFloor = elev->get_floor(); 
    
    //will be called after emergency state so we don't care about whether we can run it or not
    
    if(currentFloor + 1 != elev->get_max_floor()){ //direction lock
        currentFloor++;
    }

    else{
        currentFloor--;
    }
        
    moving_timer();
    elev->set_floor(currentFloor); 
    cout << "ELEVATOR #" + to_string(elev->get_number()) + " CURRENTLY ON FLOOR #" + to_string(toFloor) + "!" << endl;
    
}

void MovingState::move(void){ //Set implemented with Linked List, moves on floor at a time
    int currentFloor = elev->get_floor();
    Set* stoppingFloors = elev->get_stopping_floors();
    

    if(run && direction_lock != null){ 
        if(direction_lock == UP){ //direction lock
            currentFloor++;
        }

        else if (direction_lock == DOWN){
            currentFloor--;
        }
        
        //DONT USE DELAY
        moving_timer();
        elev->set_floor(currentFloor); 
        cout << "ELEVATOR #" + to_string(elev->get_number()) + " CURRENTLY ON FLOOR # " + to_string(toFloor) + "!" << endl;

        if(stoppingFloors->contains(currentFloor)){
            cout << "ELEVATOR #" + to_string(elev->get_number()) + " CURRENTLY LEAVING AND PICKING PEOPLE ON FLOOR #" + to_string(toFloor) + "!" << endl;
            stoppingFloors->remove(currentFloor);
            stopped = true;
        }
        else stopped = false;
    }
}

bool MovingState::canMove(void){
    Set* stoppingFloors = elev->get_stopping_floors();
    return stoppingFloors->size() > 0;
}

bool MovingState::should_switch_direction(void) //whether we should change direction lock
{ 
    Set* stoppingFloors = elev->get_stopping_floors();
    bool shouldChange = true;

    for(int i = 0; i < stoppingFloors->size(); i++) //get the nearest floor 
    {
        int otherFloors = stoppingFloors->get(i);
        if(direction_lock == UP && otherFloors > elev->get_floor()){ //more floors up
            shouldChange = false;            
        }

        else if(direction_lock == DOWN && otherFloors < elev->get_floor()){ //more floors down
            shouldChange = false;            
        }

    }
    return shouldChange;
}

bool MovingState::made_stop(void){
    return stopped;
}

bool MovingState::canRun(void){
    return run;
}

void MovingState::setRun(bool set){
    run = set;
}


