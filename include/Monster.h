#ifndef MONSTER_H
#define MONSTER_H
#include<Guest.h>

class Monster :public Guest
{
    public:
        Monster();
        virtual ~Monster();
         int getNightPrice();
        int getSpaPrice();
        int getCleanPrice();



    protected:

    private:
        int nightPrice=200;
        int dryCleaningPrice=30;
        int spaPrice=50;


};

#endif // MONSTER_H
