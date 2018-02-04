
#ifndef LOGGER_H
#define LOGGER_H

#define LOG_INFO      100
#define LOG_WARNING   200
#define LOG_ERROR     300
#define LOG_SYSTEM    400

#define LOG_TIMESTAMP_MAX   26
#define LOG_MESSAGE_MAX     255
#define LOG_SOURCE_MAX      20


static char *get_filename();
void logger_print(int log_level, const char *source, const char *msg);
void get_timestamp(char *buffer);

#endif // LOGGER_H
