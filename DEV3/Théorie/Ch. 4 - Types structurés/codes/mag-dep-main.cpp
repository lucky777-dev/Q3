#include <iostream>
#include "departement.h"
#include "manager.h"

using namespace std;

int main()
{
	Departement esi("ESI");
	Manager mwi("Willemse", esi);

	esi.mgr = &mwi;
}
