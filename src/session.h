#ifndef SESSION_H
#define SESSION_H

#include <string>
#include "player.h"



class Session
{
    public:
        Session(std::string playerName);
        virtual ~Session();

        void execute();

    protected:


    private:
        Player *m_player;
};

#endif // SESSION_H
