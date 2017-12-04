#include "session.h"
#include "dataService.h"
#include "roomEngine.h"
#include "player.h"
#include "directions.h"
#include "gameEngine.h"
#include "interpreter.h"

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

    Interpreter::parse(m_player, input);
}
