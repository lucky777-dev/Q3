#include <stdio.h>
#include <stdlib.h>

int * addr_auto, * addr_dyn, * addr_stat = NULL; //statiques, globales
int global = 2; //statique, globale

int f()
{
	int j = 42; //automatique, locale à f
	addr_auto = &j; //ok
	int * pt = (int*)malloc(sizeof(int)); //dynamique, locale
    *pt = 23; //ok : espace alloué
	addr_dyn = pt; //ok
    static int l = 17; //statique, locale
    addr_stat = &l;
	global = 3;
} //j et pt sont désalloués (mais pas *pt, ni l)

int main()
{
	f();
    printf("%p:", addr_auto); //ok (dangling)
    printf("%d\n", *addr_auto); //KO : j est désaloué	
    printf("%p:", addr_dyn); //ok
    printf("%d\n", *addr_dyn); //ok : *addr_dyn n'a pas été désalloué	
    printf("%p:", addr_stat); //ok
    printf("%d\n", *addr_stat); //ok : l n'a pas été désalloué
    printf("%d\n", global); //ok    
    
    free(addr_dyn);
    printf("%p:", addr_dyn); //ok (dangling)
    printf("%d\n", *addr_dyn); //KO : *addr_dyn est désalloué	    
}