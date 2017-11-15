#include "Room.h"
#include "../utils/ConsoleFormatter.h"

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
    result += ConsoleFormatter::horizontalLine();

    return result;
}
