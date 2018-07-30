#include "std_lib_facilities.h"
#include "date.h"



int input() {
		try {
			int day;
			int month;
			int year;
			cout << prompt;
			cin >> year;


			if (cin.get() != ',')
			{
				cout << "expected ','\n";
				return 1;
			}
			cin >> month;
			if (cin.get() != ',')
			{
				cout << "expected ','\n";
				return 1;
			}
			cin >> day;
			Date today{int(year),month,day };
			today.print();
		}
		catch (exception& e) {
			cerr << e.what() << '\n';
			return 1;

		}
	return 0;
}


int main(){
	Date today{ 1998,01,28 };
	today.add_day(30);
	while (true) {
		char output = input();
		char a = 'i';
		if (int(output) == 1) {
			cout << "Enter '.' to enter new date: \n";
			cin.clear();
			cin.ignore();
			while (a != '.') {
				cin >> a;
			}
		}
		else
			break;
	}
	return 0;
	keep_window_open();

}


