#include <iostream>
#include <string>
using namesapce std;

// use nodes to create a linked list

struct ListNode 
{
	string item;
	ListNode *next;
};

// This is circularly defined, each instance will be one node

int main () {
	
	// Recap:
	// pointers allow us to keep track of data, and are needed for dynamic memory allocation
	// pointers can point to user defined types (structs, classes)

	// Dynamic Memory:
	// create variables "on the fly", it uses the heap instead of the stack
	// allows for greater program flexibility, write a program that works on various sized files

	// Nodes and Lists:
	// Arrays use continuous space in memoery, 1004, 1008, 1012, ect.
	// If you need to insert within an array, you have to copy all the elements and move them over
	// Alternative approach is to allocate space for elements, dynamically
	// We link the elements via pointers, one node per element
	// A node stores an element and a pointer, and the pointer stores the address of the next element in the next node
	// These are dynamic data structures, each element is a node

	// Copy elements from array to linked list

	string a[4] = {"one", "two", "three", "four"};
	Listnode *head, *tmp, *current;
	head = new ListNode;
	head->item = a[0];
	head->next = nullptr;
	current = head;   
	int i = 1;             // right now we have a node names head, with a[0] as the data and the pointer as NULL
	while (i < 4) {
		tmp = new ListNode;
		tmp->item = a[i];
		tmp->next = nullptr;
		current->next = tmp;
		current = tmp;
		i++;
							// this sets the pointer in your current to the next element, sets the next element pointer to null, and sets next to current
							// to retrieve an element, you have to start the the beginning anf TRAVERSE the list, because you don't actually have the address
	}
	current = head; 
	while (current != nullptr) {
		cout << current->item << endl;
		current = current->next;
	}

	return 0;
}

// (*current).next
// current->next  
// SAME THING