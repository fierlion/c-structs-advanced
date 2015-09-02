#ifndef DLIST_H
#define DLIST_H

#include <stdlib.h>

typedef struct DListElmt_ {
  void *data;
  struct DListElmt_ *prev;
  struct DListElmt_ *next;
} DListElmt;

typedef struct DList_ {
  int size;
  DListElmt *head;
  DListElmt *tail;
  void (*destroy)(void *data);
  int (*match)(const void *key1, const void *key2);
} DList;

void dlist_init(DList *list, void (*destroy)(void *data));
int dlist_ins_next(DList *list, DListElmt *element, const void *data);
int dlist_ins_prev(DList *list, DListElmt *element, const void *data);
int dlist_remove(DList *list, DListElmt *elmt);
void dlist_destroy(DList *list);
#define dlist_head(list) ((list)->head)
#define dlist_tail(list) ((list)->tail)

#endif
