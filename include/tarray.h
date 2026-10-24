#include <stddef.h>

typedef struct {
    size_t length;
    void *data[];
} array_t;

/// @brief Initializes a new array with the given length.
/// @return The newly created array.
array_t* array_init(size_t length, void *start_value);

/// @brief Resizes the array with the new length. This will discard values if the array gets smaller.
void array_resize(array_t *arr, size_t new_length);

/// @brief Returns the value at the given index.
/// @return The value (void*)
void* array_peek(array_t *arr, size_t index);

/// @brief Frees the array, and sets the pointer to NULL.
void array_free(array_t **arr); 
