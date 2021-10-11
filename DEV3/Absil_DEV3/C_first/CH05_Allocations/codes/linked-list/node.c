#include <stdio.h>
#include "node.h"

void print_data(node n)
{
    printf("%d", n.data);
}

void print_node(node* n)
{
    printf("node %p with data %d and next %p\n", n, n->data, n->next);
}