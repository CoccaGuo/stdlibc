#include "utils.h"

ref* ref_create(void *data) {
    ref *r = (ref *)malloc(sizeof(ref));
    r->data = data;
    return r;
}

void ref_destroy(ref *r) {
    free(r);
}

box* box_create(void *data, size_t size) {
    box *b = (box *)malloc(sizeof(box));
    b->data = malloc(size);
    memcpy(b->data, data, size);
    return b;
}

void box_destroy(box *b) {
    free(b->data);
    free(b);
}