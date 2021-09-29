#include <iostream>

template<class T> class A;

template<class T> std::ostream& operator<<(std::ostream&, const A<T>&);

template<class T> A<T> operator+(const T&, const A<T>&);

template<class T>
class A
{
	T i;
	public:
		explicit A(T t) : i(t) {}

		friend A<T> operator+ <>(const T& t, const A<T>& a);//YOU HAVE TO DECLARE THIS HERE
		friend std::ostream& operator<< <>(std::ostream& out, const A<T>& a);				
		
		A operator +(A<T> a) const
		{
			return A(a.i + i);
		}
				
		A operator +(T t) const 
		{ 
			return (*this) + A<T>(t); 
		}				
};

template<class T>
std::ostream& operator<<(std::ostream& out, const A<T>& a)
{
	out << a.i;
	return out;
}

template<class T>
A<T> operator +(const T& t, const A<T>& a)
{
	return A<T>(t) + a;
}

int main()
{
	A<int> a(3);
	A<int> b(2);
	std::cout << b << std::endl;
	std::cout << (a + b) << std::endl;
	std::cout << (b + a) << std::endl;
	std::cout << (b + 2) << std::endl;
	std::cout << (2 + b) << std::endl;
}
