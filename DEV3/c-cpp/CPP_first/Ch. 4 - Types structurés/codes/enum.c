#include <stdio.h>

enum color { red, green, blue };
enum boolean { vrai = 1, faux = 0 };

//typedef enum color color;
//void f(color c) {}

void f(enum color c) {}

int main()
{
	enum color c1 = red;
	enum color c2 = c1;

	printf("%i\n", c1);
	printf("%i\n", c2);

	int n = blue;
	int p = green * n + 2; //Wtf ?!

	printf("%i\n",n);
	printf("%i\n",p);
	//green = n;
	
	enum color c3 = faux;
	enum boolean brol = 3 * c2 + 4; //Wtf ?!

	printf("%i\n",c3);
	printf("%i\n",brol);

	//try to assign faux to 1
	//try to define red in bool
}
