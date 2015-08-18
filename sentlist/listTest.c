#include "list.c"

void print_list(List *list) {
    ListElmt *iterator = malloc(sizeof(ListElmt));
    iterator = list_head(list)->next;
    for (int i = 0; i < list_size(list); i++) {
        printf("the value of list%d: %d\n", i, *(int*)iterator->data);
        iterator = iterator->next;
    }
}

void destroy_int(void *intIn) {
  free((int*)intIn);
}

int main() {
    List *list1 = malloc(sizeof(List));
    printf("test list_init\n");
    list_init(list1, &destroy_int);
    printf("list_init success\n");

    printf("test list_ins_front\n");
    int *five = malloc(sizeof(int));
    int *four = malloc(sizeof(int));
    int *three = malloc(sizeof(int));
    *five = 5;
    *four = 4;
    *three = 3;
    list_ins_front(list1, five);
    list_ins_front(list1, four);
    list_ins_front(list1, three);
    print_list(list1);

    printf("test list_ins_next\n");
    int *two = malloc(sizeof(int));
    int *one = malloc(sizeof(int));
    *two = 2;
    *one = 1;
    list_ins_next(list1, list_head(list1), two);
    ListElmt *go_to_end = malloc(sizeof(ListElmt));
    go_to_end = list_head(list1);
    while(go_to_end->next != NULL) {
        go_to_end = go_to_end->next;
    }
    list_ins_next(list1, go_to_end, one);
    print_list(list1);

    printf("test list_rem_next\n");
    void *tempvar = malloc(sizeof(int));
    list_rem_next(list1, list_head(list1), tempvar);
    list1->destroy(tempvar);
    print_list(list1);
    
}
