#include <stdio.h>
#include <stdlib.h>

int * pt1, * pt2, * pt3 = NULL; //statiques, globales
int global = 2; //statique, globale

int f()
{
	int j = 42; //automatique, locale à f
	pt1 = &j; //ok
	int * k = (int*)malloc(sizeof(int)); //dynamique, locale
    *k = 23; //ok : espaec alloué
	pt2 = k; //ok
    static int l = 17; //statique, locale
    pt3 = &l;
	global = 3;
} //j et k sont désalloués (mais pas *k, ni l)

int main()
{
	f();
    printf("%p:", pt1); //ok
    printf("%d\n", *pt1); //ko : j est désaloué	
    printf("%p:", pt2); //ok
    printf("%d\n", *pt2); //ko : *k n'a pas été désalloué	
    printf("%p:", pt3); //ok
    printf("%d\n", *pt3); //ok : l n'a pas été désalloué
    printf("%d\n", global); //ok
}