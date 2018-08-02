#include "std_lib_facilities.h"

struct Reading { 
	int i1; // int
	char sep1; // comma
	double d1; // double
	char sep2; // comma
	double d2; // double
};

int main()
{
	cout << "Please enter input file name: ";
	string iname;
	cin >> iname;
	ifstream ist{ iname }; // read
	if (!ist) {
		error("can't open input file ", iname);
	}

	string oname;
	cout << "Please enter name of output file: ";
	cin >> oname;
	ofstream ost{ oname }; // ost writes to a file named oname
	if (!ost) {
		error("can't open output file ", oname);
	}

	vector<Reading> temps; // store the readings here
	int i1;
	double d1;
	char sep1;
	double d2;
	char sep2;
	while (ist >> i1 >> sep1 >> d1 >> sep2 >> d2) {
		temps.push_back(Reading{ i1, sep1, d2, sep2, d2});
	}
	for (int i = 0; i<temps.size(); ++i)
		ost << temps[i].i1 << '\t' << temps[i].d1 << '\t' << temps[i].d2 << "\n";
}