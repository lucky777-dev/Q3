#include <iostream>
#include <algorithm>

using namespace std;

class DynSpace
{
    int size;
    char * data;
    int offset;
    
    public:            
        DynSpace(int size = 0) 
            : size(size > 0 ? size : 0), 
              data(size > 0 ? new char[size] : nullptr), 
              offset(0)
        {}
    
        void* operator*()
        {
            return data;   
        }
    
        template<class T>
        void store(const T& t)
        {
            *(data + offset) = t;
            offset += sizeof(T);
        }
    
        template<class T>
        const T& retrieve(int offset)
        {
            return *reinterpret_cast<T*>(data + offset); //don't use this at home  
        }
    
        friend void swap(DynSpace& s1, DynSpace& s2) noexcept //inline independent function
        {
            std::swap(s1.size, s2.size);   
            std::swap(s1.data, s2.data);
            std::swap(s1.offset, s2.offset);
        }
    
        ~DynSpace() noexcept
        { 
            if(data)
                delete[] data; 
        }            
    
        DynSpace& operator=(DynSpace s) //note that argument is passed by value
        {
            swap(*this, s);
            
            return *this;
        }
    
        DynSpace(const DynSpace& s) : size(s.size), data(new char[size]), offset(s.offset)
        {           
            std::copy(s.data, s.data + s.offset, data);
        }
    
        DynSpace(DynSpace&& s) noexcept : DynSpace() 
        {
           swap(*this, s);
        }
};

template<class T>
DynSpace createArray(int size)
{
    return DynSpace(size * sizeof(T));   
}

int main()
{
    DynSpace s(10);  
    s.store(2);
    s.store('c');
    
    cout << s.retrieve<int>(0) << endl;
    cout << s.retrieve<char>(sizeof(int)) << endl;        
}
