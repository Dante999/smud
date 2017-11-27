#include "GameEngine.h"

#include "StringHelper.h"
#include "RoomEngine.h"
#include "Room.h"
#include "Directions.h"
#include "DataService.h"


/*******************************************************************************
 * constructor
 *
 * @param   none
 *
 * @return  none
 *
 ******************************************************************************/
GameEngine::GameEngine()
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
GameEngine::~GameEngine()
{
    //dtor
}


/*******************************************************************************
 * moves the player into the given direction
 *
 * @param   player      the player who moves
 *
 * @param   direction   the direction where the player should move
 *
 * @return  none
 *
 ******************************************************************************/
void GameEngine::movePlayer(Player* player, int direction)
{
    Room *room = RoomEngine::getRoom(player->getRoomPath());
    std::string roomPath = room->getExit(direction);

    if(roomPath != "")
    {
        room->removeLivingOrganism(player);
        player->setRoomPath(roomPath);

        room = RoomEngine::enterRoom(player, player->getRoomPath());
        player->println(room->toString());
    }
    else
    {
        player->println("ungueltige Eingabe");
    }
}


/*******************************************************************************
 * function
 *
 * @param
 *
 * @return
 *
 ******************************************************************************/
void GameEngine::exploreDetail(Player *player, GameObject *object, std::string detailName)
{
    std::string detail = object->getDetail(detailName);

    if(detail != "")
    {
        player->println(detail);
    }
    else
    {
        player->println("so etwas siehst du dort nicht");
    }
}


/*******************************************************************************
 * function
 *
 * @param
 *
 * @return
 *
 ******************************************************************************/
void GameEngine::exploreObject(Player* player, GameObject* object)
{
    player->print(object->getDescription());
}


/*******************************************************************************
 * function
 *
 * @param
 *
 * @return
 *
 ******************************************************************************/
void GameEngine::exploreRoom(Player* player)
{
    Room *room = RoomEngine::getRoom(player->getRoomPath());

    player->print(room->toString());
}



void GameEngine::savePlayer(Player *player)
{
    DataService::savePlayer(player);
}


/*******************************************************************************
 * prints the help screen to the given player
 *
 * @param   player      the player for which the help screen should printed
 *
 * @return  none
 *
 ******************************************************************************/
void GameEngine::printHelp(Player *player)
{
    std::string result = "";

    result += StringHelper::horizontalLine();
    result += "Dies ist eine Uebersicht aller Befehle\n";
    result += "\n";
    result += "Bewegungen:\n";
    result += "===========\n";
    result += "   n       -> gehe nach Norden\n";
    result += "   o       -> gehe nach Osten\n";
    result += "   s       -> gehe nach Sueden\n";
    result += "   w       -> gehe nach Westen\n";
    result += "   no      -> gehe nach Nord-Osten\n";
    result += "   nw      -> gehe nach Nord-Westen\n";
    result += "   so      -> gehe nach Sued-Osten\n";
    result += "   sw      -> gehe nach Sued-Westen\n";
    result += "\n";
    result += "Umgebung:\n";
    result += "=========\n";
    result += "   schau          -> zeige informationen zur Umgebung\n";
    result += "   schau <detail> -> untersuche Detail im Raum\n";
    result += "";
    result += "\n";

    player->println(result);

}




