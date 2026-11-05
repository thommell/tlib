#include <stdlib.h>

typedef struct {
    unsigned char *buffer;
    size_t  total_size;
    size_t  offset;
    size_t  committed;
} arena_t;

#define is_power_of_two(x) ((x != 0) && ((x & (x - 1)) == 0))
#define DEFAULT_ALIGNMENT (2 * sizeof(void *))

void arena_init(arena_t *a, size_t size);

void *arena_alloc(arena_t *arena, const size_t buf_len);

void arena_free(arena_t *arena);
