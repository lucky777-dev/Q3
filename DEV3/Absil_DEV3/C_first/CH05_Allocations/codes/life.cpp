#include <iostream>

using namespace std;

int * addr_auto, * addr_dyn, * addr_stat = NULL; //statiques, globales
int global = 2; //statique, globale

int f()
{
    int j = 42; //automatique, locale à f
	addr_auto = &j; //ok
	int * pt = new int(23); //dynamique, locale
    *pt = 23; //ok : espace alloué
	addr_dyn = pt; //ok
    static int l = 17; //statique, locale
    addr_stat = &l;
	global = 3;
} //j et k sont désalloués (mais pas *k, ni l)

int main()
{
	f();
	cout << addr_auto << ":"; //ok
	cout << *addr_auto << endl; //KO : j est désaloué
	cout << addr_dyn << ":"; //ok
	cout << *addr_dyn << endl; //ok : *pt n'a pas été désalloué
    cout << addr_stat << ":"; //ok
	cout << *addr_stat << endl; //ok : l n'a pas été désalloué
	cout << global << endl; //ok
    
    delete addr_dyn;
    cout << addr_dyn << ":"; //ok
	cout << *addr_dyn << endl; //KO : *pt est désalloué
}