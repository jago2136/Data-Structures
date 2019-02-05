#include <iostream>
#include <string>
#include <fstream> 
#include <sstream>
#include <ctime>
#include "priorityQueueLL.h"
using namespace std;

LL::LL() {
	head = nullptr;
	tail = nullptr;
	quantity = 0;
}

LL::~LL() {

}

void LL::printQueue() {
	if (!head) {
		cout << "Empty Queue.\n";
		return;
	}
	Node *temp = head;
	if (!temp->next) {
		cout << temp->name << ' ' << temp->priority << ' ' << temp->treatment << endl;
		return;
	}
	while (temp) {
		cout << temp->name << ' ' << temp->priority << ' ' << temp->treatment << endl;
		temp = temp->next;
	}
	return;
}

void LL::enqueue(Node *temp) {
	//cout << quantity;
	if (!temp) return;
	if (!quantity) {
		head = temp;
		head->next = nullptr;
		quantity++;
		return;
	}
	if (quantity == 1) {
		quantity++;
		if(head->priority == temp->priority) {
			if(head->treatment > temp->treatment) {
				tail = head;
				head = temp;
				head->next = tail;
				tail->next = nullptr;
				return;
			}
			else {
				tail = temp;
				head->next = tail;
				tail->next = nullptr;
				return;
			}
		}
		if(head->priority < temp->priority) {
			tail = temp;
			head->next = tail;
			tail->next = nullptr;
			return;
		}
		if (head->priority > temp->priority) {
			tail = head;
			head = temp;
			head->next = tail;
			tail->next = nullptr;
			return;
		}
	}
	Node *curr = head;
	Node *prev = nullptr;
	if (quantity > 1) {
		quantity++;
		while(curr->next) {
			if(curr->priority == temp->priority) {
				while ((curr->priority == temp->priority) && curr->next) {
					if (curr->treatment >= temp->treatment) break;
					prev = curr;
					curr = curr->next;
				}
				if (curr == head) {
					temp->next = curr;
					head = temp;
					return;
				}
				if (curr == tail) {
					if (curr->priority < temp->priority) {
						curr->next = temp;
						temp->next = nullptr;
						tail = temp;
						return;
					} 
					temp->next = prev->next;
					prev->next = temp;
					return;
				}
				temp->next = curr;
				prev->next = temp;
				return;
			}
			if (curr->priority > temp->priority) {
				if (curr == head) {
					temp->next = curr;
					head = temp; 
					return;
				}
				temp->next = curr;
				prev->next = temp;
				return;
			}
			prev = curr;
			curr = curr->next;
		}
		if (curr == tail) {
			if (curr->priority < temp->priority) {
				curr->next = temp;
				temp->next = nullptr;
				tail = temp;
				return;
			} 
			temp->next = prev->next;
			prev->next = temp;
			return;
		}
		cout << "Node could not be added\n";
		return;
	}
}

bool LL::dequeue () {
	if (!head) {
		cout << "Empty queue.\n";
		return false;
	}
	cout << head->name << ",  " << head->priority << ",  " << head->treatment << endl;
	Node* temp = head->next;
	delete head;
	head = temp;
	return true;
}


Node* LL::createNode(string name, int priority, int treatment) {
	Node *temp = new Node;
	temp->name = name;
	temp->priority = priority;
	temp->treatment = treatment;
	return temp;
}

int mainLL (string file) {
	clock_t start;
    start = clock();
    int i = 0;
    //while (i < 500){
		LL LinkedList;
		ifstream data(file);                          
		string info[3];
		int x = 0, k = 0;  
		if(data.is_open()) {
			while(data.good() /*&& k < 100*/) {
				getline(data, info[0], ',');
				getline(data, info[1], ',');
				getline(data, info[2], '\r');
				if(x > 0) {
					k++;
					Node *temp = LinkedList.createNode(info[0], stoi(info[1]), stoi(info[2]));
					//cout << temp->name << ' ' << temp->priority << ' ' << temp->treatment << endl;
					LinkedList.enqueue(temp);
				}
				x = 1;
			}
		}
		//LinkedList.printQueue();
		cout << "Rank" << '\t' <<  "Patient, Priority, treatment\n";
		//cout << x << ":\t";
		while (k) {
			cout << x << ":\t";
			if (!LinkedList.dequeue()) break;
			x++;
			k--;
		}
		i++;
	//}
	cout << endl << "Time: " << (clock() - start) / (double)(CLOCKS_PER_SEC) << " seconds\n" << endl;
	return 0;
}