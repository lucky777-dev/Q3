#include <iostream>
#include <stdexcept>
#include <iostream>
#include <initializer_list>
#include <utility>

//don't look at these 3
template<class T, int N> class Array;
template<class T, int N> std::ostream& operator<<(std::ostream&, const Array<T,N>&);
template<class T, int N> void swap(Array<T,N>& a1, Array<T,N>& a2) noexcept;

template<class T, int N> class Array
{
	T * t;       
    
	public:
		Array() : t(new T[N]) {}
		Array(std::initializer_list<T> l) : Array()
		{
			if(N != l.size())
				throw std::out_of_range("Non matching sizes");

			auto it = l.begin();
			for(unsigned i = 0; i < N; i++)
			{
				t[i] = *it;
				it++;
			}
		}

		~Array() 
        { 
            if(t != nullptr)
                delete[] t; 
        }

		Array(const Array<T,N>& a) : Array()
        {
            std::copy(a.t, a.t + N, t);
        }    
    
		Array<T,N>& operator=(Array<T,N> a)
        {
            swap(*this, a);
            return *this;
        }
    
        Array(Array<T,N>&& a) noexcept
        {            
            steal(std::forward<Array<T,N>>(a)); //recall std::forward
        }
    
        Array& operator =(Array<T,N>&& a) noexcept
        {            
            steal(std::forward<Array<T,N>>(a));
            return *this;
        }

        //recall difference between these two
		T& operator[](unsigned i) { return t[i]; } 
		const T& operator[](unsigned i) const { return t[i]; }

		unsigned size() const { return N; }                           
            
        friend void swap <>(Array<T,N>& a1, Array<T,N>& a2) noexcept; //don't look at prototype        
        friend std::ostream& operator<< <>(std::ostream& out, const Array<T,N>& a); //don't look at prototype    
    
    private:
        void steal(Array<T,N>&& a) noexcept
        {
            swap(*this, a);
            a.t = nullptr; 
        }
};

template<class T, int N>
std::ostream& operator<<(std::ostream& out, const Array<T,N>& a)
{
    out << "{ ";
    for(unsigned i = 0; i < a.size() - 1; i++)
        out << a[i] << " , ";
    out << a[a.size() - 1] << " }";

    return out;
}

template<class T, int N>
void swap(Array<T,N>& a1, Array<T,N>& a2) noexcept
{
   std::swap(a1.t, a2.t);
}