#include <stdio.h>

long unsigned sneaky(int array[])
{
	return sizeof(array) / sizeof(*array);
}

void print_tab(int tab[], int length)
{
    for(unsigned i = 0; i < length; i++)
        printf("%d ", tab[i]);
    printf("\n");
}

void copy_tab(int tab1[], int tab2[], int l1)
{
    for(unsigned i = 0; i < l1; i++)
        tab1[i] = tab2[i];
}

int main()
{
	int t1[5] = {1,2,3,4};
	int t2[] = {1,2,3,4,5};
	int * t3 = t2;
	//int t4[]; 
	//int t5[5] = {1,2,3,4,5,6}; 
	int t6[8];
	
	for(int i = 0; i < 5; i++)
		printf("%d %d %d %d\n", t1[i], t2[i], t3[i], t6[i]);
		
	printf("%lu\n", sizeof(t6) / sizeof(*t6));
	printf("%lu\n", sneaky(t6));
    
    print_tab(t2, sizeof(t2) / sizeof(*t2));
    
    int i = *(t2 + 3); //4e elem
    printf("%d\n", i);
    
    int t2d[2][3];
    for(unsigned i = 0; i < 2; i++)
        for(unsigned j = 0; j < 3; j++)
            t2d[i][j] = i * j;
    for(unsigned i = 0; i < 2; i++)
    {
        for(unsigned j = 0; j < 3; j++)
            printf("%d ", t2d[i][j]);
        printf("\n");
    }
    printf("\n");
    int * it = t2d;
    for(unsigned i = 0; i < 2; i++)
    {
        for(unsigned j = 0; j < 3; j++)   
        {
            printf("%d ", *it);
            it++;
        }
        printf("\n");
    }
}
