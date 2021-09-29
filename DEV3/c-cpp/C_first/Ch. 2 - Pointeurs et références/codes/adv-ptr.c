#include <stdio.h>

void increment_and_print(int* ptr, unsigned count)
{
    for(unsigned i = 0; i < count; i++)
    {
        long long shift = (long long)ptr;
        ptr++;
        printf("adress : %p shifted by %ll bytes", ptr, (long long)ptr - shift);
        printf("because sizeof(int) is %zu bytes\n", sizeof(int));
    }
}

int main()
{
    int i = 0;
    int* ptr = &i;
    printf("adress before : %p\n", ptr);
    
    increment_and_print(ptr, 3); //DO NOT deference anymore    
}
