#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class array
{
	int n;
	double * tab;
	
	public:
		array(int nbr) : n(nbr), tab(new double[n]) {}
		
		array(const array & v) : n(v.n), tab(new double[v.n])
		{
			for(int i = 0; i < n; i++)
				tab[i] = v.tab[i];		
		}
		
		~array()
		{
			delete[] tab;
		}	
		
		array & operator = (const array & v)
		{
			if(this != &v)
			{
				delete[] tab;
				n = v.n;
				tab = new double[n];
				for(int i = 0; i < n; i++)
					tab[i] = v.tab[i];
			}
			return * this;
		}

		double & operator [] (int i)
		{
			rangeCheck(i);
			return tab[i];
		}

		inline int size() const
		{
			return n;
		}

	private:
		inline void rangeCheck(int i) const
		{
			if(i < 0 || i >= n)
			{
				string s = "out of range : size of ";
				s += to_string(n);
				s += " , accessed at ";
				s += to_string(i);
				throw out_of_range(s);
			}
		}
};

int main()
{
	array v(5);

	for(int i = 0; i < 5; i++)
		v[i] = i * i;

	for(int i = 0; i < 5; i++)
		cout << v[i] << endl;
	cout << endl;

	v[0] = 2; //try to remove & from []

	for(int i = 0; i < 5; i++)
		cout << v[i] << endl;
	
	try
	{
		v[-1] = 4; //try to remove rangeCheck
	}
	catch(const out_of_range& e)
	{
		cerr << e.what() << endl;
	}
}
