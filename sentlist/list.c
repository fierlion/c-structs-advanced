#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void list_init(List *list, void (*destroy)(void *data)) {
    list->size = 0;
    list->destroy = destroy;
    ListElmt *head = malloc(sizeof(ListElmt));
    head->next = NULL;
    head->data = NULL;
    list->head = head;
}

void list_destroy(List *list) {
    void *data;
    while(list_size(list) > 0) {
        list_rem_next(list, list_head(list), (void **)&data);
        list->destroy(data);
    }
}

int list_ins_front(List *list, const void *data) {
    ListElmt *new = malloc(sizeof(ListElmt));
    new->data = (void *)data;
    new->next = list->head->next;
    list->head->next = new;
    list->size += 1;
    return 0;
}

int list_ins_next(List *list, ListElmt *element, const void *data) {
    ListElmt *new = malloc(sizeof(ListElmt));
    new->data = (void *)data;
    new->next = element->next;
    element->next = new;
    list->size += 1;
    return 0;
}

int list_rem_next(List *list, ListElmt *element, void **temp) {
   if (elem_next(element) == NULL) {
       return -1;
   }
   ListElmt *old_element;
   *temp = element->next->data;
   old_element = element->next;
   element->next = element->next->next;
   free(old_element);
   list->size -= 1;
   return 0;
}
