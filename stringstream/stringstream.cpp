 #include "std_lib_facilities.h"

double str_to_double(string s) {
	// if possible, convert characters in s to floating-point value
	istringstream is{ s };// make a stream so that we can read from s
	double d;
	is >> d;
	if (!is) error("double format error: ", s);
	return d;
}
int main() {
	double d1 = str_to_double("12.4");		// testing
	double d2 = str_to_double("1.34e-3");
	// double d3 = str_to_double("twelve point three"); // will call error()
	cout << d1 << " " << d2 << endl;

	int i = 123;
	ostringstream oss;
	oss << "Test " << i << " times";
	cout << oss.str() << endl;
	oss.str("New text");
	cout << oss.str() << endl;

	//oss >> i; // error, cannot use ostringstream for input
	double d;
	istringstream iss{ "123 45.67" };
	iss >> i >> d;
	cout << i << " " << d << endl; // works well
	
	string s1, s2;
	stringstream ss{ "Initial 1234567890" }; // A read&write stringstream
	ss >> s1 >> s2;
	cout << s1 << ", " << s2 << endl;
	ss.str(""); // both these two statements are needed to
	ss.clear(); // reset the stringstream
	ss << "more" << " text" << endl;
	cout << ss.str() << endl;
}