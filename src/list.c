#include "list.h"
#include <stdlib.h>

// typedef struct list_s {
//     void *data;
//     struct list_node_s *prev;
//     struct list_node_s *next;
// } list_node;

// typedef struct list_s {
//     list_node *head;
//     list_node *tail;
//     size_t size;
// } list;


list *list_create() {
    list *l = malloc(sizeof(list));
    l->head = NULL;
    l->tail = NULL;
    l->size = 0;
    return l;
}

void list_destroy(list *l) {
    list_node *cur = l->head;
    while (cur != NULL) {
        list_node *tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    free(l);
}

void list_push_back(list *l, void *element) {
    list_node *node = malloc(sizeof(list_node));
    node->data = element;
    node->prev = l->tail;
    node->next = NULL;
    if (l->tail != NULL) {
        l->tail->next = node;
    }
    l->tail = node;
    if (l->head == NULL) {
        l->head = node;
    }
    l->size++;
}

void list_push_front(list *l, void *element) {
    list_node *node = malloc(sizeof(list_node));
    node->data = element;
    node->prev = NULL;
    node->next = l->head;
    if (l->head != NULL) {
        l->head->prev = node;
    }
    l->head = node;
    if (l->tail == NULL) {
        l->tail = node;
    }
    l->size++;
}

void *list_pop_back(list *l) {
    if (l->size == 0) {
        return NULL;
    }
    list_node *node = l->tail;
    void *data = node->data;
    l->tail = node->prev;
    if (l->tail != NULL) {
        l->tail->next = NULL;
    }
    free(node);
    l->size--;
    return data;
}

void *list_pop_front(list *l) {
    if (l->size == 0) {
        return NULL;
    }
    list_node *node = l->head;
    void *data = node->data;
    l->head = node->next;
    if (l->head != NULL) {
        l->head->prev = NULL;
    }
    free(node);
    l->size--;
    return data;
}

void list_insert(list *l, list_node *pos, void *element) {
    list_node *node = malloc(sizeof(list_node));
    node->data = element;
    node->prev = pos->prev;
    node->next = pos;
    if (pos->prev != NULL) {
        pos->prev->next = node;
    }
    pos->prev = node;
    if (l->head == pos) {
        l->head = node;
    }
    l->size++;
}

void list_erase(list *l, list_node *pos) {
    if (pos->prev != NULL) {
        pos->prev->next = pos->next;
    }
    if (pos->next != NULL) {
        pos->next->prev = pos->prev;
    }
    if (l->head == pos) {
        l->head = pos->next;
    }
    if (l->tail == pos) {
        l->tail = pos->prev;
    }
    free(pos);
    l->size--;
}

size_t list_size(list *l) {
    return l->size;
}

int list_empty(list *l) {
    return l->size == 0;
}