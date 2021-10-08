#include <iostream>

using namespace std;

struct ressource
{
	bool locked;
	
	ressource() : locked(false) {}	

	bool acquire() 
	{
		if(locked)
			return false;
		else
		{
			locked = true;

			cout << "Ressource " << this << " locked" << endl;

			return true;
		}	
	}
	bool liberate() 
	{
		if(! locked)
			return false;
		else
		{
			locked = false;

			cout << "Ressource " << this << " liberated" << endl;

			return true;			
		}		
	}
};

ressource r1;
ressource r2;

void f()
{
	r1.acquire();
	r2.acquire();
	
	try
	{
		throw 1;
	}
	catch(...)
	{
		r2.liberate();
		r1.liberate();

		throw; // rethrow
	}
		
	r2.liberate();
	r1.liberate();	
}

int main()
{
	f();
}
