  // type_1.cpp      Demonstrates simple use of string, and more
#include "std_lib_facilities.h"
int main() {
	//**************************************************
	// part a) Uninitialized variables, MS-Visual Studio (used in 2019) gives error message for these
	// MS-VS Code, used in the 2020 course allows these, but gives good warnings and advice for improving the code
	
	int x;		// could get a “random” initial value on some compilers, is set to 0 by VS code
	char c; 	// could get a “random” initial value on some compilers, is set to ' ' by VS code
	double d; 	// could get a “random” initial value on some compilers, is set to zero or almost zero by VS code
				//     – not every bit pattern is a valid floating-point value
	double dd = d;	// potential error: some implementations, can’t copy invalid floating-point values
	cout << " x: " << x << " c: " << c << " d: " << d << " dd: " << dd << '\n';

	//**************************************************
	// Part b) Implicit narrowing, from PPP 3.9.2
	{
		int a = 20000;
		char c = a;  // narrowing conversion, not good
		int b = c;
		if (a != b)	{    	//  != means “not equal”
			cout << "Oops: " << a << " != " << b << '\n';
		}
		else {
			cout << "Wow! We have large characters\n";
		}
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
		// int y{ x }; // VS code: error: type 'double' cannot be narrowed to 'int' in initializer list
		int a{ 40 }; // OK
		//char b{ a }; // VS code: error: non-constant-expression cannot be narrowed from type 'int' to 'char' in initializer list
		char bb1 = 1000; // not good, allowed, but gives warning
		char b1{ 1000 }; // VS code:  error: constant expression evaluates to 1000 which cannot be narrowed to type 'char' 
		char b2{ 48 }; // OK
		cout << endl;
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