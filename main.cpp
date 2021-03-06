#include "States/FSM.h"

int main()
{
    Elevator* elev = new Elevator(1);
    //SET ELEVATOR PARAMETERS WITH SETTERS HERE
    elev->set_max_floor(8);
    //query of floors to visit
    Set* floors = new Set();
    floors->add(4);
    floors->add(5);
    floors->add(8);
    floors->add(1);

    elev->set_stopping_floors(floors);

    FSM* machine = new FSM(elev);
    machine->setup();
    machine->run(9);

    delete machine;
    return 0; //DON'T REMOVE
}