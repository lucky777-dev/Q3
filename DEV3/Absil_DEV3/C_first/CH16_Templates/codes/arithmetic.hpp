#ifndef ARITHMETIC_H
#define ARITHMETIC_H

#include <cmath>
#include <stdexcept>
#include <limits>

template<class T = double> constexpr T pi = T(atan(1) * 4);
constexpr double PI = pi<>;

template<class Integer>
constexpr Integer gcd(Integer a, Integer b)
{    
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}

template<class Integer>
constexpr Integer lcm(Integer a, Integer b)
{
    return (a  / gcd(a, b)) * b; //ask why not (a * b) / gcd(a,b)
}

//Si il y a du temps et si ça les interesse
//faire une intro sur la progra dyn.
//    Intro Fibo
//    1. Ss struct d'opt
//	Ex avec shortest et longest path
//    2. Recouvrement ss pbm
//	Ex euclide
//    3. Mémoïsation

template<class Natural> //try to make it constexpr, without calling, compile, then call
Natural binom(Natural n, Natural k)//dynamic programming alg
{//takes n * n * sizeof(Natural) bytes in memory
    if (k  > n || n == 0)
        return 0;
    if (k == 0 || n == k)
        return 1;
    if (k == 1)
        return n;

    Natural * pascal_array = new Natural[n * n]; //I'm sexy and I know it. But maybe I can use auto alloc
    std::fill_n(pascal_array, n * n, 0);

    class n_choose_k//dynamic the shit out of that
    {
        Natural * pascal;//array containing pascal triangle
        Natural size;//size of the array

        public:
            n_choose_k(Natural* array, const Natural& size)
                : pascal(array), size(size)
            {}

            //returns value of n choose k previously computed
            //if == 0 -> not already computed
            inline Natural& memo(const Natural& n, const Natural& k)
            {
                return pascal[size * n + k];
            }

            //compute n choose k using dynamic programming
            Natural compute(const Natural& n, const Natural& k)
            {
                if ((k == 0) || (k == n))
                    return 1;

                Natural v1 = memo(n - 1, k - 1);
                if (v1 == 0)
                    v1 = memo(n - 1, k - 1) = compute(n - 1, k - 1);

                Natural v2 = memo(n - 1, k);
                if (v2 == 0)
                    v2 = memo(n - 1, k) = compute(n - 1, k);

                return v1 + v2;
          }
       };

    Natural result = n_choose_k(pascal_array, n).compute(n, k);

    delete [] pascal_array;
    return result;
}

#endif // ARITHMETIC_H
