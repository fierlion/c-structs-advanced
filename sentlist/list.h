#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct ListElmt_ {
  void *data;
  struct ListElmt_ *next;
} ListElmt;

typedef struct List_ {
  int size;
  int (*match)(const void *key1, const void *key2);
  void (*destroy)(void *data);
  ListElmt *head;
} List;

void list_init(List *list, void (*destroy)(void *data)) ;
void list_destroy(List *list);
int list_ins_front(List *list, const void *data);
int list_ins_next(List *list, ListElmt *element, const void *data);
int list_rem_next(List *list, ListElmt *element, void **data);
void print_list(List *list);
#define list_size(list) ((list)->size)
#define list_head(list) ((list)->head)
#define list_tail(list) ((list)->tail)
#define elem_is_head(list, elem) ((list)->head == (elem) ? 1 : 0)
#define elem_is_tail(elem) ((elem)->next == NULL ? 1 : 0)
#define elem_data(elem) ((elem)->data)
#define elem_next(elem) ((elem)->next)

#endif
