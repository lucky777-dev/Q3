#include <iostream>
#include <vector>
#include <list>

using namespace std;

template<class T>
void print_container_not_so_template(const vector<T> & v) //I can"t use td::list
{
    for(const T& t : v)
        cout << t << " ";
    cout << endl;
}

template<class Container>
void print_container_template_try(const Container & v)
{
    for(const auto& t : v) //can't force t to be T
        cout << t << " ";
    cout << endl;
}

//I can force t to be T, but I can't use std::list
template<class T, class ... OtherParams>
void print_container_not_so_template_but_better(const vector<T,OtherParams...> & v)
{
    for(const T& t : v)
        cout << t << " ";
    cout << endl;
}

//that's what I want
template<template<class, class ...> class Container, class T, class ... OtherParams>
void print_container(const Container<T,OtherParams...> & c)
{
    for(const T& t : c)
        cout << t << " ";
    cout << endl;
}

//excellent
template<template<class, class ...> class Container, class T, class ... OtherParams>
ostream& operator<<(ostream& out, const Container<T,OtherParams...> & c)
{
    for(const T& t : c)
        out << t << " ";
    return out;
}

int main()
{
    vector<int> v = {1,2,3,4,5};
    print_container_not_so_template(v);
    print_container_template_try(v);
    print_container_not_so_template_but_better(v);
    
    list<int> l = {1,2,3,4,5,6};
    //print_container_not_so_template(l);
    print_container_template_try(l);
    //print_container_not_so_template_but_better(l);    
    
    print_container(v);
    print_container(l);
    
    cout << v << endl;
    cout << l << endl;
}
