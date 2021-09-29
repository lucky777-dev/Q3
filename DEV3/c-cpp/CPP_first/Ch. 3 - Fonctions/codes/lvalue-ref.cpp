#include <iostream>

using namespace std;

int n = 5;

int& truc = n;

int& brol()
{
	return n;
}

int main()
{
	cout << brol() << endl;
	brol() = 10;
	cout << brol() << endl;

	truc = 15;

	cout << brol() << endl;

	//int & i = 2;
}
