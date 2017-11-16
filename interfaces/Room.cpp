#include "Room.h"
#include "../utils/ConsoleFormatter.h"
#include "Directions.h"



Room::Room()
{
    //ctor
}

Room::~Room()
{
    //dtor
}

std::string Room::toString()
{
    std::string result = "";

    result += ConsoleFormatter::horizontalLine();
    result += ConsoleFormatter::caption(this->name);
    result += ConsoleFormatter::horizontalLine();
    result += ConsoleFormatter::text(this->description);
    result += ConsoleFormatter::caption("");
    result += ConsoleFormatter::caption("Es gibt folgende Ausgaenge:");

    for(size_t i=0; i < this->roomExits.size(); i++)
    {
        std::string line = "   " + Directions::parseToString(roomExits.at(i).direction) + " -> " + roomExits.at(i).roomName;
        result += ConsoleFormatter::caption(line);
    }

    result += ConsoleFormatter::horizontalLine();


    return result;
}


void Room::addExit(int direction, std::string room)
{
    roomExit *exit = new roomExit;

    exit->direction = direction;
    exit->roomName = room;

    this->roomExits.push_back(*exit);
}
