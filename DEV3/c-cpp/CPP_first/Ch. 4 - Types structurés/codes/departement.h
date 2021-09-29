#ifndef DEP
#define DEP

#include <string>

struct Manager;

struct Departement
{
	std::string nom;
	Manager* mgr;//not allocated here

	Departement(std::string nom, Manager* mgr = nullptr);
};

#endif
