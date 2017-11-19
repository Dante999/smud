#include "Session.h"
#include "../persistence/DataService.h"
#include "RoomEngine.h"
#include "Player.h"
#include "Directions.h"
#include "InteractionEngine.h"

Session::Session(std::string playerName)
{
    std::string playerPath = "/players/" + playerName + ".xml";
    m_player = DataService::loadPlayer(playerPath);

    m_player->println(m_player->toString());

    Room *room = RoomEngine::enterRoom(m_player, m_player->getRoomPath());

    m_player->print(room->toString());

}



Session::~Session()
{
    // save PlayerStats
    delete m_player;
}


void Session::execute()
{
    std::string input = m_player->readInput();

    InteractionEngine::interact(m_player, input);




//    Room *room = RoomEngine::enterRoom(m_player, m_player->getRoomPath());
//
//    m_player->print(room->toString());
//
//    std::string roomPath    = "";
//    std::string direction   = m_player->readInput();
//
//    int dir = Directions::parseFromString(direction);
//
//    roomPath = room->getExit(dir);
//
//    if(roomPath != "")
//    {
//        room = RoomEngine::enterRoom(m_player, roomPath);
//        m_player->setRoomPath(roomPath);
//    }
//    else{
//        m_player->println("ungueltige Eingabe");
//    }

}
