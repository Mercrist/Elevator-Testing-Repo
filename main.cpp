#include "States/FSM.h"

int main()
{
    Elevator* elev = new Elevator(1);
    //SET ELEVATOR PARAMETERS WITH SETTERS HERE
    elev->set_max_floor(5);
    //query of floors to visit
    Set* floors = new Set(2);
    floors->add(4);
    floors->add(5);
    floors->add(1);

    elev->set_stopping_floors(floors);

    FSM* machine = new FSM(elev);
    machine->setup();
    machine->run(7); //CHANGE TO WHATEVER COMMAND PARAMETERS YOU WANT
    delete machine;

    return 0; //DON'T REMOVE
}