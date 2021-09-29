#include <deque>
#include <queue>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{	
    priority_queue<int> q;
	//priority_queue<int, deque<int> > q;
	
	for(int i = 0; i < 10; i++)
	{
		int r = rand() % 100 + 1;
		q.push(r);
		cout << "pushed " << r << endl;
	}	
	cout << endl;

	while(! q.empty())
	{
		cout << q.top() << " ";
		q.pop();
	}

	cout << endl;
}
