#include <string.h>
#include <stdlib.h>
# include "array.h"

// typedef struct array_s {
//     void *data;
//     size_t element_size;
//     size_t size;
//     size_t capacity;
// } array;

array *array_create(size_t element_size) {
    array *arr = (array *)malloc(sizeof(array));
    arr->element_size = element_size;
    arr->size = 0;
    arr->capacity = 8;
    arr->data = malloc(arr->capacity * element_size);
    return arr;
}

void array_destroy(array *arr) {
    free(arr->data);
    free(arr);
}

array *array_create_with_capacity(size_t element_size, size_t capacity) {
    array *arr = (array *)malloc(sizeof(array));
    arr->element_size = element_size;
    arr->size = 0;
    arr->capacity = capacity;
    arr->data = malloc(arr->capacity * element_size);
    return arr;
}

array* array_create_from_carray(size_t element_size, void* carray, size_t size) {
    array *arr = (array *)malloc(sizeof(array));
    arr->element_size = element_size;
    arr->size = size;
    arr->capacity = size;
    arr->data = malloc(arr->capacity * element_size);
    memcpy(arr->data, carray, size * element_size);
    return arr;
}

void array_extend_capacity(array *arr) {
    arr->capacity *= 2;
    arr->data = realloc(arr->data, arr->capacity * arr->element_size);
    // check if realloc failed
    if (arr->data == NULL) {
        // alloc new memory and copy old data
        void *new_data = malloc(arr->capacity * arr->element_size);
        memcpy(new_data, arr->data, arr->size * arr->element_size);
        free(arr->data);
        arr->data = new_data;
    }
}

void array_push_back(array *arr, void *element) {
    if (arr->size == arr->capacity) {
        array_extend_capacity(arr);
    }
    memcpy(arr->data + arr->size * arr->element_size, element, arr->element_size);
    arr->size++;
}

void array_pop_back(array *arr, void *ret) {
    if (arr->size == 0) {
        return;
    }
    arr->size--;
    if (ret != NULL)
        memcpy(ret, arr->data + arr->size * arr->element_size, arr->element_size);
}

void *array_at(array *arr, size_t index) {
    if (index >= arr->size || index < 0) {
        return NULL;
    }   
    return arr->data + index *  arr->element_size;
}

void array_set(array *arr, size_t index, void *element) {
    if (index >= arr->size || index < 0) {
        return;
    }
    memcpy(arr->data + index * arr->element_size, element, arr->element_size);
}

void array_insert(array *arr, size_t index, void *element) {
    if (index >= arr->size || index < 0) {
        return;
    }
    memmove(arr->data + (index + 1) * arr->element_size, arr->data + index * arr->element_size, (arr->size - index) * arr->element_size);
    memcpy(arr->data + index * arr->element_size, element, arr->element_size);
    arr->size++;
}

int array_extend(array *arr, array *other) {
    if (arr->element_size != other->element_size) {
        return 0;
    }
    if (arr->size + other->size > arr->capacity) {
        while (arr->size + other->size > arr->capacity) {
            array_extend_capacity(arr);
        }
    }
    memcpy(arr->data + arr->size * arr->element_size, other->data, other->size * other->element_size);
    arr->size += other->size;
    return 1;
}

void array_swap(array *arr, size_t index1, size_t index2){
    void *tmp = malloc(arr->element_size);
    memcpy(tmp, arr->data + index1 * arr->element_size, arr->element_size);
    memcpy(arr->data + index1 * arr->element_size, arr->data + index2 * arr->element_size, arr->element_size);
    memcpy(arr->data + index2 * arr->element_size, tmp, arr->element_size);
    free(tmp);
}

void array_erase(array *arr, size_t index) {
    memmove(arr->data + index * arr->element_size, arr->data + (index + 1) * arr->element_size, (arr->size - index - 1) * arr->element_size);
    arr->size--;
}

void array_clear(array *arr) {
    arr->size = 0;
}

void array_reserve(array *arr, size_t capacity) {
    arr->capacity = capacity;
    arr->data = realloc(arr->data, arr->capacity * arr->element_size);
    // check if realloc failed
    if (arr->data == NULL) {
        // alloc new memory and copy old data
        void *new_data = malloc(arr->capacity * arr->element_size);
        memcpy(new_data, arr->data, arr->size * arr->element_size);
        free(arr->data);
        arr->data = new_data;
    }
}

size_t array_size(array *arr) {
    return arr->size;
}

int array_empty(array *arr) {
    return arr->size == 0;
}

size_t array_capacity(array *arr) {
    return arr->capacity;
}

