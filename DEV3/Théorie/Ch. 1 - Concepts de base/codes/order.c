#include <stdio.h>

void g();
void f();

int main()
{
	f();
	g();
}

void f()
{
	printf("Coucou\n");
}

void g()
{
	printf("Beuh\n");
}
