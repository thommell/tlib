#include <stdio.h>

#include "logger.h"

void logm(enum LOG_TYPE type, char *message) {
    const char *log_state = get_enum_str(type);
    printf("[%s]: %s\n", log_state, message);
}

static const char *get_enum_str(enum LOG_TYPE log) {
    switch (log) {
        case DEBUG: return "DEBUG";
        case INFO:  return "INFO";
        case WARN:  return "WARN";
        case ERROR: return "ERROR";
        case FATAL: return "FATAL";
    }
}
