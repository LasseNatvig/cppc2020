 // bug_1.cpp, demonstrates two functions with a bug, both can 
// "fall through the end of the function" and give undefined results
#include "std_lib_facilities.h"
int maxOfTwo(int a, int b) {
	if (a > b)
		return a ;
	else if (b > a)
		return b;
}    
double maxOfTwo(double a, double b) {
	if (a > b)
		return a;
	else if (b > a)   
		return b;
}
int main() {
try {
	cout << maxOfTwo(2.0, 1.99999999) << endl;                 
	cout << maxOfTwo(2.0, 3.0) <<  endl;              
	cout << maxOfTwo(2.0, 2.0) << endl;      
	cout << maxOfTwo(2.0, 1.9999999999999999) << endl;
     
	cout << maxOfTwo(4, 5) << endl;     
	cout << maxOfTwo(4, 4) << endl;
	}
 catch (...) {
	 cout << "Exception caught, but not handled\n";
	 return -1;
 }
	keep_window_open();
}