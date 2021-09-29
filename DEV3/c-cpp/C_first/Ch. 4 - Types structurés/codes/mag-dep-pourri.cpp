#include <iostream>
#include <string>

using namespace std;

struct Manager
{
	Departement& dpt;
	string nom;
	
	Manager(string nom, Departement& dpt) : nom(nom), dpt(dpt) {}
};

struct Departement
{
	Manager mgr;
	string nom;

	Departement(string nom) : nom(nom) {}
};

int main()
{
	Departement esi("ESI");
	Manager aro("Rousseau", esi);
	esi.mgr = aro;
}
