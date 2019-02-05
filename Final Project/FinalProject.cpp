#include <iostream>
#include <string>
#include <fstream> 
#include <sstream>
#include <ctime>
#include "priorityQueueH.cpp"
#include "priorityQueue.cpp"
#include "priorityQueueLL.cpp"
using namespace std;

void printMenu() {
	cout << "======== Menu ========\n";
	cout << "1. Print Linked List Output and Performance\n";
	cout << "2. Print STL Output and Performance\n";
	cout << "3. Print minHeap Output and Performance\n";
	cout << "4. Quit\n";
	return;
}

int main (int argc, char * argv[]) {
	int userInput = 0;
	int x = 1;
	while(x) {
		printMenu();
		cin >> userInput;
		if (userInput == 1) {
			cout << "\nLinked List output and performance:\n";
			mainLL(argv[1]);
		}
		if (userInput == 2) {
			cout << "\nSTL output and performance:\n";
			mainSTL(argv[1]);
		}
		if (userInput == 3) {
			cout << "\nHeap List output and performance:\n";
			mainHeap(argv[1]);
		}
		if (userInput == 4) {
			cout << "Goodbye!\n";
			return 0;
		}

	}
	return 0; 
}