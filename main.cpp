#include <iostream>
#include<Guest.h>
#include<Rooms.h>
#include<Monster.h>
#include<Human.h>
#include<vector>
using namespace std;

int main()
{
    //**************some variable**********************
    Rooms humanRooms(5);
    Rooms monsterRooms(15);
    //human and monster data
    vector<Human> humanGuests;
    vector<Monster> MonsterGuests;
    string name;
    int i=0;
    int id;
    int kindChoice;
    int serviceChoice;
    int numberOfRooms=0;
    int numberOfNights=0;
    int additionalService;
    int extraNightsCost=0;
    //************************************************

    //**************************************************
    while(1)
    {
    Human newHuman;
    Monster newMonster;

        // first choice if you is monster or human or receptionist
        cout << "\n********Choose***********\n1-New Guest\n2-Old Guest\n3-Receptionist" << endl;
        int firstChoice;
        cin>> firstChoice;
        // if he isn't a receptionist then ask him if he is monster or human
        if(firstChoice==1||firstChoice==2)
        {
            do{
            cout<<"\n******Choose********\n1-Monster\n2-Human"<<endl;
            cin>>kindChoice;}
            while(kindChoice!=1&&kindChoice!=2);
        }
        // if he is a new guest
        if (firstChoice==1)
        {
            // if he is monster
            if(kindChoice==1)
            {
                cout<<"enter your name:"<<endl;
                cin>>name;
                // first i set the guest to new(monster or human) and at the end , i add him to Monster vector  as the guest may want to cancel the reservation before saving it
                newMonster.setUserName(name);
                newMonster.setId(MonsterGuests.size()+10);
                cout<<"Your UserName:  "<<newMonster.getUserName()<<"\nYour ID:  "<<newMonster.getID();

            }
            //if he is a human
            else if(kindChoice==2)
            {
                cout<<"enter your name:"<<endl;
                cin>>name;
                newHuman.setUserName(name);
                newHuman.setId(humanGuests.size()+100);
                cout<<"Your UserName:  "<<newHuman.getUserName()<<"\nYour ID:  "<<newHuman.getID();

            }
        }
        //*************************************************
        //if he is old user i ask him for it's id and search
        else if (firstChoice==2)
        {
            while(1)
            {
                cout<<"\nEnter your ID:"<<endl;
                cin>>id;
                int x=0;

                if(kindChoice==1)
                {
                    for(i=0; (i<MonsterGuests.size()); i++)
                    {
                        if(id==MonsterGuests[i].getID())
                        {
                            x=1;
                            break;
                        }
                    }
                }
                else if(kindChoice==2)
                {
                    for(i=0; (i<humanGuests.size()); i++)
                    {
                        if(id==humanGuests[i].getID())
                        {
                            x=1;
                            break;
                        }
                    }
                }
                if(x==1)
                {
                    cout<<"\nFound";
                    break;
                }
                else
                {
                    cout<<"\nNot Found";
                }
            }
        }
        //*********************************************************
        // if the receptionist want to see all the data
        else if(firstChoice==3)
        {
            cout<<"\nNumber of available monster rooms:"<<monsterRooms.getAvailableRooms()<<"\nNumber of unavailable monster rooms:"<<15-monsterRooms.getAvailableRooms();
            cout<<"\nNumber of available human rooms:"<<humanRooms.getAvailableRooms()<<"\nNumber of unavailable human rooms:"<<5-humanRooms.getAvailableRooms();
            cout<<"\n\n****Monster*****\n\n";
            for(int j=0; j<MonsterGuests.size(); j++)
            {
                cout<<"\nMonster name:"<<MonsterGuests[j].getUserName()<<"\nID:"<<MonsterGuests[j].getID()<<"\nRooms:"<<MonsterGuests[j].getRooms()<<"\nnights:"<<MonsterGuests[j].getNights()<<"\nTotalPrice:"<<MonsterGuests[j].getTotalCost();

            }
            cout<<"\n\n****Humans*****\n\n";
            for(int j=0; j<humanGuests.size(); j++)
            {
                cout<<"\nHuman name:"<<humanGuests[j].getUserName()<<"\nID:"<<humanGuests[j].getID()<<"\nRooms:"<<humanGuests[j].getRooms()<<"\nnights:"<<humanGuests[j].getNights()<<"\nTotalPrice:"<<humanGuests[j].getTotalCost();

            }
            int r;
            cout<<"\n\n1-back\n2-Exit";
            cin >>r;
            if(r==2)
                break;
            else
                continue;
        }else continue;
        //*******************************************
        //second choice
        while(1)
        {

            cout<< "\n******Choose**********\n1-New Reservation\n2-Extend Reservation\n3-Additional Reservation\n4-Cancel Reservation\n5-Exit And Save";


            cin>>serviceChoice;
            //new reservation
            if(serviceChoice==1)
            {
                cout<<"Enter The Number Of Rooms:";
                cin>>numberOfRooms;
                if(kindChoice==1)
                {
                    //check if there is available rooms or not
                    if(monsterRooms.getAvailableRooms()-numberOfRooms>=0)
                    {
                        cout<<"Available Rooms";
                        //if there is available rooms then make the reservation
                        monsterRooms.reservation(numberOfRooms);
                        newMonster.setRooms(numberOfRooms);
                        cout<<"\nEnter The Number Of Nights:";
                        cin>>numberOfNights;
                        newMonster.addCost(newMonster.getNightPrice()*numberOfNights*numberOfRooms);
                        newMonster.addNights(numberOfNights);
                        cout<<"\nRoomsNumber:"<<newMonster.getRooms()<<"\nNightsNumber:"<<newMonster.getNights()<<"\nTotal cost:"<<newMonster.getTotalCost();


                    }
                    else
                    {
                        cout << "No Available Rooms";

                    }
                }
                //the same this but if the guest is a human
                else if (kindChoice==2)
                {
                    if(humanRooms.getAvailableRooms()-numberOfRooms>=0)
                    {
                        cout<<"Available Rooms";
                        humanRooms.reservation(numberOfRooms);
                        newHuman.setRooms(numberOfRooms);
                        cout<<"\nEnter The Number Of Nights";
                        cin>>numberOfNights;
                        newHuman.addCost(newHuman.getNightPrice()*numberOfNights*numberOfRooms);
                        newHuman.addNights(numberOfNights);
                        cout<<"\nRoomsNumber:"<<newHuman.getRooms()<<"\n NightsNumber"<<newHuman.getNights()<<"\n Total cost"<<newHuman.getTotalCost();

                    }
                    else
                    {
                        cout << "No Available Rooms";

                    }

                }


            }
            //extend reservation
            else if( serviceChoice==2)
            {
                cout<<"Enter TheNumber of Extra Nights:";
                cin>>numberOfNights;

                if(kindChoice==1)
                {
                    newMonster.addNights(numberOfNights);
                    extraNightsCost=numberOfNights*newMonster.getNightPrice()*newMonster.getRooms();
                    cout<<"\nRoomsNumber:"<<newMonster.getRooms()<<"\nNightsNumber:"<<newMonster.getNights()<<"\nAdditional NightsNumber:"<<numberOfNights<<"\nNew Total cost:"<<extraNightsCost;
                    newMonster.addCost(extraNightsCost);
                }
                else if(kindChoice==2)
                {
                    newHuman.addNights(numberOfNights);
                    extraNightsCost=numberOfNights*newHuman.getNightPrice()*newHuman.getRooms();
                    cout<<"\nRoomsNumber:"<<newHuman.getRooms()<<"\nNightsNumber:"<<newHuman.getNights()<<"\nAdditional NightsNumber:"<<numberOfNights<<"\nNew Total cost:"<<extraNightsCost;
                    newHuman.addCost(extraNightsCost);
                }
            }
            //service
            else if(serviceChoice==3)
            {
                cout<<"\n***************Choose*********\n1-Dry Cleaning\n2-Spa\n3-Both";
                cin>>additionalService;
                //dry cleaning
                if(additionalService==1)
                {
                    //monster
                    if(kindChoice==1)
                    {
                        cout<<"\nCost Of Dry Cleaning:"<<newMonster.getCleanPrice();
                        newMonster.addCost(newMonster.getCleanPrice());
                    }
                    //human
                    else if(kindChoice==2)
                    {

                        cout<<"\nCost Of Dry Cleaning:"<<newHuman.getCleanPrice();
                        newHuman.addCost(newHuman.getCleanPrice());
                    }
                }
                //spa
                else if(additionalService==2)
                {
                    if(kindChoice==1)
                    {
                        cout<<"\nCost Of Spa:"<<newMonster.getSpaPrice();
                        newMonster.addCost(newMonster.getSpaPrice());
                    }
                    else if(kindChoice==2)
                    {

                        cout<<"\nCost Of Spa:"<<newHuman.getSpaPrice();
                        newHuman.addCost(newHuman.getSpaPrice());
                    }
                }
                //both spa and dry cleaning
                else if(additionalService==3)
                {
                    if(kindChoice==1)
                    {
                        cout<<"\nCost Of Spa:"<<newMonster.getSpaPrice()<<"Cost Of Dry Cleaning:"<<newMonster.getCleanPrice();
                        newMonster.addCost(newMonster.getSpaPrice()+newMonster.getCleanPrice());
                    }
                    else if(kindChoice==2)
                    {

                        cout<<"\nCost Of Spa:"<<newHuman.getSpaPrice()<<"\nCost Of Dry Cleaning:"<<newHuman.getCleanPrice();
                        newHuman.addCost(newHuman.getSpaPrice()+newHuman.getCleanPrice());
                    }
                }

            }
            //*********************************************************************
            //cancel the whole reservation
            else if (serviceChoice==4)
            {
                //if the guest is old , i just make his attributes(rooms , night ,total cost)=0
                if(firstChoice==2)
                {
                    if(kindChoice==1)
                    {
                        monsterRooms.reservation(MonsterGuests[i].getRooms()*-1);
                        MonsterGuests[i].setRooms(0);
                        MonsterGuests[i].addNights(MonsterGuests[i].getNights()*-1);
                        MonsterGuests[i].addCost(MonsterGuests[i].getTotalCost()*-1);
                        cout<<"You Canceled The Reservation";
                        break;
                    }
                    else if(kindChoice==2)
                    {
                        humanRooms.reservation(humanGuests[i].getRooms()*-1);
                        humanGuests[i].setRooms(0);
                        humanGuests[i].addNights(humanGuests[i].getNights()*-1);
                        humanGuests[i].addCost(humanGuests[i].getTotalCost()*-1);
                        cout<<"\nYou Canceled The Reservation\n";
                        break;

                    }

                }
                // but if the guest is new , i don't add him to the system and i make his rooms available again
                else if(firstChoice==1)
                {
                    if(kindChoice==1)
                    {
                        monsterRooms.reservation(newMonster.getRooms()*-1);
                    }
                    else if(kindChoice==2)
                    {
                        monsterRooms.reservation(newHuman.getRooms()*-1);
                    }
                    cout<<"\nYou Canceled The Reservation and You Won't be Saved !! Thanks\n";
                    break;
                }


            }
            // if he choose save ans exit
            else
            {
                if(firstChoice==1)
                {
                    if(kindChoice==1)
                    {
                        MonsterGuests.push_back(newMonster);
                        cout<<"\n<<Saved>>\n";
                        break;
                    }
                    else if(kindChoice==2)
                    {
                        humanGuests.push_back(newHuman);
                        cout<<"\n<<Saved>>\n";
                        break;
                    }
                }
                else if(firstChoice==2)
                {
                    // if he is old guest
                    if(kindChoice==1)
                    {
                        MonsterGuests[i].addCost(newMonster.getTotalCost());
                        MonsterGuests[i].addNights(newMonster.getNights());
                        MonsterGuests[i].setRooms(newMonster.getRooms());
                        cout<<"\n<<Saved>>\n";
                        break;
                    }
                    else if(kindChoice==2)
                    {
                        humanGuests[i].addCost(newHuman.getTotalCost());
                        humanGuests[i].addNights(newHuman.getNights());
                        humanGuests[i].setRooms(newHuman.getRooms());
                        cout<<"\n<<Saved>>\n";
                        break;
                    }
                }
            }

        }

    }


    return 0;
}
