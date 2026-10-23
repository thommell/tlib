#include "linked-list.h"

int main(void) {
    struct linked_list_t* list = linkedl_create();
    linkedl_append(list, 1);
    linkedl_append(list, 10);
    linkedl_append(list, 100);
    linkedl_append(list, 1000);
    linkedl_append(list, 10000);
    linkedl_prepend(list, 42067);
    linkedl_debug(list);
    linkedl_free(&list);
}
