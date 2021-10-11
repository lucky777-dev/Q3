#include <iostream>

using namespace std;

int main()
{
	int a[] = {1, 2};
	int* pt = &a[0];
	*(pt + 1) = 10;   //OK : p + 1 is an rvalue, but *(p + 1) is an lvalue

	//taking adress
	int i = 10;
	//int* pti = &(i + 1);   // KO : lvalue required
	int* pti = &i;           // OK: i is an lvalue
	//&i = 20;               // KO : lvalue required

	//reference making
	//std::string& sref = std::string(); //KO : non const-ref init from rvalue
}
