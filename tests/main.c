#include <stdio.h>
#include <tlogger.h>
#include <tstring.h>
#include <tarray.h>
#include <inttypes.h>

int main(void) {
    string_t *one = string_init("Hello");
    string_t *two = string_init("World");
    string_append(one, two);

    printf("%s", one->data);

    string_free(&one);
    string_free(&two);
    return 0;
}
