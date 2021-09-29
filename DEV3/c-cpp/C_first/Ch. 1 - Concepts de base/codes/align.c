#include <stdio.h>

struct A
{
	int i; //size 4
};

struct B
{
	char c; //size 1
};

struct C
{
	int i; //size 4
	char c; //size 1
	//3 bytes padding
}; //size 8

int main()
{
	printf("%lu %lu %lu\n", sizeof(struct A), sizeof(struct B), sizeof(struct C));
}
