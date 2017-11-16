#ifndef DIRECTIONS_H
#define DIRECTIONS_H

#include <string>


#define NORTH       0
#define NORTH_EAST  1
#define NORTH_WEST  2
#define SOUTH       3
#define SOUTH_EAST  4
#define SOUTH_WEST  5
#define EAST        6
#define WEST        7








class Directions
{

    public:

        static int parseFromString(std::string direction);
        static std::string parseToString(int direction);

        Directions();
        virtual ~Directions();

    protected:

    private:
};

#endif // DIRECTIONS_H
