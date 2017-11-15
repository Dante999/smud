#include "DataService.h"

#include <iostream>
#include "pugixml.hpp"



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

    if( result.status == pugi::status_ok )
    {
        name        = root.child_value("name");
        description = root.child_value("description");
    }
    else
    {
        name        = "error loading room";
        description = "no description";
    }



    Room *room = new Room();

    room->setName(name);
    room->setDescription(description);

    return room;
}
