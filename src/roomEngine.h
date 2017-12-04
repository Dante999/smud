#ifndef ROOMENGINE_H
#define ROOMENGINE_H

#include <string>
#include <map>

#include "room.h"
#include "livingOrganism.h"



class RoomEngine
{
public:
    RoomEngine();
    virtual ~RoomEngine();

    static Room *enterRoom(LivingOrganism *organism, std::string roomPath);
    static Room *leaveRoom(LivingOrganism *organism, std::string roomPath);
    static Room *getRoom(std::string roomPath);

};

#endif // ROOMENGINE_H
