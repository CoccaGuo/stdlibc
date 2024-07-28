#include <stdio.h>
#include "queue.h"
#include "utils.h"

int main()
{

    // int
    queue *q = queue(int);
    printf("queue capacity: %I64d\n", queue_capacity(q));
    printf("queue size: %I64d\n", queue_size(q));

    int a = 1;
    int b = 2;
    int c = 3;
    queue_push(q, &a);
    queue_push(q, &b);
    queue_push(q, &c);



    printf("%d ", *(int *)queue_pop(q));
    printf("%d ", *(int *)queue_pop(q));
    printf("%d\n", *(int *)queue_pop(q));
    queue_destroy(q);

    // string
    queue *q3 = queue(char *);
    char *g = "hello";
    char *h = "world";
    char *i = "!";
    queue_push(q3, g);
    queue_push(q3, h);
    queue_push(q3, i);
    printf("%s", (char *)queue_pop(q3));
    printf("%s", (char *)queue_pop(q3));
    printf("%s\n", (char *)queue_pop(q3));
    queue_destroy(q3);

    // for-test
    queue *q4 = queue(int);
    for (int i = 0; i <= 1000; i++) {
        queue_push(q4, &i);
    }

    for (int i = 0; i <= 10; ++i) {
        printf("%d ", *(int*)queue_pop(q4));
    }
    printf("\n");
    queue_destroy(q4);

    // ref test
    queue *q5 = queue(ref);
    for (int i = 0; i <= 100; i++) {
        ref *b = ref(&i);
        queue_push(q5, b);
        free(b);
    }

    for (int i = 100-10; i <= 100; ++i) {
        printf("%d ", *deref(int, queue_pop(q5)));
    }
    printf("\n");
    queue_destroy(q5);

    // circular queue test
    queue *q6 = queue_create_with_capacity(sizeof(int), 4);
    int t = 1;
    queue_push(q6, &t);
    t++;
    queue_push(q6, &t);
    t++;
    queue_push(q6, &t);
    t++;
    queue_push(q6, &t);
    t++;

    queue_pop(q6);
    queue_pop(q6);

    queue_push(q6, &t);
    t++;
    queue_push(q6, &t);

    while (queue_size(q6) > 0) {
        printf("%d ", *(int *)queue_pop(q6));
    }
    printf("\n");

    printf("queue capacity: %I64d (should be 4)\n", queue_capacity(q6));

    queue_destroy(q6);

    return 0;
}