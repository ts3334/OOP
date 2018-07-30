const string prompt = "Please enter a date in YYYY,MM,DD format:";
const vector<string> monthNames = { "January ","February ","March ","April ","May ","June ","July ","August ","September ","October ","November ","December " };

class Date {
public:
	int days_in_month(int i);
	void add_day(int n);
	int month();
	int year();
	int day();
	Date(int y, int mm, int d);
	void print();
	

private:	
	int y; // Year
	int m;
	int d; // Date
	bool is_valid();
	bool leapyear();

};
