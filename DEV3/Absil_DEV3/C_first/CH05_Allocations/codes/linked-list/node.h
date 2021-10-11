#ifndef NODE_H
#define NODE_H

struct node
{
    int data;
    struct node* next;
};

typedef struct node node;

void print_data(node n);
void print_node(node* n);

#endif