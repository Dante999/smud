#include "directions.h"

Directions::Directions()
{
    //ctor
}

Directions::~Directions()
{
    //dtor
}


/*******************************************************************************
 * function
 *
 * @param
 *
 * @return  -1  parsing failed
 *
 ******************************************************************************/
int Directions::parseFromString(std::string direction)
{

    if( direction == "N" || direction == "n")
    {
        return NORTH;
    }
    else if(direction == "NO" || direction == "no")
    {
        return NORTH_EAST;
    }
    else if(direction == "NW" || direction == "nw")
    {
        return NORTH_WEST;
    }
    else if( direction == "S" || direction == "s")
    {
        return SOUTH;
    }
    else if(direction == "SO" || direction == "so")
    {
        return SOUTH_EAST;
    }
    else if(direction == "SW" || direction == "sw")
    {
        return SOUTH_WEST;
    }
    else if(direction == "O" || direction == "o")
    {
        return EAST;
    }
    else if(direction == "W" || direction == "w")
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
