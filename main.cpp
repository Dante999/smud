#include <iostream>



#include "persistence/DataService.h"
#include "RoomEngine.h"
#include "Directions.h"


int main()
{
    std::cout << "------------" << std::endl;
    std::cout << "Hello world!" << std::endl;
    std::cout << "------------" << std::endl;
    std::cout << std::endl;

    Player *player = DataService::loadPlayer("/players/dante999.xml");

    std::cout << player->toString() << std::endl;


    std::string roomPath = player->getRoomPath();

    Room *room = RoomEngine::enterRoom(player, roomPath);

    std::cout << room->toString();


    while(1)
    {
        std::string direction;

        std::cout << ">>";
        std::cin >>  direction;
        std::cout << std::endl;

        int dir = Directions::parseFromString(direction);

        roomPath = room->getExit(dir);

        room = RoomEngine::enterRoom(player, roomPath);

        std::cout << room->toString();



    }



    delete player;
//    Room *room = DataService::loadRoom("/rooms/winkelgasse/zum_tropfenden_kessel.xml");
//
//    std::cout << room->toString() << std::endl;
//
//    delete room;
//
//    room = DataService::loadRoom("/rooms/winkelgasse/winkelgassenstrasse_1.xml");
//    std::cout << room->toString() << std::endl;
//
//    delete room;



    return 0;
}




