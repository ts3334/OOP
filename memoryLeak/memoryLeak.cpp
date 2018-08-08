#include "std_lib_facilities.h"

int main() {
	    for (int i = 0; i < 10000000; i++) {
		    double* p = new double[10000];
	        cout << i << endl;
	    }
	keep_window_open();
	return 0;
}

// 26412 loops before crashing. 8 bytes per double and 10000 doubles per loop. I used approximately 2.11296 gigabytes.