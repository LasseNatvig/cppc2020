 // algo_3.cpp
#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
#include<string>
using namespace std;

// From PPP page 797, used in Part3: of this file
template<typename C> // requires a container C
void sort(C& c) {
	sort(c.begin(), c.end());
}

struct Student {
	string name;
	double grade;
	Student(string s, double g) :
		name{ s }, grade{ g }{}
};
bool operator<(const Student& lhs, const Student& rhs) {
	return (lhs.grade > rhs.grade);
}

bool compare(const Student& lhs, const Student& rhs) {
	return (lhs.name < rhs.name);
}

ostream& operator<<(ostream& ofs, const Student& s) {
	return ofs << s.name << " : " << s.grade;
}

int main() {
	// Part 1:
	{
		int sum = 0;
		vector<int> v{ 1,1,1,1000 };
		cout << accumulate(v.begin(), v.end(), 3) << endl;

		vector<int> v2{ 2,0,0,3 };
		cout << inner_product(v.begin(), v.end(), v2.begin(), 100);
		cout << endl;

		vector<int> result(v.size());
		partial_sum(v.begin(), v.end(), result.begin());
		for (auto e : result) cout << e << " ";
		cout << endl;
	}

	// Part 2:
	{
		vector<double> dv{ 22.22, 11.11, 33.33, 7.7 };
		sort(dv.begin(), dv.end());
		for (auto e : dv) cout << e << " ";
		cout << endl;

		vector<Student> sv{ {"Kari", 4.5},{"Ola", 4.0}, {"Bjarne", 3.0} };
		sort(sv.begin(), sv.end());
		for (auto e : sv) cout << e << " ";
		cout << endl;

		sort(sv.begin(), sv.end(), compare);
		for (auto e : sv) cout << e << " ";
		cout << endl;
	
	}

	// Part 3:
	{
		vector<double> dv{22.22, 11.11, 33.33, 7.7};
		sort(dv);
		for (auto e : dv) cout << e << " "; 
		cout << endl;
	}

	return 0;
}