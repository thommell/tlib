#include <tlogger.h>
#include <tstring.h>
#include <tarray.h>

int main(void) {
    // logm(INFO, "Information!");
    // string_t *string = string_init("Hello world!");
    // logm(DEBUG, string->data);
    // string_free(&string);
    array_t *arr = array_init(10, (void*)0);
    array_free(&arr);
    return 0;
}
