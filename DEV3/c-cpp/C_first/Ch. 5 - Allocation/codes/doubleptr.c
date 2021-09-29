#include <stdio.h>
#include <stdlib.h>

//But : écrire une fonction qui crée un tableau, et le retourner

int* allocate_auto(int size) //wrong
{
    int tab[size];
    for(int i = 0; i < size; i++)
		tab[i] = i;
    return tab;
}

int* allocate1(int size)
{
	int* pt = (int*)malloc(size * sizeof(int));
	for(int i = 0; i < size; i++)
		pt[i] = i;

	return pt;
}

//But : écrire une fonction qui crée un tableau, et affecte son adresse dans un param (effet bord)

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
    /*
    int * tab = allocate_auto(5);
    for(int i = 0; i < 5; i++)
		printf("%d ", tab[i]);
	printf("\n");
    */        
    
	int * pt = allocate1(5); //create a pointer to store 5 ints
	for(int i = 0; i < 5; i++)
		printf("%d ", pt[i]);
	printf("\n");

	free(pt);    
    
    
	int * pt1 = NULL; 
	
    /*
	allocate2(pt1, 5); //create a pointer to store 5 ints
    //after this call, I want pt1 to be the array

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









