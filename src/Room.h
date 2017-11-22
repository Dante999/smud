#ifndef ROOM_H
#define ROOM_H

#include "GameObject.h"
#include "vector"
#include "map"

class Room : public GameObject
{
    private:
//        struct roomExit {int direction; std::string roomName; };

    public:
        Room();
        virtual ~Room();

        std::string toString();

        void addExit(int direction, std::string roomPath);

        std::string getExit(int direction);


    protected:

    private:
        std::map<int,std::string> m_exits;

};

#endif // ROOM_H
