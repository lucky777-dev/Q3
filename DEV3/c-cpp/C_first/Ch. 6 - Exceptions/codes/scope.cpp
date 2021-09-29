#include <iostream>

using namespace std;

void f(int& n)
{
	int i = 1;
	try
	{		
		int& j = i;
		n++;
		throw j;
	}
	catch(int& j)
	{
		n++;//n is accessible
		j++;
		cout << "i : " << i << endl;//copied
		cout << "j : " << j << endl;
	}
}

void f2(int& n)
{
	int i = 1;
	try
	{
		int* j = &i;
		n++;
		throw j;
	}
	catch(int* pt)
	{
		n++;
		(*pt)++;	
		cout << "i : " << i << endl;
		cout << "j : " << *pt << endl;
	}
}

void g()
{
	try
	{
		int i = 1;
		int* pti = &i;
		throw pti;
	}
	catch(int* pti)
	{
		cout << "*pti : " << *pti << endl; //undefined behaviour
	}
}

int main()
{
	int n = 1;
	f(n);
	cout << "n : " << n << endl;

	n = 1;
	f2(n);
	cout << "n : " << n << endl;
	g();
}
