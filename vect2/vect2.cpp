#include "std_lib_facilities.h"

class vect {
	int sz;
	double* elem;

public:
	vect(int s)
		:sz{ s }, elem{ new double[s] } { /*  */}

	vect(const vect& a)
		:sz{ a.sz }, elem{ new double[a.sz] } { copy(a.elem, a.elem+a.sz, elem);}

	vect& operator=(const vect& a)
	{
		if (elem == a.elem) return *this;
		double* p = new double[a.sz];
		copy(a.elem, a.elem + sz, p);
		delete[] elem;
		elem = p;
		sz = a.sz;
		return *this;
	}

	double& operator[](int n) { return elem[n]; }

	double get(int i) { return elem[i]; }
	void set(int i, double d) { elem[i] = d; }

	~vect()
	{
		delete[] elem;
	}
};



void f()
{
	vect v(3);
	v.set(2, 2.2);
	vect v2 = v;
	v.set(1, 9.9);
	v2.set(0, 8.8);
	cout << v.get(0) << ' '<< v2.get(0) << ' ' << v2.get(1)<<  endl;
}

int main() 
	{
	for (int i = 0; i < 10; i++) {
		f();
	}
	keep_window_open();
	return 0;
}

