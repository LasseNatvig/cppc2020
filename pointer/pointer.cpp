// pointer.cpp, note this is an "empty project" without the PPP scaffolding
#include<iostream>
using namespace std;
int main() {

	// Part 1, slide pointer and pointer values
	int num = 10;
	double realNum = 22.33;
	int *intPtr; // a pointer to int
	double* doublePtr; // a pointer to double
	intPtr = &num; // & is address of operator
	doublePtr = &realNum;
	cout << *intPtr << " " << *doublePtr << endl; // * is dereferencing operator

	{ // A much better way of doing exactly the same
		int num = 10;
		double realNum = 22.33;
		int *intPtr{&num}; // a pointer to int
		double* doublePtr = &realNum; // a pointer to double
		cout << *intPtr << " " << *doublePtr << endl;
	}

	// Part 2, slide "Access through pointers"
	{ // this is C-arrays
		int* p3 = new int[5]; // get (allocate) 5 ints
			// array elements are numbered [0], [1], [2], …
		p3[0] = 7;	// write to (“set”) the 1st element  of p3
		p3[1] = 9;
		int x2 = p3[1];	// get the value of the 2nd element of p3
		int x3 = *p3; // we can also use the dereference operator * for an array
		 // *p3 means p3[0]  (and vice versa, p3[0] means *p3)
	}

	{
		typedef int* intPtr; // 
		intPtr p1;
		intPtr p2 = nullptr;
		cout << *p1 << " " << *p2;   // *p2 gives exception in debugger 
	}
}