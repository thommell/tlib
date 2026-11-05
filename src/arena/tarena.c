#include <stdint.h>
#include <assert.h>
#include <tarena.h> 

#include <tlogger.h> // For: logm
#include <string.h> // For: memset
 

// void *arena_alloc_align(Arena *a, size_t size, size_t align) {
// 	// Align 'curr_offset' forward to the specified alignment
// 	uintptr_t curr_ptr = (uintptr_t)a->buf + (uintptr_t)a->curr_offset;
// 	uintptr_t offset = align_forward(curr_ptr, align);
// 	offset -= (uintptr_t)a->buf; // Change to relative offset
//
// 	// Check to see if the backing memory has space left
// 	if (offset+size <= a->buf_len) {
// 		void *ptr = &a->buf[offset];
// 		a->prev_offset = offset;
// 		a->curr_offset = offset+size;
//
// 		// Zero new memory by default
// 		memset(ptr, 0, size);
// 		return ptr;
// 	}
// 	// Return NULL if the arena is out of memory (or handle differently)
// 	return NULL;
// }

void arena_init(
        arena_t *a,
        size_t size
        ) {
    a->total_size = size;
    a->buffer = malloc(size);
    memset(a->buffer, 0, size);
    a->offset = 0;
    a->committed = 0;

    logm(DEBUG, text_fm("SET TOTAL ARENA SIZE TO: %zu", size));
}

uintptr_t align_forward(uintptr_t ptr, size_t alignment) {
    uintptr_t p, a, modulo;
    if (!is_power_of_two(alignment)) {
        return 0;
    }
    p = ptr;
    a = (uintptr_t)alignment;
    modulo = p & (a - 1);

    if (modulo) {
        p += a - modulo;
    }

    return p;
}

void *arena_alloc(
        arena_t *a, 
        const size_t size
        ) {
    if (a == NULL) {
        logm(FATAL, "GIVEN ARENA WAS NULL.");
        return NULL;
    }
    if (!size) {
        logm(WARN, "TRIED ALLOCATING ZERO MEMORY");
        return NULL;
    }

    uintptr_t curr_ptr = (uintptr_t)a->buffer + a->offset;
    uintptr_t aligned_ptr = align_forward(curr_ptr, DEFAULT_ALIGNMENT);
    size_t offset = aligned_ptr - (uintptr_t)a->buffer;

    if (offset >= a->total_size || size >= a->total_size - offset) {
        logm(FATAL, text_fm("ARENA HAS RAN OUT OF MEMORY. MAX: %zu - WANTED SIZE: %zu", a->total_size, offset));
        return NULL;
    }

    void *ptr = (unsigned char*)a->buffer + offset;

    a->committed += size;
    a->offset = offset + size;
    logm(DEBUG, text_fm("CURRENT ARENA OFFSET: %zu", a->offset));

    return ptr;


    return ptr;
}

void arena_free(arena_t *arena) {
    free(arena->buffer);
}
