#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void list_init(List *list) {
    list->size = 0;
    ListElmt *head = malloc(sizeof(ListElmt));
    head->next = NULL;
    head->data = NULL;
    list->head = head;
}

int list_ins_front(List *list, const void *data) {
    ListElmt *new = malloc(sizeof(ListElmt));
    new->data = (void *)data;
    new->next = list->head->next;
    list->head->next = new;
    return 0;
}
