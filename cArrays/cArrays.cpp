 // cArrays.cpp
// - demonstrates 1D and 2D C-arrays
#include<iostream>
#include<iomanip> // needed for setw() and setfill()
using namespace std;

constexpr int sizeA = 5;
int globalA[sizeA];     // global array. MAYBE initialized to zeros, but do not trust it

void normalAccessGlobalArr() { /* Demonstrates access to a global array. It is known everywhere in your
	program so you do not need to pass it as parameter. HOWEVER, always try to avoid global variables! */

	// traditional:
	for (int i = 0; i < sizeA; i++) {
		cout << globalA[i] << " ";
	}
	cout << endl; // range for:
	for (int i : globalA) {
		cout << i << " ";
	}
	cout << endl; // with auto:
	for (auto element : globalA) {
		cout << element << " ";
	}
	cout << endl;
}

void localArr(int n) {
	int localInts[sizeA]; // local array, is NOT initialized, random values
	for (int i : localInts) {
		cout << i << " ";
	}
	cout << endl;
	char localChars[4*2]; // local array, is NOT initialized, random values
	for (auto c : localChars) {
		cout << c << " ";
	}
	// double localDoubles[n]; // error, value of parameter "n" cannot be used as constant
}

void arrayInit() { // PPP 18.6.3.
	int ai[] = { 1, 2, 3, 4, 7 }; // size is given by init. list
	//int bi[] = {}; // error, empty initializer is invalid for an array with unspecified bound
	int ci[4] = {}; // OK, since we know the size, elements filled with 0'es
	int di[4] = { 1,2 }; // OK, result is {1, 2, 0, 0}
}

int sumArray(int arr[], int n) {  // a classical function
	// with an array as argument (of unknown size) and 
	// its size as following argument
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}
	return sum;
}

void twoDimensional() {
	constexpr int m = 4;
	int twoDim[m][m]; // a 4 x 4 array of int
	for (int i = 0; i < m; i++) // set values
		for (int j = 0; j < m; j++)
			twoDim[i][j] = (i + 1) * 1000 + j;

	for (int i = 0; i < m; i++) { // print
		cout << setw(6);  
		cout << "\n i = " << i << " : ";
		for (int j = 0; j < m; j++)
			cout << twoDim[i][j] << " ";
	}
	cout << endl;
}

void cStrings() {
	char a[] = "abcde"; // C-strings are indexed from 0
	// Note, only character arrays can be initialized with literal strings
	cout << "size of a in bytes: " << sizeof(a) << endl;  //prints 6, why? --- C-strings are zero-terminated. Check it in the debugger
	cout << a << ", " << a[0] << " " << a[4] << endl;
	a[5] = 'X'; // destroys zero-termination by will
	cout << a << endl; // Shows string is destroyed
}

void outOfRangeAccess() {
	cout << "Dangerous out of range read: " << globalA[-10] << " "
		<< globalA[2000] << endl;
	cout << "Even worse: ";
	globalA[-10] = 8888; globalA[2000] = 9999;
	cout << "Out of range read after dangerous writing: " 
	     << globalA[-10] << " " << globalA[2000] << endl;
}

void testArrays() {
	// --------------------------------------
	// global vs. local arrays
	normalAccessGlobalArr();
	localArr(5); // Argument value 5 not used, see the function
	cout << endl;

	//----------------------------------------
	// access via [] or *
	globalA[3] = 88; // normal array access, preferred
	*globalA = 55; // arrayName[0] is equivalent to *arrayName
	int* ptr = &globalA[1]; // get address of array element 
	*ptr = 66;  // write to that element
	ptr++; // example of pointer arithmetic  
	*ptr = 77;
	for (int i = 0; i < sizeA; i++) {
		cout << globalA[i] << " ";
	}
	cout << endl;

	//----------------------------------
	// Array initialization and C-strings
	arrayInit();
	cStrings();

	//-----------------------------------------------------
	// Typical handling of array of unknown size
	constexpr int n = 4;
	int arr[n] = { 1,2,3,100 };
	cout << sumArray(arr, n) << endl;

	// ---------------------------------
    // Two dimensional array, you can have 3D, 4D etc...
	twoDimensional();
	
	// ---------------------------------
	// Out of range access, Don't do this!
	outOfRangeAccess();
}

int main() try {
	testArrays();
	cout << "\nType any char + return to quit:";
	char c; cin >> c;
	return 0;
}
catch (exception& e) {
	cerr << "error: " << e.what() << endl;
	char c; cin >> c;
	return -1;
}
catch (...) {
	cerr << "error: unknown exception";
	char c; cin >> c;
	return -2;
}