 // casting.cpp - casting
#include "std_lib_facilities.h"
/* - these lines are needed if you do not include std_lib_facilities.h
#include<iostream>
#include<iomanip>
using namespace std; */

int main() {
	int i = 2;
	int j = 7; 
	cout << setprecision(4) << fixed; // print doubles with 4 decimals
	cout << "i: " << i << ", i as double: " << static_cast<double>(i) << endl;
	cout << "j/i: " << j / i << ", j/i as double: " << static_cast<double>(j / i) << endl;
	cout << "j / static_cast<double>(i) as double: " << j / static_cast<double>(i) << endl;

	// Old style cast
	cout << "Old style (double)i: " << (double)i << endl;

	keep_window_open();
	return 0;
}