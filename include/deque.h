#ifndef __stdlibc_deque_h
#define __stdlibc_deque_h


#include "array.h"


#define deque(typename)             deque_create(sizeof(typename))


typedef struct deque_s {
    array* data;
    size_t front;
    size_t deque_size;
} deque;


deque* deque_create(size_t element_size);
deque* deque_create_with_capacity(size_t element_size, size_t capacity);
void deque_destroy(deque* q);

void deque_push_last(deque* q, void* element);
void deque_pop_last(deque* q, void* ret);
void* deque_peek_last(deque* q);

void deque_push_first(deque* q, void* element);
void deque_pop_first(deque* q, void* ret);
void* deque_peek_first(deque* q);

size_t deque_size(deque* q);
int deque_empty(deque* q);
size_t deque_capacity(deque* q);

void deque_clear(deque* q);



#endif