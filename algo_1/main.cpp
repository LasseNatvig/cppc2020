 // algo_1.cpp
#include<iostream>
#include<vector>
#include<set>
#include <algorithm> // Required by find_if() (But not by find() !?)
using namespace std;

void search(vector<int>& v, int x) {
	vector<int>::iterator it = find(v.begin(), v.end(), x);
	if (it != v.end()) {
		cout << "we found " << *it << endl;
	}
}

// generic search and print
template <typename T, typename E>
void genSearchPrint(const T& container, const E& elt) {
	auto it = find(container.begin(), container.end(), elt);	
	if (it != container.end()) {
		cout << "we found " << *it << endl;
	}
}

bool odd(int i) { return i % 2; }

bool larger_than_42(double x) { return x > 42; }

double v_val; // the value to which larger_than_v() 
			  // compares its argument
bool larger_than_v(double x) { return x > v_val; }

class Larger_than {
	int v;
public:
	Larger_than(int vv) : v{ vv } {}
	bool operator()(int x) const { return x > v; }
};


int main() {
	vector<int> v{ 11, 22, 33, 77, 44 };
	search(v, 22);
	search(v, 23);
	search(v, 44);

	genSearchPrint(v, 77);
	set<double> ds{ 11.11, 22.22, 44.44, 33.33 };
	genSearchPrint(ds, 22.23);
	genSearchPrint(ds, 22.22);

	vector<int> v2{ 10, 22, 33, 77, 44 };
	auto it = find_if(v2.begin(), v2.end(), odd);
	if (it != v2.end()) {
		cout << "find_if found " << *it << endl;
	}

	vector<double> vd{ 11.11, 22.22, 44.44, 55.55, 33.33 };
	auto it2 = find_if(vd.begin(), vd.end(), larger_than_42);
	if (it2 != vd.end()) {
		cout << "find_if found " << *it2 << endl;
	}

	v_val = 42;
	auto it3 = find_if(vd.begin(), vd.end(), larger_than_v);
	if (it3 != vd.end()) {
		cout << "find_if found " << *it3 << endl;
	}

	auto it4 = find_if(vd.begin(), vd.end(), Larger_than(42));
	if (it4 != vd.end()) {
		cout << "find_if found " << *it4 << endl;
	}



	return 0;
}