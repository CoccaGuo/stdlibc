#ifndef __stdlibc_queue_h
#define __stdlibc_queue_h

#include "deque.h"

typedef deque queue;

#define queue(typename)             deque_create(sizeof(typename))

#define  queue_create(element_size)                             deque_create(element_size)
#define  queue_create_with_capacity(element_size, capacity)     deque_create_with_capacity(element_size, capacity)
#define  queue_destroy(q)           deque_destroy(q)

#define  queue_push(q, element)     deque_push_last(q, element)
#define  queue_pop(q, ret)               deque_pop_first(q, ret)
#define  queue_peek(q)              deque_peek_first(q)

#define  queue_size(q)              deque_size(q)
#define  queue_empty(q)             deque_empty(q)
#define  queue_capacity(q)          deque_capacity(q)
#define  queue_clear(q)             deque_clear(q)

#endif