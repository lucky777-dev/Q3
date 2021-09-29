#include <stdio.h>

int main()
{
	int x = 3 + 2;
    printf("%d\n", x);	

	x++;
	printf("%d\n", x);
	++x;
	printf("%d\n\n", x);

	int y = x++;
	printf("%d\n", x);
	printf("%d\n\n", y);

	int z = ++x;
	printf("%d\n", x);
	printf("%d\n", z);
}
