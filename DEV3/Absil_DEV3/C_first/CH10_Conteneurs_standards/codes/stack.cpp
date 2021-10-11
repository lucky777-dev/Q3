#include <list>
#include <stack>
#include <iostream>

using namespace std;

int main()
{	
    stack<int> q;
	//stack<int, list<int> > q;

	for(int i = 0; i < 10; i++)
		q.push(i * i);

	while(! q.empty())
	{
		cout << q.top() << " ";
		q.pop();
	}
	cout << endl;
	
	for(int i = 0; i < 10; i++)
		q.push(i * i);
	q.top() = 99;
		
	for(int i = 0; i < q.size(); i++)//sneaky loop is sneaky
	{
		cout << q.top() << " ";
		q.pop();
	}
	cout << endl << q.size() << endl;
}
