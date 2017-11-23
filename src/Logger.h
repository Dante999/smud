#ifndef LOGGER_H
#define LOGGER_H

#include <string>

#define LOG_DEBUG   100
#define LOG_INFO    200
#define LOG_CONFIG  300
#define LOG_WARNING 400
#define LOG_ERROR   500



class Logger
{
    public:
        Logger();
        virtual ~Logger();

        static void init();
        static void println(int level,std::string classname ,std::string text);
        static std::string getTimestamp();

    protected:

    private:
};

#endif // LOGGER_H
