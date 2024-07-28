#include "list.h"
#include <stdio.h>
#include "utils.h"

int main() {
    list *l = list();

    for (int i = 0; i < 10; i++) {
        list_push_back(l, &i);
    }

    // print list in a while loop
    list_node *cur = l->head;
    while (cur != NULL) {
        printf("%d ", *(int*)cur->data);
        cur = cur->next;
    }
    printf("\n");
    list_destroy(l);

    // list test static cast
    list *l2 = list();
    for (int i = 0; i < 20; i++) {
        list_push_back(l2, (int*)i);
    }

    list_node *cur2 = l2->head;
    while (cur2 != NULL) {
        printf("%d ", (int)cur2->data);
        cur2 = cur2->next;
    }
    printf("\n");
    list_destroy(l2);

    // list test box
    list *l3 = list();

    for (int i = 100; i < 110; i++) {
        box *b = box(int, &i);
        list_push_back(l3, b);
    }

    list_node *cur3 = l3->head;
    while (cur3 != NULL) {
        printf("%d ", *unbox(int, cur3->data));
        // destroy box
        box_destroy(cur3->data);
        cur3 = cur3->next;
    }
    printf("\n");
    list_destroy(l3);
    return 0;
  
}