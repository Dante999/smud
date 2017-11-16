#include "DataService.h"

#include <iostream>
#include "pugixml.hpp"
#include "Directions.h"


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

    std::string filepath = "/home/dante999/Git/smud/gamedata/gameobjects/rooms/" + roomPath;

    pugi::xml_document doc;
    std::string name        = "";
    std::string description = "";


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

    }
    else
    {
        room->setName("error loading room");
        room->setDescription("no description");
    }

    return room;
}
