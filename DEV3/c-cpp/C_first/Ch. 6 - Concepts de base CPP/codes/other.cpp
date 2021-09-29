#include <iostream>

int main()
{
	bool rep = true;
	if(rep)
		std::cout << "True" << std::endl;

	char c = 'A';
	std::cout << c << std::endl;

	int i = 3;
	int j = 0;
	int k = 1;

	if(i)
		std::cout << "i ok" << std::endl;
	if(j)
		std::cout << "j ok" << std::endl;	
	if(k)
		std::cout << "k ok" << std::endl;		
	if(c)
		std::cout << "c ok" << std::endl;	

	int n = 2;
	int m = n;
	int & rn = n;
	int * pn = &n;	

	n++;
	std::cout << n << " " << m << " " << rn << " " << *pn << std::endl;
}
