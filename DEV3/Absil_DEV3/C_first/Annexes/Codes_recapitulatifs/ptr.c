#include <stdio.h>

void print_tab(int tab[], int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", tab[i]);
    printf("\n");
}

void print_tab2(int* tab, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", *tab);
        tab = tab + 1;
    }
    printf("\n");
}

void print_tab3(int* tab, int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", *(tab + i)); 
    printf("\n");
}

int main()
{
    int i = 2;
    int* pti = &i;
    
    int j = *pti; //j = 2
    
    int * pt = i; //terrifying idea
    
    printf("i = %d, ptr ( %p ) -> %d\n", i, pti, *pti);
    
    i = 4;
    printf("i = %d, ptr ( %p ) -> %d\n", i, pti, *pti);
    
    int tab[] = {1,2,3,4};
    int* ptt = tab; //impl. conv       
    //tab == ptt == adresse du premier élément
    
    print_tab(tab, 4);
    print_tab(ptt, 4);  //ok
    
    print_tab2(tab, 4);
    print_tab3(tab, 4);
}
