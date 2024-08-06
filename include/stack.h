#ifndef __stdlibc_stack_h
#define __stdlibc_stack_h

#include "deque.h"

typedef deque stack;

#define stack(typename)             deque_create(sizeof(typename))
#define stack_create(element_size)                             deque_create(element_size)
#define stack_create_with_capacity(element_size, capacity)     deque_create_with_capacity(element_size, capacity)

#define stack_destroy(q)           deque_destroy(q)
#define stack_push(q, element)     deque_push_last(q, element)
#define stack_pop(q, ret)               deque_pop_last(q, ret)

#define stack_size(q)              deque_size(q)
#define stack_empty(q)             deque_empty(q)
#define stack_capacity(q)          deque_capacity(q)

#define stack_clear(q)             deque_clear(q)

#endif