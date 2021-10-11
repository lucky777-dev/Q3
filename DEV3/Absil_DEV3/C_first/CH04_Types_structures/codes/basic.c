#include <stdio.h>

struct point
{
    int x, y;  
};

int main()
{
    struct point p;
    p.x = 1; 
    p.y = 2;
    printf("(%d,%d)\n", p.x, p.y);
    
    struct point * pt = &p;
    pt->x = 3; //same as (*pt).x = 3;
    pt->y = 4;
    printf("(%d,%d)\n", pt->x, pt->y);
}
