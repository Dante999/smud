#include "interpreter.h"
#include "gameEngine.h"
#include "directions.h"
#include "stringHelper.h"
#include "roomEngine.h"


/*******************************************************************************
 * constructor
 *
 * @param   none
 *
 * @return  none
 *
 ******************************************************************************/
Interpreter::Interpreter()
{
    //ctor
}


/*******************************************************************************
 * destructor
 *
 * @param   none
 *
 * @return  none
 *
 ******************************************************************************/
Interpreter::~Interpreter()
{
    //dtor
}


/*******************************************************************************
 * converts the string into a command
 *
 * @param   inString    the string to convert
 *
 * @return  the parsed command (see enum cmd)
 *
 ******************************************************************************/
cmd Interpreter::convert(std::string word)
{
    if (word == "n")            return CMD_GOTO_NORTH;
    if (word == "s")            return CMD_GOTO_SOUTH;
    if (word == "o")            return CMD_GOTO_EAST;
    if (word == "w")            return CMD_GOTO_WEST;
    if (word == "no")           return CMD_GOTO_NORTH_EAST;
    if (word == "nw")           return CMD_GOTO_NORTH_WEST;
    if (word == "so")           return CMD_GOTO_SOUTH_EAST;
    if (word == "sw")           return CMD_GOTO_SOUTH_WEST;
    if (word == "schau")        return CMD_EXPLORE;
    if (word == "untersuche")   return CMD_EXPLORE;
    if (word == "unt")          return CMD_EXPLORE;
    if (word == "hilfe")        return CMD_HELP;
    if (word == "speichern")    return CMD_SAVE;
    else                        return CMD_NOT_FOUND;
}


/*******************************************************************************
 * parse and executes player input
 *
 * @param   player  the player who inputs a command
 *
 * @param   input   the input string of the player
 *
 * @return  none
 *
 ******************************************************************************/
void Interpreter::parse(Player *player, std::string input)
{
    std::string firstWord = StringHelper::getWordFromText(0, input);

    switch (convert(firstWord))
    {

    case CMD_GOTO_NORTH:
        GameEngine::walk(player, NORTH);
        break;

    case CMD_GOTO_SOUTH:
        GameEngine::walk(player, SOUTH);
        break;

    case CMD_GOTO_EAST:
        GameEngine::walk(player, EAST);
        break;

    case CMD_GOTO_WEST:
        GameEngine::walk(player, WEST);
        break;

    case CMD_GOTO_NORTH_EAST:
        GameEngine::walk(player, NORTH_EAST);
        break;

    case CMD_GOTO_NORTH_WEST:
        GameEngine::walk(player, NORTH_WEST);
        break;

    case CMD_GOTO_SOUTH_EAST:
        GameEngine::walk(player, SOUTH_EAST);
        break;

    case CMD_GOTO_SOUTH_WEST:
        GameEngine::walk(player, SOUTH_WEST);
        break;

    case CMD_EXPLORE:
        cmdExplore(player, input);
        break;

    case CMD_HELP:
        GameEngine::printHelp(player);
        break;

    case CMD_SAVE:
        GameEngine::savePlayer(player);
        break;

    case CMD_NOT_FOUND:
        player->println("ungueltiger Befehl!");
        break;
    }

}


/*******************************************************************************
 * handle the explore command
 *
 * @param   player  the player who sends the command
 *
 * @param   input   the player input
 *
 * @return  none
 *
 ******************************************************************************/
void Interpreter::cmdExplore(Player* player, std::string input)
{
    if(StringHelper::getWordFromText(1, input)=="")
    {
        GameEngine::exploreRoom(player);
    }
    else
    {
        Room *room = RoomEngine::getRoom(player->getRoomPath());
        std::string secondWord = StringHelper::getWordFromText(1, input);

        secondWord = StringHelper::tolowerCase(secondWord);

        GameEngine::exploreDetail(player, room, secondWord);
    }
}


/*******************************************************************************
 * handle the help command
 *
 * @param   player  the player who sends the command
 *
 * @param   input   the player input
 *
 * @return  none
 *
 ******************************************************************************/
void Interpreter::cmdHelp(Player* player, std::string input)
{
    if(StringHelper::getWordFromText(1, input)=="")
    {
        GameEngine::exploreRoom(player);
    }
    else
    {
        Room *room = RoomEngine::getRoom(player->getRoomPath());
        std::string secondWord = StringHelper::getWordFromText(1, input);

        GameEngine::exploreDetail(player, room, secondWord);
    }
}
