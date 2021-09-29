#include <stdio.h>
#include <stdlib.h>

int* allocate(int size)
{
	int* pt = (int*)malloc(size * sizeof(int));
	for(int i = 0; i < size; i++)
		pt[i] = i;

	return pt;
}

//terrifyingly wrong
void allocate2(int* pt, int size)
{
	pt = (int*)malloc(size * sizeof(int));
	for(int i = 0; i < size; i++)
		pt[i] = i;
}

void allocate3(int** pt, int size)
{
	*pt = (int*)malloc(size * sizeof(int));
	for(int i = 0; i < size; i++)
		(*pt)[i] = i; //talk about the importance of ()
}

int main()
{
	int * pt = allocate(5); //create a pointer to store 5 ints
	for(int i = 0; i < 5; i++)
		printf("%d ", pt[i]);
	printf("\n");

	free(pt);

	int * pt1 = NULL; 

	/*
	allocate2(pt1, 5);//create a pointer to store 5 ints

	for(int i = 0; i < 5; i++)
		printf("%d ", pt1[i]);
	printf("\n");
	*/

	allocate3(&pt1, 5);

	for(int i = 0; i < 5; i++)
		printf("%d ", pt1[i]);
	printf("\n");

	free(pt1);
}
