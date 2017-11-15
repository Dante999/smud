#include <iostream>



#include "persistence/DataService.h"



int main()
{
    std::cout << "------------" << std::endl;
    std::cout << "Hello world!" << std::endl;
    std::cout << "------------" << std::endl;
    std::cout << std::endl;


    Room *room = DataService::loadRoom("winkelgasse/tropfender_kessel.xml");

    std::cout << room->toString() << std::endl;

    delete room;

    room = DataService::loadRoom("winkelgasse/winkelgassenstraße_1.xml");
    std::cout << room->toString() << std::endl;

    delete room;



    return 0;
}




