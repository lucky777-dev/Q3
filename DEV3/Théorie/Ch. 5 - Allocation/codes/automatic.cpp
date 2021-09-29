#include <iostream>

using namespace std;

int main()
{
	int i = 5; //most likely on stack
	while(i >= 0)
	{
		int j = i + 2; //most likely on stack
		
		cout << i << " " << j << endl;

		i--;
	}
	cout << i << endl;
	//cout << j << endl;//j is out of the scope
}
