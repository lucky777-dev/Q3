#include <iostream>

//using namespace std; //unwise because of std::array

struct Array {
    int i;
    int * arr;
    
    Array(int i)
    {
    	this->i = i;
        arr = new int[i];
    }    
}; //missing sooo many things to make it safe...

int main() {
    Array a(2); //a automatic
                //i automatic
                //tab automatic
                //*tab dynamic    
    
    static Array b(2); //b static
                       //i static
                       //tab static
                       //*tab dynamic

    Array * c = new Array(2); //c dynamic
                              //i dynamic
                              //tab dynamic
                              //*tab dynamic
}