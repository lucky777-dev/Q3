#include <iostream>

using namespace std;

void swap(int& x, int& y)
{
	cout << "Entering swap : " << x << " " << y << endl;	

	int tmp = y;
	y = x;
	x = tmp;

	cout << "Exiting swap : " << x << " " << y << endl;
}

int main()
{
	int i = 1;
	int j = 2;

	cout << "Before call : " << i << " " << j << endl;
	swap(i, j);
	cout << "After call : " << i << " " << j << endl;
}
