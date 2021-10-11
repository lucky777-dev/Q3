#include <iostream>

using namespace std;

int main()
{
	string s1 = "Hello ";
	string s2 = "World";  	            
    
	string && s3 = s1 + s2; //rvalue reference
	cout << s3 << endl;        

	s3 += "!";
	sout << s3 << endl;
}
