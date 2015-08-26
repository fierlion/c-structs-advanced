#include "list.c"

int *create_int(int intIn) {
  int *intOut;
  intOut = malloc(sizeof(int));
  // intialize for valgrind happy
  memset(intOut, 0, sizeof(int));
  *intOut = intIn;
  return(intOut);
}

void destroy_int(void *intIn) {
  free((int*)intIn);
}

int main() {
    // setup
    List *list1 = malloc(sizeof(List));
    memset(list1, 0, sizeof(List));
    int *five = create_int(5);
    int *four = create_int(4);
    int *three = create_int(3);
    int *two = create_int(2);
    int *one = create_int(1);
    ListElmt *go_to_end;
    void *tempvar = malloc(sizeof(int));

    printf("test list_init\n");
    list_init(list1, &destroy_int);

    printf("test list_ins_front\n");
    list_ins_front(list1, five);
    list_ins_front(list1, four);
    list_ins_front(list1, three);
    print_list(list1);

    printf("test list_ins_next\n");
    list_ins_next(list1, list_head(list1), two);
    // find list end
    go_to_end = list_head(list1);
    while(go_to_end->next != NULL) {
        go_to_end = go_to_end->next;
    }
    list_ins_next(list1, go_to_end, one);
    print_list(list1);

    printf("test list_rem_next\n");
    // list_rem_next(list1, list_head(list1), tempvar);
    // list1->destroy(tempvar);
    print_list(list1);

    printf("test list destroy\n");
    list_destroy(list1);
    print_list(list1);
    printf("list size: %d\n", list_size(list1));

    // clean up
    free(tempvar);
    free(list1);
}
