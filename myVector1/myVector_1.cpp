// myVector_1.cpp, note this is an "empty project" without the PPP scaffolding
// The example shows the first step towards a proper implementation of vector
#include<iostream>
using namespace std;
// our own implementation of vector, based on PPP chapter 17
class myVector { // PPP 17.2
	int sz;	// the number of elements (“the size”)
	double* elem; // pointer to the first element
public:
	myVector(int s); // constructor declaration: allocate s elements,
		// let elem point to them, store s in sz
	int size() const { return sz; }	// the current size
	double get(int n) const { return elem[n]; } // PPP 17.6
	void set(int n, double v) { elem[n] = v; }
};
myVector::myVector(int s) // constructor implementation
	: sz{ s }, // store the size s in sz
	elem{ new double[s] }	// allocate s doubles on the free store
		// store a pointer to those doubles in elem
{ }
int main() {
	myVector age(4);
	age.set(0, 0.33);
	age.set(1, 22.0);
	age.set(2, 27.2);
	age.set(3, 54.2);
	for (int i = 0; i < age.size(); i++) {
		cout << age.get(i) << " ";
	}
}