#include "std_lib_facilities.h"
#include "token.h"
#include "vars.h"	
#include "parser.h"
#include <cmath>
#include <map>
#include <string>
#include <functional>

std::map<const string, std::function<double(double)> > funcTable{
	{ "sin", [](double a) { return sin(a); } },
	{ "cos", [](double a) { return cos(a); } },
	{ "tan", [](double a) { return tan(a); } },
	{ "asin", [](double a) { return asin(a); } },
	{ "acos", [](double a) { return acos(a); } },
	{ "atan", [](double a) { return atan(a); } },
	{ "sinh", [](double a) { return sinh(a); } },
	{ "cosh", [](double a) { return cosh(a); } },
	{ "tanh", [](double a) { return tanh(a); } },
	{ "sqrt", [](double a) { return sqrt(a); } },
	{ "log", [](double a) { return log(a); } },
	{ "log2", [](double a) { return log2(a); } },
	{ "log10", [](double a) { return log10(a); } },
	};

double exec_func(string fname, double arg)
{
	try {
		return funcTable[fname](arg);
	}
	catch (exception) {
		cout << "Error: undefined function" << fname << '\n';
	}
	return 0.0;
}



double statement(Token_stream& ts)
{
	Token t = ts.get();
	if (t.kind == name) {
		Token var = t;
		t = ts.get();
		if (t.kind == '=') {
			double d = expression(ts);
			set_value(var.name, d);
			return d;
		}
		else if (t.kind == print) {
			ts.putback(t);
			return get_value(var.name);
		}
		ts.putback(t);
		ts.putback(var);
		return expression(ts);
	}
	ts.putback(t);
	return expression(ts);
}

double expression(Token_stream& ts)
{

	double left = term(ts);  
	Token t = ts.get();    

	while (true) {
		switch (t.kind) {
		case '+':
			left += term(ts);  
			t = ts.get();
			break;
		case '-':
			left -= term(ts);  
			t = ts.get();
			break;
		default:
			ts.putback(t); 
			return left;     
		}
	}
}

double term(Token_stream& ts)
{

	double left = exp(ts);
	Token t = ts.get();

	while (true) {
		switch (t.kind) {
		case '*':
			left *= exp(ts);
			t = ts.get();
			break;
		case '/':
		{
			double d = exp(ts);
			if (d == 0) error("divide by zero");
			left /= d;
			t = ts.get();
			break;
		}
		case '%':
		{
			double d = exp(ts);
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

double exp(Token_stream& ts)
{
	double left = primary(ts);
	Token t = ts.get();
	if (t.kind == power) {
		double d = primary(ts);
		return pow(left, d);
	}
	else {
		ts.putback(t);
		return left;
	}
}

double primary(Token_stream& ts)
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{
		double d = expression(ts);
		t = ts.get();
		if (t.kind != ')') error("')' expected");
		return d;
	}
	case number:
		return t.value;
	case name:
	{
		Token next_t = ts.get();
		if (next_t.kind == '(') {
			double d = expression(ts);
			next_t = ts.get();
			if (next_t.kind != ')') throw runtime_error("')' expected");
			d = exec_func(t.name, d);
			return d;
		}
		else {
			ts.putback(next_t);
			error("print expected");
		}
	}
	case '-':
		return -primary(ts);
	case '+':
		return primary(ts);
	default:
		error("primary expected");
	}
	return 0.0;
}

