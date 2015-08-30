#ifndef DLIST_H
#define DLIST_H

#include <stdlib.h>

typedef struct DListElmt_ {
  void *data;
  DListElmt_ *prev;
  DListElmt_ *next;
} DListElmt;

typedef struct DList_ {
  int size;
  // can be used for sets, priority queues
  // int (*match)(const void *key1, const void *key2);
  void (*destroy)(void *data);
  DListElmt *head;
  DListElmt *tail;
} DList;

void dlist_init(DList *list, void (*destroy)(void *data));
void dlist_destroy(DList *list);
int dlist_ins_next(DList *list, DListElmt *element, const void *data);
int dlist_ins_prev(DList *list, DListElmt *element, const void *data);
int dlist_remove(DList *list, DListElmt *element, void **data);

#endif
