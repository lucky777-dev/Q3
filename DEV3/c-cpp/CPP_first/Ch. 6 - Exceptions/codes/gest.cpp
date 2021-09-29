#include <iostream>

using namespace std;
                                    //////////////////////////////////
struct exceptA {};                  /////////       A      ///////////
                                    /////////       |      ///////////
struct exceptB : exceptA {};        /////////       B      ///////////
                                    /////////       |      ///////////
struct exceptC : exceptB {};        /////////       C      ///////////
                                    //////////////////////////////////

void f()
{
	//throw exceptB();		
	throw 1.;//try with int and catch double
}

/*
 * 1. Normal run    //base
 * 2. Switch A & B  //exact
 * 3. Delete A & B  //any
 * 4. //subclass ???
 */
int main()
{
	try             
	{
		f();
		cout << "Fine" << endl;
	}
	catch(exceptA e)
	{
		cout << "I caught an A" << endl;
	}
	catch(exceptB e)
	{
		cout << "I caught a B" << endl;
	}
	catch(exceptC e)
	{
		cout << "I caught a C" << endl;
	}
	catch(int d)
	{
		cout << "I caught an int" << endl;
	}
	catch(...)
	{
		cout << "I caught something" << endl;
	}
}
