#include <iostream>

using namespace std;

enum class Color { red, green = 20, blue };

enum class altitude : char
{ 
     high='h',
     low='l'
}; 

int main()
{
    Color r = Color::blue;
    switch(r)
    {
        case Color::red  : cout << "red" << endl;   break;
        case Color::green: cout << "green" << endl; break;
        case Color::blue : cout << "blue" << endl;  break;
    }
    
    // int n = r; 
    int n = static_cast<int>(r); // OK, n = 21
}
