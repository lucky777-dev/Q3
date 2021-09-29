#include <iostream>
#include <memory>

using namespace std;

int main()
{
	shared_ptr<int> p1 = make_shared<int>(5);
	weak_ptr<int> wp1 = p1; //p1 owns the memory.
	
	{
		shared_ptr<int> p2 = wp1.lock(); //Now p1 and p2 own the memory.
		if(p2) //check if the memory still exists!
		{
		    cout << "if p2" << endl;
		}
	} //p2 is destroyed. Memory is owned by p1.
	
	p1.reset(); //Memory is deleted.
	
	shared_ptr<int> p3 = wp1.lock(); //Memory is gone, so we get an empty shared_ptr.
	if(p3)
	{
		cout << "if p3" << endl;
	}
}
