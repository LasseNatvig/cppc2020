  // type_1.cpp      Demonstrates simple use of string, and more
#include "std_lib_facilities.h"
int main() {
	//**************************************************
	// part a) Uninitialized variables, MS-VS gives error message for these, therefore commented out
	
	int x;		// x gets a “random” initial value
	char c; 	// c gets a “random” initial value
	double d; 	// d gets a “random” initial value
				//     – not every bit pattern is a valid floating-point value
	double dd = d;	// potential error: some implementations
					// can’t copy invalid floating-point values
	cout << " x: " << x << " c: " << c << " d: " << d << " dd: " << dd << '\n';

	//**************************************************
	// Part b) Implicit narrowing, from PPP 3.9.2
	{
		int a = 20000;
		char c = a;  
		int b = c;
		if (a != b)	    	//  != means “not equal”
			cout << "Oops: " << a << " != " << b << '\n';
		else
			cout << "Wow! We have large characters\n";
	}

	//**************************************************
	// Part c) PPP page 82-83
	{
		double x = 2.7;
		// lots of code ..., and we might have forgotten that x is double
		int y = x; // y becomes 2

		int a = 1000;
		char b = a; // b becomes –24 (on some machines)
		cout << endl;
	}

	{
		double x{ 2.7 }; // OK
		// int y{ x }; // error: double -> int might narrow
		int a{ 40 }; // OK
		//** char b{ a }; // error: int -> char might narrow

		//** char b1{ 1000 }; // error: narrowing (assuming 8-bit chars)
		char b2{ 48 }; // OK
	}

	//**************************************************
	// Part d) PPP page 81
	{
		double d = 0;
		while (cin >> d) {
			int i = d; // try to squeeze a double into an int
			char c = i; // try to squeeze an int into a char
			int i2 = c; // get the integer value of the character
			cout << "d==" << d // the original double
				<< " i==" << i // converted to int
				<< " i2==" << i2 // int value of char
				<< " char(" << c << ")\n"; // the char
		}
	}

	keep_window_open();
}