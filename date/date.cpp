#include "std_lib_facilities.h"
#include "date.h"


Date::Date(int yy, int mm, int dd)
:y{ yy }, m{ mm }, d{ dd }
{
	if (!is_valid()) {
		error("invalid date");
	}
}

bool Date::is_valid(){
	if (m < 1 || m > 12) {
		return false;
	}
	if (d < 1 || d > days_in_month(m)) {
		return false;
	}
	return true;
}

bool Date::leapyear() {
	if (y % 4 == 0)
	{
		if (y % 100 == 0)
		{
			if (y % 400 == 0)
			{
				return true;
			}
			else {
				return false;
			}
		}
		else{
			return true;
		}
	}
	return false;
}
int Date::days_in_month(int i) {
	int daysinmonth = 0;
	switch (i)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		daysinmonth = 31;
		break;
	case 4: case 6: case 9: case 11:
		daysinmonth = 30;
		break;
	case 2:
		if (leapyear()){
			daysinmonth = 29;
		}
		else {
			daysinmonth = 28;
		}
		break;
	}
	return daysinmonth;
}
void Date::add_day(int n)
{
	
	int remainder = 0;
	int daysinmonth = days_in_month(m);
	if (d + n > daysinmonth) {
		m++;
		if (!is_valid()) {
			y += 1;
			m = 1;
		}

		remainder = d + n - daysinmonth;
		d = remainder;
	}
	else {
		d += n;
	}
	
}

void Date::print() {
	cout << monthNames[int(month()) - 1] << day() << "," << year() << endl;
}
int Date::year() {
	return y;
}

int Date::month(){
	return m;
}

int Date::day() {
	return d;
}

