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
    
        ~DynSpace() 
        { 
            if(data)
                delete[] data; 
        }            
    
        DynSpace& operator=(const DynSpace& s)
        {
            if(this != &s)
            {
                if(data)
                    delete[] data;
            
                size = s.size;
                data = new char[size];
                std::copy(s.data, s.data + offset, data);
            }
            
            return *this;
        }
    
        DynSpace(const DynSpace& s) : size(s.size), data(new char[size]), offset(s.offset)
        {           
            std::copy(s.data, s.data + s.offset, data);
        }
    
        DynSpace(DynSpace&& s)
        {
            size = s.size;
            data = s.data;
            s.data = nullptr; //why necessary ?
            offset = s.offset;
        }
};

template<class T>
DynSpace createSpace(int size)
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
    
    DynSpace s2 = createSpace<char>(10);
    s.store(2);
    s.store('c');    
    cout << s.retrieve<int>(0) << endl;
    cout << s.retrieve<char>(sizeof(int)) << endl;
}
