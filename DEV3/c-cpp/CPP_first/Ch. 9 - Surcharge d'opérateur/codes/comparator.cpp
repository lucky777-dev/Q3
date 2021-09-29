#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

class IntegerOp
{
    int i;
    public:
        IntegerOp(int i) : i(i) {}
    
        int& value() { return i; }
        const int& value() const { return i; }
    
        bool operator<(const IntegerOp& other) const
        {
            return i < other.i;
        }
    
        friend ostream& operator<<(ostream& out, const IntegerOp& i)
        {
            return out << i.i;
        }
};

class Integer
{     
    int i;
    public:
        Integer(int i) : i(i) {}
    
        int& value() { return i; }
        const int& value() const { return i; }
    
        friend ostream& operator<<(ostream& out, const Integer& i)
        {
            return out << i.i;
        }
};

int main()
{
    vector<int> v = {3, 5, 2, 1, 4};
    sort(v.begin(), v.end()); //ok : int has <
    for(int i : v)
        cout << i << " ";
    cout << endl;
    
    vector<IntegerOp> v2 = {IntegerOp(3), IntegerOp(5), IntegerOp(2), IntegerOp(1), IntegerOp(4)};
    sort(v2.begin(), v2.end()); //ok : IntegerOp has <
    for(IntegerOp i : v2) 
        cout << i << " ";
    cout << endl;
    
    vector<Integer> v3 = {Integer(3), Integer(5), Integer(2), Integer(1), Integer(4)};
    vector<Integer> v4 = v3;
    //sort(v3.begin(), v3.end()); //ko : no < in Integer
    sort(v3.begin(), v3.end(), [](const Integer& i1, const Integer& i2) { return i1.value() < i2.value(); }); //lambda
    for(Integer i : v3) 
        cout << i << " ";
    cout << endl;
    
    struct IntegerComparator
    {
        bool operator()(const Integer& i1, const Integer& i2) const
        {
            return i1.value() < i2.value();      
        }
    };
    
    sort(v4.begin(), v4.end(), IntegerComparator()); //function object
    for(Integer i : v4) 
        cout << i << " ";
    cout << endl;
    
    //priority_queue<Integer> p; //ko : no < in Integer
        
    priority_queue<Integer, deque<Integer>, IntegerComparator> p;
    p.push(Integer(3));
    p.push(Integer(5));
    p.push(Integer(2));
    p.push(Integer(1));
    p.push(Integer(4));
    while(! p.empty())
    {
        cout << p.top() << " ";
        p.pop();
    }
    cout << endl;
    
    //    key   value  key_comparator
    map<Integer, int, IntegerComparator> m;    
    m[Integer(3)] = 3;
    m[Integer(5)] = 5;
    m[Integer(2)] = 2;
    m[Integer(1)] = 1;
    m[Integer(4)] = 4;
    for(auto p : m)
        cout << p.second << " ";
    cout << endl;
}
