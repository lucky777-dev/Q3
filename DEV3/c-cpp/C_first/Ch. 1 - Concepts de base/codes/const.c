#include <stdio.h>

#define PI 3.141592654

int main()
{
	int i = 2;
	const int ci = 3;

	i += 2;
	//ci += 2; //ko
    
    //PI = PI + 2;     
    printf("%d\n", PI);
    //printf("%p\n", &PI);
}
