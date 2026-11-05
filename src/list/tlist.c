#include <stdio.h>
#include <tlist.h>
#include <tlogger.h>
#include <stdbool.h>

list_t *list_init() {
    list_t *plist = malloc(sizeof(list_t));
    plist->capacity = 2;
    plist->length = 0;
    plist->data = malloc(plist->capacity * sizeof(int));
    return plist;
}

list_t *list_add(list_t *plist, int val) {
    if (plist == NULL) {
        logm(FATAL, "GIVEN LIST IS NULL");
        return NULL;
    }

    if (plist->length >= plist->capacity) {
        list_realloc(plist);
    }

    *(plist->data + plist->length) = val;
    ++(plist->length);

    logm(DEBUG, text_fm("LIST LEN: %zu, CAP: %zu", plist->length, plist->capacity));

    return plist;
}


list_t *list_add_range(list_t *dlist, list_t *slist) {
    size_t total_size = dlist->length + slist->length;
    if (total_size >= dlist->capacity) {
        list_realloc_size(dlist, total_size);
    }

    for (size_t i = 0; i < slist->length; ++i) {
        dlist->data[dlist->length + i] = slist->data[i];
        logm(DEBUG, text_fm("%zu", dlist->data[i]));
    }
    dlist->length = total_size;

    return dlist;
}

list_t *list_add_range_raw(list_t *dlist, int* raw, size_t size) {
    size_t total_size = dlist->length + size;
    if (total_size >= dlist->capacity) {
        list_realloc_size(dlist, total_size);
    }

    for (size_t i = 0; i < size; ++i) {
        dlist->data[dlist->length + i] = raw[i];
    }

    return dlist;
}

list_t *list_add_at(list_t *plist, int val, int position) {
    if (plist == NULL) {
        logm(FATAL, "GIVEN LIST IS NULL");
        return NULL;
    }
    if (position > plist->length || position < 0) {
        logm(FATAL, text_fm("GIVEN POSITION IS INVALID: %d", position));
        return NULL;
    }

    if (plist->length >= plist->capacity) {
        list_realloc(plist);
    }

    bool found = false;
    size_t i = 0;
    while (!found) {
        if (i == position) {
            for (int outer = plist->length; outer > i; --outer) {
                plist->data[outer] = plist->data[outer - 1];
            }
            plist->data[i] = val;
            ++plist->length;
            found = true;
        }
        ++i;
    }
    return plist;
}

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
        logm(ERROR, text_fm("GIVEN SIZE %zu IS OUT OF BOUNDS.", position));
        return plist;
    }

    for (int outer = position; outer < plist->length; ++outer) {
        plist->data[outer] = plist->data[outer + 1];
    }
    plist->length -= 1;

    return plist;
}

static void list_realloc(list_t *plist) {
    plist->capacity *= 2;
    int *tmp = realloc(plist->data, plist->capacity * sizeof(int));
    if (tmp == NULL) {
        logm(ERROR, "COULDN'T REALLOCATE MORE MEMORY FOR A LIST.");
    }             
    plist->data = tmp;
}

static void list_realloc_size(list_t *plist, size_t size) {
    while (plist->capacity <= size) {
        plist->capacity *= 2;
    }

    int *tmp = realloc(plist->data, plist->capacity * sizeof(int));
    if (tmp == NULL) {
        logm(ERROR, "COULDN'T REALLOCATE MORE MEMORY FOR A LIST.");
        return;
    }             
    plist->data = tmp;
}

void list_free(list_t **list) {
    if (*(list) == NULL) {
        logm(WARN, "GIVEN LIST TO FREE IS NULL.");
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
