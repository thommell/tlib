#include "logger.h"

int main(void) {
    logm(DEBUG, "Debug!");
    logm(INFO, "Info!");
    logm(WARN, "Warning!");
    logm(ERROR, "Error!");
    logm(FATAL, "Fatal!");
    return 0;
}
