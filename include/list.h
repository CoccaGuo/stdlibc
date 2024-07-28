#ifndef __stdlibc_list_h
#define __stdlibc_list_h

#include <stdint.h>

#define list()             list_create()

typedef struct list_node_s {
    void *data;
    struct list_node_s *prev;
    struct list_node_s *next;
} list_node;

typedef struct list_s {
    list_node *head;
    list_node *tail;
    size_t size;
} list;


list *list_create();
void list_destroy(list *l);
void list_push_back(list *l, void *element);
void list_push_front(list *l, void *element);
void *list_pop_back(list *l);
void *list_pop_front(list *l);
void list_insert(list *l, list_node *pos, void *element);
void list_erase(list *l, list_node *pos);

size_t list_size(list *l);
int list_empty(list *l);



#endif