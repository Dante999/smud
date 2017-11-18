#include "Room.h"
#include "../utils/ConsoleFormatter.h"
#include "Directions.h"


#define INDENT  15



Room::Room()
{

}

Room::~Room()
{
    //dstor
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

    std::map<int, std::string>::iterator it = m_exits.begin();

    while(it != m_exits.end())
    {
        int dir = it->first;
        std::string direction   = Directions::parseToString(dir);
        std::string roomName    = it->second;

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

        it++;
    }

    result += ConsoleFormatter::horizontalLine();


    return result;
}


void Room::addExit(int direction, std::string room)
{
    m_exits[direction] = room;
}


std::string Room::getExit(int direction)
{
    if(m_exits.find(direction) != m_exits.end())
    {
        return m_exits.find(direction)->second;
    }
    else
    {
        return 0;
    }
}



