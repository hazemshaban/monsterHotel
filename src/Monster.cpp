#include "Monster.h"
#include<string>
using namespace std;
Monster::Monster()
{
    //ctor
}

Monster::~Monster()
{
    //dtor
}

int Monster::getNightPrice(){return Monster::nightPrice;}
int Monster::getSpaPrice(){return Monster::spaPrice;}
int Monster::getCleanPrice(){return Monster::dryCleaningPrice;}
