#include <stdarg.h>
#include <stdio.h>
#include <tlogger.h>

#define MAX_STRING_LEN 1024
#define MAX_ARGS_LEN 128

char* text_fm(const char *text, ...) {
    char buffers[MAX_STRING_LEN][MAX_ARGS_LEN];
    int index = 0;

    char *buffer = buffers[index];
    va_list args;
    va_start(args, text);
    vsprintf(buffer, text, args);
    va_end(args);

    index = (index + 1) % 4;

    return buffer;
}

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
