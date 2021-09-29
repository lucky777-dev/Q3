#include <iostream>

using namespace std;

const double PI = 3.14;

double circle_area(double r)
{
	return PI * r * r;
}

int countDown()
{
	static int i = 6;//try to remove '= 6'
	i--;
	return i;
}

void boom()
{
	bool stop = false;
	while(! stop)
	{
		int j = countDown();

		if(j >= 0)
			cout << j << endl;
		else
			stop = true;
	}

	cout << "BOOM" << endl;		
}

int main()
{
	cout << circle_area(2) << endl;

	//cout << i << endl;//i is out of the scope
	
	boom();
}
