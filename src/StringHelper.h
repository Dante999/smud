#ifndef CONSOLEFORMATTER_H
#define CONSOLEFORMATTER_H

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

protected:

private:
};

#endif // CONSOLEFORMATTER_H
