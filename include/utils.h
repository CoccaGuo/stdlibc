#ifndef __stdlibc_utils_h
#define __stdlibc_utils_h

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/* 
Class ref
return a reference to a basic data type. to avoid deep ref
in array.

`ref(pdata)` : pointer to data
`deref(typename, pref)` : pointer to data
*/
#define ref(pdata)           ref_create(pdata)

/* 
`deref(typename, pref)` : pointer to data
*/
#define deref(type, pref)   ((type*)(((ref*)pref)->data))

typedef struct ref_s {
    void *data;
} ref;

ref* ref_create(void *data);
void ref_destroy(ref *r);

/////////////////////////////////////////////////////


/* 
Class box
put a basic data type into a box on the heap.

`box(type, pdata)` : pointer to data
`unbox(type, pbox)` : pointer to data
*/
#define box(type, pdata)           box_create(pdata, sizeof(type))
/*
`unbox(type, pbox)` : pointer to data
*/
#define unbox(type, pbox)          ((type*)((box*)pbox)->data)


typedef struct box_s {
    void *data;
} box;

box* box_create(void *data, size_t size);
void box_destroy(box *c);

#endif