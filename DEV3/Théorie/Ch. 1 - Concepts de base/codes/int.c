#include <stdio.h>
#include <limits.h>

int main()
{
	unsigned i = -1;
	if(i == UINT_MAX)
		printf("Two complement\n");
	else
		printf("Unknown negative representation\n");
		
	unsigned j = 1;
	char* ptr = (char*)&j;
	if(*ptr == 0) //a bit ugly
		printf("Little indian\n");
	else
		printf("Big indian\n");
}
