#include <stdio.h>

int f(int i)
{
	printf("Integer %d\n", i);
	return 0;
}

int f(double d) //you can't overload
{
	printf("Double %f\n", d);
	return 0;
}

int f(int i, int j) //you still can't, even with more params
{
    printf("Integers %d and %d\n", i, j);
    return 0;
}

int main()
{
	int k = 1;
	f(k);
	double d = 2.1;
	f(d);
	f(k,d);
}
