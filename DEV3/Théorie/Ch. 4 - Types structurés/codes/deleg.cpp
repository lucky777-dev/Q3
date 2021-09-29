#include <iostream>

using namespace std;

class A
{	
	int i;
	const int k;

	private:
		A() : k(5)
		{
			cout << "Init " << endl;
			//k = 5;
		}	
	
	public:
		A(int x) : A()/*, i(x)*/ 
		{
			i = x;
		}

		void print() { cout << "A : " << i << endl;}
};

int main()
{
	//A a;//error
	A a(3);
}
