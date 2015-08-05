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
  printf("%d\n", *five);
  List *fives = (List *)malloc(sizeof(List));
  list_init(fives, &destroy_int);
  list_ins_next(fives, NULL, five);
  list_ins_next(fives, list_tail(fives), six);
  ListElmt *iterator = (ListElmt *)malloc(sizeof(ListElmt));
  iterator = list_head(fives);
  printf("%d\n", *(int*)list_data(iterator));
  iterator = iterator->next;
  printf("%d\n", *(int*)list_data(iterator));
}
