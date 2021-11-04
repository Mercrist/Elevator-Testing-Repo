//HEAVILY EDIT UNTIL YOU CAN RESOLVE INCLUDES AND GET THEM TO WORK

#include <iostream> //you should be able to delete these two lines once you format them where i specified
using namespace std;

#include "src/lib/States/FSM.h"
#include "src/lib/States/Elevator.h" 


int main()
{
    Elevator elev = new Elevator(1);
    //SET ELEVATOR PARAMETERS WITH SETTERS HERE
    elev->set_max_floor(5);
    Set* floors = new Set(2);
    floors.add(4);
    floors.add(5);
    floors.add(1);

    elev->set_stopping_floors(floors);

    FSM* machine = new FSM(elev);
    machine->setup();
    machine->run(NULL); //CHANGE TO WHATEVER COMMAND PARAMETERS YOU WANT

    delete machine;

    return 0; //DON'T REMOVE
}