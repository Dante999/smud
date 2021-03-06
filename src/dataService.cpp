#include "dataService.h"

#include <iostream>
#include "pugixml.hpp"
#include "directions.h"
#include "logger.h"



#define LOG_NAME    "DataService"


#define BASEPATH "../gamedata/gameobjects"

DataService::DataService()
{
    //ctor
}

DataService::~DataService()
{
    //dtor
}

Room *DataService::loadRoom(std::string filepath)
{

    filepath = BASEPATH + filepath;

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

        for (pugi::xml_node item = root.child("item"); item; item = item.next_sibling("item"))
        {
            std::string filepath = item.child_value("filepath");
            room->addItem(DataService::loadItem(filepath));

        }

        Logger::println(LOG_INFO, LOG_NAME, "room successfully loaded from path '" + filepath + "'");
    }
    else
    {
        room->setName("error loading room");
        room->setDescription(filepath);

        Logger::println(LOG_ERROR, LOG_NAME, "room failed to load from path '" + filepath + "'");


    }

    return room;
}

Player* DataService::loadPlayer(std::string filepath)
{
    filepath = BASEPATH + filepath;

    pugi::xml_document doc;

    pugi::xml_parse_result result = doc.load_file(filepath.c_str() );
    pugi::xml_node root = doc.document_element();

    Player *player = new Player(filepath);

    if( result.status == pugi::status_ok )
    {
        player->setName(root.child_value("name"));
        player->setDescription(root.child_value("description"));
        player->setRoomPath(root.child_value("room"));

        Logger::println(LOG_INFO, LOG_NAME, "player successfully loaded from path '" + filepath + "'");
    }
    else
    {
        player->setName("error loading player");
        player->setDescription(filepath);

        Logger::println(LOG_ERROR, LOG_NAME, "player failed to load from path '" + filepath + "'");
    }

    return player;
}



Item *DataService::loadItem(std::string filepath)
{
    Logger::println(LOG_INFO, LOG_NAME, "loading item from path '" + filepath + "'");

    Item *item = new Item();

    item->setName("testItem");

    return item;
}



void DataService::savePlayer(Player* player)
{
    std::string path = BASEPATH;

    path += "/players/" + player->getName() + ".xml";

    pugi::xml_document doc;

    pugi::xml_node gameobject = doc.append_child("gameobject");

    gameobject.append_attribute("type") = "player";

    pugi::xml_node name = gameobject.append_child("name");
    name.append_child(pugi::node_pcdata).set_value(player->getName().c_str());

    pugi::xml_node description = gameobject.append_child("description");
    description.append_child(pugi::node_pcdata).set_value(player->getDescription().c_str());

    pugi::xml_node room = gameobject.append_child("room");
    room.append_child(pugi::node_pcdata).set_value(player->getRoomPath().c_str());

    doc.save_file(path.c_str());
}


