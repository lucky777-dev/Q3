#include <iostream>

using namespace std;

int main()
{
	int x = 3 + 2;
	cout << x << endl;

	x++;
	cout << x << endl;
	++x;
	cout << x << endl << endl;

	int y = x++;
	cout << x << endl;
	cout << y << endl << endl;

	int z = ++x;
	cout << x << endl;
	cout << z << endl;
}
