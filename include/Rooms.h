#ifndef ROOMS_H
#define ROOMS_H


class Rooms
{
    public:
        Rooms(int rooms);
        virtual ~Rooms();
        void reservation(int roomsNumber);
        int getAvailableRooms();

    protected:

    private:
    int availableRooms;
};

#endif // ROOMS_H
