#include <stdio.h>

int main()
{
	int i = 5; //most likely on stack
	while(i >= 0)
	{
		int j = i + 2; //most likely on stack
		
		printf("%d %d\n", i, j);

		i--;
	}
	printf("%d\n", i);
	//printf("%d\n", i); //j is out of the scope
}//i is destroyed
