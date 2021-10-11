#include <stdio.h>

void f(int * pt) {}

int main()
{
	int i = 3;
	int * pti = &i;

    printf("i = %d, pti ( %p ) : %d\n", i, pti, *pti);
	printf("Pointer address : %p of size %lu\n", &pti, sizeof(pti));
	//printf("i = %d, pti (%p) : %d", i, pti, *pti);
	//printf("Pointer address : %p of size %lu\n", &pti, sizeof(pti));
    
	i++;
    printf("i = %d, pti ( %p ) : %d\n", i, pti, *pti);    
    
	double d = 2.5;
	double * ptd = &d;
	
	//pti = ptd; //Error
    //pti = (int*)ptd; //Ok, but bad idea
	//f(ptd); //Error
	f(NULL); //Ok
	*pti = *ptd;

	//void * ptv = pti;
    //printf("%lu\n", *ptv);
    //int * conv = (int*)ptv;
    //int pointed = *conv;
    //printf("%d\n", *((int*)ptv));

	int * ptn = NULL; //int * ptn = 0; //same stuff
	int * ptinv1;
	int * ptinv2 = 3; //bad idea

    printf("%d\n", *ptn);
    printf("%d\n", *ptinv1); //bad idea
}
