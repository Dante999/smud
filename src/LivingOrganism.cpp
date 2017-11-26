#include "LivingOrganism.h"

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
