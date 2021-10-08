#include <stdio.h>

void swap(int * ptx, int * pty)
{
	printf("Entering swap : %d %d\n", *ptx, *pty);

	int* tmp = pty;
	pty = ptx;
	ptx = tmp;

	printf("Exiting swap : %d %d\n", *ptx, *pty);
}

int main()
{
	int x = 2;
	int y = 3;

	printf("Before call : %d %d\n", x, y);
    swap(&x, &y);
    printf("After call : %d %d\n", x, y);
}
