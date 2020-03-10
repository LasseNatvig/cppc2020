 /* myVector_5.cpp, note this is an "empty project" without the PPP scaffolding
 The example shows the fifth and last step *towards* a proper implementation of vector,
 it builds on myVector_1-2-3-4.cpp.
 - new in this version is 
	. move constructor and move assignment (From PPP 18.3.4, but here in template-version)
	. rudimentary implementation of some "half-way iterators" for illustration purpose
 - Note that this version of myVector is deliberately still not yet complete, 
	. dynamic size, reserve, resize, push_back and much more are still not included
*/
#include<iostream>
#include<string>
using namespace std;

struct myVectorRangeError {
	int wrongIndex;
	myVectorRangeError(int i) : wrongIndex{i} {}
};

template<typename T>
class myVector {
	int sz;	// the number of elements (“the size”)
	T* elem; // pointer to the first element
public:
	myVector(int s) : sz{ s },
		elem{ new T[s] }{ // allocate s elements of type T
		for (int i = 0; i < sz; i++) elem[i] = T(); // initialize, use default constructor to create new element,  PPP-19.3.7.  
	}
	myVector(const myVector&);	// copy constructor, defined below
	myVector& operator=(const myVector& arg); // copy assignment, defined below 
	myVector(myVector&& a); // move constructor, defined below
	myVector& operator=(myVector&& a); // move assignment, defined below
	~myVector() { delete[] elem; } // destructor
	int size() const { return sz; }	// the current size
	T get(int n) const { return elem[n]; } // PPP 17.6
	void set(int n, T v) { elem[n] = v; }
	myVector(initializer_list<T> lst);   // initializer-list constructor
	T& operator[](int i) { return elem[i]; }  // unchecked access via []
	T operator[](int i) const { return elem[i]; }   // unchecked const access via []
	T& at(int i); // checked access
	const T& at(int i) const; // checked const access

	const T* begin() const; // const iterator to first element
	const T* end() const; // const iterator one beyond last element
	T* begin(); // iterator to first element
	T* end(); // iterator one beyond last element
};


template<typename T>
T & myVector<T>::at(int i) {
	if (i < 0 || i >= sz) throw myVectorRangeError(i);
	return elem[i];
}

template<typename T>  // This must be repeated before every "section" of code
myVector<T>::myVector(initializer_list<T> lst) // initializer-list constructor
	: sz{ static_cast<int>(lst.size()) }, // static_cast: assume size fits in an int
	elem{ new T[sz] } {
	copy(lst.begin(), lst.end(), elem); // copy lst to elem copy from std lib See B.5.2
}

template<typename T>
const T & myVector<T>::at(int i) const {
	if (i < 0 || i >= sz) throw myVectorRangeError(i);
	return elem[i];
}

template<typename T>
myVector<T>::myVector(const myVector& arg)
	:sz{ arg.sz }, 	elem{ new T[arg.sz] }
{ // allocate space for elements, 
  // then initialize them (by copying)
	for (int i = 0; i < sz; ++i) {
		elem[i] = arg.elem[i];
	}
	cout << "copy constructor returns\n"; // debug/demo
}
template<typename T>
myVector<T>& myVector<T>::operator=(const myVector<T>& arg)
// like copy constructor, but we must deal with old elements
// make a copy of arg then replace the current sz and elem with a’s
{
	T* p = new T[arg.sz];	// allocate new space
	for (int i = 0; i < arg.sz; ++i) p[i] = arg.elem[i]; // copy elements
	delete[] elem;	// deallocate old space
	sz = arg.sz; // set new size
	elem = p; // set new elements
	cout << "assignment operator returns\n"; // debug/demo
	return *this; //  return a self-reference
}

template<typename T>
myVector<T>::myVector(myVector<T>&& a) // move constructor
	: sz{ a.sz }, elem{a.elem} {
	a.sz = 0;
	a.elem = nullptr;
	cout << "move constructor returns\n"; // debug/demo
}

template<typename T>
myVector<T>& myVector<T>::operator=(myVector<T>&& a) { // move assignment
	delete[] elem;
	elem = a.elem;
	sz = a.sz;
	a.elem = nullptr;
	a.sz = 0;
	cout << "move assignment returns\n"; // debug/demo
	return *this;
}

// "half-way iterators"
template<typename T>
const T* myVector<T>::begin() const { return elem; };
template<typename T>
const T* myVector<T>::end() const { return elem + sz; };
template<typename T>
T* myVector<T>::begin() { return elem; };
template<typename T>
T* myVector<T>::end() { return elem + sz; };

// a generic print vector function
template<typename T>
void print(myVector<T>& vec) {
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << endl;
}

myVector<double> fill(int n) {
	myVector<double> res(n);
	for (int i = 0; i < res.size(); i++) {
		res[i] = sqrt(i);
	}
	cout << endl;
	return res;
}

int main()
try {
	// demonstrate generic print function
	myVector<double> dv1{ 1.1, 2.2, 3.3 };
	print(dv1);
	myVector<char> cv{ 'a', 'c', 'd', 'x' };
	print(cv);

	// demonstrate move constructor and assignment
	cout << "\nCase a:";
	myVector<double> dv2 {fill(10)};  // C++14: move constructor used.
	  // clang (TDT4102-spring 2020): move constructor NOT used (see slide notes)
	print(dv2);

	cout << "\nCase b:";
	myVector<double> dv3{}; 
	dv3 = fill(5); // Move is selected by compiler in return from function.
		// First an unnamed object is constructed by move constructor (C++14 only), 
		// and then assigned to dv3 by move assignment
	print(dv3);

	cout << "\nCase c:\n";
	myVector<double> dv4{};
	dv4 = dv3; // assignment operator
	print(dv3);
	print(dv4);

	cout << "\nCase d:\n";
	myVector<double> dv5{2.2, 9.9};
	myVector<double> dv6{};
	dv6 = move(dv5); // move assignment operator used
	print(dv5);
	print(dv6);

	// ********************************************************************************
	// auto and iterators
	cout << "\n ****** auto and iterator testing ******\n";
	myVector<double> v2{ 2.2, 1.1, 3.3, 4.4, 77.88 };
	// this myVector can be iterated by both iterator and const iterator
	for (auto e : v2) cout << e << " ";
	cout << endl;

	const myVector<long> v3{ 2666662, 1333331, 36666663, 46666664};
	// this myVector can only be iterated by a const iterator
	for (auto e : v3) cout << e << " "; // compiler error if const iterator is missing
	cout << endl;

	myVector<int> v4{ 62, 131, 63, 464 };
	for (auto e : v4) {
		e += 2;  // e is a copy of the element in the vector, does not change the vector
		cout << e << " ";  
	}
	cout << endl;
	print(v4); // shows vector not changed
	
	//for (auto e : v4) {  // try to change vector
	//	*e = e + 2; // * does not compile, we need a proper Iterator
	//	cout << e << " ";
	//}
	//cout << endl;

	//for (auto it = v4.begin(); it != v4.end; it++) {  // try to change vector
	//	it = it + 2; // * does not compile, we need a proper Iterator
	//	cout << *it << " ";
	//}
 
	cout << "\nType any char + return to quit:";
	char c; cin >> c;
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