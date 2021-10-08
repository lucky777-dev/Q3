#include <iostream>

using namespace std;

int explodeStack(int i)
{	
	int j = i * 2;//creates j on the stack

	if(i != 1)
		explodeStack(j);//backup registers on stack and call (infinite recursion)
}

int main()
{
	explodeStack(2);
}
