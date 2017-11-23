#include "Room.h"
#include "StringHelper.h"
#include "Directions.h"


#define INDENT  15


/*******************************************************************************
 * constructor
 *
 * @param   none
 *
 * @return  none
 *
 ******************************************************************************/
Room::Room()
{
    //cstor
}


/*******************************************************************************
 * destructor
 *
 * @param   none
 *
 * @return  none
 *
 ******************************************************************************/
Room::~Room()
{
    //dstor
}


/*******************************************************************************
 * add a exit to the room
 *
 * @param   direction   the direction of the exit (use defines in Directions)
 *
 * @param   roomPath    the path to the room, where the exit goes
 *
 * @return  none
 *
 ******************************************************************************/
void Room::addExit(int direction, std::string roomPath)
{
    m_exits[direction] = roomPath;
}


/*******************************************************************************
 * returns the roomPath of an exit
 *
 * @param   direction   the direction from which you want the rommPath
 *
 * @return  the roomPath in the given direction, the path is empty if the
 *          direction does not have an exit
 *
 ******************************************************************************/
std::string Room::getExit(int direction)
{
    if(m_exits.find(direction) != m_exits.end())
    {
        return m_exits.find(direction)->second;
    }
    else
    {
        return "";
    }
}


void Room::addLivingOrganism(LivingOrganism* organism)
{
    m_livingOrganismMap[organism->getId()] = organism;

    showMessage(organism->getName() + " betritt den raum");
}


void Room::removeLivingOrganism(LivingOrganism* organism)
{
    showMessage("Spieler " + organism->getName() + " verlaesst den raum");
    m_livingOrganismMap.erase(organism->getId());
}


void Room::showMessage(std::string message)
{
    std::map<std::string,LivingOrganism*>::iterator it;
    Player *player = 0;

    for (it=m_livingOrganismMap.begin(); it!=m_livingOrganismMap.end(); ++it)
    {
        player = dynamic_cast<Player*>(it->second);

        if(player != 0)
        {
            player->println(message);
        }

    }
}

/*******************************************************************************
 * returns the room-information as a string
 *
 * @param   none
 *
 * @return  the room information as a string
 *
 ******************************************************************************/
std::string Room::toString()
{
    std::string result = "";

    result += StringHelper::horizontalLine();
    result += StringHelper::textLine(this->getName());
    result += StringHelper::horizontalLine();
    result += StringHelper::textBlock(this->getDescription());
    result += StringHelper::textLine("");
    result += StringHelper::textLine("Es gibt folgende Ausgaenge:");

    std::map<int, std::string>::iterator it = m_exits.begin();

    while(it != m_exits.end())
    {
        int dir = it->first;
        std::string direction   = Directions::parseToString(dir);
        std::string roomName    = it->second;

        size_t pos = roomName.find_last_of('/');

        if( pos > 0)
        {
            roomName.erase(0,pos+1);
        }

        roomName.erase(roomName.find_last_of('.'), 4);

        while(roomName.find ('_') != std::string::npos)
        {
            roomName.replace(roomName.find('_'), 1, " ");
        }

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

        result += StringHelper::textLine(line);

        it++;
    }

    result += StringHelper::horizontalLine();


    return result;
}

