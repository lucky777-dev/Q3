#include <iostream>

using namespace std;

int main()
{
	cout << "Tapez un entier" << endl;
	int i;
	cin >> i;
	cout << "Vous avez tapé " << i << endl;

	cout << "Tapez un flottant" << endl;
	double d;
	cin >> d;
	cout << "Vous avez tapé " << d << endl;

	cout << "Tapez deux entier" << endl;
	int j, k;
	cin >> j >> k;
	cout << "Vous avez tapé " << j << " et " << k << endl;	

	cout << "Tapez une chaîne de caractères" << endl;
	string s;
	cin >> s;
	cout << "Vous avez tapé " << s << endl;	
}
