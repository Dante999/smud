#include "StringHelper.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#define LINE_WIDTH  80


StringHelper::StringHelper()
{
    //ctor
}

StringHelper::~StringHelper()
{
    //dtor
}


/*******************************************************************************
 * returns a horizontal line
 *
 * @param   none
 *
 * @return  a string, filled with '-'
 *
 ******************************************************************************/
std::string StringHelper::horizontalLine()
{
    std::string line (LINE_WIDTH, '-');

    return line;
}


std::string StringHelper::textLine(std::string textLine)
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

std::string StringHelper::textBlock(std::string textBlock)
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
            output += StringHelper::textLine(textBlock.substr(0, 76));
            textBlock.erase(0, 76);
        }
        else
        {
            output += StringHelper::textLine(textBlock);
            textBlock = "";
        }

    }

    return output;
}



std::string StringHelper::getWordFromText(unsigned int number, std::string text)
{

    std::vector<std::string> v;

    std::istringstream buf(text);

    for(std::string word; buf >> word; )
    {
        v.push_back(word);
    }


    if( number < v.size() )
    {
        return v.at(number);
    }
    else
    {
        return "";
    }
}


//TODO:
// Function to cut-off leading and trailing whitespaces
