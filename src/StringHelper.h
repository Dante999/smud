#ifndef STRINGHELPER_H
#define STRINGHELPER_H

#include <string>

class StringHelper
{
private:
    StringHelper();
    virtual ~StringHelper();

public:


    /*******************************************************************************
     * @brief returns a horizontal line
     *
     * @param   none
     *
     * @return  a string, filled with '-'
     *
     ******************************************************************************/
    static std::string horizontalLine();
    static std::string textLine(std::string textLine);
    static std::string textBlock(std::string textBlock);
    static std::string getWordFromText(unsigned int number, std::string text);

    static std::string tolowerCase(std::string text);

protected:

private:
};

#endif // STRINGHELPER_H
