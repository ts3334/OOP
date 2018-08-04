#include "std_lib_facilities.h"

int main() {
	int v1 = 53;
	char v2 = 'z';
	double v3 = 600.323;
	int* int1 = &v1;
	char* ch = &v2;
	double* doub = &v3;
	cout << "Pointer int: " << int1 << "; Value: " << *int1 << endl;
	cout << "Pointer ch: " << ch << "; Value: " << *ch << endl;
	cout << "Pointer double: " << doub << "; Value: " << *doub << endl;
	
	cout << "the size of int pointer is: "  << sizeof(int1) << "; the size of int var is: " << sizeof(v1) << '\n';
	cout << "the size of char pointer is: "  << sizeof(ch) << "; the size of char var is: " << sizeof(v2) << '\n';
	cout << "the size of double pointer is: " << sizeof(doub) << "; the size of double var is: " << sizeof(v3) << '\n';

	keep_window_open();
	return 0;
}