#include <iostream>
#include <vector>

using namespace std;


template<int i, template<class> class Collection, class Element>
const Element& get(Collection<Element>& c)
{
	return c[i];
}

template<class E>
class Array
{
	E* a;
	int _size;

	public:
		Array(std::initializer_list<E> l) : a(new E[l.size()]), _size(l.size())
		{
			int i = 0;
			for(E e : l)
			{
				a[i] = e;
				i++;
			}
		}	

		~Array()
		{
			delete[] a;
		}

		Array(const Array<E>& array) = delete;
		Array& operator=(const Array<E> array) = delete;
        //I probably should override move constructor

		E& operator[](int i)
		{
			return a[i];
		}
};

int main()
{
	Array<int> a = {1,2,3,4,5};
	cout << (get<2>(a)) << endl;
}
