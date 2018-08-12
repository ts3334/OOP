class Variable {
public:
	string name;
	double value;
};

double get_value(string s);
void set_value(string s, double d);
void print_vars();
void save_vars();
void open_vars();
void show_vars();
void delete_var();