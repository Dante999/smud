#ifndef ROOM_H
#define ROOM_H

#include "GameObject.h"
#include "vector"

class Room : public GameObject
{
    private:
        struct roomExit {
            int direction;
            std::string roomName;
        };

        std::vector<roomExit> roomExits;


    public:
        Room();
        virtual ~Room();

        std::string toString();
        void addExit(int direction, std::string roomName);


    protected:

    private:
};

#endif // ROOM_H
