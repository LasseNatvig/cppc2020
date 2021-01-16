// string_2.cpp   
#include "std_lib_facilities.h"
int main() {
	//*****************************************************
	// A) Correct use of string
	string str1{"ABCDEF"};  
	for (unsigned int i = 3; i < str1.size(); ++i) {
		str1[i] = '*';
	}
	cout << "str1: " << str1 << endl;

	//*****************************************************
	// B) The same code, but condition is <= size() and not < size()
	// This will go 1 position beyond end of string, it is allowed!
	// https://en.cppreference.com/w/cpp/string/basic_string/operator_at 
	// States that if index in [index] is greater than size() the result is undefined
	// if index == size() the null character is returned
	// This is UNSAFE CODE
	string str2{"ABCDEF"}; // 
	for (unsigned int i = 3; i <= str2.size(); ++i) {
		str2[i] = '*';
	}
	cout << "str2: " << str2 << endl;  // VScode debugger shows str2 == "ABC****" (7 chars) but reports size as 6!
		// This shows that the unsafe code "confuses" the debugger. Don't do this!

	//*****************************************************
	// C) when accessing chars in a string we can use member function at() instead of [], and we see
	// that at() is range checked. Code below does exactly the same as case B) above, and has the same erroneous <= in condition 
	// and it will throw an exception. So it is SAFE
	string str3 = "ABCDEF"; 
	for (unsigned int i = 3; i < str3.size(); ++i) { // this line needed to be able to proceed to case D)
    //for (unsigned int i = 3; i <= str3.size(); ++i) {
		str3.at(i) = '*';
	}
	cout << "str3: " << str3 << endl;

	//*****************************************************
	// D) Old C-style string, C-string (PPP 27.5), 
	// strlen(s) gives the length of a C-string, correct use
	char str4[] = "ABCDEF";  
	for (unsigned int i = 3; i < strlen(str4); ++i) {
		str4[i] = '*';
	}
	cout << "str4: " << str4 << endl;

	//*****************************************************
	// E) Just as case B above but with C-string 
	char str5[] = "ABCDEF"; 
	for ( unsigned int i = 3; i <= strlen(str5); ++i) {
		str5[i] = '*';
	}
	cout << "str5: " << str5 << endl;

	keep_window_open();
	cout << "goodbye";
}