#include <stdlib.h>

typedef struct {
    int *data;
    size_t length;
    size_t capacity;
} list_t;

/// @brief Initializes and allocates the list.
/// @return An allocated and empty list.
list_t *list_init();

/// @brief Appends a new value to the list.
/// @param plist: The list to be changed.
/// @param val: The appened value.
/// @return The changed list, NULL if appending failed.
list_t *list_add(list_t *plist, int val);

/// @brief Appends the given value at a specified location, this must be between the bounds of the list.
/// @param plist: The list to be changed.
/// @param val: The new value of said position.
/// @param position: The position of the new value.
/// @return The changed list, NULL if appending failed.
list_t *list_add_at(list_t *plist, int val, size_t position);

/// @brief Removes all occurences of the given value from the list.
/// @param plist: The list to be changed.
/// @param val: The removed value.
/// @return The changed list, if removing failed it will return the original list.
list_t *list_remove(list_t *plist, int val);

/// @brief Removes a value from a specified position.
/// @param plist: The list to be changed.
/// @param position: The specified position.
/// @return The changed list, if removing failed it will return the original list.
list_t *list_remove_at(list_t *plist, size_t position);

void list_clear();
void list_free(list_t **list);
void list_print(list_t *list);
