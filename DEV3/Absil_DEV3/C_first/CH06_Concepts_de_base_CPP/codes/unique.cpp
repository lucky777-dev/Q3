#include <iostream>
#include <memory>

using namespace std;

struct A
{
    int i, j;
    
    A(int i = 1, int j = 2) : i(i), j(j) {}
    
    void print() 
    { 
        cout << i << " " << j << endl; 
    }
};

int main()
{
	int i = 2;	
	int * pti = &i;
    
	//unique_ptr<int> u1(&i); //terrible use, causes invalid pointers everywhere
    
	{
		//unique_ptr<int> u2(&i); //bad idea
		//unique_ptr<int> u2 = u1; //compile error
		//unique_ptr<int> u2 = move(u1); //u2 owns, u1 invalid
	}

	//cout << *pti << endl;
	//u1.reset(); //deletes memory, ko since i is auto
	//cout << i << endl; //seg fault		    

	unique_ptr<int> u3 = make_unique<int>(3);//good use
	cout << *u3 << endl;
    
    //good uses
    unique_ptr<A> pta = make_unique<A>();
    unique_ptr<A> ptb = make_unique<A>(42);
    auto ptc = make_unique<A>(23, 42); //good looking
    
    pta->print();
    ptb->print();
    ptc->print();
}
