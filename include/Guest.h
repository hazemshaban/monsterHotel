#ifndef GUEST_H
#define GUEST_H
#include<string>
using namespace std;

class Guest
{
    public:
        Guest();
        virtual ~Guest();
        void setUserName(string name);
        void setId(int id);
        string getUserName();
        int getID();
        void addNights(int nightsNumber);
        void addCost(int cost);
        void setRooms(int roomsNumber);
        int getNights();
        int getTotalCost();
        int getRooms();



    protected:

    private:
        string userName;
        int userId;
        int nights=0;
        int totalCost=0;
        int rooms=0;

};

#endif // GUEST_H
