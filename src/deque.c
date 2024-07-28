#include <stdlib.h>
#include <string.h>
#include "deque.h"

deque* deque_create(size_t element_size) {
    return deque_create_with_capacity(element_size, 8);
}

deque* deque_create_with_capacity(size_t element_size, size_t capacity) {
    deque* q = (deque *)malloc(sizeof(deque));
    q->data = array_create_with_capacity(element_size, capacity);
    q->front = 0;
    q->deque_size = 0;
    return q;
}

void deque_destroy(deque* q) {
    array_destroy(q->data);
    free(q);
}


void* _deque_at(deque* q, size_t index) {
    return q->data->data + index * q->data->element_size;
}

void _deque_set(deque* q, size_t index, void* element) {
    memcpy(q->data->data + index * q->data->element_size, element, q->data->element_size);
}

void deque_push_first(deque* q, void* element) {
    if (q->deque_size == q->data->capacity) {
        array_extend_capacity(q->data);
    }
    q->front = (q->front - 1 + q->data->capacity) % q->data->capacity;
    // array_set(q->data, q->front, element);
    _deque_set(q, q->front, element);
    q->deque_size++;
}

void deque_push_last(deque* q, void* element) {
   if (q->deque_size == q->data->capacity) {
       array_extend_capacity(q->data);
   }
    // array_set(q->data, (q->front + q->deque_size) % (q->data->capacity), element);
    // because the size of the array is not increased when deque_push, so we manage the index by ourselves
    _deque_set(q, (q->front + q->deque_size) % (q->data->capacity), element);
    q->deque_size++;
}

void* deque_pop_first(deque* q) {
    void* element = deque_peek_first(q);
    q->front = (q->front + 1) % q->data->capacity;
    q->deque_size--;
    return element;
}

void* deque_pop_last(deque* q) {
    void* element = deque_peek_last(q);
    q->front = (q->front + 1) % q->data->capacity;
    q->deque_size--;
    return element;
}

void* deque_peek_first(deque* q) {
    if (q->deque_size == 0) {
        return NULL;
    }
    // return array_at(q->data, q->front);
    return _deque_at(q, q->front);
}

void* deque_peek_last(deque* q) {
    if (q->deque_size == 0) {
        return NULL;
    }
    // return array_at(q->data, (q->front + q->deque_size - 1) % q->data->capacity);
    return _deque_at(q, (q->front + q->deque_size - 1) % q->data->capacity);
}

size_t deque_size(deque* q) {
    return q->deque_size;
}

int deque_empty(deque* q) {
    return q->deque_size == 0;
}

size_t deque_capacity(deque* q) {
    return q->data->capacity;
}


void deque_clear(deque* q) {
    q->front = 0;
    q->deque_size = 0;
}
