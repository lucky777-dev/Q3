#include <iostream>

using namespace std;

template<class T1, class T2, int I>
class A {}; // primary template
 
template<class T, int I>
class A<T, T*, I> {}; // partial specialization where T2 is a pointer to T1
 
template<class T, class T2, int I>
class A<T*, T2, I> {}; // partial specialization where T1 is a pointer
 
template<class T>
class A<int, T*, 5> {}; // partial specialization where T1 is int, I is 5,
                        // and T2 is a pointer 
template<class X, class T, int I>
class A<X, T*, I> {}; // partial specialization where T2 is a pointer

int main()
{
	A<int, int, 1> a1;   // no specializations match, uses primary template
	A<int, int*, 1> a2;  // uses partial specialization #1 (T=int, I=1)
	A<int, char*, 5> a3; // uses partial specialization #3, (T=char)
	A<int, char*, 1> a4; // uses partial specialization #4, (X=int, T=char, I=1)
	//A<int*, int*, 2> a5; // error: matches #2 (T=int, T2=int*, I=2)
                     	   //        matches #4 (X=int*, T=int, I=2)
                           // neither one is more specialized than the other
}
