// this.cpp
// Gives help to students with execise 8, TDT4102 spring 2019
// demonstrates this, <set> insert & erase, static member variable, pointer to const object, destructor

#include "std_lib_facilities.h"

class Person {
	unsigned int age;
	static set<const Person*> oldPersons;
public:
	Person(unsigned int age);
	~Person();
	void listOld();
};
Person::Person(unsigned int age) : age{ age } {
	if (age > 40) {
		oldPersons.insert(this);
	}
}
Person::~Person() {
	oldPersons.erase(this);
}

set<const Person*> Person::oldPersons;  // static member variable is one common variable for all
// objects of the class and must be initialized outside the class declaration, OR you can use inline (see exercise 8))

void Person::listOld() {
	cout << "Old: ";
	for (const Person* p : oldPersons) {
		cout << p->age << " "; // arrow-notation for the object that p points at
		// p->age = 33; // does not compile, since p is a const Person*
		// cout << (*p).age << " ";  // This is equivalent with the line above
	}
}

int main() {
	Person p1{ 20 };
	Person p2{ 42 };
	{
		Person p3{ 44 };
		Person p4{ 24 };
		p1.listOld();
	}
	p2.listOld(); // access via . (dot) operator, p2 is a named object
	// p3.listOld();  // error, why?
	return 0;
}