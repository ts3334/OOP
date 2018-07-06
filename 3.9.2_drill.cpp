#include "std_lib_facilities.h"

int main()
{
	cout << "double to int \n";
	double init = 555.555;
	int narrow = init;
	double reconverted = narrow;
	cout << "double value: " << init << "\n";
	cout << "int value: " << narrow << "\n";
	cout << "reconverted value: " << reconverted << "\n" << "\n";

	cout << "double to char \n";
	double init1 = 555.555;
	char narrow1 = init;
	double reconverted1 = narrow1;
	cout << "double value: " << init1 << "\n";
	cout << "char value: " << narrow1 << "\n";
	cout << "reconverted value: " << reconverted1 << "\n" << "\n";

	cout << "double to bool \n";
	double init2 = 5.555;
	bool narrow2 = init;
	double reconverted2 = narrow2;
	cout << "double value: " << init2 << "\n";
	cout << "bool value: " << narrow2 << "\n";
	cout << "reconverted value: " << reconverted2 << "\n" << "\n";

	cout << "int to char \n";
	int init3 = 56;
	char narrow3 = init3;
	int reconverted3 = narrow3;
	cout << "int value: " << init3 << "\n";
	cout << "char value: " << narrow3 << "\n";
	cout << "reconverted value: " << reconverted3 << "\n" << "\n";

	cout << "int to bool \n";
	int init4 = 5;
	bool narrow4 = init4;
	int reconverted4 = narrow4;
	cout << "int value: " << init4 << "\n";
	cout << "bool value: " << narrow4 << "\n";
	cout << "reconverted value: " << reconverted4 << "\n" << "\n";

	cout << "char to bool \n";
	char init5[] = "Hello";
	bool narrow5 = init;
	char reconverted5 = narrow5;
	cout << "char value: " << init5 << "\n";
	cout << "bool value: " << narrow5 << "\n";
	cout << "reconverted value: " << reconverted5 << "\n" << "\n";

	keep_window_open();
	return 0;
}

