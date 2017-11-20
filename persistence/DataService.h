#ifndef DATASERVICE_H
#define DATASERVICE_H

#include <string>
#include "Room.h"
#include "Player.h"

class DataService
{
    public:
        DataService();
        virtual ~DataService();

    static Room     *loadRoom(std::string roomPath);
    static Player   *loadPlayer(std::string playerPath);

    static void savePlayer(Player *player);


    protected:

    private:
};

#endif // DATASERVICE_H
