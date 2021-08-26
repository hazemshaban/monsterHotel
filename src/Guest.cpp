#include "Guest.h"
#include<string>
using namespace std;
Guest::Guest()
{
    //ctor
}

Guest::~Guest()
{
    //dtor
}
int  Guest::getID(){return Guest::userId;}
string Guest::getUserName(){return Guest::userName;}
void Guest::setId(int id){Guest::userId=id;}
void Guest::setUserName(string name){Guest::userName=name;}
void Guest::addCost(int cost){Guest::totalCost=Guest::totalCost+cost;}
void Guest::addNights(int nightsNumber){Guest::nights=Guest::nights+nightsNumber;}
void Guest::setRooms(int roomsNumber){Guest::rooms=Guest::rooms+roomsNumber;}
int Guest::getNights(){return Guest::nights;}
int Guest::getTotalCost(){return Guest::totalCost;}
int Guest ::getRooms(){return Guest::rooms;}
