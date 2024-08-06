#include "priority_queue.h"
#include <stdlib.h>
#include <string.h>

void heapify_down(priority_queue* q, int i);
void heapify_up(priority_queue* q, int i);

priority_queue* priority_queue_create(size_t element_size, cmp comparator) {
    return priority_queue_create_with_capacity(element_size, comparator, 0);
}

priority_queue* priority_queue_create_with_capacity(size_t element_size, cmp comparator, size_t capacity) {
    priority_queue* q = malloc(sizeof(priority_queue));
    q->data = array_create_with_capacity(element_size, capacity);
    q->comparator = comparator;
    return q;
}

priority_queue* priority_queue_create_from_array(array* arr, cmp comparator){
    priority_queue* q = malloc(sizeof(priority_queue));
    q->data = arr;
    q->comparator = comparator;
    for (int i = array_size(q->data) / 2 - 1; i >= 0; i--) {
        heapify_down(q, i);
    }
    return q;
}


void priority_queue_destroy(priority_queue* q) {
    array_destroy(q->data);
    free(q);
}


/* 获取左子节点的索引 */
int left(int i) {
    return 2 * i + 1;
}

/* 获取右子节点的索引 */
int right(int i) {
    return 2 * i + 2;
}

/* 获取父节点的索引 */
int parent(int i) {
    return (i - 1) / 2; // 向下整除
}

// heapify from bottom to top
void heapify_up(priority_queue* q, int i) {
    while (i > 0) {
        int p = parent(i);
        if (q->comparator(array_at(q->data, i), array_at(q->data, p)) < 0) {
            array_swap(q->data, i, p);
            i = p;
        } else {
            break;
        }
    }
}

// heapify from top to bottom
void heapify_down(priority_queue* q, int i) {
    while (left(i) < array_size(q->data)) {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (l < array_size(q->data) && q->comparator(array_at(q->data, l), array_at(q->data, smallest)) < 0) {
            smallest = l;
        }
        if (r < array_size(q->data) && q->comparator(array_at(q->data, r), array_at(q->data, smallest)) < 0) {
            smallest = r;
        }
        if (smallest != i) {
            array_swap(q->data, i, smallest);
            i = smallest;
        } else {
            break;
        }
    }
}

void priority_queue_push(priority_queue* q, void* element) {
    array_push_back(q->data, element);
    heapify_up(q, array_size(q->data) - 1);
}

void priority_queue_pop(priority_queue* q, void* ret) {
    if (array_empty(q->data)) {
        return;
    }
    memcpy(ret, array_at(q->data, 0), q->data->element_size);
    array_swap(q->data, 0, array_size(q->data) - 1);
    array_pop_back(q->data, NULL);
    heapify_down(q, 0);    
}

void* priority_queue_peek(priority_queue* q) {
    return array_at(q->data, 0);
}

size_t priority_queue_size(priority_queue* q) {
    return array_size(q->data);
}

int priority_queue_empty(priority_queue* q) {
    return array_empty(q->data);
}