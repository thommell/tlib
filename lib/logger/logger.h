#pragma once

enum LOG_TYPE{
    DEBUG,
    INFO,
    WARN,
    ERROR,
    FATAL
};

void logm(enum LOG_TYPE type, char *message);
static const char *get_enum_str(enum LOG_TYPE log);
