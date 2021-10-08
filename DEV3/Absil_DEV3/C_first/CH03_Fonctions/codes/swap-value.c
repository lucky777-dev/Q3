#include <stdio.h>

void swap(int x, int y)
{
    printf("Entering swap : %d %d\n", x, y);
    
    int tmp = y;
    y = x;
    x = tmp;
    
    printf("Exiting swap : %d %d\n", x, y);
}

int main()
{
    int x = 2; 
    int y = 3;
    
    printf("Before call : %d %d\n", x, y);
    swap(x, y);
    printf("After call : %d %d\n", x, y);
}
