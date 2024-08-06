#include <stdio.h>
#include "priority_queue.h"


int compare(void* a, void* b) {
    return *(int*)b - *(int*)a;
}

int main() {
    priority_queue* q = priority_queue_create(sizeof(int), compare);
    int a[] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
    int size = sizeof(a) / sizeof(a[0]);
    for (int i = 0; i < size; i++) {
        priority_queue_push(q, &a[i]);
    }

    while (!priority_queue_empty(q)) {
        int ret;
        priority_queue_pop(q, &ret);
        printf("poped: %d , element left:", ret);
        for (int i = 0; i < priority_queue_size(q); i++) {
            printf("%d ", *(int*)array_at(q->data, i));
        }
        printf("\n");
    }
    printf("\n");

    priority_queue_destroy(q);

    return 0;
}