 // Iterator.cpp
#include<iostream>
#include<vector>
#include<set>
using namespace std;
int main() {
	// Part 1) 
	{
		cout << "Part 1)\n";
		vector<int> v{ 1,2,4,2,4,1,8 };
		for (vector<int>::iterator it = v.begin();
			 it != v.end(); it++) {
			cout << *it << " ";
		}
		cout << endl;
	}
	{
		set<int> s{ 1,4,2,4,4,2 };
		for (set<int>::iterator it = s.begin();
				it != s.end(); it++) {
			cout << *it << " ";
		}
		cout << endl;
	}
	{
		multiset<int> ms{ 1,4,2,4,4,2 };
		for (multiset<int>::iterator it = ms.begin();
				it != ms.end(); it++) {
			cout << *it << " ";
		}
		cout << endl << endl;
	}

	// Part 2)
	{
		cout << "Part 2)\n";
		vector<int> v{ 1,2,4,2,4,1,8 };
		for (auto e : v) cout << e << " ";
		cout << endl;
		//vector<int>::iterator it;
		//it[2] = 999;  // runtime error, since the iterator it was not initialized
		vector<int>::iterator it = v.begin();
		it[2] = 999; // random access iterator
		for (auto e : v) cout << e << " ";
		cout << endl;
		it = it + 4;
		cout << *it << " ";
		it--;  // bidirectional iterator
		cout << *it; cout << endl;
		set<int> s{ 1,4,2,4,4,2 };
		set<int>::iterator sit = s.begin();
		// sit[2] = 999; // set does not have random access iterator
		cout << endl;
	}

	// Part 3)
	{
		cout << "Part 3)\n";
		const vector<int> v{ 1,2,4,8 }; // const vector
		for (auto e : v) {
			cout << e << " ";
			e = 7;  // e is read, but is local variable, not an iterator
		}
		cout << endl;
		for (auto e : v) cout << e << " ";
		cout << endl;  // v is unchanged

		const vector<int> v2{ 1,2,4,8 }; // const vector
		for (vector<int>::const_iterator it = v2.begin();
			it != v2.end(); it++) {
				cout << *it << " ";
				// *it = 7;  // error, cannot assign to variable that is const
		}
		cout << endl;
		for (auto e : v2) cout << e << " ";

		vector<int> v3{ 1,2,4,8 }; // mutable vector
		for (vector<int>::iterator it = v3.begin();
			it != v3.end(); it++) {
			*it = 7;  // fills array with 7
		}
		cout << endl;
		for (auto e : v3) cout << e << " ";
		cout << endl;

		vector<int> v4{ 1,2,4,8 }; 
		for (vector<int>::reverse_iterator rit = v4.rbegin();
			rit != v4.rend(); rit++) {
			cout << *rit << " "; 
		}
		cout << endl;
	}
	return 0;
}
