#include <tlogger.h>
#include <stdlib.h>
#include <tarray.h>

array_t* array_init(size_t length, void *start_value) {
    array_t *arr = malloc(sizeof(array_t));
    *arr->data = malloc(length * sizeof(void*));
    if (arr == NULL) {
        logm(FATAL, "Can't allocate more memory!");
        return NULL;
    }

    arr->length = length;
    for (size_t i = 0; i < length; ++i) {
        arr->data[i] = start_value;
    }
    logm(DEBUG, "Successfully set the array!");

    return arr;
}

void array_free(array_t **arr) {
    if (*arr == NULL) {
        logm(WARN, "Given array is null - freeing failed.");
        return;
    }

    size_t pos = 0;
    for (size_t i = 0; i < (*arr)->length; ++i) {
        free((*arr)->data[i]);
    }
    free(*arr);
    *arr = NULL;
}
