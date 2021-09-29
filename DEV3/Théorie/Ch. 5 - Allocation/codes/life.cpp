#include <iostream>

using namespace std;

int * pt1, * pt2, * pt3 = nullptr; //statiques, globales
int global = 2; //statique, globale

int f()
{
	int j = 42; //automatique, locale à f
	pt1 = &j; //ok
	int * k = new int(23); //dynamique, locale
	pt2 = k; //ok
    static int l = 17; //statique, locale
    pt3 = &l;
	global = 3;
} //j et k sont désalloués (mais pas *k, ni l)

int main()
{
	f();
	cout << pt1 << ":"; //ok
	cout << *pt1 << endl; //ko : j est désaloué
	cout << pt2 << ":"; //ok
	cout << *pt2 << endl; //ok : *k n'a pas été désalloué
    cout << pt3 << ":"; //ok
	cout << *pt3 << endl; //ok : l n'a pas été désalloué
	cout << global << endl; //ok
}