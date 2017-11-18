#ifndef ROOMENGINE_H
#define ROOMENGINE_H

#include <string>
#include <map>

#include "../interfaces/Room.h"
#include "../interfaces/LivingOrganism.h"



class RoomEngine
{
    public:
        RoomEngine();
        virtual ~RoomEngine();

        static Room *enterRoom(LivingOrganism *player, std::string roomPath);
        static Room *goDirection(LivingOrganism* player, std::string roomPath, int direction);
        static Room *leaveRoom(LivingOrganism *player, std::string roomPath);

    protected:

    private:



};

#endif // ROOMENGINE_H
