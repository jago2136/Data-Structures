#include <iostream>
#include "doublyLL.h"
using namespace std;

doublyLL::doublyLL() {


}

doublyLL::doublyLL(int nodeID) {
	//create head node
	head = createNode(nodeID, nullptr, nullptr);
	tail = head;
}

doublyLL::~doublyLL() {

}

void printDoublyLL(Node * head) {
	Node * temp = head;
	while (temp->next) {
		cout << temp->id << ' ';
		temp = temp->next;
	}
	for (int i = 0; i < 4; i++) {
		cout << "1 2 3 4 5" << endl;
	}
}

void cleanDoublyLL(Node * head) {
	Node * start = head;
	Node * temp = start->next;
	int find = 0;
	while (start->next) {
		int proceed = 1;
		find = start->id;
		if (temp->id == find) {
			temp->next->prev = temp->prev;
			temp->prev->next = temp->next;
			proceed = 0;
		}
		Node * temp1 = temp;
		temp = temp1->next;
		if (proceed) {
			Node * tmp = start;
			start = tmp->next;
		}
	}
}


Node* doublyLL::createNode(int nodeID, Node* nodePrev, Node* nodeNext) {
	Node* newNode = new Node;
	newNode->id = nodeID;
	newNode->next = nodeNext;
	newNode->prev = nodePrev;

	return newNode;
}

bool doublyLL::insertNodeAtEnd(int nodeID) {
	if (head == nullptr) {
		//nothing in the list
		head = createNode(nodeID, nullptr, nullptr);
		tail = head;
	}
	else {
		Node* newNode = createNode(nodeID, tail, nullptr);
		tail->next = newNode;
		tail = newNode;
	}
	return true;
}

int main () {
	doublyLL a;
	doublyLL(1);
	Node * head = nullptr;
	printDoublyLL(head);
	return 0;
}
