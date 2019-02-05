#include <iostream>
#include <string>
using namespace std;


/* Recap Class/Object
	
	Object is an instance of a class
	Similar to structs, but have public as well as private. 
		- a struct is just all public, no control over input data
	Have member functions, called methods.
		- control access to the member data
	Constrcutors are used to initialie objects of a given class.
		- gets the same name as the class

		------------------------------------------------

	Create a Linked List Class
		-still use a node as before: struct Node { string item; Node *next; }
		-introduce an approach to constructing a LL that lends itself well to class-based
			1) 2 private members: head and tail pointers
			2) Public: Constructor that initializes both pointers to NULL
					   Grow method for allocating nodes dynamically (and also fill the node payload)
					   		1) If LL is empty
					   			- Allocate node and point head
					   			- Point tail to same Node
					   			- Write contents to Node member
					   			- Write null to head->next or tail->next
					   		2) If LL is not empty
					   			- Use temp pointer and allocate new Node
					   			- Write contents to node member
					   			- tmp->next point to NULL
					   			- Write tail->next = tmp
					   			- Tail pointer point to last node
					   		3) Desctructor (gets called automatically when object goes out of scope)
					   			- Deallocate dynamic memory
					   		4) Display function
					   			- Traverse + cout



*/

struct Node {
	string item
	Node *next
};

class List {
private:
	Node *head, *tail;

public:
	List() {            //constructor definition
		head = nullptr;
		tail = nullptr;
	}

	~List() {
		// define destructor here
	}

	void growList (string newItem) {
		if (head == nullptr) {
			head = new Node;
			head->item = newItem;
			head->next = nullptr;
			tail = head;
		}
		else {
			Node *tmp = new Node;
			temp->item = newItem;
			// next, link tail with new node
			tail->next = temp
			tail = temp;
			tail->next = nullptr;
		}
	}

	void displayList() {
		Node *current = head;
		while (current != nullptr) {
			cout << current->item << endl;
			current = current->next;
		}
	}
};





int main() {

	List l;
	string arr[] = {"jeden","dwa","trzy"};
	int arrLen = 3;
	for(int i = 0; i<arrLen; i++) {
		l.growList(arr[i]);
	}

displayList();

	return 0;
}