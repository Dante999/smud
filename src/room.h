#ifndef ROOM_H
#define ROOM_H

#include "gameObject.h"
#include "itemstorage.h"
#include "player.h"
#include "item.h"
#include "vector"
#include "map"

class Room : public GameObject, public ItemStorage
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
