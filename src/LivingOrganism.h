#ifndef LIVINGORGANISM_H
#define LIVINGORGANISM_H

//#include "Gender.h"
#include "GameObject.h"

class LivingOrganism : public GameObject
{
    public:
        LivingOrganism();
        virtual ~LivingOrganism();

    protected:
        int m_level;
//        gender m_gender;
        int m_init_strength;
        int m_init_dextery;
        int m_init_magic;
        int m_init_vitality;

    private:
};

#endif // LIVINGORGANISM_H
