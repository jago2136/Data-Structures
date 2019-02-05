#include <iostream>
#include <string>
using namespace std;

/* 
	Delete a node from an exisiting linked list
	Delete a specified node:
		1) Find the node preceeding the specified node
		2) Link previous to with the new next node
		3) Deallocate memory for deleted nod3

		If your specified node happens to be the head node...
		1) Update the head to point to head->next
		2) Free the specified node 

	--------------------------------------------------------------------------------------------

	Given a structure

		struct Time {
			int hour;
			int minute;
			string meridien; // am or pm
		};
		Time t;
		t.hour = 13;   // this is an issue, you compromised your data integrity
		               //you could include an if statement that returns an our if greater than 12

		What if we had a way to embed data violation within the struct itself...

		Classes and Objects:

		Class is a complex type, just like struct.
		The instance of a class is an object.
		If you defined a class with only public members, it would be a struct, simple as that.

		Features: 
			1) A complex type, has members just like a struct
			2) Can define member functions, called methods
				- A method is a function that is part of a class
				- It controls the access to member variables
			3) Members can either be private or public
				- Public means they can be accessed outside the class
				- Private means they can't, only accessed by class methods
				- Cannot access pirvate members within main
			4) Constructors are public methods used to initialize objects. They get the same name as the class.

		Create a class called Time12 for storing time in the 12hr format.
			- Will have three private members as designed above.
			- Constructor takes 3 arguments.
			- Public method to display the time.


	*/


class Time12 {
private:
	int hour;
	int minute;
	string mer;

public:
	// constructro definition
	Time12 (int h, int m, string me) {
		hour = h;
		minute = m;
		mer = me;
	}

	void printDate() {
		cout << hour << ":" << minute << mer << endl;
	}

	void setHour (int h) {
		if (h >= 0 && h <= 12) {
			hour = h; 
		}
		else {
			cout << "bad choice" << endl;
		}
	}
};

int main() {
	Time12 t= Time12(10, 15, "AM");
	cout << Time12.hour << endl;
	t.printDate;
	// t.hour = 12   this wont work if the variables are private!
	t.printFate();
	t.setHour(99);



	return 0;
}