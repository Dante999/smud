#include "DataService.h"

#include <iostream>
#include "pugixml.hpp"
#include "Directions.h"


#define BASEPATH "/home/dante999/Git/smud/gamedata/gameobjects"

DataService::DataService()
{
    //ctor
}

DataService::~DataService()
{
    //dtor
}

Room *DataService::loadRoom(std::string roomPath)
{

    std::string filepath = BASEPATH + roomPath;

    pugi::xml_document doc;



    pugi::xml_parse_result result = doc.load_file(filepath.c_str() );
    pugi::xml_node root = doc.document_element();

    //std::cout << "Load result: " << result.description() << std::endl;
    Room *room = new Room();


    if( result.status == pugi::status_ok )
    {
        room->setName(root.child_value("name"));
        room->setDescription(root.child_value("description"));


        for (pugi::xml_node roomExit = root.child("exit"); roomExit; roomExit = roomExit.next_sibling("exit"))
        {
            int direction = Directions::parseFromString(roomExit.child_value("direction"));

            room->addExit(direction, roomExit.child_value("room"));
        }

        for (pugi::xml_node detail = root.child("detail"); detail; detail = detail.next_sibling("detail"))
        {
            std::string detailDescription = detail.child_value("description");

            for (pugi::xml_node name = detail.child("name"); name; name = name.next_sibling("name"))
            {
                room->addDetail(name.child_value(), detailDescription);
            }
        }
    }
    else
    {
        room->setName("error loading room");
        std::cout << "path: " << filepath << std::endl;
        room->setDescription(filepath);
    }

    return room;
}

Player* DataService::loadPlayer(std::string playerPath)
{
    std::string filepath = BASEPATH + playerPath;

    pugi::xml_document doc;

    pugi::xml_parse_result result = doc.load_file(filepath.c_str() );
    pugi::xml_node root = doc.document_element();

    //std::cout << "Load result: " << result.description() << std::endl;
    Player *player = new Player(playerPath);


    if( result.status == pugi::status_ok )
    {
        player->setName(root.child_value("name"));
        player->setDescription(root.child_value("description"));
        player->setRoomPath(root.child_value("room"));
    }
    else
    {
        player->setName("error loading player");
        player->setDescription(filepath);
    }

    return player;
}

void DataService::savePlayer(Player* player)
{

}


