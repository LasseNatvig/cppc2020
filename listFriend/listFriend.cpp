 // listFriend.cpp
// a simpler example than PPP 17.9.3

#include <iostream>
#include <string>
using namespace std;

class Node {
	string data;
	Node* next;
public: 
	Node(string data) : data{ data }, next{ nullptr }{};
	friend class List;
};
class List {
	Node* head = nullptr;
	Node* last = nullptr;
public:
	void add(string data);
	void print();
	~List();
};

void List::print() {
	Node* ptr = head;
	while (ptr != nullptr) {
		cout << ptr->data << " ";
		ptr = ptr->next;
	}
	cout << endl;
}
void List::add(string data) {
	if (head == nullptr) {
		head = new Node{ data };
		last = head;
	}
	else {
		last->next = new Node{ data };
		last = last->next;
	}
}
List::~List() {
	while (head != nullptr) {
		Node* prev = head; // previous node
		head = head->next;
		delete prev;
		print(); // debug, show correct destruction of one Node
	}
	cout << "List contents at end of List-destructor: ";
	print(); // debug, show correct destruction by empty list
}

int main() {
	{
		List words;
		words.add("How");
		words.add("are");
		words.add("you?");
		words.print();
	}
	return 0;
}