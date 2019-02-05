#include <iostream>
using namespace std;

struct ListNode {
	string userName;
	ListNode *link;   //circular definition 
};

//Dynamically allocated memory

// automatic variables are allocated on the stack, dynamic are on the heap (allocated at run-time)
// main operatores used with these is "new" and "delete"
// always need a pointer, and assign that pointer to point to "int *p1 = new 'data type'" (new int, new char, etc)
// then delete the memory, delete pl;
//it doesnt delete the pointer, but it deletes the data so you cn reuse it

Node * searchLL(ListNode *head, string target);


int switch(int *a, int *b){
	int x = *a;
	*a = *b;
	*b = x;
	return 0;
}

int main () {

	int p = 3;
	int q = 4;
	int *r = &p;
	int *s = &q;
	int err = switch(r,s);
	cout << p << q << endl;
	return 0;

	// coding a dynamic array, user input length

	int n;
	int *ptr;
	cin >> n;
	ptr = new int[n];
	delete [] ptr;

	// create a dynmaic array of length n, then fill with user inputs, then double the length while keeping exisiting values unchanged

	n = 5;
	int *a;
	a = new int[n]; //dynamically allocated
	for (int i = 0; i<n; i++) {
		cin >> a[i];
	}
	for (int i=0;i<n;i++) {
		cout << a[i] << endl;
	}
	int *temp;
	temp = new int[2*n];
	for (int i = 0; i<n; i++) {
		temp[i] = a[i];
	}
	a = temp;
	delete [] temp;


	// New Lecture

	/*
	Minimum needed is usually three elements (Node struct)
		- Head, temp, curr
	Allocate space for each node one at a time, set 'head' pointing to first node (THIS NEVER CHANGES)
	Use 'current' to point to the most recently created node (prev node)
	Use 'temp' to create new nodes
		- always initialize the 'temp' node to point to NULL
		- the tail should point to NULL, always assume the new node could be the last one
	Traverse a list by running through pointers until you find NULL
	Ex.
	Find a node that contains "tres" and return its address, if not found, return Null

	while (current != NULL) {
		if current->item = target return current;
		else return NULL;

	3 Scenarios for Creating Nodes:
	1) At the beginning
		- Create new Node (will initially be your temp)
		- Link new node with the current head
		- Make head point to new node
		- Set temp to NULL
	2) After a given Node
		- Create new Node (initially be your temp)
		- Link new Node with next Node
		- Link previous with New Node
	3)


	}
	*/


	return 0;
}



Node * searchLL(ListNode *head, string target) {
	Node *current;
	current = head;

	while (current != nullptr){
		if (current->item == target) {
			return current;
		}
		else {
			current = current->next;
		}
	}
	return nullptr;
}

Node * insertHead ( Node *head, string newItem) {
	Node *tmp = new Node;
	tmp->Item = newItem;
	tmp->next = head;
	return tmp;
}

Node * insertAfter ( Node *prev, string  newItem) {
	Node *tmp = new Node;
	tmp->Item = newTiem;
	tmp->next = prevNode->next;
	prevNode->next = tmp;
}
