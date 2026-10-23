#include "linked-list.h"
#include <stdio.h>
#include <stdlib.h>

#include "../logger/logger.h"

struct linked_list_t* linkedl_append(struct linked_list_t *plist, int data) {
    if (plist == NULL) {
        logm(ERROR, "Tried appending a NULL list.");
        return NULL;
    }

    struct linked_node_t *node = linkedl_create_node(data);

    if (plist->head == NULL) {
        plist->head = node;
        logm(DEBUG, "Assigned node to HEAD");
        return plist;
    }
    else if (plist->tail == NULL){
        plist->tail = node;
        plist->head->next = plist->tail;
        logm(DEBUG, "Assigning node to TAIL.");
    }
    else {
        struct linked_node_t *prev_tail = plist->tail;
        plist->tail = node;
        prev_tail->next = plist->tail;
        logm(DEBUG, "Assigning node to the list.");
    }
    
    return plist;
}

struct linked_list_t* linkedl_prepend(struct linked_list_t *plist, int data) {
    if (plist == NULL) {
        logm(ERROR, "Tried prepending a NULL list.");
        return NULL;
    }

    struct linked_node_t *node = linkedl_create_node(data);
    if (plist->head == NULL) {
        plist->head = node;
    } 
    else {
        struct linked_node_t *prev_head = plist->head;
        plist->head = node;
        plist->head->next = prev_head;
    }
    logm(DEBUG, "Assigning node to HEAD.");

    return plist;
}

struct linked_list_t* linkedl_remove(struct linked_list_t *plist, int data);

void linkedl_free(struct linked_list_t **pplist) {
    if (pplist == NULL) {
        logm(ERROR, "Tried freeing a NULL list.");
        return;
    }

    struct linked_node_t *current = (*pplist)->head;
    if (current == NULL) {
        logm(WARN, "Tried freeing an empty list.");
        free(*pplist);
        *pplist = NULL;
        return;
    }

    while (current != NULL) {
        struct linked_node_t *next_node = current->next;       
        free(current);
        current = next_node;
    }

    free(*pplist);
    *pplist = NULL;
    logm(DEBUG, "Freed the linked list.");
}

struct linked_list_t* linkedl_create() {
    struct linked_list_t *plist;
    plist = calloc(1, sizeof(struct linked_list_t));
    return plist;
}

static struct linked_node_t* linkedl_create_node(int data) {
    struct linked_node_t *node = calloc(1, sizeof(struct linked_node_t));
    node->data = data;
    logm(DEBUG, "Initialized new node data");
    return node;
}

void linkedl_debug(struct linked_list_t *plist) {
    struct linked_node_t *current = plist->head;
    while (current != NULL) {
        printf("%d, ", current->data);
        current = current->next;
    }
    printf("\n");
}
