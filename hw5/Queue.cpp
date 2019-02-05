#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Queue.h"
using namespace std;


// Check if empty by seeing if count is zero.

bool Queue::queueIsEmpty() {
	if (!queueCount) {
		cout << "Queue is Empty\n";
		return true;
	}
	return false;
}


// Test for full queue by observing queue count.

bool Queue::queueIsFull() {
	if (queueCount == queueSize) {
		cout << "Queue is full\n";
		return true;
	}
	return false;
}



// Insert one string at the tail of the queue, checking if its full first.
// Increment tail and queue count.

void Queue::enqueue(string word) {
	if (queueIsFull()) return;
	arrayQueue[queueTail] = word;
	if (queueTail == queueSize-1) {
		queueTail = 0;
	}
	else queueTail++;
	queueCount++;
	cout << "E: " << word << endl;
	cout << "H: " << queueHead << endl;
	cout << "T: " << queueTail << endl;
	return;
}



// Dequeue a word from the head of the list, checking if empty first.
// Increment head and decrement queue count.

void Queue::dequeue() {
	if (queueIsEmpty()) return;
	string tmp = arrayQueue[queueHead];
	if (queueHead == queueSize-1) {
		queueHead = 0;
	}
	else queueHead++;
	queueCount--;
	cout << "H: " << queueHead << endl;
	cout << "T: " << queueTail << endl;
	cout << "word: " << tmp << endl;
}



// Print the queue from head to tail, checking if empty first.

void Queue::printQueue() {
	if (queueIsEmpty()) return;
	int x = queueHead;
	while (x != queueTail-1) {
		cout << x << ": " << arrayQueue[x] << endl;
		if (x == queueSize-1) x = 0;
		else x++;
		if (x == queueCount) break;
	}
	cout << x << ": " << arrayQueue[x] << endl;;
	return;
}


// Enqeue an entire sentence, printing that the queue is full for every word over the limit.

void Queue::enqueueSentence(string given) {
	string curr;
	//cout << given;
	stringstream ss(given);
	while (ss >> curr) {
		//cout << "enqueueSentence:  " << curr << endl;
		enqueue(curr);
	}
	return;
}


// Constructor

Queue::Queue(int qs) {
 queueSize = qs;
 arrayQueue = new string[queueSize];
 queueHead = 0;
 queueTail = 0;
 queueCount = 0;
}

// Destructor

Queue::~Queue() {
 delete [] arrayQueue;
 arrayQueue = nullptr;
}


// Menu printed after every loop.

void printMenu() {
	cout << "======Main Menu=====\n";
	cout << "1. Enqueue word\n";
	cout << "2. Dequeue word\n";
	cout << "3. Print queue\n";
	cout << "4. Enqueue sentence\n";
	cout << "5. Quit\n";
	return;
}



int main () {
	printMenu();
	int x = 1;
	Queue A(10);
	int choice;
	cin >> choice;
	while (x) {
		cin.ignore();
		if (choice == 1) {
			string userWord;
			cout << "word: ";
			cin >> userWord;
			A.enqueue(userWord);
		}
		else if (choice == 2) {
			A.dequeue();
		}
		else if (choice == 3) {
			A.printQueue();
		}
		else if (choice == 4) {
			cout << "sentence: ";
			string Sentence;
			getline(cin, Sentence, '\n');
			A.enqueueSentence(Sentence);
		}
		else if (choice == 5) {
			cout << "Goodbye!\n";
			x = 0;
			A.~Queue();
			return 0;
		}
		printMenu();
		cin >> choice;
	}
	return 0;
}

