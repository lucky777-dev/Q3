#include <stdio.h>
#include <stdlib.h>

void synch()
{
	int n, p;
	printf("Donnez une valeur pour n\n");//1 2
	scanf("%d", &n);
	printf("Merci pour %d\n", n);
	printf("Donnez une valeur pour p\n");
    scanf("%d", &p);
	printf("Merci pour %d\n", p);
}

void block()    
{
	int n = 12;
	char c = 'a';
	printf("Donnez un entier et un caractère\n");//x 25
    scanf("%d", &n);	
	printf("Merci pour %d et %c\n", n, c);
	printf("Donnez un caractère\n");
	scanf("%c", &c);
	printf("Merci pour %c\n", c);
}

void loop()
{
	//3
	//à
	int n;
	do
	{
		printf("Tapez un nombre entier\n");
		scanf("%d", &n);
		printf("Son carré est %d\n", (n*n));
	}
	while(!n);	
}

void good()
{
    printf("Tapez un entier non nul\n");
        
    char buffer[20];
    scanf("%s", buffer);
    int i = atoi(buffer);
    if(i != 0)
        printf("Vous avez tapé %d\n", i);
    else
        printf("Pas un entier\n");
}

int main()
{
	//synch();
	//block();
	//loop();
    good();
}
