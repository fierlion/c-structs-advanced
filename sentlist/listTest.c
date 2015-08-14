#include "list.c"

int main() {
    List * list1 = malloc(sizeof(List));
    list_init(list1);
    int *five = malloc(sizeof(int));
    int *four = malloc(sizeof(int));
    int *three = malloc(sizeof(int));
    *five = 5;
    *four = 4;
    *three = 3;
    list_ins_front(list1, five);
    list_ins_front(list1, four);
    list_ins_front(list1, three);
    ListElmt *iterator = malloc(sizeof(ListElmt));
    iterator = list_head(list1)->next;
    printf("the value of the list1[0]: %d\n", *(int*)iterator->data);
    iterator = iterator->next;
    printf("the value of the list1[1]: %d\n", *(int*)iterator->data);
    iterator = iterator->next;
    printf("the value of the list1[2]: %d\n", *(int*)iterator->data);
}
