#pragma once

struct linked_node_t {
    int data;
    struct linked_node_t *next;
    struct linked_node_t *previous;
};

struct linked_list_t {
    struct linked_node_t *head;
    struct linked_node_t *tail;
};

struct linked_list_t* linkedl_create();
void linkedl_free(struct linked_list_t **pplist);
struct linked_list_t* linkedl_append(struct linked_list_t *plist, int data);
struct linked_list_t* linkedl_prepend(struct linked_list_t *plist, int data);
struct linked_list_t* linkedl_remove(struct linked_list_t *plist, int data);
void linkedl_debug(struct linked_list_t *plist);
static struct linked_node_t* linkedl_create_node(int data);
