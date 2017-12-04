#include "logger.h"
#include <iostream>
#include <fstream>
#include <stdio.h>      /* puts */
#include <time.h>       /* time_t, struct tm, time, localtime, strftime */



#define LOG_LEVEL   LOG_DEBUG

#define LENGTH_CLASS_NAME   20
#define LENGTH_LOG_LEVEL    8

Logger::Logger()
{
    //ctor
}

Logger::~Logger()
{
    //dtor
}

void Logger::init()
{
    std::string classname = "Logger";
    std::string loglevel = "STARTUP";


    classname.resize(LENGTH_CLASS_NAME, ' ');
    loglevel.resize(LENGTH_LOG_LEVEL, ' ');

    std::ofstream logfile;
    logfile.open("logfile.txt", std::ios::out | std::ios::binary);
    logfile << "###################################################################\n";
    logfile << "# Server started                                                  #\n";
    logfile << "###################################################################\n";
    logfile << "\n";
    logfile << Logger::getTimestamp() << " | " << loglevel << " | " << classname << " | " << "initialized \n";
    logfile.close();

}


void Logger::println(int level, std::string classname, std::string text)
{
    std::string levelStr = Logger::levelAsString(level);

    classname.resize(LENGTH_CLASS_NAME, ' ');
    levelStr.resize(LENGTH_LOG_LEVEL, ' ');


    if( level >= LOG_LEVEL)
    {
        std::ofstream logfile;
        logfile.open("logfile.txt", std::ios::out | std::ios::app | std::ios::binary);
        logfile << Logger::getTimestamp() << " | " << levelStr << " | " << classname << " | " << text << "\n";
        logfile.close();
    }


}


std::string Logger::getTimestamp()
{
    time_t rawtime;
    struct tm * timeinfo;
    char buffer [80];

    time (&rawtime);
    timeinfo = localtime (&rawtime);

    strftime (buffer,80,"%F %T",timeinfo);

    std::string result(buffer);

    return result;
}

std::string Logger::levelAsString(int loglevel)
{
    std::string level = "";

    switch(loglevel)
    {
    case LOG_DEBUG:
        level = "DEBUG";
        break;

    case LOG_INFO:
        level = "INFO";
        break;

    case LOG_CONFIG:
        level = "CONFIG";
        break;

    case LOG_WARNING:
        level = "WARNING";
        break;

    case LOG_ERROR:
        level = "ERROR";
        break;

    default:
        level = "UNKOWN";
        break;
    }

    return level;
}

