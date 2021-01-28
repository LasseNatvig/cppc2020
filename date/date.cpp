// date.cpp, inspired by PPP section 9.4
#include "std_lib_facilities.h"

struct Date {
	int year;
	int month;
	int day;
	Date(int y, int m, int d);
	void add_day(int n);
};
Date::Date(int y, int m, int d) { // check for valid date and initialize
	cout << "checking valid date NOT completely implemented\n";
	// But see exam May 2018 problem 2a..2e 
	if (d > 31) {
		throw runtime_error("Invalid date passed to constructor"); 
	}
	else {
		year = y;
		month = m;
		day = d;
	}
}

void Date::add_day(int n) {	// increase the Date by n days
	cout << "add_day NOT implemented\n"; // not even in the PPP-book
}
void print_day(const Date& day) {
	vector<string> months{ "jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec" };
	cout << "Date: " << day.day << " " << months[day.month - 1] << " " << day.year << endl;
}

class Date_s { // short for Date_safe
	int year;
	int month;
	int day;
public:
	Date_s(int y, int m, int d);
	void add_day(int n);
	int get_month() const { return month; }
	int get_day() const { return day; }
	int get_year() const { return year; }
};

Date_s::Date_s(int y, int m, int d) : year{ y }, month{ m }, day{ d } {
	// above line uses so called (member) initializer list (PPP 9.4.4)
	// This constructor should check that (y, m, d) is a valid date
	cout << "checking valid date NOT completely implemented\n";
	if (day > 31) {  
		throw runtime_error("Invalid date passed to constructor");  
	}
	// The created Date_s object is OK

}

void Date_s::add_day(int n) {	// increase the Date by n days
	cout << "add day NOT implemented\n";
}

int main() try {
	// (1)
	//Date my_birthday; // error: no default contructor
	//Date today{ 12, 24, 2007 };  // gives run time error (exception)
	Date last{ 2000, 12, 31 }; // OK, recommended style
	Date next = { 2014, 2, 14 }; // slightly verbose, acceptable but not so good
	Date christmas = Date{ 1976, 12, 24 }; // verbose, acceptable but not so good

	Date whatAday(1958, 5, 20); // OK, but now a rather OLD style (C++98) (PPP p. 312)

	// add_day(1); // error, add_day undefined, (what date?)
	last.add_day(2);  //

	//************************
	// (2)
	print_day(christmas);
	christmas.month = 14; // Free access to member variable in struct date makes it easy to produce an illegal date.
	// Imagine much later, in another part of a huge program, after hours of execution you will print it ... ("Time bomb")
	print_day(christmas);  // run-time error

	//************************
	// (3)
	Date_s fineDay{ 2019, 1, 29 };
	// cout << "fineDay.month = " << fineDay.month << endl;  // error, cannot acces private member
	cout << "fineDay.month = " << fineDay.get_month() << endl;
	Date_s someDay{ 2019, 1, 299 };  // demonstrates exception thrown by Date_s constructor

	return 0;
}
catch (exception& e) {
	cerr << e.what();
	return 1;
}
catch (...) {
	cerr << "Unknown exception\n";
	return 2;
}