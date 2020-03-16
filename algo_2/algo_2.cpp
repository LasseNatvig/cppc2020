 // algo_2.cpp
// Inspired by https://en.cppreference.com/w/cpp/algorithm/for_each

#include <vector>
#include <algorithm>
#include <iostream>
#include<string>

using namespace std;

struct PrintGE {// Greater or Equal
	PrintGE(int v) : value{ v } { }
	int value;
	// This version was used in the lecture tuesday 26/3 but the return type is not needed here
	// since the printout is done in the function
	//bool operator()(int x) {
	//	if (x >= value) {
	//		cout << " " << x;
	//		return true;
	//	}
	//	else return false;
	//}
	void operator()(int x) {  // mark-A
		if (x >= value) {
			cout << " " << x;
		}
	}
};

// This version was used in an earlier lecture but the return type is not needed 
//    in the overloading of operator() above (mark-A)
//bool operator()(int x) {
//	if (x >= value) {
//		cout << " " << x;
//		return true;
//	}
//	else return false;
//}

void print(const int& n) {
	cout << " " << n;
}

int myFunc(int a, int b) {
	return ((a / 100) + b);
}

int main() {
	{// Part 1, for_each
		vector<int> nums{ 1, 2, 3, 100, 200, 300 };
		for_each(nums.begin(), nums.end(), print);
		cout << '\n';
		for_each(nums.begin(), nums.end(), PrintGE(100));
		cout << '\n';
	}
	cout << endl;

	{// Part 2, unique_copy
		vector<int> v{ 1, 2, 2, 3, 2, 2, 4, 4, 4, -7, 8};
		vector<int> v2(v.size()); // Reserve sufficient space in destination
		unique_copy(v.begin(), v.end(), v2.begin());
		for_each(v2.begin(), v2.end(), print);
		cout << '\n';
	}
	cout << endl;

	{// Part 3, merge
		vector<int> v1{ 1, 2, 3, 100, 200, 300 };
		vector<int> v2{ 3, 4, 5, 6, 800, 10000 }; 
		vector<int> dest(v1.size() + v2.size());
		merge(v1.begin(), v1.end(), v2.begin(), v2.end(), dest.begin());
		for_each(dest.begin(), dest.end(), print);
		cout << '\n';	
	}
	cout << endl;

	{// Part 4, transform
		string s  = "hello";
		cout << "s before: " << s;
		transform(s.begin(), s.end(), s.begin(), toupper);
		cout << " and after: " << s;
		cout << endl;

		vector<int> v1{ 1000, 2000, 10000, 20000 };
		vector<int> v2{ 3, 9, 21, 64 };
		transform(v1.begin(), v1.end(), v2.begin(), v1.begin(), myFunc);
		for (auto e : v1) cout << e << " ";
		cout << endl;

	}

	{
		vector<int> s1{ 10, 20, 30, 40, 50 };
		vector<int> s2{             40, 50, 60, 70};
		vector<int> res(s1.size()+s2.size());
		set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), res.begin());
		for (auto e : res) cout << e << " "; cout << endl;
		res.clear(); 

		res.resize(min(s1.size(), s2.size()));
		set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), res.begin());
		for (auto e : res) cout << e << " "; cout << endl;
		res.clear();

		res.resize(s1.size());
		set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), res.begin());
		for (auto e : res) cout << e << " "; cout << endl;

	}

	return 0;
}