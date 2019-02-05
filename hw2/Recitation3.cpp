#include <iostream>
#include <string>
#include <fstream>
using namespace std;


void resizeArray(int* &oldArray, int *capacity)
{
	int newCapacity = *capacity * 2;
	int *newArray = new int[2* (*capacity)];
	for (int i = 0; i < *capacity; i++) {
		newArray[i] = oldArray[i];
	}
	delete [] oldArray;
	oldArray = newArray;
	*capacity = newCapacity;


}
int main (int argc, char *argv[]) {
	if (argc != 2) return -1;
	int capacity = 10, numOfElement = 0, curr2;
	string filename = argv[1], curr1;
	ifstream myfile;
	myfile.open(filename);
	int *array = new int[capacity];
	if (myfile.is_open()) {
		while (getline(myfile, curr1)) {
			if (numOfElement == capacity) {
				resizeArray(array, &capacity);
			}
			curr2 = stoi(curr1);
			array[numOfElement] = curr2;
			numOfElement++;
		}
	}
	for (int i = 0; i < numOfElement; i++) {
		cout << array[i] << endl;
	}
	return 0;
}
