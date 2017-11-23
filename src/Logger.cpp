#include "Logger.h"
#include <iostream>
#include <fstream>
#include <stdio.h>      /* puts */
#include <time.h>       /* time_t, struct tm, time, localtime, strftime */



#define LOG_LEVEL   LOG_DEBUG

#define CLASS_NAME_SIZE 20

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

    classname.resize(CLASS_NAME_SIZE, ' ');


    std::ofstream logfile;
    logfile.open("logfile.txt", std::ios::out | std::ios::binary);
    logfile << "###################################################################\n";
    logfile << "# Server started                                                  #\n";
    logfile << "###################################################################\n";
    logfile << "\n";
    logfile << Logger::getTimestamp() << " | " << classname << " | " << "initialized \n";
    logfile.close();

}


void Logger::println(int level, std::string classname, std::string text)
{
    classname.resize(CLASS_NAME_SIZE, ' ');

    if( level >= LOG_LEVEL)
    {
        std::ofstream logfile;
        logfile.open("logfile.txt", std::ios::out | std::ios::app | std::ios::binary);
        logfile << Logger::getTimestamp() << " | " << classname << " | " << text << "\n";
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
