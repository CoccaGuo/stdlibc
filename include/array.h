#ifndef __stdlibc_array_h
#define __stdlibc_array_h

#include <stdint.h>


#define array(typename)             array_create(sizeof(typename))

typedef struct array_s {
    void *data;
    size_t element_size;
    size_t size;
    size_t capacity;
} array;

array *array_create(size_t element_size);
void array_destroy(array *arr);
array *array_create_with_capacity(size_t element_size, size_t capacity);
void array_extend_capacity(array *arr);

void array_push_back(array *arr, void *element);
void *array_pop_back(array *arr);
void *array_at(array *arr, size_t index);
void array_set(array *arr, size_t index, void *element);
void array_insert(array *arr, size_t index, void *element);
void array_erase(array *arr, size_t index);

void array_clear(array *arr);
void array_reserve(array *arr, size_t capacity);
size_t array_size(array *arr);
int array_empty(array *arr);
size_t array_capacity(array *arr);

#define array_get(arr, index)  array_at(arr, index)

#endif