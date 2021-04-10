// testing.cpp
// This is based on example code from Chapter 26.3.2.2 "A simple test harness" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
#include <algorithm>
#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <vector>
using namespace std;

// Since binary_search() is in the standard library we define our own bin_search() to
// be able to inject errors for demonstrating the testing. 
// Thanks to Einar Johan for contributing to this code (guest lecture 2019)
bool bin_search(const vector<int>::const_iterator& start, 
        const vector<int>::const_iterator& end, int value) {
	if (start != end) { // start == end implies an empty sequence
		auto mid_point = distance(start, end) / 2; // sets iterator for midpoint, distance returns distance in vector measured by "number of hops"
          // See also https://en.cppreference.com/w/cpp/iterator/distance
		auto mid_value = *(start + mid_point); // reads and stores the value found at the midpoint

		if (mid_value == value) {
			return true;  // value found
		} else if (mid_point == 0) {
			return false; // value is not found, and there are no more elements to check
		} else if (value > mid_value) { // search in upper half
			return bin_search(start + mid_point, end, value); // Try with "end - 1", testcase 1.4 will find the bug
		} else if (value < mid_value) { // search in lower half
			return bin_search(start, end - mid_point, value); // Uses "iterator subtraction". Try with "start + 1", testcase 1.1 will find the bug
		}
		return true;
	}
	return false;
}

struct Test {  
    string label;  // label (name)
    int val; // value to search after
    vector<int> seq; // sequence to search in
    bool res; // expected result
};

struct TestSyntaxError {
    string s1 = "ERROR: Invalid test file format ";
    TestSyntaxError(string msg) { 
        throw runtime_error(s1 + msg);
    }
};

// The following code has a compact layout to fit on one slide
// Example input: { SomeLabel 7 { 1 2 3 5 8 13 21} 0 }
istream& operator>>(istream& is, Test& t) { 
    string leftPar1, leftPar2;
    if ((is >> leftPar1 >> t.label >> t.val >> leftPar2) 
         && (leftPar1 != "{" || leftPar2 != "{")) 
         {  throw TestSyntaxError("before number sequence"); }
    t.seq.clear();  // clear erases all elements and sets size of vector to zero
    string s = ""; bool endOfSequenceFound = false;
    while ((is >> s) && !endOfSequenceFound) {
        if (s == "}") { endOfSequenceFound = true; break; }
        t.seq.push_back(stoi(s));
    }
 
    string rightPar = "";
    if ( !(is >> t.res)) { throw TestSyntaxError("result-value missing");} 
    else if ((is >> rightPar) && 
        (rightPar != "}")) { throw TestSyntaxError("after number sequence");}  
    return is;
}

ostream& operator<<(ostream& os, const Test& t) {
    os << "{ " << t.label << ' ' << t.val << " { ";
    for (auto e : t.seq) os << e << " ";
    return os << "} " << t.res << " }";
}

int test_all(string testFileName)  {
    ifstream tests{testFileName};
    if (!tests) { // check file is OK
        cerr << "Could not open test-file: " << testFileName << " will exit!" << endl;
        exit(-1);
    };
    int error_count = 0;
    Test t;
    while (!tests.eof() && tests >> t) {
        cout << t <<  " --- done " << endl; // to show progress during testing
        bool result = bin_search( t.seq.begin(), t.seq.end(), t.val);
        if (result != t.res) { // Report failure
            cout << "failure: test " << t.label
                 << " binary_search: "
                 << t.seq.size() << " elements, v == " << t.val
                 << " -> " << t.res << '\n';
            ++error_count;
        }
    }
    return error_count;
}

int main()
try {
    string testFile{"BinarySearchTests.txt"}; 
    cout << "Running all tests from " + testFile + "\n\n";
    int errors = test_all(testFile);
    cout << "number of errors: " << errors << "\n";
    return 0;
} catch (exception e) {
    cerr << "Exception caught: " << e.what() << endl;
    return -1;
}