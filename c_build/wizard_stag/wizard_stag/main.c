#include <stdio.h>
#include <stdlib.h>
#include "logger.h"

int system_check();

int main()
{
    //printf("Hello world!\n");
    int error_counter = 0;
    error_counter = system_check();

    printf("--------\n");
    printf("Systemcheck finished with %i errors\n",  error_counter);
    printf("--------\n\n");

    if( error_counter > 0)
    {
        exit(1);
    }

    logger_print(LOG_SYSTEM, "systemcheck", "finished with 0 errors");


    logger_print(LOG_INFO, "test", "this is a info");
    logger_print(LOG_WARNING, "mainFunction" , "this is a warning");
    logger_print(LOG_ERROR,   "aha",  "this is a error");


    return 0;
}

int system_check()
{
    int error_counter = 0;
    int temp_status = 0;


    temp_status = logger_init(LOG_INFO, "");

    if(temp_status==0)
    {
        printf("[OK] Checking logfile...\n");
    }
    else
    {
        printf("[ERROR] Checking logfile -> status %i\n", temp_status);
        error_counter++;
    }

    return error_counter;

}
