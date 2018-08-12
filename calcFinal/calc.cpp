#include "std_lib_facilities.h"
#include "token.h"
#include "parser.h"
#include "vars.h"

const string prompt = "> ";
const string result = "= ";

void helper() {
	cout << "Help: " << endl;
	cout << "\t" << "variable functions:" << endl;
	cout << "\t\t" << "show: shows all named variables" << endl;
	cout << "\t\t" << "open: opens previously saved variables" << endl;
	cout << "\t\t" << "save: saves all named variables" << endl;
	cout << "\t\t" << "deletevar: saves all named variables" << endl;

	cout << "\t" << "calculator functions:" << endl;
	cout << "\t\t" << "Addition: +" << endl;
	cout << "\t\t" << "Subtraction: -" << endl;
	cout << "\t\t" << "Multiplication: *" << endl;
	cout << "\t\t" << "Square root: sqrt()" << endl;
	cout << "\t\t" << "Logarithm: log(), log2(), log10()" << endl;
	cout << "\t\t" << "Exponent: ^" << endl;
	cout << "\t\t" << "Modulus: %" << endl;
	cout << "\t\t" << "Trigonometry: sin(), cos(), tan(), asin(), acos(), atan(), sinh(), cosh(), tanh()," << endl;
	cout << "Enter 'help' to bring up this menu again" << endl;
}

void clean_up_mess(Token_stream& ts)
{
	ts.ignore(print);
}

void calculate(Token_stream& ts)
{
	while (cin) {
		try {
			cout << prompt;
			Token t = ts.get();
			while (t.kind == print) t = ts.get();
			switch (t.kind) {
			case quit:
				return;
			case help:
				helper();
				break;
			case open:
				open_vars();
				break;
			case save:
				save_vars();
				break;
			case showvars:
				show_vars();
				break;
			case deletevar:
				delete_var();
				break;
			default:
				ts.putback(t);
				cout << result << statement(ts) << '\n';
			}

		}
		catch (exception& e) {
			cerr << e.what() << '\n';
			clean_up_mess(ts);
		}
	}

}

int main()
{
	Token_stream ts;
	helper();
	try {
		calculate(ts);
		keep_window_open();
		return 0;
	}
	catch (...) {
		cerr << "unknown exception \n";
		return 2;
	}
	return 1;
}

