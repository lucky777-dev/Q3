#include <iostream>

using namespace std;

class A
{
    int i;   
    
    public:
        A(int i) 
        { 
            this->i = i; 
        }
    
        void set(int i) 
        { 
            this->i = i; 
        }
    
        int& get() 
        { 
            cout << "g "; 
            return i; 
        }
    
        const int& get() const //try to remove const on return type
        { 
            cout << "cg "; 
            return i; 
        }
};

int main()
{
    A a(2);   
    
    a.set(3);
    cout << a.get() << endl;
    
    a.get() = 5;
    cout << a.get() << endl;
    
    const A ca(42);
    //ca.set(5);
    cout << ca.get() << endl;
}
