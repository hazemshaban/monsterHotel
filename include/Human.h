#ifndef HUMAN_H
#define HUMAN_H
#include<Guest.h>

class Human : public Guest
{
    public:
        Human();
        virtual ~Human();
        int getNightPrice();
        int getSpaPrice();
        int getCleanPrice();

    protected:

    private:
        int nightPrice=500;
        int dryCleaningPrice=70;
        int spaPrice=100;

};

#endif // HUMAN_H
