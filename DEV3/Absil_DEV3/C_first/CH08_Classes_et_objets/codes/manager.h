#ifndef MAG
#define MAG

#include <string>
#include "departement.h"

struct Manager
{
	Departement& dpt;
	std::string nom;
	
	Manager(std::string nom, Departement& dpt);
};

#endif
