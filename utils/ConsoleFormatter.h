#ifndef CONSOLEFORMATTER_H
#define CONSOLEFORMATTER_H

#include <string>

class ConsoleFormatter
{
    public:
        ConsoleFormatter();
        virtual ~ConsoleFormatter();

        static std::string horizontalLine();
        static std::string caption(std::string caption);
        static std::string text(std::string text);

    protected:

    private:
};

#endif // CONSOLEFORMATTER_H
