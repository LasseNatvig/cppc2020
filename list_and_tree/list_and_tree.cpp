// list_and_tree.cpp
// Note:
// This code (wrt. linked list) is simpler and "less object-oriented" than LinkedList.cpp from earlier in the course
// - main purpose here is to illustrate list vs. tree, and some simple recursive functions
// - destructors for list and tree are not shown here

#include <iostream>
#include<vector>
#include <cassert>

using namespace std;

struct ListNode {
	int data;
	ListNode* next;
	ListNode(int i) : data{ i }, 
		next{ nullptr } {}
};

struct TreeNode {
	int data;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int i) : data{ i }, 
		left{ nullptr }, right{ nullptr } {}
};

ListNode* buildList(const vector<int>& v) {
	ListNode* last = nullptr;
	ListNode* first = nullptr;
	for (int e : v) { // for all elelements in vector
		if (last == nullptr) { // first element to insert
			last = new ListNode{ e };
			first = last;
		}
		else { // append next element after last
			last->next = new ListNode{ e };
			last = last->next;
		}
		// last->next = nullptr;  // Not needed since next is set to nullptr in constructor
	}
	return first;
}
void printList(ListNode* l) {
	ListNode* n = l;
	cout << "List: ";
	while (n != nullptr) {
		cout << n->data << " ";
		n = n->next;
	}
	cout << endl;
}
// You should free up memory in all nodes allocated in a list. Not
// implemented here for brewity. Loop through the list and delete nodes on the way.
// You need a pointer to previous node, see LinkedList.cpp

// Using recursion to reverse list
void printReverseList(ListNode* l) {
	if (l == nullptr) {
		cout << "Reverse list: ";
		return;
	}
	else {
		cout << "Node: " << l->data << endl; // debug
		printReverseList(l->next);
		cout << l->data << " ";
	}
}

void insertNode(int i, TreeNode* root) {  
	if (i < root->data) {
		if (root->left == nullptr) {
			root->left = new TreeNode{ i };
		}
		else { insertNode(i, root->left); }
	}
	else {
		if (root->right == nullptr) {
			root->right = new TreeNode{ i };
		}
		else { insertNode(i, root->right); }
	}
}

TreeNode* buildTree(const vector<int>& v) { 
	// assumes at least one element
	assert(v.size() > 0);
	TreeNode* root = new TreeNode(v[0]);
	for (unsigned int i = 1; i < v.size(); i++) { 
		insertNode(v[i], root);
	}
	return root;
}

void printTree(TreeNode* root) {
	if (root != nullptr) {
		printTree(root->left);
		cout << root->data << " ";
		printTree(root->right);
	}
}

int main() {
	vector<int> v{ 40, 20, 50, 10, 60, 30 };
	ListNode* list = buildList(v);
	printList(list);
	printReverseList(list);
	
	TreeNode* root = buildTree(v);
	cout << endl << endl << "Binary tree: ";
	printTree(root);

	// // uncomment this to see the effect of assert
	// vector<int> v2{};
	// root = buildTree(v2);

	return 0;
}