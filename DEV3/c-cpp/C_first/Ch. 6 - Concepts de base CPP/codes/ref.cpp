#include <iostream>

using namespace std;

int main()
{
	int i = 2;
	int & ri = i;
	//int & rj;
	cout << i << " " << ri << endl;	

	i++;
	cout << i << " " << ri << endl;
	ri = 5;
	cout << i << " " << ri << endl;

	int j = 8;
	ri = j;

	cout << i << " " << ri << endl;

	double d = 2.5;
	double & rd = d;

	ri = d;
	ri = rd;
    
    cout << i << " " << ri << endl;
    cout << d << " " << rd << endl;
}
