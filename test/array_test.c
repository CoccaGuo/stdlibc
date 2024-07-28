#include <stdio.h>

#include "array.h"
#include "utils.h"

int main() {

    // int 
    array *arr = array(int);
    int a = 1;
    int b = 2;
    int c = 3;
    array_push_back(arr, &a);
    array_push_back(arr, &b);
    array_push_back(arr, &c);
    printf("%d ", *(int *)array_at(arr, 0));
    printf("%d ", *(int *)array_at(arr, 1));
    printf("%d\n", *(int *)array_at(arr, 2));
    array_pop_back(arr);
    printf("%d ", *(int *)array_at(arr, 0));
    printf("%d\n", *(int *)array_at(arr, 1));
    array_set(arr, 0, &c);
    printf("%d ", *(int *)array_at(arr, 0));
    array_destroy(arr);
    
    // string
    array *arr3 = array(char *);
    char *g = "hello";
    char *h = "world";
    char *i = "!";
    array_push_back(arr3, g);
    array_push_back(arr3, h);
    array_push_back(arr3, i);
    printf("%s", (char *)array_at(arr3, 0));
    printf("%s", (char *)array_at(arr3, 1));
    printf("%s\n", (char *)array_at(arr3, 2));
    array_pop_back(arr3);
    printf("%s", (char *)array_at(arr3, 0));
    printf("%s\n", (char *)array_at(arr3, 1));
    array_destroy(arr3);

    // for-test
    array *arr4 = array_create_with_capacity(sizeof(int), 4);
    for (int i = 0; i <= 1000; i++) {
        array_push_back(arr4, &i);
    }

    for (int i = 1000-10; i <= 1000; ++i) {
        printf("%d ", *(int*)array_at(arr4, i));
    }
    printf("\n");
    array_destroy(arr4);

    // ref test
    array *arr5 = array(ref);
    for (int i = 0; i <= 100; i++) {
        ref *b = ref(&i);
        array_push_back(arr5, b);
        free(b);
    }

    for (int i = 100-10; i <= 100; ++i) {
        printf("%d ", *deref(int, array_at(arr5, i)));
    }
    printf("\n");
    array_destroy(arr5);


    return 0;
}