#include <iostream>

using namespace std;

struct vehicle
{		
	virtual int nbWheels() = 0;
};

struct car : vehicle
{
	int nbWheels() override { return 4; }
};

struct bike : vehicle
{
	int nbWheels() override { return 2; }
};

int main()
{
	car c;
	bike b;		

	cout << "Bike with " << b.nbWheels() << " wheels" << endl;
	cout << "Car with " << c.nbWheels() << " wheels" << endl;

	//vehicle v = bike(); //KO (instance)
	//vehicle v; //KO (instance)
	
	vehicle & rv = b; //ok
	cout << "Vehicle with " << rv.nbWheels() << " wheels" << endl;
	rv = c; //reaffacting a ref does not change the ref, but the referenced object
	cout << "Vehicle with " << rv.nbWheels() << " wheels" << endl;

	vehicle * v = new car();
	cout << "Vehicle with " << v -> nbWheels() << " wheels" << endl;
}
