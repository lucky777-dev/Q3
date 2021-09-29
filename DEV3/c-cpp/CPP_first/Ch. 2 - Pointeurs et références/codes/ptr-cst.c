#include <stdio.h>

int main()
{
	int i = 2;
	const int ci = 3; //int const ci = 3 similaire
	i += 2;
	//ci += 2; //ko

	int * pi = &i;
	printf("%p : %d\n", pi, i);
	*pi = 3; 
	printf("%p : %d\n", pi, i);

	int * const cpi = &i; //ptr constant
	*cpi = 5;
	//cpi++;

	const int * pic = &ci; //ptr d'entier constant	
	//*pic = 4;	
	pic++;

	const int * const cpic = &ci; //ptr cst d'entier cst
	//*cpic = 4;	
	//cpic++;
}
