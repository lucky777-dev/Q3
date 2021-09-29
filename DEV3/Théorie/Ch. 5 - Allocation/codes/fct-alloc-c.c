#include <stdio.h>
#include <stdlib.h>

void print_int_array(int * array, int size)
{
    for(int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int main()
{
    int * p = (int*) malloc(4 * sizeof(int));
    print_int_array(p, 4); //undeterminate values
    
    free(p);
    print_int_array(p, 4); //undefined behaviour
    
    p = (int*) calloc(4, sizeof(int));
    print_int_array(p, 4); //0 0 0 0
    
    for(int i = 0; i < 4; i++)
        p[i] = i;
    print_int_array(p, 4); //0 1 2 3
    
    p = (int*) realloc(p, 2 * sizeof(int));
    if(p)
    {
        print_int_array(p, 2); //0 1
        print_int_array(p, 4); //0 1 2 3 : not undeterminate
    }
    else
        free(p);
    
    p = (int*) realloc(p, 4 * sizeof(int));
    if(p)
    {        
        print_int_array(p, 2); //0 1
        print_int_array(p, 4); //0 1 ? ?
    }
    else
        free(p);
}
