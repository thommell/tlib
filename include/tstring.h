#include <stdlib.h>

typedef struct {
  char *data;
} string_t;

/// @brief Allocates and initializes the string.
string_t* string_init(char* str);

/// @brief Frees the initialized string.
void string_free(string_t** str);

void *string_memcpy(void *dest, const void *src, size_t length);

/// @return Returns the length of the string, excluding the null terminator.
/// -1 If an error has occurred.
int string_length(char* str);
