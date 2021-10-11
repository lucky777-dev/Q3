#include <stdio.h>

void foreach_ro(int tab[], int size, void (*f)(int))
{
	for(int i = 0; i < size; i++)
		f(tab[i]);
}

void foreach_rw(int tab[], int size, int (*f)(int))
{
	for(int i = 0; i < size; i++)
		tab[i] = f(tab[i]);
}

void foreach_rw2(int tab[], int size, int (*f1)(int), int (*f2)(int))
{
	for(int i = 0; i < size; i++)
		tab[i] = f1(tab[i]) + f2(tab[i]);
}

void print(int i)
{
	printf("%d ", i);
}

int increment(int i)
{
	return i + 1;
}

int negate(int i)
{
    return -i;   
}

int main()
{
	int tab[] = {1,2,3,4,5};

	foreach_ro(tab, 5, print);
	printf("\n");
	
	foreach_rw(tab, 5, increment);
	foreach_ro(tab, 5, print);
	printf("\n");
    
    foreach_rw(tab, 5, negate);
	foreach_ro(tab, 5, print);
	printf("\n");
}
