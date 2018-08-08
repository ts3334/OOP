#include "std_lib_facilities.h"

void foo(int i) {
	cout << i << endl;
	foo(i+1);
}

int main() {
	foo(1);
	return 0;
}

// I was able to call the function 4760 times before stack overflow error.