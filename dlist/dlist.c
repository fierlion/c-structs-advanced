#include "dlist.h"

void dlist_init(DList *list, void (*destroy)(void *data)) {
  DListElmt *head_sent = malloc(sizeof *head_sent);
  DListElmt *tail_sent = malloc(sizeof *tail_sent);
  list->size = 0;
  list->destroy = destroy;
  list->head = head_sent;
  list->tail = tail_sent;
  return;
}
