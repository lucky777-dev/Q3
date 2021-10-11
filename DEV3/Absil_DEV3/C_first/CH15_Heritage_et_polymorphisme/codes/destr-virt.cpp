#include <iostream>

using namespace std;

struct Mere
{
	~Mere() { cout << "-M" << endl; }
	virtual void print() { cout << "Mère " << endl; }	
};

struct Fille : Mere
{
	~Fille() { cout << "-F" << endl; }
	void print() { cout << "Fille " << endl; }	
};

void print_indep(Mere* m) { m->print(); }

int main() //try to compile with -Wall
{
	Mere * m = new Fille;
	print_indep(m);
    delete m;
}
