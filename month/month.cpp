 #include "std_lib_facilities.h"
enum class Month {
	jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};
Month operator++(Month& m) {	// prefix increment operator
	// “wrap around”:
	m = (m == Month::dec) ? Month::jan : Month(static_cast<int>(m) + 1);  // PPP page 321 textbook use "old style cast" (int)
	return m;
}
vector<string> monthTable{ "January", "February", "March", "April", "May", 
	"June", "July","August", "September", "October", "November", "December" };
ostream& operator<<(ostream& os, Month m) {
	return os << monthTable[static_cast<int>(m) - 1];
}
int main() {
	Month m = Month::nov;
	++m;	// m becomes dec
	cout << m << endl;
	++m;	// m becomes jan
	cout << m << endl;
	return 0;
}