#include <iostream>

using namespace std;

struct A
{
	~A() { cout << "-A" << endl; }
};

class ExceptA
{
	A * a;
	const char* msg;

	public:
		ExceptA(A * a, const char* msg) : a(a), msg(msg) {}
		~ExceptA() { delete a; }
		const char* what() const {	return msg; }
};

void f()
{
	try
	{
		int i = 1;
		A  * a = new A;
		//throw i;
		throw ExceptA(a, "Error");
	}	
	catch(const ExceptA & e)
	{
		cout << e.what() << endl;
	}
	catch(...)
	{
		cout << "Exception caught" << endl;		
	}
}

int main()
{
	f();
}
