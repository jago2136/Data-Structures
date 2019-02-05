#include <iostream>
#include <string>
#include <fstream>
#include "Assignment4.h"
using namespace std;

// Delete the entire network

void CommunicationNetwork::deleteNetwork() {
	City * tmp = head->next;
	while(tmp->next) {
		cout << "deleting " << tmp->previous->cityName << endl;
		delete tmp->previous;
		tmp = tmp->next;
	}
	cout << "deleting " << tmp->previous->cityName << "\ndeleting " << tmp->cityName << endl;
	delete tmp;
	head = nullptr;
	tail = nullptr;
}

// Add a city to the network 

void CommunicationNetwork::addCity(string newCityName, string previousCityName) {
    if (previousCityName == "First") {
        City * newCity = new City;
        newCity->message = "";
        newCity->cityName = newCityName;
        newCity->next = head;
        head->previous = newCity;
        head = newCity;
    }
	if (!head) {
		head = new City;
		head->message = "";
		head->cityName = newCityName;
		return;
	}
	City * temp = head;
	City * newCity = new City;
	newCity->cityName = newCityName;
	newCity->message = "";
	while(temp->next) {
		if (temp->cityName == previousCityName) {
			newCity->previous = temp;
			newCity->next = temp->next;
			temp->next->previous = newCity;
			temp->next = newCity;
			return;
		}
		temp = temp->next;
	}
	if ((previousCityName == "")||(previousCityName == temp->cityName)) {
	    newCity->previous = temp;
		newCity->next = nullptr;
		temp->next = newCity;
		tail = temp;
		return;
	}
	return;
}

// Transmits a message to all of the cities

void CommunicationNetwork::transmitMsg (char * filename) {
	if (!head) {
		cout << "Emptylist" << endl;
		return;
	}
	ifstream myfile;
	myfile.open(filename);
	string word;
	if (myfile.is_open()) {
		while (getline(myfile, word, ' ')) {
			City * tmp = head;
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
			tmp = tail;
			tmp = tmp->previous;
			while(tmp->previous) {
				cout << tmp->cityName << " received " << tmp->message << endl;
				tmp = tmp->previous;
			}
			cout << tmp->cityName << " received " << tmp->message << endl;

		}
	}
}

// Delete a specified city from the network

void CommunicationNetwork::deleteCity(string removeCity) {
	int x = 0;
	if (head->cityName == removeCity) {
		head = head->next;
		head->previous = nullptr;
		x = 1;
	}
	City * tmp = head;
	while (tmp->next) {
		if (tmp->cityName == removeCity) {
			tmp->previous->next = tmp->next;
            tmp->next->previous = tmp->previous;
			tmp = tmp->next;
			x = 1;
		}
		else tmp = tmp->next;
	}
	if (tail->cityName == removeCity) {
		tail = tail->previous;
		tail->next == nullptr;
		x = 1;
	}
	if (x == 0) cout << removeCity << " not found\n";
	return;
}

// Print current network

void CommunicationNetwork::printNetwork() {
	if (!head) {
		cout << "Empty Network\n";
		return;
	}
	cout << "===CURRENT PATH===" << endl;
	City * tmp = head;
	cout << "NULL <- ";
	while (tmp->next) {
		cout << tmp->cityName << " <-> ";
		tmp = tmp->next;
	}
	cout << tmp->cityName << " -> ";
	tmp = tmp->next;
	cout << "NULL" << endl;
	cout <<	"==================" <<	endl;	
	return;
}


// Build the initial network provided in the assignment

void CommunicationNetwork::buildNetwork() {
	head = new City;
	head->cityName = "Los Angeles";
	head->message = "";
	head->next = nullptr;
	head->previous = nullptr;
	string cities[10] = {"Phoenix", "Denver", "Dallas", "St. Louis", "Chicago", "Atlanta", "Washington, D.C.", "New York", "Boston"};
	City * temp = head;
	for (int i = 0; i < 9; i++) {
		/*City * curr(cities[i], nullptr, temp, "");
		temp->next = curr;
		temp = curr;*/
		City * curr = new City;
		curr->cityName = cities[i];
		curr->message = "";
		curr->next = nullptr;
		curr->previous = temp;
		temp->next = curr;
		temp = curr;
	}
	tail = temp;
	return;
}


// Print the initial menu, with options for selection.

void printMenu() {
	cout << "======Main Menu======\n";
	cout << "1. Build Network\n";
	cout << "2. Print Network Path\n";
	cout << "3. Transmit Message Coast-To-Coast-To-Coast\n";
	cout << "4. Add City\n";
	cout << "5. Delete City\n";
	cout << "6. Clear Network\n";
	cout << "7. Quit\n";
	return;
}

// Default constructor

CommunicationNetwork::CommunicationNetwork() {
	//cout << "Constructor Called\n";
	head = nullptr;
	tail = nullptr;
}

// Default destructor

CommunicationNetwork::~CommunicationNetwork() {
	//cout << "Destructor called\n";
	head = nullptr;
	tail = nullptr;
}

int main (int argc, char* argv[]) {
	CommunicationNetwork A;
	//A.buildNetwork();
	//printMenu();
	//return 0;
	int x = 1;
	int userChoice;
	while (x) {
		printMenu();
		cin >> userChoice;
		if (userChoice == 1) {
			A.buildNetwork();
			A.printNetwork();
		} 
		if (userChoice == 2) {
			A.printNetwork();
		}
		if (userChoice == 3) {
			A.transmitMsg(argv[1]);
		}
		if (userChoice == 4) {
			string newCityName, previousCityName;
			cout << "Enter a city name:\n";
			cin >> newCityName;
			cout << "Enter a previous city name:\n";
			cin >> previousCityName;
			A.addCity(newCityName,previousCityName);
		}
		if (userChoice == 5) {
			string newCityName;
			cout << "Enter a city name:\n";
			cin >> newCityName;
			A.deleteCity(newCityName);

		}
		if (userChoice == 6) {
			A.deleteNetwork();
		}
		if (userChoice == 7) {
			cout << "Goodbye!\n";
			x = 0;
		}
	}
	return 0;
}


