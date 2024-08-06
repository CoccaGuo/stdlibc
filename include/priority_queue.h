#ifndef __stdlibc_priority_queue_h
#define __stdlibc_priority_queue_h

#include "array.h"

typedef int (*cmp)(void*, void*);


typedef struct priority_queue_s {
    array* data;
    cmp comparator;
} priority_queue;


priority_queue* priority_queue_create(size_t element_size, cmp comparator);
priority_queue* priority_queue_create_with_capacity(size_t element_size, cmp comparator, size_t capacity);
priority_queue* priority_queue_create_from_array(array* arr, cmp comparator);
void priority_queue_destroy(priority_queue* q);

void priority_queue_push(priority_queue* q, void* element);
void priority_queue_pop(priority_queue* q, void* ret);
void* priority_queue_peek(priority_queue* q);

size_t priority_queue_size(priority_queue* q);
int priority_queue_empty(priority_queue* q);



#endif