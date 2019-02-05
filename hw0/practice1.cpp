// Chapter 2, C++ basics

#include <iostream>
#include <string> // needed if you want to use strings
using namespace std;

int main() {
	cout<<"Hello World!\n";
	// test
	int number = 7, number2 = 8;
	cout << number << " " << number2 << "\n";
	// input output
	double cost;
	cout<< "The price should be $1.25.\nPlease enter the price: $";
	cin>>cost;
	cout<< "Good! " << cost << endl;
    // char practice
    char letter1, letter2, letter3 = ' ';
    cout<< "Please enter two letters\n";
    cin>> letter1 >> letter2;
    cout << "Thanks!\n" << letter1 << letter3 << letter2 << "\n";
    //
    string word1, word2, word3;
    word1 = "Hello";
    word2 = "World";
    word3 = word1 + " " + word2;
    cout << word3 << "\n";
    // a do-while loop, it makes sure it execites at least once, so if the boolean expression isn't true,
    // at least it does it once!
    int x = 3;
    do {
    	cout << "Here\n";
    	x-=1;
    } while (x > 0);
    x = -1;
    do {
    	cout << "Here again\n";
    	x-=1;
    } while (x > 0);

	return 0;

}
