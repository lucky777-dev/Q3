#include <iostream>
#include <memory>

using namespace std;

int main()
{
	int i = 2;	
	int * pti = &i;

	unique_ptr<int> u1(&i);
	{
		//unique_ptr<int> u2(&i); //bad idea
		//unique_ptr<int> u2 = u1; //compile error
		unique_ptr<int> u2 = move(u1); //u2 owns, u1 invalid
	}

	cout << *pti << endl;
	u1.reset();//deletes memory (why ?!)
	cout << i << endl; //seg fault		

	unique_ptr<int> u3 = make_unique<int>(3);//good use
	cout << *u3 << endl;
}
