#include <iostream>

using namespace std;

class A
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

struct B : A
{    
    B() : A(7), j(3)
    {}
    
    B(int  i, int j) : A(i), j(j)
    {}
    
    private:
        int j;
}

int main()
{
	//A a;//error
	A a(3);
    
    B b; //ok
    B b(6, 3); //ok
}
