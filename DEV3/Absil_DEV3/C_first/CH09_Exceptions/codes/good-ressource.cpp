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

class ressource_ptr
{
	private:
		ressource* ptr;
		bool acquired;

	public:
		ressource_ptr(ressource& r) : ptr(&r), acquired(r.acquire()) {}

		virtual ~ressource_ptr()
		{
			acquired = ptr->liberate();
		}
		
		bool operator() () 
		{ 
			return acquired;
		}
};

void f()
{
	ressource_ptr ptr1(r1);
	ressource_ptr ptr2(r2);

	throw 1;
}

int main()
{
	f();
}
