#include <stdio.h>
#include <limits.h>

int main()
{
	int x = INT_MAX;
	printf("%d\n", x);
	x+=x;//overflow
	printf("%d\n\n", x);

	float y = 1E30;   
	printf("%f\n", y);
    printf("%f\n\n", y / y / y / y);	

	double zero = 0;
	printf("%f\n", x / zero);
}