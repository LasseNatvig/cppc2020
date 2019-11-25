 // unique_ptr.cpp
#include <iostream>
#include <string>
#include <vector>
#include <memory> // needed for unique_ptr
using namespace std;

vector<int>*make_vecOld() {
	vector<int>* p{ new vector<int> };
	p->push_back(3); 
	p->push_back(-2);
	// ... other code, an exception here will give memory leak
	return p;
}

vector<int>*make_vecModern() { /// PPP page 703 - top
	unique_ptr<vector<int>> p{ new vector<int> };
	p->push_back(3);
	p->push_back(-2);
	// ... other code, p will be properly destroyed by destructor if an exception is thrown 
	return p.release();  // returns the pointer
}

unique_ptr<vector<int>> make_vecBetter() { // PPP page 703 - bottom
	unique_ptr<vector<int>> p{ new vector<int> };
	p->push_back(3);
	p->push_back(-2);
	return p;  // returns unique_ptr
}

vector<int> make_vecMove() { // PPP 19.5.5 
	vector<int> res;  // this is the best solution
	res.push_back(3);
	res.push_back(-2);
	return res;  // return by move constructor
}

unique_ptr<vector<int>> make_vec_make_unique(int n)  // make a filled vector
{
	auto p = make_unique<vector<int>>();  // allocate on free store
	   // … fill the vector with data; this may throw an exception …
	for (int i = 0; i < n; i++) p->push_back(i*i);

	return p;
}

int main() {
	vector<int>* ivPtr;
	vector<int>* ivPtr2;
	ivPtr = make_vecOld();
	ivPtr2 = ivPtr;
	delete ivPtr;	
	//delete ivPtr2;  // error, crash, multiple delete on same pointer

	ivPtr = make_vecModern();
	ivPtr2 = ivPtr;
	delete ivPtr;
	// delete ivPtr2; // will still crash

	unique_ptr<vector<int>> uniPtr = make_vecBetter();
	unique_ptr<vector<int>> uniPtr2;

	//	uniPtr2 = uniPtr;  // error, not allowed, an unique_ptr must be kept UNIQUE!
	uniPtr2 = move(uniPtr); // transfer ownership of unique ptr 
	// value of uniPtr is now unspecified
	auto uPtr = move(uniPtr2);  // 
	// value of uniPtr2 is now unspecified

	// It is always one and only one pointer to the memory, and the
	// unique_ptr will always call delete when it leaves scope

	auto v = make_vecMove();
	for (auto e : v) cout << e << " ";
	cout << endl;

	unique_ptr<vector<int>> uniPtr3 = make_vec_make_unique(5);
	for (auto e : *uniPtr3) cout << e << " ";
	return 0;
}