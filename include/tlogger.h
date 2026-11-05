#pragma once

/// @brief Formats the given text + arguments to a single char*.
/// @param text: The given text.
/// @return Formatted text in a single char*
char* text_fm(const char *text, ...);

enum LOG_TYPE{
    DEBUG,
    INFO,
    WARN,
    ERROR,
    FATAL
};

/// @brief Logs a message to the terminal.
/// @param type: The given log type.
/// @param message: The message displayed.
void logm(enum LOG_TYPE type, char *message);
static const char *get_enum_str(enum LOG_TYPE log);
