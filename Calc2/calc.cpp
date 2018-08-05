#include "std_lib_facilities.h"
#include "token.h"
#include "parser.h"
#include "vars.h"

const string prompt = "> ";
const string result = "= ";

void clean_up_mess(Token_stream& ts)   // naive version
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
			if (t.kind == quit) return;
			ts.putback(t);
			cout << result << statement(ts) << '\n';
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