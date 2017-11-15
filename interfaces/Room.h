#ifndef ROOM_H
#define ROOM_H

#include "GameObject.h"

class Room : public GameObject
{
    public:
        Room();
        virtual ~Room();

        std::string toString();

    protected:

    private:
};

#endif // ROOM_H
