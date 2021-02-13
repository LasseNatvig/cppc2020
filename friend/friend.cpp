// friend.cpp
 #include "std_lib_facilities.h"

class Date {
private:
	int year;
	int month;
	int day; 
public:
	Date(int y, int m, int d);
	//ostream& operator<<(ostream& out, const Date &d); // Error, does not compile
	friend ostream& operator<<(ostream& out, const Date &d);
};

ostream& operator<<(ostream& out, const Date &d) {
	out << setfill('0') << setw(4) << d.year << "-";
	out << setfill('0') << setw(2) << d.month << "-";
	out << setfill('0') << setw(2) << d.day;
	return out;
}
Date::Date(int y, int m, int d) : year{ y }, month{ m }, day{ d }{}

int main(){
	Date d1{ 2019, 2, 23 };
	Date d2{ 2019, 3, 1 };
	cout << d1 << " " << d2 << endl;
}