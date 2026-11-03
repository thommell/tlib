#include <textformatter.h>
#include <tlogger.h>
#include <tstring.h>
#include <tarray.h>
#include <tlist.h>

int main(void) {
    logm(FATAL, text_fm("age: %d", 10)); 
    return 0;
}
