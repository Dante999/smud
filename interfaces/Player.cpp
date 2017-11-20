#include "Player.h"
#include <iostream>

#include "../utils/ConsoleFormatter.h"


/*******************************************************************************
 * constructor
 *
 * @param   none
 *
 * @return  none
 *
 ******************************************************************************/
Player::Player(std::string playerPath)
{
    m_playerPath = playerPath;
    m_roomPath = "/rooms/winkelgasse/tropfender_kessel.xml";
}


/*******************************************************************************
 * destructor
 *
 * @param   none
 *
 * @return  none
 *
 ******************************************************************************/
Player::~Player()
{
    //dtor
}


/*******************************************************************************
 * returns the roomPath, where the player is currently
 *
 * @param   none
 *
 * @return  current roomPath
 *
 ******************************************************************************/
std::string Player::getRoomPath()
{
    return m_roomPath;
}


/*******************************************************************************
 * sets the roomPath, where the player is currently
 *
 * @param   roomPath    path to the room
 *
 * @return  none
 *
 ******************************************************************************/
void Player::setRoomPath(std::string roomPath)
{
    m_roomPath = roomPath;
}


/*******************************************************************************
 * sends the content to the player (without at the end)
 *
 * @param   printToUser     the text which should be shown
 *
 * @return  none
 *
 ******************************************************************************/
void Player::print(std::string printToUser)
{
    std::cout << printToUser;
}


/*******************************************************************************
 * sends the content to the player (with a newline at the end)
 *
 * @param   printToUser     the text which should be shown
 *
 * @return  none
 *
 ******************************************************************************/
void Player::println(std::string printToUser)
{
    std::cout << printToUser << std::endl;
}


/*******************************************************************************
 * reads player inputs
 *
 * @param   none
 *
 * @return  the player input
 *
 ******************************************************************************/
std::string Player::readInput()
{
    std::string input;

    print(">>");
    //std::cin >> input;
    getline (std::cin, input);
    println("");
    return input;
}


/*******************************************************************************
 * returns the player-info as a string
 *
 * @param   none
 *
 * @return  the player-info as a string
 *
 ******************************************************************************/
std::string Player::toString()
{
    std::string result = "";

    result += ConsoleFormatter::horizontalLine();
    result += ConsoleFormatter::textLine(this->getName());
    result += ConsoleFormatter::horizontalLine();
    result += ConsoleFormatter::textBlock(this->getDescription());
    result += ConsoleFormatter::horizontalLine();

    return result;
}
