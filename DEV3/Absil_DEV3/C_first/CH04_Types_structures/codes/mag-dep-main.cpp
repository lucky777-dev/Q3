#include <iostream>
#include "departement.h"
#include "manager.h"

using namespace std;

int main()
{
	Departement esi("ESI");
	Manager aro("Rousseau", esi);

	esi.mgr = &aro;
}
