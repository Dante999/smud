#include "RoomEngine.h"
#include "../persistence/DataService.h"


        static std::map<std::string,Room*> m_loadedRooms;

RoomEngine::RoomEngine()
{
    //ctor
}

RoomEngine::~RoomEngine()
{
    //dtor
}

Room* RoomEngine::enterRoom(LivingOrganism* player, std::string roomPath)
{
    if(m_loadedRooms.find(roomPath) == m_loadedRooms.end())
    {
        m_loadedRooms[roomPath] = DataService::loadRoom(roomPath);
    }

    return m_loadedRooms.find(roomPath)->second;
}



Room* RoomEngine::leaveRoom(LivingOrganism* player, std::string roomPath)
{
    return 0;
}
