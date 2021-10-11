#include <stdio.h>
#include <stdlib.h>

#include "list.h"

list create_list()
{
    list l = {NULL, NULL, 0};
    return l;
}

int length(list l)
{    
    return l.length;
}

void print_list(list l)
{
    printf("{ ");
    
    if(l.length != 0)
    {        
        node* current = l.head;
        
        while(current != NULL) //tant que je suis pas après tail
        {
            print_data(*current);
            printf(" ");
            current = current->next;
        }
    }
    
    printf("}\n");
}

bool push_back(list* l, int data)
{
    node* n = (node*) malloc(sizeof(node));
    if(n == NULL) //if malloc fails
        return false;
    
    n->data = data;
    n->next = NULL;
    
    if(l->length == 0)
    {
        l->head = n;   
        l->tail = n;
    }
    else
    {        
        l->tail->next = n;
        l->tail = n;
    }
    
    (l->length)++;
    return true;
}

void free_list(list* l)
{
    if(l->length != 0)
    {        
        node* current = l->head;
        
        while(current != NULL)
        {
            node* to_free = current;
            current = current->next;
            free(to_free);
        }
    }
    
    l->length = -1;
}

bool is_free(list l)
{
    return l.length == -1;   
}