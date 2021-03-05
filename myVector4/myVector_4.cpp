 /* myVector_4.cpp, note this is an "empty project" without the PPP scaffolding
  The example shows the fourth step towards a proper implementation of vector,
  it builds on myVector_1, 2 and 3.cpp.
  - new in this version of myVector is the use of templates, generic programming, see PPP 19.3
     . myVector is now generic for type T 
	 . simple struct Run used to demonstrate how the generic myVector can be used also on user defined types
	 . very simple test program 
  - Note that this version of myVector is deliberately still not yet complete
     . dynamic size, reserve, resize, push_back is still not included
	 . begin() and end() is still missing, and more
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct myVectorRangeError {
	int wrongIndex;
	myVectorRangeError(int i) : wrongIndex(i) {}
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
	myVector(const myVector&);	// copy constructor: defined below
	myVector& operator=(const myVector& arg); // copy assignment: defined below 
	~myVector() { delete[] elem; } // destructor
	int size() const { return sz; }	// the current size
	T get(int n) const { return elem[n]; } // PPP 17.6
	void set(int n, T v) { elem[n] = v; }
	myVector(initializer_list<T> lst);   // initializer-list constructor
	T& operator[](int i) { return elem[i]; }  // unchecked access via []
	T operator[](int i) const { return elem[i]; }   // unchecked const access via []
	T& at(int i); // checked access
	const T& at(int i) const; // checked const access
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
	:sz{ arg.sz },
	elem{ new T[arg.sz] }
{ // allocate space for elements, 
  // then initialize them (by copying)
	for (int i = 0; i < sz; ++i) {
		elem[i] = arg.elem[i];
	}
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
	return *this; //  return a self-reference
}

template<typename T>
void print(myVector<T>& vec) {
	for (int i = 0; i < vec.size(); i++) {
		cout << vec.at(i) << " ";
	}
	cout << endl;
}

struct Run {
	string name;
	unsigned int distance;
	Run() { name = "empty"; distance = 0; }
	Run(string s, unsigned int i)
		: name{ s }, distance{ i }{}
};

ostream& operator<<(ostream& ofs, const Run& session) {
	return ofs << "\nRun: " << session.name << " "
		<< session.distance << " km.";
}

int main()
try {
	// Some very simple testing
	{
		myVector<int> dv(5);
		print(dv);
		myVector<double> dv1{ 1.1, 2.2, 3.3 };
		print(dv1);
		myVector<char> cv{ 'a', 'c', 'd', 'x' };
		print(cv);
		cv[2] = 'c';
		//cv[5] = '#';  // not good, writes out of range
		print(cv);
		// cv.at(5) = 'y';  // throws an exception, as it should
		cv.at(2) = '*';
		print(cv);
	}

	cout << "\n****************************************\n";
	{  // demonstrate generic print function
		myVector<Run> training(3);
		training.at(0) = { "Staup", 8 };
		training.at(1) = { "Tveite-runden", 40 };
		training.at(2) = { "Vogel-runden", 12 };
		print(training);
		cout << endl;
	}

	// However, myVector is still incomplete ...
	{
		vector<double> properVector{ 1.1, 2.2, 3.3 };
		for (auto e : properVector) cout << e << " ";
		myVector<double> dv1{ 1.1, 2.2, 3.3 };
		// for (auto e : dv1) cout << e << " ";  // does not compile, begin() and end() functions are missing
		cout << endl;
	}
	
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