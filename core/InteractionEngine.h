#ifndef INTERACTIONENGINE_H
#define INTERACTIONENGINE_H

#include <string>
#include "Player.h"

#define ACTION_MOVE     0
#define ACTION_EXPLORE  1




class InteractionEngine
{
    public:
        InteractionEngine();
        virtual ~InteractionEngine();

        static void interact(Player *player, std::string userInput);



    protected:

    private:
        static void movePlayer(Player *player, int direction);
        static void exploreDetail(Player *player, GameObject *object, std::string detailName);
};

#endif // INTERACTIONENGINE_H
