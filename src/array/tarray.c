#include <stdio.h>
#include <tlogger.h>
#include <stdlib.h>
#include <tarray.h>

array_t* array_init(size_t capacity) {
    array_t *arr = malloc(sizeof(array_t));
    if (arr == NULL) {
        logm(FATAL, "Allocating the array failed!");
        return NULL;
    }
    arr->data = calloc(1, capacity * sizeof(int));
    if ((arr)->data == NULL) {
        logm(FATAL, "Allocating array's data failed!");
        free(arr);
        return NULL;
    }
    arr->count = capacity;

    logm(DEBUG, "Successfully set the array!");
    return arr;
}

void array_push(array_t *arr, int value) {
    if (arr->count+1 > arr->capacity) {

    }
}

void array_free(array_t **arr) {
    if (*arr == NULL) {
        logm(WARN, "Given array is null - freeing failed.");
        return;
    }

    free((*arr)->data);

    free(*arr);
    *arr = NULL;
}
