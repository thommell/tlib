#include <stddef.h>

typedef struct {
    size_t count;
    size_t capacity;
    int *data;
} array_t;

/// @brief Initializes a new array with the given length.
/// @param capacity: Capacity of the array.
/// @return The newly created array.
array_t* array_init(size_t capacity);

/// @brief Pushes a new value to the end of the array.
/// This resizes the array automatically and allocates new memory if needed.
void array_push(array_t *arr, int value);

/// @brief Returns the value at the given index.
/// @param arr: The array to look at.
/// @param index: The index to look at.
/// @return Value at index.
void* array_peek(array_t *arr, size_t index);

/// @brief Frees the array, and sets the pointer to NULL.
void array_free(array_t **arr); 
