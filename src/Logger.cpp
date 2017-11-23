#include "Logger.h"
#include <iostream>
#include <fstream>

Logger::Logger()
{
    //ctor
}

Logger::~Logger()
{
    //dtor
}

void Logger::println(int level, std::string text)
{
  char date[9];
  time_t t = time(0);
  struct tm *tm;




  tm = gmtime(&t);
  strftime(date, sizeof(date), "%Y%-m%-d%", tm);


    std::ofstream logfile;
    logfile.open("logfile.txt", std::ios::out | std::ios::app | std::ios::binary);
    logfile << date << " | " << text << "\n";
    logfile.close();
}

