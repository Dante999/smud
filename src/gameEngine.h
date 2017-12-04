#ifndef INTERACTIONENGINE_H
#define INTERACTIONENGINE_H

#include <string>
#include "player.h"
#include "livingOrganism.h"

class GameEngine
{
public:
    GameEngine();
    virtual ~GameEngine();

    static bool walk(LivingOrganism *organism, int direction);
    static void exploreDetail(Player *player, GameObject *object, std::string detailName);
    static void exploreObject(Player *player, GameObject *object);
    static void exploreRoom(Player *player);
    static void savePlayer(Player *player);
    static void printHelp(Player *player);



protected:

private:

};

#endif // INTERACTIONENGINE_H
