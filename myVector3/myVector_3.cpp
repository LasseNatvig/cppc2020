 /* myVector_3.cpp, note this is an "empty project" without the PPP scaffolding
  The example shows the third step towards a proper implementation of vector,
  it builds on myVector_1 and ...2.cpp.
  - new in this version of myVector is copy constructor, copy assignment operator=,
    initializer-list constructor, operator [] for unchecked access and at() function
	for checked access. Also const version of both access methods
  - struct myVectorRangeError is used to report range error found by the at() function
 */
#include<iostream>
using namespace std;

struct myVectorRangeError {
	int wrongIndex;
	myVectorRangeError(int i) : wrongIndex(i) {}
};

class myVector {
	int sz;	// the number of elements (“the size”)
	double* elem; // pointer to the first element
public:
	myVector(int s) : sz{ s },
		elem{ new double[s] }{ // allocate s doubles
		for (int i = 0; i < sz; i++) elem[i] = 0.0; // initialize
	}
	myVector(const myVector&);	// copy constructor: defined below
	myVector& operator=(const myVector& arg); // copy assignment: defined below 
	~myVector() { delete[] elem; } // destructor
	int size() const { return sz; }	// the current size
	double get(int n) const { return elem[n]; } // PPP 17.6
	void set(int n, double v) { elem[n] = v; }
	myVector(initializer_list<double> lst);   // initializer-list constructor
	double& operator[](int i) { return elem[i]; }  // unchecked access via []
	double& operator[](int i) const { return elem[i]; }   // unchecked const access via []
	double& at(int i); // checked access
	const double& at(int i) const; // checked const access
};

myVector::myVector(initializer_list<double> lst) // initializer-list constructor
	: sz{ static_cast<int>(lst.size()) }, // static_cast: assume size fits in an int
	elem{ new double[sz] } {
	copy(lst.begin(), lst.end(), elem); // copy lst to elem copy from std lib See B.5.2
}

double & myVector::at(int i) {
	if (i < 0 || i >= sz) throw myVectorRangeError(i);
	return elem[i];
}
const double & myVector::at(int i) const {
	if (i < 0 || i >= sz) throw myVectorRangeError(i);
	return elem[i];

}

myVector::myVector(const myVector& arg)
	:sz{ arg.sz },
	elem{ new double[arg.sz] }
{ // allocate space for elements, 
  // then initialize them (by copying)
	for (int i = 0; i < sz; ++i) {
		elem[i] = arg.elem[i];
	}
}

myVector& myVector::operator=(const myVector& arg)
// like copy constructor, but we must deal with old elements
// make a copy of arg then replace the current sz and elem with a’s
{
	double* p = new double[arg.sz];	// allocate new space
	for (int i = 0; i < arg.sz; ++i) p[i] = arg.elem[i]; // copy elements
	delete[] elem;	// deallocate old space
	sz = arg.sz; // set new size
	elem = p; // set new elements
	return *this; //  return a self-reference
}

void useVector(myVector& v) {
	for (int i = 0; i < v.size(); i++)
		v.set(i, static_cast<double>(sqrt(i)));
}

void printVector(myVector& v) {
	for (int i = 0; i < v.size(); i++)
		cout << v.get(i) << " ";
}

int main()
try {
	myVector doubleVec(10);
	useVector(doubleVec);
	printVector(doubleVec);

	// Test copy constructor
	{
		myVector v(3);
		v.set(2, 2.2);
		myVector v2 = v;  // v2 is constructed as a copy of v
		printVector(v2);
		cout << endl;
	}

	// Test copy assignment
	{ // we should be able to use v and v2 as variables names also in this block, but for
	  // some reasons (bug?) VS Code will not show v and v2 values in debugger. Therefore x and x2
		myVector x(3);
		x.set(2, 2.2);
		myVector x2(4);
		x2 = x;  // x2 already exist, so copy constructor is not used, but assignment operator= is used
		printVector(x2);
		cout << endl;
	}

	// Test initializer list
	{
		myVector v1{ 1,2,3 };
		myVector v2(3);
		printVector(v1);
		cout << endl;
		printVector(v2);
		cout << endl;
	}

	// Test operator[] access
	{
		myVector v(10);
		for (int i = 0; i < v.size(); ++i) {
			v[i] = i; // v[i] returns a reference to the ith element
			cout << v[i];
		}
		cout << endl;
		// test operator[] const
		myVector const vReadOnly{ 8, 9, 11 };
		for (int i = 0; i < vReadOnly.size(); ++i) {
			cout << vReadOnly[i];
		}
	}

	// Test unchecked access with [] and checked access with .at()
	{
		myVector v(5);
		cout << v[100] << endl;
		cout << v.at(100) << endl;
	}

	cout << "\nType any char + return to quit:";
	char c; cin >> c;
	return 0;
}
catch (myVectorRangeError& e) {
	cerr << "Range error in myVector at index: " 
		 << e.wrongIndex << endl;
	return -2;
}
catch (exception& e) {
	cerr << "error: " << e.what() << endl;
	return -1;
}