#ifndef LIST_H
#define LIST_H
#include <stdbool.h>

#include "node.h"

struct list
{
    node* head;
    node* tail;    
    int length;
};

typedef struct list list;

list create_list();
int length(list l);
void print_list(list l);

bool push_back(list* l, int data);
//bool push_front(list* l, int data);
//bool push_middle(list* l, node* index, int data);

//bool pop_back(list* l);
//bool pop_head(list* l);
//bool remove_middle(list* l, int index);

void free_list(list* l);
bool is_free(list l);

#endif