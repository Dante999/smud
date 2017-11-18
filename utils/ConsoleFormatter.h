#ifndef CONSOLEFORMATTER_H
#define CONSOLEFORMATTER_H

#include <string>

class ConsoleFormatter
{
    public:
        ConsoleFormatter();
        virtual ~ConsoleFormatter();

        static std::string horizontalLine();
        static std::string textLine(std::string textLine);
        static std::string textBlock(std::string textBlock);

    protected:

    private:
};

#endif // CONSOLEFORMATTER_H
