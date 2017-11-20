#include "RoomEngine.h"
#include "../persistence/DataService.h"

/*******************************************************************************
 * TODO:
 * - delete the rooms again, when no action happens in there for like 30 minutes
 *
 *
 ******************************************************************************/








static std::map<std::string,Room*> m_loadedRooms;


/*******************************************************************************
 * constructor
 *
 * @param   none
 *
 * @return  none
 *
 ******************************************************************************/
RoomEngine::RoomEngine()
{
    //ctor
}


/*******************************************************************************
 * destructor
 *
 * @param   none
 *
 * @return  none
 *
 ******************************************************************************/
RoomEngine::~RoomEngine()
{
    //dtor
}


/*******************************************************************************
 * function
 *
 * @param
 *
 * @return
 *
 ******************************************************************************/
Room* RoomEngine::enterRoom(LivingOrganism* player, std::string roomPath)
{
    if(m_loadedRooms.find(roomPath) == m_loadedRooms.end())
    {
        m_loadedRooms[roomPath] = DataService::loadRoom(roomPath);
    }

    return m_loadedRooms.find(roomPath)->second;
}


/*******************************************************************************
 * function
 *
 * @param
 *
 * @return
 *
 ******************************************************************************/
Room* RoomEngine::getRoom(std::string roomPath)
{
    if(m_loadedRooms.find(roomPath) == m_loadedRooms.end())
    {
        m_loadedRooms[roomPath] = DataService::loadRoom(roomPath);
    }

    return m_loadedRooms.find(roomPath)->second;
}


/*******************************************************************************
 * function
 *
 * @param
 *
 * @return
 *
 ******************************************************************************/
Room* RoomEngine::leaveRoom(LivingOrganism* player, std::string roomPath)
{
    return 0;
}
