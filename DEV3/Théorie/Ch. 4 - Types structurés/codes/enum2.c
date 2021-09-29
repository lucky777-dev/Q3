#include <stdio.h>

typedef enum color { RED, GREEN, BLUE} color;

enum Foo { A, B, C=10, D, E=1, F, G=F+C};
//A=0, B=1, C=10, D=11, E=1, F=2, G=12

int main()
{
    color c = RED;
    
    switch(c) 
    {
        case RED   : printf("red\n"); break;
        case GREEN : printf("green\n"); break;
        case BLUE  : printf("blue\n"); break;
    }
}
