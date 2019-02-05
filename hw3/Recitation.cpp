#include <iostream>
#include <string>
#include <fstream> 
using namespace std;


struct Node {
	int key;
	Node * next;
};

void displayList(Node * head) {
	Node *current = head;
	while (current != nullptr) {
		cout << current->key << ' ';
		current = current->next;
	}
	cout << endl;
}

Node * Append1 (Node * head, int key) {
	if (key % 2 == 0){
		Node * temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->key = key;
		Node * newNode = new Node;
		newNode->key = temp->key;   
		newNode->next = NULL;
		temp->next = new Node;
	}
	return head;
}

Node * Append2 (Node * head, int key) {
	Node * temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->key = key;
	Node * newNode = new Node;
	newNode->key = temp->key;   
	newNode->next = NULL;
	temp->next = new Node;
	return head;
}

int main() {
	Node * head = new Node;
	Node * first = new Node;
	Node * second = new Node;
	head->key = 5;
	first->key = 1;
	second->key = 3;
	head->next = first;
	first->next = second;
	second->next = NULL;
	int insert = 3;
	Append1(head, insert);
	displayList(head);
	Append2(head, insert);
	displayList(head);
	return 0;
}