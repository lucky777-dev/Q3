#include <list>
#include <queue>
#include <iostream>

using namespace std;

int main()
{	
    queue<int> q;	
	//queue<int, list<int> > q;	

	for(int i = 0; i < 10; i++)
		q.push(i * i);

	q.front() = 99;
	q.back() = -99;

	while(! q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}
