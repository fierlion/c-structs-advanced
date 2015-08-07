#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "list.c"

int * create_int(int intIn) {
  int *intOut;
  intOut = malloc(sizeof(int));
  *intOut = intIn;
  return(intOut);
}

void destroy_int(void *intIn) {
  printf("%d\n", *(int*)intIn);
  free((int*)intIn);
}

int main(int argc, char* argv[]) {
  int *five = create_int(5);
  int *six = create_int(6);
  int *temp = malloc(sizeof(int));
  void *voidtemp = (void*)temp;
  List *fives = (List *)malloc(sizeof(List));
  //test list_init
  list_init(fives, &destroy_int);
  //test list_add
  list_ins_next(fives, NULL, five);
  printf("after add, list size: %d\n", list_size(fives));
  list_ins_next(fives, list_tail(fives), six);
  printf("after add, list size: %d\n", list_size(fives));
  //test list elements
  ListElmt *iterator = (ListElmt *)malloc(sizeof(ListElmt));
  iterator = list_head(fives);
  printf("iterator list data (0): %d\n", *(int*)list_data(iterator));
  iterator = iterator->next;
  printf("iterator list data (1): %d\n", *(int*)list_data(iterator));
  iterator = list_head(fives);
  //test remove next
  list_rem_next(fives, list_head(fives), voidtemp);
  printf("after remove, list size: %d\n", list_size(fives));
  //test remove from head
  list_rem_next(fives, NULL, voidtemp);
  printf("after remove head, list size: %d\n", list_size(fives));
  // test list destroy
  list_destroy(fives);
}
