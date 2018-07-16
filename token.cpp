#include "std_lib_facilities.h"

class Token {
public:
	char kind;
	double value;
};

class Token_stream {
public:
	Token get();
	void putback(Token t);
private:
	Token buffer;
	bool full{ false };
};

void Token_stream::putback(Token t) {
	buffer = t;
	full = true;
}

Token Token_stream::get() {
	if (full) {
		full = false;
		return buffer;
	}
	char ch;
	cin >> ch;
	switch (ch) {
	case ';': case 'q': case '(': case ')': case '+': case '-':  case '*': case '/':
		return Token{ ch };
	case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': case '.':
	{
		cin.putback(ch);
		double val;
		cin >> val;
		return Token{ '8',val };
	}
	default:
		return Token{ 'i' };
	}
	return Token{ 'q' };
}

Token_stream ts;

int main()
{
	double val = 0.0;
	while (cin) {
		Token t = ts.get();
		cout << "Got token of kind: " << t.kind << " with value of: " << t.value << "\n";
		if (t.kind == 'q')
			break;
		if (t.kind == ';')
			cout << " = " << val << '\n';
	}
	keep_window_open();

}

