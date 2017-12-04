#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "livingOrganism.h"

class Player : public LivingOrganism
{
    public:
        Player(std::string playerPath);
        virtual ~Player();

        std::string toString();

        std::string getPlayerPath();


        void print(std::string printToUser);
        void println(std::string printToUser);
        std::string readInput();

    protected:

    private:
        std::string m_playerPath;
        std::string m_password;
        std::string m_roomPath;

};

#endif // PLAYER_H
