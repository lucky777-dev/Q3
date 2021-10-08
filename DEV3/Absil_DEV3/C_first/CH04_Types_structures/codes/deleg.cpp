#include <iostream>

using namespace std;

class A : AB
{		
	const int k;
    int i;

	private:
		A() : A(0)
		{
			cout << "Init " << endl;
			//k = 5;
		}	
	
	public:
		A(int x) : k(5), i(x)
		{
		}

		void print() { cout << "A : " << i << endl;}
};

int main()
{
	//A a;//error
	A a(3);
}
