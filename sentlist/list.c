#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void list_init(List *list) {
  list->size = 0;
  ListElmt *head = malloc(sizeof(ListElmt));
  ListElmt *tail = malloc(sizeof(ListElmt));
  head->next = tail;
}
