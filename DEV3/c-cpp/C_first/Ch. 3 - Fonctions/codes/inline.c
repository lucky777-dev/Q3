#include <stdio.h>

void for_each(int* array, unsigned n, int (*f)(int))
{
    for(unsigned i = 0; i < n; i++)
        array[i] = f(array[i]);
}

int plus_one(int i)
{
    return i + 1;   
}

inline int plus_two(int i)
{
    return i + 2;   
}

int main()
{
    int array[] = {1,2,3,4,5};
    for_each(array, 5, plus_one);
    for(unsigned i = 0; i < 5; i++)
        printf("%d ", array[i]);
    printf("\n");
    
    /*
    for_each(array, 5, plus_two);
    for(unsigned i = 0; i < 5; i++)
        printf("%d ", array[i]);
    printf("\n");
    */
}
