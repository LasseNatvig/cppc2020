 /* myVector_2.cpp
  The example shows the early steps towards a proper implementation of vector,
  it builds on myVector_1.cpp. Some codelines are commented only or in more detail 
  in myVector_1.cpp since we expect the reader to study example by example.
  - the definition of the constructor of myVector is here moved inline 
  - example is used in lecture to demonstrate memory leak, to motivate 
    the concept destructor, and the danger of C-arrays not being range-checked. */
#include<iostream>
#include<math.h>
using namespace std;
class myVector { 
	int sz;	// the number of elements (“the size”)
	double* elem; // pointer to the first element
public:
	myVector(int s) : sz{ s }, 
		elem{ new double[s] }{ // allocate s doubles
		for (int i = 0; i < sz; i++) elem[i] = 0.0; // initialize
	}
	~myVector() { delete[] elem; } // destructor
	int size() const { return sz; }	// the current size
	double get(int n) const { return elem[n]; } // PPP 17.6
	void set(int n, double v) { elem[n] = v; }
};

void setVector(myVector& v) {
	for (int i = 0; i < v.size(); i++) 
		v.set(i, sqrt(i));
}

void printVector(myVector& v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v.get(i) << " "; 
	}
	cout << endl;
}
void memoryLeak(int x) {
	myVector v(x);
	setVector(v);
	//... cleanup missing, or not?
}
int main()
try {
	myVector doubleVec(10);
	setVector(doubleVec);
	printVector(doubleVec);
	
	// // Part-1) demonstrate memory leakage
	// cout << "One double is " << sizeof(double) << " bytes\n";
	// for (int i = 0; i < 3000; i++) {
	// 	  memoryLeak(1000000);
	// }
	// cout << endl;

	{ // Part-2, demonstrate the danger of C-arrays not being range-checked
		myVector test(10);
		cout << test.get(-7);  // can read outside the vector !
		test.set(20, 777);
		cout << endl << test.get(20); // can write outside the vector!!! Don't do this!

	}

	// Part-3, demonstrate missing copy constructor, Chap. 18, will crash
	{	
		myVector v(3);
		v.set(2, 2.2);
		myVector v2 = v;
		cout << endl;
	}	 // Program will crash when leaving scope

	cout << "\nType any char + return to quit:";
	char c; cin >> c;
	return 0;
}
catch (exception& e) {
	cerr << "error: " << e.what() << endl;
	return -1;
}