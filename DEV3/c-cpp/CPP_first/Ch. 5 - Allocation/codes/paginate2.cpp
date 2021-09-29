#include <iostream>
#include <thread>

using namespace std;

int main()
{		
	bool stop = false;

    long long unsigned i = 0;
	while(! stop)
	{       
        new int[1000 * 250]; //1Mb
        std::this_thread::sleep_for(1ns);
        
        i++;
        
        if(i % 1000 == 0)
            cout << i << endl;
	}	
}	
