#include <iostream>
#include <string>
#include <fstream>
using namespace std;


struct city {
	string cityName;
	string message;
	city * next;
	city(){};
	city(string initName, city *initNext, string initMessage) {
		cityName = initName;
		next = initNext;
		message = initMessage;
	}

};

// Print the initial menu, with options for selection.

void printMenu() {
	cout << "======Main Menu======" << endl;
	cout << "1. Build Network" << endl;
	cout << "2. Print Network Path" << endl;
	cout << "3. Transmit Message Coast-To-Coast" << endl;
	cout << "4. Add City" << endl;
	cout << "5. Quit" << endl;
	return;
}

// Print and exit program

void quitStatement() {
	cout << "Goodbye!" << endl;
	return;
}

// Print current path of the program

void printPath (city * head) {
	cout << "===CURRENT PATH===" << endl;
	city * tmp = head;
	while (tmp->next) {
		cout << tmp->cityName << " -> ";
		tmp = tmp->next;
	}
	cout << tmp->cityName << " ->  ";
	tmp = tmp->next;
	cout << "NULL" << endl;
	cout <<	"==================" <<	endl;	
}

city * buildNetwork() {
	string cities[10] = {"Phoenix", "Denver", "Dallas", "St. Louis", "Chicago", "Atlanta", "Washington, D.C.", "New York", "Boston"};
	city * head = new city;
	head->cityName = "Los Angeles";
	head->next = nullptr;
	city * tail = head;
	for (int i = 0; i < 9; i++) {
		city * curr = new city;
		curr->cityName = cities[i];
		curr->message = "";
		tail->next = curr;
		tail = curr;
		tail->next = nullptr;
	}
	return head;
}

// Transmits a message to all of the cities

void transmitMsg (city * head) {
	if (!head) {
		cout << "Emptylist" << endl;
		return;
	}
	ifstream myfile;
	myfile.open("messageIn.txt");
	string word;
	if (myfile.is_open()) {
		while (getline(myfile, word, ' ')) {
			city * tmp = head;
			if (word.substr(0,1) == "\n") {
				word.erase(0,1);
			}
			if (word.substr(word.length()-1,1) == "\n") {
				word.erase(word.length()-1,1);
			}
			while (tmp->next) {
				tmp->message = word;
				cout << tmp->cityName << " received " << tmp->message << endl;
				tmp = tmp->next;
			}
			tmp->message = word;
			cout << tmp->cityName << " received " << tmp->message << endl;
			tmp = tmp->next;
		}
	}
}


city * addCity (city * head, city * previous, string cityName) {
	if ((previous == NULL) || (head == NULL)) {
		return head;
	}
	city * newNode = new city;
	newNode->cityName = cityName;
	newNode->next = previous->next;
	previous->next = newNode;
	return head;
}


int main() {
	int x = 1;
	int userChoice;
	city * head;
	while (x) {
		printMenu();
		cin >> userChoice;
		if (userChoice == 1) {
			head = buildNetwork();
		}
		else if (userChoice == 2) {
			printPath(head);
		}
		else if (userChoice == 3) {
			transmitMsg(head);
		}
		else if (userChoice == 4) {
			string newCity, previousCity;
			cout << "Enter a City name:" << endl;
			cin >> newCity;
			cout << "Enter a previous City name:" << endl;
			cin >> previousCity;
			city * tmp = head;
			while (tmp->next) {
				if (tmp->cityName == previousCity) {
					break;
				} 
				tmp = tmp->next;
			}	
			head = addCity(head, tmp, newCity);
		}
		else if (userChoice == 5) {
			quitStatement();
			return 0;
		}
	}
	return 0;
}