#include <iostream>
#include <string>
using namespace std;

int main() {

	// Note that if you declare variables within an if-else statement, or loop, the variables are local and will
	// delete after this 'block', as its called, is executed
	
	cout << "Please enter fuel level, 0 - 1" << endl;
	double fuel_level;
	cin >> fuel_level;
	if (fuel_level < .75) {
		if (fuel_level < .25) {
			cout << "Fill up soon!" << endl;
		}
		else {
			"Doing okay, check back soon\n";
		}
	}
	else { 
		cout << "You're just getting started\n";
	}

	// the break statement tells is when to stop looking, make sure to include one after every case
	// the compiler wont warn you
	// the default says that the program ends there if no break is encountered
	// switches are typically used when wanting to display a number of possible outcomes, and having the user pick one
	// ie. Would you like to see document 1, 2, 3, or 4?

	char grade;
	cout << "Please enter your letter grade.\n";
	cin >> grade;
	switch (grade) {
		case 'A':
			cout << "You're doing well!\n";
			break;
		case 'B':
			cout << "Doing okay\n";
			break;
		case 'C':
		case 'D':
			cout << "Barely passing\n";
			break;
		case 'F':
			cout << "You suck\n";
			break;
		default: 
			cout << "Please enter a valid grade\n";

	}

	return 0;
}