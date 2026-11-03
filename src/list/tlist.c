#include <stdio.h>
#include <tlist.h>
#include <tlogger.h>

list_t *list_init() {
    list_t *plist = malloc(sizeof(list_t));
    plist->capacity = 2;
    plist->length = 0;
    plist->data = malloc(plist->capacity * sizeof(int));
    return plist;
}

list_t *list_add(list_t *plist, int val) {
    if (plist == NULL) {
        logm(FATAL, "GIVEN LIST IS NULL - DID YOU FORGET TO INITIALIZE?");
        return NULL;
    }

    if (plist->length >= plist->capacity) {
        plist->capacity *= 2;
        int *tmp = realloc(plist->data, plist->capacity * sizeof(int));
        if (tmp == NULL) {
            logm(FATAL, "COULDN'T REALLOCATE MORE MEMORY FOR A LIST.");
            return plist;
        }             
        plist->data = tmp;
    }

    *(plist->data + plist->length) = val;
    ++(plist->length);

    return plist;
}

list_t *list_add_at(list_t *plist, int val, size_t position);

list_t *list_remove(list_t *plist, int val) {
    size_t position = 0;
    for (int inner = 0; inner < plist->length; ++inner) {
        if (plist->data[inner] == val) {
            for (int outer = inner; outer < plist->length; ++outer) {
                plist->data[outer] = plist->data[outer + 1];
            }
            --plist->length;
            --inner;
        }
    }
    return plist;
}

list_t *list_remove_at(list_t *plist, size_t position) {
    if (position >= plist->length) {
        logm(ERROR, "Specified position to remove is out of bounds.");
        return plist;
    }
    
    for (int outer = position; outer < plist->length; ++outer) {
        plist->data[outer] = plist->data[outer + 1];
    }
    plist->length -= 1;

    return plist;
}

void list_free(list_t **list) {
    if (*(list) == NULL) {
        logm(WARN, "given list to free is null.");
    }
    free((*list)->data);
    free(*(list));
    *list = NULL;
}

void list_clear();

void list_print(list_t *list) {
    printf("len: %zu, cap: %zu\n", list->length, list->capacity);
    printf("[");
    for (int i = 0; i < list->length; ++i) {
        if (i != list->length-1) {
            printf("%d, ", *(list->data + i));
            continue;
        }
        printf("%d", list->data[i]);
    }
    printf("]\n");
}
