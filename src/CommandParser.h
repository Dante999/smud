#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H

#include <string>
#include "Player.h"

enum cmd {
    CMD_NOT_FOUND,
    CMD_GOTO_NORTH,
    CMD_GOTO_SOUTH,
    CMD_GOTO_WEST,
    CMD_GOTO_EAST,
    CMD_GOTO_NORTH_EAST,
    CMD_GOTO_NORTH_WEST,
    CMD_GOTO_SOUTH_EAST,
    CMD_GOTO_SOUTH_WEST,
    CMD_EXPLORE,
    CMD_HELP,
};

class CommandParser
{
    public:
        CommandParser();
        virtual ~CommandParser();
        static void parse(Player *player, std::string input);

    protected:

    private:
        static void cmdMove(Player *player, std::string input);
        static void cmdExplore(Player *player, std::string input);
        static void cmdHelp(Player *player, std::string input);

        static cmd convert(std::string word);
};

#endif // COMMANDPARSER_H
