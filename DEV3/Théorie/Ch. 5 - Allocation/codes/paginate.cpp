#include <iostream>
#include <thread>

using namespace std;

int main()
{		
	long long unsigned int j = 0;
	long long unsigned int m5GB = 800000;

	while(true)
	{
		new int[1000 * 250];//1Mb
		j++;
		if(j % 1000 == 0)
		{
			cout << j << "kb allocated" << endl;
			std::this_thread::sleep_for(10ms);
		}
		if(j >= m5GB)
			break;
	}

	int i;
	cout << "Type sth to close" << endl;
	cin >> i;
}	
