#include "Room.h"
#include "../utils/ConsoleFormatter.h"
#include "Directions.h"


#define INDENT  15



Room::Room()
{
    //ctor
}

Room::~Room()
{
//
//    for(int i = m_roomExits.size(); i>=0; i--)
//    {
//        roomExit *exit = &m_roomExits[i];
//
//        delete exit;
//
//    }

    m_roomExits.clear();


}

std::string Room::toString()
{
    std::string result = "";

    result += ConsoleFormatter::horizontalLine();
    result += ConsoleFormatter::textLine(m_name);
    result += ConsoleFormatter::horizontalLine();
    result += ConsoleFormatter::textBlock(m_description);
    result += ConsoleFormatter::textLine("");
    result += ConsoleFormatter::textLine("Es gibt folgende Ausgaenge:");

    for(size_t i=0; i < m_roomExits.size(); i++)
    {
        int dir = m_roomExits.at(i).direction;
        std::string direction   = Directions::parseToString(dir);
        std::string roomName    = m_roomExits.at(i).roomName;

        // 11
        std::string line = "";

        line += "   ";
        line += direction;

        if(line.length() < INDENT)
        {
            for(size_t j=0; j<line.length()-INDENT; j++ )
            {
                line += " ";
            }

        }

        line += " -> ";
        line += roomName;

        result += ConsoleFormatter::textLine(line);
    }

    result += ConsoleFormatter::horizontalLine();


    return result;
}


void Room::addExit(int direction, std::string room)
{
    roomExit exit;

    exit.direction  = direction;
    exit.roomName   = room;

    m_roomExits.push_back(exit);

//    roomExit *exit = new roomExit;

//    exit->direction = direction;
//    exit->roomName  = room;
//
//    m_roomExits.push_back(*exit);
}
