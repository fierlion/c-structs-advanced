#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dlist.c"

int *create_int(int data) {
  int *value = malloc(sizeof(data));
  memset(value, 0, sizeof(data));
  *value = data;
  return(value);
}

char *create_char(char data) {
  char *value = malloc(sizeof(data));
  memset(value, 0, sizeof(data));
  *value = data;
  return(value);
}

void destroy_int(void *data) {
  free((int *)data);
}

void dlist_print(DList *list) {
  DListElmt *iterator = list->head->next;
  printf("[ ");
  while (iterator->next != list->tail) {
    printf("%d ", *(int*)iterator->data);
    iterator = iterator->next;
  }
  printf("]\n");
  return;
}

void dlist_chars_print(DList *list) {
  DListElmt *iterator = list->head->next;
  printf("[ ");
  while (iterator != list->tail) {
    printf("%d ", *(char*)iterator->data);
    iterator = iterator->next;
  }
  printf("]\n");
  return;
}

int main() {
  DList *list1 = malloc(sizeof(DList));
  dlist_init(list1, &destroy_int);
  printf("head->next == tail: %d\n", list1->head->next == list1->tail);
  int *five = create_int(5);
  int *four = create_int(4);
  int *three = create_int(3);
  int *two = create_int(2);
  dlist_ins_next(list1, dlist_head(list1), five);
  dlist_print(list1);
  printf("head next: %d\n", *(int *)list1->head->next->data);
  printf("tail prev: %d\n", *(int *)list1->tail->prev->data);
  dlist_ins_next(list1, dlist_tail(list1)->prev, four);
  dlist_print(list1);
  int result = dlist_ins_next(list1, dlist_tail(list1), five);
  printf("dlist_ins_next(dlist_tail) should be 0: %d\n", result);
  dlist_ins_prev(list1, dlist_head(list1)->next, three);
  dlist_ins_prev(list1, dlist_head(list1)->next, two);
  dlist_print(list1);
  dlist_ins_prev(list1, dlist_tail(list1), three);
  dlist_print(list1);
  result = dlist_ins_prev(list1, dlist_head(list1), five);
  printf("dlist_ins_prev(dlist_head) should be 0: %d\n", result);
  dlist_remove(list1, dlist_head(list1)->next);
  dlist_print(list1);
  dlist_destroy(list1);
  dlist_print(list1);
  free(list1);
}
