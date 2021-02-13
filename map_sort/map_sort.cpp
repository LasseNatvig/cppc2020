// map_sort.cpp
#include "std_lib_facilities.h"

struct Student {
	string firstName;
	string lastName; 
	int id;
};
ostream& operator<<(ostream& os, const Student& s) {
	return os << s.id << ":" << s.firstName << " " << s.lastName;
}
// bool operator<(const Student& left, const Student& right) {
// 	return left.firstName < right.firstName;
// }

bool operator<(const Student& left, const Student& right) {
	return left.id < right.id;
}

int main() {
	map<Student, double> gradeStats;
	Student s1{ "Ola", "Helt", 1 };
	Student s2{ "Kari", "Heltinne", 2 };
	Student s3{ "Bjarne", "Helt", 007 };

	gradeStats[s1] = 2.0;
	gradeStats[s2] = 1.8;
	gradeStats[s3] = 1.99;

	for (const auto result : gradeStats) {
		cout << result.first << " "
			<< result.second << endl;
	}
}