#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

void synch()
{
	int n, p;
	cout << "Donnez une valeur pour n" << endl;//1 2
	cin >> n;
	cout << "Merci pour " << n << endl;
	cout << "Donnez une valeur pour p" << endl;
	cin >> p;
	cout << "Merci pour " << p << endl;
}

void block()
{
	int n = 12;
	char c = 'a';
	cout << "Donnez un entier et un caractère" << endl;//x 25
	cin >> n >> c;
	cout << "Merci pour " << n << " et " << c << endl;
	cout << "Donnez un caractère" << endl;
	cin >> c;
	cout << "Merci pour " << c << endl;
}

void loop()
{
	//3
	//à
	int n;
	do
	{
		cout << "Tapez un nombre entier " << endl;
		cin >> n;
		cout << "Son carré est " << (n*n) << endl;
	}
	while(!n);	
}

void good()
{
    cout << "Tapez un entier" << endl;
        
    string line;
    getline(cin, line);
    
    try
    {
        int i = stoi(line);
        cout << "Vous avez tapé " << i << endl;
    }
    catch(invalid_argument ex)
    {
        cout << "Pas un entier" << endl;
    }
}

int main()
{
	//synch();
	//block();
	//loop();
    good();
}
