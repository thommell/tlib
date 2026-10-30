#include <stdlib.h>

typedef struct {
    /// The data of the string.
	char *data;

    /// The length of the string (null terminator inclusive).
	size_t length;
} string_t;

/// @brief Allocates and initializes the string.
string_t* string_init(char* str);

/// @brief Frees the initialized string.
void string_free(string_t** str);

//TODO: doxygen
/// @brief Copies the given source string.
void string_copy(string_t *dest, const string_t *src);

/// @brief Appends the source string on the destination string. This loops until the source's length.
/// @param dest: The appended string.
/// @param src: The string to add.
/// @return Returns if function has successfully exited (0), or if it failed (-1).
int string_append(string_t *dest, const string_t *src);

/// @brief Counts the amount of times the character is in the string.
/// @param str: The given string.
/// @param c: The given character.
/// @return Returns the amount of times the character is in the string.
size_t string_count_char(string_t *str, char c);

/// @brief Copies all the bytes from source onto the destination till the length.
void *string_memcpy(void *dest, const void *src, size_t length);

/// @return Returns the length of the string, excluding the null terminator.
/// -1 If an error has occurred.
int string_length(char* str);
