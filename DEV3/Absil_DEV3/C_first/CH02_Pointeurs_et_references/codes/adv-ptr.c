#include <stdio.h>

void increment_and_print(int* ptr, unsigned count)
{
    for(unsigned i = 0; i < count; i++)
    {
        long long shift = (long long)ptr;
        ptr++;
        printf("adress : %p shifted by %lld bytes ", ptr, ((long long)ptr - shift));
        printf("because sizeof(int) is %zu bytes\n", sizeof(int));
    }
}

//pt assumed to be an array
void print_array(int* pt, unsigned n)
{
    for(unsigned i = 0; i < n; i++)
    {
        printf("%d ", *pt);
        pt++;
    }
    printf("\n");        
}

int main()
{
    int i = 0;
    int* ptr = &i;
    printf("adress before : %p\n", ptr);
    
    increment_and_print(ptr, 3); //DO NOT deference anymore 
    printf("%p\n", ptr);
    
    printf("\n");
    
    int tab[] = {1,2,3,4,5};
    print_array(tab, 5);
}
