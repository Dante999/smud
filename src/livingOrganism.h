#ifndef LIVINGORGANISM_H
#define LIVINGORGANISM_H

#include "gender.h"
#include "gameObject.h"

class LivingOrganism : public GameObject
{
    public:
        LivingOrganism();
        virtual ~LivingOrganism();

        std::string getRoomPath();
        void setRoomPath(std::string roomPath);


    protected:
        int m_level;
        gender m_gender;
        int m_init_strength;
        int m_init_dextery;
        int m_init_magic;
        int m_init_vitality;

    private:
        std::string m_roomPath;
};

#endif // LIVINGORGANISM_H
