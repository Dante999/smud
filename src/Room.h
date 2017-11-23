#ifndef ROOM_H
#define ROOM_H

#include "GameObject.h"
#include "Player.h"
#include "vector"
#include "map"

class Room : public GameObject
{
    private:
//        struct roomExit {int direction; std::string roomName; };

    public:
        Room();
        virtual ~Room();

        std::string toString();

        void addExit(int direction, std::string roomPath);

        std::string getExit(int direction);

        void addLivingOrganism(LivingOrganism *organism);
        void removeLivingOrganism(LivingOrganism *organism);
        void showMessage(std::string message);

    protected:

    private:
        std::map<int,std::string> m_exits;
        std::map<std::string, LivingOrganism*> m_livingOrganismMap;

};

#endif // ROOM_H
