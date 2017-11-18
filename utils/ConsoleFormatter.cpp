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


std::string ConsoleFormatter::textLine(std::string textLine)
{
    int i=0;
    std::string line = "";

    line += "| " + textLine;

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

std::string ConsoleFormatter::textBlock(std::string textBlock)
{
    std::string output = "";

    while( textBlock.length() > 1 )
    {
        if( textBlock.at(0) == ' ' )
        {
            textBlock.erase(0,1);
        }

        if( textBlock.length() >= 76)
        {
            output += ConsoleFormatter::textLine(textBlock.substr(0, 76));
            textBlock.erase(0, 76);
        }
        else
        {
            output += ConsoleFormatter::textLine(textBlock);
            textBlock = "";
        }

    }

    return output;
}

//TODO:
// Function to cut-off leading and trailing whitespaces
