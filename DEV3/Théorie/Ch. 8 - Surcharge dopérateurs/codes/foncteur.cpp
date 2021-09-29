#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Tada //try to remove default cstr
{
	public:
		void operator () (int n)
		{
			cout << "Tada " << n << endl;
		}
};

void f(int& n)
{
	cout << "Applying f on " << n << endl;
	n = n * 2;
	if(n % 3 == 0)
		n++;
}

bool impair(int n)
{
	return n % 2 == 1;
}

int main()
{	
	vector<int> v = {1, 2, 3, 4, 5, 6};	

	for_each(v.begin(), v.end(), f);
	cout << endl;

	for_each(v.begin(), v.end(), Tada()); //try to build Tada before
	cout << endl;

	auto result = find_if(v.begin(), v.end(), impair);
	while(result != v.end())
	{
		cout << *result << endl;
		result++;
	}
}
