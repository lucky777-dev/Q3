#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s1 = "Hello ";
	string s2 = "World";

	for(long i = 0; i < s1.length(); i++)
		cout << s1[i] << endl;
	for(long i = 0; i < s2.length(); i++)
		cout << s2[i] << endl;
	cout << endl;

	string s3 = s1 + s2;
	cout << s3 << endl;	
	s1 += s2;
	cout << s1 << endl << endl;

	string s4;
    cout << "Length = " << s4.length() << ", capacity = " << s4.capacity() << endl;
	for(int i = 0; i < 20; i++)
	{
		s4 += 'a';
		cout << "Length = " << s4.length() << ", capacity = " << s4.capacity() << endl;		
	}
}
