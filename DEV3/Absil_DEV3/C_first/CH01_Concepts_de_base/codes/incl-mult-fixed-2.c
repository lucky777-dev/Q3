#include "incl-mult-fixed-2.h" //pour récuperer declaration f

#include "incl-mult-fixed.h" //pour récupérer déclaration g
#include <stdio.h>

void f()
{	
	printf("Coucou\n");
	g();
}
