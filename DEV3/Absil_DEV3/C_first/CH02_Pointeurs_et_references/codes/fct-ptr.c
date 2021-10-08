#include <stdio.h> 

void f(int a) 
{ 
	printf("a = %d\n", a); 
} 

int main() 
{ 	
	void (*ptr)(int) = f; 
    //void (*ptr)(int) = &f; //similar	

	//Function call	
	ptr(10);
    //(*ptr)(10); //similar
} 
