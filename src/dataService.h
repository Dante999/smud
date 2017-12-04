#ifndef DATASERVICE_H
#define DATASERVICE_H

#include <string>
#include "room.h"
#include "player.h"

class DataService
{
public:
    DataService();
    virtual ~DataService();

    static Room     *loadRoom(std::string filepath);
    static Player   *loadPlayer(std::string filepath);
    static Item     *loadItem(std::string filepath);

    static void savePlayer(Player *player);

};

#endif // DATASERVICE_H
