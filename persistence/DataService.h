#ifndef DATASERVICE_H
#define DATASERVICE_H

#include <string>
#include "Room.h"

class DataService
{
    public:
        DataService();
        virtual ~DataService();

    static Room *loadRoom(std::string roomPath);


    protected:

    private:
};

#endif // DATASERVICE_H
