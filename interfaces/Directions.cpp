#include "Directions.h"

Directions::Directions()
{
    //ctor
}

Directions::~Directions()
{
    //dtor
}

int Directions::parseFromString(std::string direction)
{

    if(direction == "N")
    {
        return NORTH;
    }
    else if(direction == "NO")
    {
        return NORTH_EAST;
    }
    else if(direction == "NW")
    {
        return NORTH_WEST;
    }
    else if( direction == "S")
    {
        return SOUTH;
    }
    else if(direction == "SO")
    {
        return SOUTH_EAST;
    }
    else if(direction == "SW")
    {
        return SOUTH_WEST;
    }
    else if(direction == "O")
    {
        return EAST;
    }
    else if(direction == "W")
    {
        return WEST;
    }
    else
    {
        return -1;
    }

}


std::string Directions::parseToString(int direction)
{
    switch(direction)
    {
        case NORTH:
            return "Norden";
            break;

        case NORTH_EAST:
            return "Nord-Osten";
            break;

        case NORTH_WEST:
            return "Nord-Westen";
            break;

        case SOUTH:
            return "Sueden";
            break;

        case SOUTH_EAST:
            return "Sued-Osten";
            break;

        case SOUTH_WEST:
            return "Sued-Westen";
            break;

        case WEST:
            return "Westen";
            break;

        case EAST:
            return "Osten";
            break;

        default:
            return "?";
            break;
    }
}
