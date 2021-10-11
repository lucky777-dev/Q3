#include <iostream>

using namespace std;

/*
void brol(char*)
{
	cout << "Brol char" << endl;
}
*/

void brol(double*)
{
	cout << "Brol double" << endl;
}

void brol(void*)
{
	cout << "Brol void" << endl;
}

void brol(int*)
{
	cout << "Brol int" << endl;
}

/*
void brol(int* const)//try to uncomment that
{
	cout << "int const" << endl;
}
*/

void brol(const int*)
{
	cout << "Const int" << endl;
}

int main()
{
	char * ptc;
	double * ptd;
	
	brol(ptc);// char, try when remove brol(char*) -> void
	brol(ptd);// double

	void* ptv;
	
	brol(ptv);//remove brol(void*) for this call : ERROR (no conv)

	int n = 3;
	const int p = 5;

	brol(&n);
	brol(&p);		
}
