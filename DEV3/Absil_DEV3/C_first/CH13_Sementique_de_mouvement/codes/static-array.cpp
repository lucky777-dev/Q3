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
    
        Array& operator=(const Array& a)
        {
            if(this != &a)
            {
                if(_data)
                    delete[] _data;
                
                _size = a._size;
                _data = a._size != 0 ? new int[a._size] : nullptr;
                std::copy(a._data, a._data + _size, _data);
            }
            
            cout << "=cA" << endl;
            
            return *this;
        }
    
        Array(const Array& a) : _size(a._size), _data(a._size != 0 ? new int[a._size] : nullptr)
        {
            std::copy(a._data, a._data + _size, _data);
            cout << "cA" << endl;
        }
    
        Array(Array && a) :
            _size(std::move(a._size)),
            _data(std::move(a._data))
        {            
            a._data = nullptr; //ask why I should do this
            cout << "mA" << endl;
        }
    
        Array& operator=(Array && a)
        {
            _size = std::move(a._size);
            _data = std::move(a._data);
            a._data = nullptr;
            
            cout << "=mA" << endl;
            
            return *this;
        }
    
        //no need for move assign operator
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
