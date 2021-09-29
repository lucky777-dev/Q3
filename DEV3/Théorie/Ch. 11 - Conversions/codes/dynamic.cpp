#include <iostream>
 
struct B 
{
    virtual void f() {};  // must be polymorphic to use runtime-checked dynamic_cast
};
struct D : B {}; //D inherits from A
 
int main()
{
    D d;
    B& b = d; //upcast
    D& new_d = dynamic_cast<D&>(b); // downcast
 
    B* b1 = new B;
    D* d1 = static_cast<D*>b1; //ok but D component is invalid
    if(D* d = dynamic_cast<D*>(b1))
    {
        std::cout << "downcast from b1 to d successful" << endl;
    }
 
    B* b2 = new D;
    if(D* d = dynamic_cast<D*>(b2))
    {
        std::cout << "downcast from b2 to d successful" << endl;
    }    

    delete b1;
    delete b2;
}
