#include <iostream>
#include <memory>

using namespace std;

int main()
{
	shared_ptr<int> p1 = make_shared<int>(5);
    auto p2 = p1; //ok
	weak_ptr<int> wp1 = p1; //p1 owns the memory.
	
    cout << *p1 << endl;
    *p1 = 6;
    cout << *p1 << endl;
    //cout << *wp1 << endl; //ko : no possession    
    
	{
		shared_ptr<int> p3 = wp1.lock(); //Now p1 and p2 own the memory.
		if(p3) //check if the memory still exists!
		    cout << "if p3 : " << *p3 << endl;
	} //p3 is destroyed. Memory is owned by p1.
    cout << *p1 << endl;
	
	p1.reset(); //Memory is deleted if no other possession
    if(p1)
        cout << *p1 << endl;
    else
        cout << "no memory in p1" << endl;
        
    //try to comment auto p2 = p1
    if(p2)
        cout << *p2 << endl;
    else
        cout << "no memory in p2" << endl;    
	
	shared_ptr<int> p3 = wp1.lock(); //Memory is gone, so we get an empty shared_ptr.
	if(p3)
		cout << "if p3" << endl;
    else
        cout << "no memory in p3" << endl;
}
