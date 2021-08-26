#include "Rooms.h"

Rooms::Rooms(int rooms)
{
    Rooms::availableRooms=rooms;
    //ctor
}

Rooms::~Rooms()
{
    //dtor
}

int Rooms::getAvailableRooms(){return Rooms::availableRooms;}
void Rooms::reservation(int roomsNumber){
Rooms::availableRooms=Rooms::availableRooms-roomsNumber;
}
