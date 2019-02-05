#include <iostream>
#include <string>
using namespace std;

/* 
Stacks 
	- LL implementation
	- Array implementation

Stack LIFO
	Data struct that allows a specific order in which operations on its data can be performed
		- Typical analogy is a stack of plates, you can only add to the top (push)
		- Can only remove from the top (pop), unless no elements are left
		- Can have a limit on max number of elements
	Usage of Stacks
		- Call stack during program execution
			 Currently active subroutines
		- Stack overflow will occur if too many functions are on the call stack (or segmentation fault)
	Stack Absract Data Type
		- Private:
			"top" keeps track of top element
			"maxSize" 
			"count" both of these depend on your implementation
		- Public:
			initialize () (constructor)
			isFull()
			isEmpty()
			push()
			pop()
			display()
	Singly LL Stack Implementation
		- A special case of SLL
		- Don't have to set maxSize 
		- "top" is a pointer to Node type
		- Stack is empty if "top" is NULL
		- "Push" adds new nodes to the LL
		- "Pop" removes node from top and returns the node (could be defined differently)





*/

#include "stack.h"

	Stack::Stack() {
		top = nullptr;
	}
	Stack::~Stack() {
		cout << "destruction" << endl;
		while (!isEmpty()) {
			pop();
		}
	}

	bool Stack::isEmpty() {
		if (top == nullptr)
			return true;
		else 
			return false;
	}

	void Stack::push (string newItem) {
		Node *temp = new Node;
		temp->item = newItem;

		if (isEmpty()) {
			top = temp;
			top->next = nullptr;
		}
		else {
			temp->next = top;
			top = temp;
		}
	}

	void Stack::display() {
		Node *current = top;
		cout << "Top of the stack: \n";
		while (current != nullptr) {
			cout << current->item << endl;
		}
	}

	Node * Stack::pop() {
		Node *temp; 
		if (isEmpty()) {
			temp = top;
			top = top->next;
		}
		else {
			cout << "Stack is empty, underflow, returning NULL pointer.\n";
			temp = nullptr;
		}
	}

int main () {

	return 0;
}