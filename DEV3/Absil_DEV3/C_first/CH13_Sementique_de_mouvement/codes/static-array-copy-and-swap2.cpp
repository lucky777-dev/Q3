#include <iostream>

using namespace std;

class Array
{
    unsigned _size;
    int * _data;
    
    public:
        Array(unsigned size = 0)
            : _size(size),
              _data(size != 0 ? new int[size] : nullptr)
        {
            cout << "+A" << endl;
        }
    
        int& operator[](unsigned pos) { return _data[pos]; }
        const int& operator[](unsigned pos) const { return _data[pos]; }
        int size() const { return _size; }
    
        ~Array()
        {
            if(_data)
                delete[] _data;
            cout << "-A" << endl;
        }
    
        friend void swap(Array& a1, Array& a2) noexcept
        {
            std::swap(a1._size, a2._size);   
            std::swap(a1._data, a2._data);   
        }
    
        Array(const Array& a) : _size(a._size), _data(a._size != 0 ? new int[a._size] : nullptr)
        {
            std::copy(a._data, a._data + a._size, _data);
            cout << "cA" << endl;
        }
    
        Array& operator=(const Array& a)
        {
            Array tmp(a); //explicit call to copy cstr
            swap(*this, tmp);
            
            cout << "=cA" << endl;
            
            return *this;
        }            
    
        Array& operator=(Array&& a) noexcept
        {
            swap(*this, a);
            a._data = nullptr;
            cout << "=mA" << endl;
        }
    
        Array(Array && a) noexcept
        {
            *this = std::forward<Array&&>(a);            
            cout << "mA" << endl;
        }                
};

void print_array(const Array& a)
{
    for(unsigned i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    cout << endl;
} 

//void print_array(Array&& a) { ... } //no need

void fill_increasing_array(Array& a)
{
    for(unsigned i = 0; i < a.size(); i++)
        a[i] = i;
}

Array create_increasing_array(unsigned n) //don't return an Array&&
{    
    Array a(n);
    fill_increasing_array(a);
    return a;
}

int main()
{
    Array a1(5);
    print_array(a1);
    fill_increasing_array(a1);
    print_array(a1);
    
    cout << endl;
    
    a1 = create_increasing_array(5);
    print_array(a1);
        
    cout << endl;
    
    Array a2 = create_increasing_array(5);
    print_array(a2);        
    
    cout << endl;
    
    print_array(create_increasing_array(5));
    
    cout << endl;
}
