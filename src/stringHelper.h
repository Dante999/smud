#ifndef STRINGHELPER_H
#define STRINGHELPER_H

#include <string>

class StringHelper
{
private:
    StringHelper();
    virtual ~StringHelper();

public:
    static std::string horizontalLine();
    static std::string textLine(std::string textLine);
    static std::string textBlock(std::string textBlock);
    static std::string getWordFromText(unsigned int number, std::string text);

    static std::string tolowerCase(std::string text);
    static std::string cropLeadingWhitespaces(std::string text);
    static std::string cropTrailingWhitespaces(std::string text);

};

#endif // STRINGHELPER_H
