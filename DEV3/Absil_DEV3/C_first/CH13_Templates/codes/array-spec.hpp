#include <iostream>
#include <stdexcept>
#include <iostream>
#include <initializer_list>

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
        }
    
        Array(Array<T,N>&& a) noexcept
        {
            steal(std::forward<Array<T,N>>(a));
        }
    
        Array& operator =(Array<T,N>&& a) noexcept
        {
            steal(std::forward<Array<T,N>>(a));
            return *this;
        }

		T& operator[](unsigned i) { return t[i]; }
		const T& operator[](unsigned i) const { return t[i]; }

		unsigned size() const { return N; }                           
            
        friend void swap <>(Array<T,N>& a1, Array<T,N>& a2) noexcept;
        friend std::ostream& operator<< <>(std::ostream& out, const Array<T,N>& a);
    
    private:
        void steal(Array<T,N>&& a)
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

/////////////////////////////SPECIALISATION for T* : deferences on print

template<class T, int N> class Array<T*,N>
{
	T ** t;       
    
	public:
		Array() : t(new T*[N]) 
        {
            for(int i = 0; i < N; i++)
                t[i] = nullptr;
        }	
        
        Array(std::initializer_list<T*> l) : Array()
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

		Array(const Array<T*,N>& a) : Array()
        {
            std::copy(a.t, a.t + N, t);
        }    
    
		Array<T,N>& operator=(Array<T*,N> a)
        {
            swap(*this, a);
        }
    
        Array(Array<T*,N>&& a) noexcept
        {
            steal(std::forward<Array<T*,N>>(a));
        }
    
        Array& operator =(Array<T*,N>&& a) noexcept
        {
            steal(std::forward<Array<T*,N>>(a));
            return *this;
        }

		T*& operator[](unsigned i) { return t[i]; } //T*& is a reference to pointer
		T* const & operator[](unsigned i) const { return t[i]; } // T* const & is a reference to a const pointer

		unsigned size() const { return N; }                           
            
        friend void swap <>(Array<T*,N>& a1, Array<T*,N>& a2) noexcept; 
        friend std::ostream& operator<< <>(std::ostream& out, const Array<T*,N>& a); 
        
    private:
        void steal(Array<T*,N>&& a)
        {
            swap(*this, a);
            a.t = nullptr; 
        }
};

template<class T, int N>
std::ostream& operator<<(std::ostream& out, const Array<T*,N>& a)
{
    out << "{ ";
    for(unsigned i = 0; i < a.size() - 1; i++)
        out << *(a[i]) << " , ";
    out << *(a[a.size() - 1]) << " }";

    return out;
}

template<class T, int N>
void swap(Array<T*,N>& a1, Array<T*,N>& a2) noexcept
{
   std::swap(a1.t, a2.t);
}

/////////////////////////////SPECIALISATION for Array<T> : prints as 2D-array

template<class T, int N, int M> class Array<Array<T,M>, N> //N rows, M columns
{
	Array<T,M> * t;       
    
	public:
		Array() : t(new Array<T,M>[N]) {}
		Array(std::initializer_list<Array<T,M>> l) : Array()
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

		Array(const Array<Array<T,M>,N>& a) : Array()
        {
            std::copy(a.t, a.t + N, t);
        }    
    
		Array<Array<T,M>,N>& operator=(Array<Array<T,M>,N> a)
        {
            swap(*this, a);
        }
    
        Array(Array<Array<T,M>,N>&& a) noexcept
        {
            steal(std::forward<Array<Array<T,M>,N>>(a));
        }
    
        Array& operator =(Array<Array<T,M>,N>&& a) noexcept
        {
            steal(std::forward<Array<Array<T,M>,N>>(a));
            return *this;
        }

		Array<T,M>& operator[](unsigned i) { return t[i]; }
		const Array<T,M>& operator[](unsigned i) const { return t[i]; }

		unsigned size() const { return N; }                           
            
        friend void swap <>(Array<Array<T,M>,N>& a1, Array<Array<T,M>,N>& a2) noexcept; 
        friend std::ostream& operator<< <>(std::ostream& out, const Array<Array<T,M>,N>& a); 
    
    private:
        void steal(Array<Array<T,M>,N>&& a)
        {
            swap(*this, a);
            a.t = nullptr; 
        }
};

template<class T, int N, int M>
std::ostream& operator<<(std::ostream& out, const Array<Array<T,M>,N>& a)
{
    for(unsigned i = 0; i < N; i++)
    {
        for(unsigned j = 0; j < M; j++)
            out << a[i][j] << " ";    
        out << std::endl;
    }

    return out;
}

template<class T, int N, int M>
void swap(Array<Array<T,M>,N>& a1, Array<Array<T,M>,N>& a2) noexcept
{
   std::swap(a1.t, a2.t);
}