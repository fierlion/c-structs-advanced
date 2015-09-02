#include "dlist.h"

void dlist_init(DList *list, void (*destroy)(void *data)) {
  DListElmt *head_sent = malloc(sizeof(DListElmt));
  // memset(head_sent, 0, sizeof(DListElmt));
  DListElmt *tail_sent = malloc(sizeof(DListElmt));
  // memset(tail_sent, 0, sizeof(DListElmt));
  //tie head to tail, initialize all others NULL
  head_sent->next = tail_sent;
  head_sent->prev = NULL;
  head_sent->data = NULL;
  tail_sent->next = NULL;
  tail_sent->prev = head_sent;
  tail_sent->data = NULL;
  // initialize other list members
  list->size = 0;
  list->destroy = destroy;
  list->head = head_sent;
  list->tail = tail_sent;
  return;
}

int dlist_ins_next(DList *list, DListElmt *elmt, const void *data) {
  if (elmt == list->tail) return 0;
  DListElmt *temp = malloc(sizeof(DListElmt));
  memset(temp, 0, sizeof(DListElmt));
  temp->data = (void *)data;
  temp->next = elmt->next;
  temp->prev = elmt;
  elmt->next->prev = temp;
  elmt->next = temp;
  list->size += 1;
  return 0;
}

int dlist_ins_prev(DList *list, DListElmt *elmt, const void *data) {
  if (elmt == list->head) return 0;
  DListElmt *temp = malloc(sizeof(DListElmt));
  memset(temp, 0, sizeof(DListElmt));
  temp->data = (void *)data;
  temp->prev = elmt->prev;
  temp->next = elmt;
  elmt->prev->next = temp;
  elmt->prev = temp;
  list->size += 1;
  return 0;
}

int dlist_remove(DList *list, DListElmt *elmt) {
  elmt->prev->next = elmt->next;
  elmt->next->prev = elmt->prev;
  list->destroy(elmt->data);
  free(elmt);
  list->size -=1;
  return 0;
}

void dlist_destroy(DList *list) {
  while(list->size > 1) {
    dlist_remove(list, dlist_head(list)->next);
  }
  // free(dlist_head(list));
  free(dlist_tail(list));
  // memset(list, 0, sizeof(DList));
  return;
}
