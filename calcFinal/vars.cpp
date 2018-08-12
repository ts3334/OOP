#include "std_lib_facilities.h"
#include "vars.h"
vector<Variable> var_table;

double get_value(string s)
{
	for (Variable var : var_table)
		if (var.name == s) return var.value;

	return 0.0;
}

void set_value(string s, double d)
{
	for (Variable& var : var_table)
		if (var.name == s) {
			var.value = d;
			return;
		}
	// if var not in table, we choose to add it:
	var_table.push_back(Variable{ s, d });
}

void print_vars()
{
	for (Variable var : var_table)
		cout << "Var " << var.name << " = " << var.value << endl;
}

void save_vars() {
	string oname;
	cout << "Please enter name of output file: ";
	cin >> oname;
	ofstream ost{ oname }; // ost writes to a file named oname
	if (!ost) {
		error("can't open output file ", oname);
	}
	for (int i = 0; i < var_table.size(); ++i)
		ost << var_table[i].name << '\t' << var_table[i].value << "\n";
}

void open_vars() {
	var_table.clear();
	cout << "Please enter input file name: ";
	string iname;
	cin >> iname;
	ifstream ist{ iname }; // read
	if (!ist) {
		error("can't open input file ", iname);
	}
	string var;
	double value;
	while (ist >> var >> value) {
		var_table.push_back(Variable{ var ,value });
	}
}

void show_vars() {
	if (var_table.size() == 0) {
		cout << "No variables" << endl;
		return;
	}
	for (int i = 0; i < var_table.size(); ++i)
		cout << var_table[i].name << " = " << var_table[i].value << "\n";
}

void delete_var() {
	cout << "Enter name of variable to delete: " << endl;
	string varname;
	cin >> varname;
	for (int i = 0; i < var_table.size(); ++i)
		if (varname == var_table[i].name)
			var_table.erase(var_table.begin()+i);
}