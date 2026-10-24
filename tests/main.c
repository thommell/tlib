#include <tlogger.h>
#include <tstring.h>

int main(void) {
    logm(INFO, "Information!");
    string_t *string = string_init("Hello world!");
    logm(DEBUG, string->data);
    string_free(&string);
    return 0;
}
