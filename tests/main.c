#include <assert.h>
#include <stdint.h>
#include <tlogger.h>
#include <tstring.h>
#include <tarray.h>
#include <tlist.h>
#include <tarena.h>

#define SIZE 15 

int main(void) {
    arena_t arena;
    arena_init(&arena, 1024 * 1024 * 64);
    int *t = arena_alloc(&arena, 1048);
    arena_free(&arena);
    return 0;
}
