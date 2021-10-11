#include <iostream>
#include <stdexcept>
#include <memory>

using namespace std;

struct A 
{
	A(int i) { cout << "+A " << i << endl; }
	
	~A()
	{
		cout << "-A" << endl;
	}
};

int main()
{
    //A * a = nullptr; //ugly
	try
	{
		//A * a = new A(3); //wrong
        //a = new A(3); //ugly
		auto smart = make_shared<A>(3); //good
		throw 0;
	}
	catch(const int & i)
	{
		cerr << "Error" << endl;
        //if(a != nullptr)
        //    delete a;
	}
    
    //if(a != nullptr)
    //        delete a;
}
