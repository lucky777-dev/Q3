#include <stdio.h>
#include "node.h"
#include "list.h"

int main()
{
    node n0;            //data = ?, next = ?
    node n1 = {1};      //data = 1, next = 0
    node n2 = {2, &n0}; //data = 2, next = &n0
    
    print_node(&n0);
    print_node(&n1);
    print_node(&n2);
    
    list l = create_list();
    print_list(l);
    
    for(int i = 0; i < 5; i++)
        push_back(&l, i);
    print_list(l);
    
    free_list(&l);
    printf("%d\n", is_free(l));
}
        
        
        
        
        
        
        
