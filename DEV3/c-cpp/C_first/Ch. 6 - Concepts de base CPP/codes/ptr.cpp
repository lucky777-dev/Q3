#include <iostream>

using namespace std;

void f(int * pt) {}

int main()
{
	int i = 3;
	int * pti = &i;

	cout << "i = " << i << ", pti (" << pti << ") : " << *pti << endl;
	cout << "Pointer address : " << &pti << " of size " << sizeof(pti) << endl;
	//printf("i = %d, pti (%p) : %d", i, pti, *pti);
	//printf("Pointer address : %p of size %lu\n", &pti, sizeof(pti));

	i++;
	cout << i << " " << *pti << endl;

	double d = 2.5;
	double * ptd = &d;
	
	//pti = ptd; //Error
	//f(ptd); //ERRRO
	f(NULL); //Ok
	*pti = *ptd;

	void * ptv = pti;
	//cout << *ptv << endl;

	int * ptn = nullptr; //int * ptn = NULL;
	int * ptinv1 ;
	//int * ptinv2 = 3; //Error

	cout << *ptn << endl; //undefined behaviour
	cout << *ptinv1 << endl; //undefined behaviour
}
