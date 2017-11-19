#include "InteractionEngine.h"

#include "RoomEngine.h"
#include "Room.h"
#include "Directions.h"

/*******************************************************************************
 * constructor
 *
 * @param   none
 *
 * @return  none
 *
 ******************************************************************************/
InteractionEngine::InteractionEngine()
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
InteractionEngine::~InteractionEngine()
{
    //dtor
}


void InteractionEngine::interact(Player *player, std::string userInput)
{
    int dir = Directions::parseFromString(userInput);

    if(dir != -1)
    {
        movePlayer(player, dir);
    }

    else
    {
         Room *room = RoomEngine::enterRoom(player, player->getRoomPath());

         exploreDetail(player, room, "tom");
    }
}


void InteractionEngine::movePlayer(Player* player, int direction)
{
    Room *room = RoomEngine::enterRoom(player, player->getRoomPath());
    std::string roomPath = room->getExit(direction);

    if(roomPath != "")
    {
        room = RoomEngine::enterRoom(player, roomPath);
        player->setRoomPath(roomPath);
        player->println(room->toString());
    }
    else{
        player->println("ungueltige Eingabe");
    }
}


void InteractionEngine::exploreDetail(Player *player, GameObject *object, std::string detailName)
{
    std::string detail = object->getDetail(detailName);

    if(detail != "")
    {
        player->println(detail);
    }
    else{
        player->println("so etwas siehst du dort nicht");
    }
}




