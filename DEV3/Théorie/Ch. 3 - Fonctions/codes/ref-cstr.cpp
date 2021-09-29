void f(int&){}

void g(const int&){}

int main()
{
	const int n = 15;
	int q;
	f(q);
	//f(2*q+3);
	//f(3);
	//f(n);

	float x;
	//f(x);

	short k;
	//f(k);
}


