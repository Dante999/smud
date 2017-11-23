#include "RoomEngine.h"
#include "DataService.h"
#include "Logger.h"


#define LOG_NAME    "RoomEngine"

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
Room* RoomEngine::enterRoom(LivingOrganism* organism, std::string roomPath)
{
    if(m_loadedRooms.find(roomPath) == m_loadedRooms.end())
    {
        Logger::println(LOG_INFO, LOG_NAME, "loading '" + roomPath);

        m_loadedRooms[roomPath] = DataService::loadRoom(roomPath);
    }

    Room *room = m_loadedRooms.find(roomPath)->second;

    room->addLivingOrganism(organism);

    return room;
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
    if(m_loadedRooms.find(roomPath) != m_loadedRooms.end())
    {

    Room *room = m_loadedRooms.find(roomPath)->second;
    room->removeLivingOrganism(player);

    return room;
    }
    else
    {
        return 0;
    }

}
