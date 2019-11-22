 // subClass.cpp
#include "std_lib_facilities.h"

class Person {
private:
	string ssn;  //social security number
	string name;
public:
	Person(const string &name, const string &ssn)
		: name{ name }, ssn{ ssn } {};
	string getName() const { return name; }
	string getSsn() const { return ssn; }
	string toString() const; // returns Person object as string
}; 
string Person::toString() const {
	return name + ", ssn = " + ssn; 
}
 
//class Student : public Person {
struct Student : Person {// Two equivalent declarations 
						 // of class Student, see PPP 14.3.2
private:
	string program;
public:
	Student(const string &name, const string &ssn, const string &program)
		: Person{ name, ssn }, program{ program } {}
	string getProgram() const { return program; }
	string toString() const;
};
string Student::toString() const {
	return Person::toString() + ", program = " + program;
}

class Teacher : public Person {
private:
	string department;
public:
	Teacher(const string &name, const string &ssn, const string &department)
		: Person{ name, ssn }, department{ department } { }
	string getDepartment() const { return department; }
	string toString() const;
};
string Teacher::toString() const {
	return Person::toString() + ", department = " + department;
}

int main() {
	Teacher t("Petter", "23456", "IDI");
	Person p("Bjarne", "12345");
	Student s("Kari", "34567", "MTTK");

	cout << p.toString() << endl;
	cout << t.toString() << endl;
	cout << s.toString() << endl;

	vector<Person> persons; 
	persons.push_back(p);
	persons.push_back(t); // upcasting, t is also a Person-object
	persons.push_back(s); // upcasting, s is also a Person-object 
	cout << endl << "Utskrift av vector<Person>" << endl;
	for (auto pers : persons) {
		cout << pers.toString() << endl; // print objects as the vector-type
	}
	cout << "s.toString()=" << s.toString() << endl;
	cout << "s.Person::toString()=" << s.Person::toString() << endl; // 
}