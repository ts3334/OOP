#include "std_lib_facilities.h"

const char number = '8';
const char quit = 'q';
const char print = ';';
const string prompt = "> ";
const string result = "= ";

class Token {
public:
	char kind;
	double value;
};

class Token_stream {
public:
	Token get();
	void putback(Token t);
	void ignore(char c);
private:
	Token buffer;
	bool full{ false };
};

void Token_stream::putback(Token t) {
	buffer = t;
	full = true;
}

void Token_stream::ignore(char c)
{
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;
	char ch = 0;
	while (cin >> ch)
		if (ch == c) return;
}

Token Token_stream::get() {
	if (full) {
		full = false;
		return buffer;
	}
	char ch;
	cin >> ch;
	switch (ch) {
	case ';': case 'q': case '(': case ')': case '+': case '-':  case '*': case '/': case '%':
		return Token{ ch };
	case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': case '.':
	{
		cin.putback(ch);
		double val;
		cin >> val;
		return Token{ '8',val };
	}
	default:
		return Token{ 'i',double(ch) };
	}
	return Token{ '~' };
}

Token_stream ts;

double expression();
double term();
double primary();


double expression() {
	double left = term();
	Token t = ts.get();
	while (true) {
		switch (t.kind) {
		case '+':
			left += term();    // evaluate Term and add
			t = ts.get();
			break;
		case '-':
			left -= term();    // evaluate Term and subtract
			t = ts.get();
			break;
		default:
			ts.putback(t);     // put t back into the token stream
			return left;       // finally: no more + or -: return the answer
		}
	}
}



double term()
{
	double left = primary();
	Token t = ts.get(); 
	while (true) {
		switch (t.kind) {
		case '*':
			left *= primary();
			t = ts.get();
			break;
		case '/':
		{
			double d = primary();
			if (d == 0) error("divide by zero");
			left /= d;
			t = ts.get();
			break;
		}
		case '%':
		{
			double d = primary();
			if (d == 0) error("divide by zero");
			left = fmod(left, d);
			t = ts.get();
			break;
		}
		default:
			ts.putback(t); 
			return left;
		}
	}
}

double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':    // handle '(' expression ')'
	{
		double d = expression();
		t = ts.get();
		if (t.kind != ')') error("')' expected");
		return d;
	}
	case number:
		return t.value;  // return the number's value
	case '-':
		return -primary();
	case '+':
		return primary();
	default:
		error("primary expected");
	}
}

void clean_up_mess()   // naive version
{
	ts.ignore(print);
}


void calculate()
{
	while (cin) {
		try {
			cout << prompt;
			Token t = ts.get();
			while (t.kind == print) t = ts.get();
			if (t.kind == quit) return;
			ts.putback(t);
			cout << result << expression() << '\n';
		}
		catch (exception& e) {
			cerr << e.what() << '\n';
			clean_up_mess();
		}
	}

}

int main()
{
	Token_stream ts;

	try {
		calculate();
		return 0;
	}
	catch (...) {
		cerr << "unknown exception \n";
		return 2;
	}
	keep_window_open();
}
