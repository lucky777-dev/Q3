#include <stdio.h>

int main()
{	
	int i;

	printf("Tapez un entier (decimal)\n");
	//scanf("%d",i); //sneaky
	scanf("%d", &i);
	
	printf("Vous avez tapé %d\n", i);
	
	printf("Tapez un entier (hexadecimal)\n");
	scanf("%x", &i);
		
	printf("Vous avez tapé %d\n", i);
}
