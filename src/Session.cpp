#include "Session.h"
#include "DataService.h"
#include "RoomEngine.h"
#include "Player.h"
#include "Directions.h"
#include "InteractionEngine.h"
#include "CommandParser.h"

Session::Session(std::string playerName)
{
    std::string playerPath    = "/players/" + playerName + ".xml";
    m_player        = DataService::loadPlayer(playerPath);

    Room *room = RoomEngine::enterRoom(m_player, m_player->getRoomPath());

    m_player->println(m_player->toString());
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

    CommandParser::parse(m_player, input);
}
