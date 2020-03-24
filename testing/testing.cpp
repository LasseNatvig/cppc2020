
// This is based on example code from Chapter 26.3.2.2 "A simple test harness" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
#include <algorithm>
#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <vector>
using namespace std;

// --- legg inn min egen binSearch --- bruk fra Einar Johan  const iterator ...  /// gå over all kode, forenkle ... 

// Since binary_search() is in the standard library we define our own bin_search() to
// be able to inject errors for demonstrating the testing. 

bool bin_search(const vector<int>::const_iterator& start, const vector<int>::const_iterator& end, int value) {
	if (start != end) {
		auto mid_point = (end - start) / 2;
		auto mid_value = *(start + mid_point);
		if (value < mid_value) {
			return bin_search(start, end - mid_point, value);
		}
        else if (value > mid_value) {
			return bin_search(start + mid_point, end, value);
		} 
        else if (mid_value == value) {
			return true;
		}
        else {
			return false;
		} 
	}
}
// EJAA-variant
// bool bin_search(const vector<int>::const_iterator& start, const vector<int>::const_iterator& end, int value) {
// 	if (start != end) {
// 		auto mid_point = (end - start) / 2;
// 		auto mid_value = *(start + mid_point);
// 		if (mid_value == value) {
// 			return true;
// 		} else if (mid_point == 0) {
// 			return false;
// 		} else if (value > mid_value) {
// 			return bin_search(start + mid_point, end, value);
// 		} else if (value < mid_value) {
// 			return bin_search(start, end - mid_point, value);
// 		}
// 		return true;
// 	}
// 	return false;
// }


struct Test {
    string label;
    int val;
    vector<int> seq;
    bool res; 
};
istream& operator>>(istream& is, Test& t) { // use the described format 
    // Example input: { 2-7 7 { 1 2 3 5 8 13 21} 0 }
    string a, b;
    if (is >> a >> t.label >> t.val >> b && (a != "{" || b != "{")) {  // *****************TODO simplify and test logic 
        cerr << "ERROR: Invalid test file format" << endl;
        return is;
    }
    // cout << a << '|' << t.label << '|'  << b << '|'  << t.val << '|' ;  // debug 
    t.seq.clear();
    copy( istream_iterator<int>(is), istream_iterator<int>(), back_inserter(t.seq));
    is.clear();
    //std::copy(t.seq.begin(), t.seq.end(), std::ostream_iterator<int>(cout," "));
    string c, d;
    int res = 0;
    if (is >> c >> res >> d && (c != "}" || d != "}")) {
        std::cerr << "ERROR: Invalid test file format" << std::endl;
        return is;
    }
    t.res = res;
    //cout << c << '|' << t.res << '|' << d << '|' ;
    return is;
}
ostream& operator<<(ostream& os, const Test& t) {
    os << "{ " << t.label << ' ' << t.val << " { ";
    std::copy(t.seq.begin(), t.seq.end(), std::ostream_iterator<int>(os," "));
    return os << "} " << t.res << " }";
}

int test_all(string testFileName)  {
    ifstream tests{testFileName};
    if (!tests) {
        cerr << "Could not open test-file: " << testFileName << " will exit!" << endl;
        exit(-1);
    };
    int error_count = 0;
    Test t;
    while (tests>>t) {
        cout << t << endl;
        bool r = bin_search( t.seq.begin(), t.seq.end(), t.val);
        if (r !=t.res) {
            cout << "failure: test " << t.label
                 << " binary_search: "
                 << t.seq.size() << " elements, v==" << t.val
                 << " -> " << t.res << '\n';
            ++error_count;
        }
    }
    return error_count;
}

int main()
try {
    string testFile{"BinarySearchTests.txt"}; 
    cout << "Running all tests from " + testFile + "\n";
    int errors = test_all(testFile);
    cout << "number of errors: " << errors << "\n";
    return 0;
} catch (exception e) {
    cerr << "Exception caught:" << e.what() << endl;
    return -1;
}


// int main() {
//     string testFile{"BinarySearchTests.txt"}; 
//     cout << "Running all tests from " + testFile + "\n";
//     int errors = test_all(testFile);
//     cout << "number of errors: " << errors << "\n";
//     return 0;
// }
