#include <iostream>
#include <initializer_list>

using namespace std;

class DataSet
{
	double sum;
	int count;

	public:
		DataSet() : sum(0), count(0) {}

		DataSet(const initializer_list<double>& data) : DataSet()
		{
			update(data);
		}

		void update(const initializer_list<double>& data)
		{
			for(double d : data)
				update(d);
		}

		inline void update(double d)
		{
			sum += d;
			count++;
		}		

		inline double mean() const
		{
			return sum / count;
		}
};

int main()
{
	DataSet set = {1,2,3};
	cout << set.mean() << endl;
	set.update({4,5,6,7});
	cout << set.mean() << endl;
}
