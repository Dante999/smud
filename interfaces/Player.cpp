#include "Player.h"
#include "../utils/ConsoleFormatter.h"


Player::Player()
{
    m_roomPath = "/rooms/winkelgasse/tropfender_kessel.xml";
}

Player::~Player()
{
    //dtor
}


std::string Player::getRoomPath()
{
    return m_roomPath;
}


void Player::setRoomPath(std::string roomPath)
{
    m_roomPath = roomPath;
}


std::string Player::toString()
{
    std::string result = "";

    result += ConsoleFormatter::horizontalLine();
    result += ConsoleFormatter::textLine(m_name);
    result += ConsoleFormatter::horizontalLine();
    result += ConsoleFormatter::textBlock(m_description);
    result += ConsoleFormatter::horizontalLine();


    return result;
}
