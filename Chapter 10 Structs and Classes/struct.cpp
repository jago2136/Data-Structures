//Structs and Classes
#include <iostream>
using namespace std;

// classes are data types whose variables are objects 

int main() {
	// structs allow you to group values 
	struct CDAccount {
		double balance;  // these are called members
		double interest_rate;
		int term; // months until maturity 
	}; // note the semi colon

	// from here you can use CDAccount like any other variable 
	// for instance 
	
	CDAccount my_account, your_account;


	return 0;
}