#include "livingOrganism.h"

LivingOrganism::LivingOrganism()
{
    m_level = 1;
    m_gender = MALE;

    m_init_dextery  = 10;
    m_init_magic    = 10;
    m_init_strength = 10;
    m_init_vitality = 10;
}

LivingOrganism::~LivingOrganism()
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
std::string LivingOrganism::getRoomPath()
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
void LivingOrganism::setRoomPath(std::string roomPath)
{
    m_roomPath = roomPath;
}
