// 1/24/18
// Number systems and Pointers
#include <iostream>
#include <string>
using namespace std;


void passByVal(int a) {
	/* Pass-by-Value, when called its a copy of the arguments passed */
	a++;
	cout << a << endl;
}

void passByRef(int &a){
	// expects an address
	a++;

}

void passByPoint(int *a) {
	// an address is passed, however is called with a pointer types

}

void passByArray(int array[], int n) {
	// like with pass by reference, the address is being passed
	// the whole array is not passed, but rather a pointer to the first element

}



int main() {
	int jenny = 5;
	int *jennyPtr; // how we declare a pointer, contains a memory address

	jennyPtr = &jenny; // address pointer

	cout << "jenny = " << jenny << endl;
	cout << "&jenny = " << &jenny << endl;
	cout << "jennyPtr = " << jennyPtr << endl;
	cout << "*jennyPtr = " << *jennyPtr << endl;

	*jennyPtr = *jennyPtr + 1;
	cout << *jennyPtr << endl;

// 1/26/2018

	int x=3;
	cout << x << endl;
	passByVal(x);
	// returns unchanged
	cout << x << endl;
	passByRef(x);
	cout << x << endl;
	int *y = &x;
	passByPoint(y);
	int array[3];
	passByArray(array, 3);


	return 0;
}

