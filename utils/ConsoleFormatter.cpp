#include "ConsoleFormatter.h"
#include <iostream>

#define LINE_WIDTH  80


ConsoleFormatter::ConsoleFormatter()
{
    //ctor
}

ConsoleFormatter::~ConsoleFormatter()
{
    //dtor
}

std::string ConsoleFormatter::horizontalLine()
{
    int i = 0;
    std::string line = "";


    for(i=0; i<LINE_WIDTH; i++)
    {
        line += "-";
    }

    line += "\n";

    return line;
}


std::string ConsoleFormatter::caption(std::string caption)
{
    int i=0;
    std::string line = "";

    line += "| " + caption;

    if( line.length() > LINE_WIDTH-2)
    {
        line.erase(LINE_WIDTH-2);
    }



    for(i=line.length(); i<(LINE_WIDTH-2); i++)
    {
        line += " ";
    }

    line += " |\n";

    return line;

}

std::string ConsoleFormatter::text(std::string text)
{
    std::string output = "";

    while( text.length() > 0 )
    {

        if( text.length() >= 78)
        {
            output += ConsoleFormatter::caption(text.substr(0, 78));
            text.erase(0, 78);
        }
        else
        {
            output += ConsoleFormatter::caption(text);
            text = "";
        }

    }

    return output;
}
