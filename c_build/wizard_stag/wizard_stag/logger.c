#include "logger.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define LOGFILE    "logfile.log"

static int m_level      = LOG_INFO;
static char *m_basepath = "";



static const char* H_ERROR      = "[ERROR]   ";
static const char* H_WARNING    = "[WARNING] ";
static const char* H_INFO       = "[INFO]    ";
static const char* H_SYSTEM     = "[SYSTEM]  ";
static const char* H_UNKNOWN    = "[UNKNOWN] ";

int logger_init(int level, const char *basepath)
{
    m_level = level;

    m_basepath = (char*) malloc(sizeof(basepath));

    strcpy(m_basepath, basepath);

    FILE *f = fopen(get_filename(m_basepath), "a+");

    if (f == NULL)
    {
        return 1;
    }
    else
    {
        fclose(f);
        return 0;
    }
}





void fill_with_spaces(char *text, int start, int length)
{
    int pos = start;

    while(pos < length-1)
    {
        text[pos] = ' ';
        pos++;

    }

    printf("finished!");


    text[length-1] = '\0';

}




void logger_print(int level, const char *source, const char *msg)
{
    const char *log_level = NULL;

    char log_timestamp[LOG_TIMESTAMP_MAX];
    char log_source[LOG_SOURCE_MAX];
    char log_message[LOG_MESSAGE_MAX];

    strncpy(log_source, source, LOG_SOURCE_MAX);
    strncpy(log_message, msg, LOG_MESSAGE_MAX);

    fill_with_spaces(log_source, strlen(log_source), LOG_SOURCE_MAX);


    switch(level)
    {
    case LOG_SYSTEM:
        log_level = H_SYSTEM;
        break;

    case LOG_ERROR:
        log_level = H_ERROR;
        break;

    case LOG_WARNING:
        log_level = H_WARNING;
        break;

    case LOG_INFO:
        log_level = H_INFO;
        break;

    default:
        log_level = H_UNKNOWN;
        break;

    }

    get_timestamp(log_timestamp);




    FILE *f = fopen(get_filename(m_basepath), "a+");

    if (f != NULL)
    {
        fprintf(f, "%s %s %s | %s\n",log_timestamp, log_level, log_source, msg);
        fclose(f);
    }


}

void get_timestamp(char *buffer)
{
    time_t timer;
    struct tm* tm_info;

    time(&timer);
    tm_info = localtime(&timer);

    strftime(buffer, LOG_TIMESTAMP_MAX, "%Y-%m-%d %H:%M:%S", tm_info);
}


static char *get_filename()
{
    char temp_timestamp[12];


    static char filename[FILENAME_MAX];

    time_t timer;
    struct tm* tm_info;

    time(&timer);
    tm_info = localtime(&timer);

    strftime(temp_timestamp, 12, "%Y-%m-%d", tm_info);

    strcpy(filename,  m_basepath);
    strcat(filename, temp_timestamp);
    strcat(filename, ".log");

    return filename;
}



