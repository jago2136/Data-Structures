#include <iostream>
#include <string>
#include <fstream> 
using namespace std;
 
 /*

	Worst case for an array of size 20? O(20)
	int main (int argc, char * argv[]) 
	Operator used to dereference a pointer is *
	&a gives the memory address of a
	Varibles created Dynamically do not automatically go out of scope
	Delete must be used in C++. not free
	A node can be implemented using a class or a struct
	We use pointers to access each node


 */



// A successful swap function

void swap(int*a, int*b) {
    int x;
    x = *a;
    *a = *b;
    *b = x;
}

// All can be used to dynamically declare new memory

i. int *p = new int(100); 
ii. int *p; p = new int; *p = 100;
iii. int *p = NULL; p = new int; *p=100;

// Shift an Array

void shiftright (int myarray[], int size);

int main (void)
{
int myarray []= {1, 3, 5, 7, 9};
shiftright( myarray, 5);
for ( int i=0; i<5; i++) 
{
	cout << myarray[i] << ' ';
}
return(0);

}

void shiftright (int myarray[], int size)
{
  
int temp;
int temp1;

for (int i=0; i<(size -1); i++)
{
	temp = 	myarray[size-1];
	myarray[size-1] = myarray[i];
	myarray[i] = temp;
}


}

// Copy all but one element

int *CopyArray(int array[], int length, int value) {
int count = 0;
for (int i = 0; i < length; i++) {
    if (array[i] != value) count++;
}
    int * newArray = new int(count);
    int j = 0;
    for (int i = 0; i < length; i++) {
        if (array[i] != value) {
            newArray[j] = array[i];
            j++;
        }
    }
    return newArray;
}

void Queue::enqueue(node *newNode) {
    if (!head) {
        head = newNode;
        newNode->next = NULL;
        return;
    }
    tail->next = newNode;
    newNode->next = NULL;
    tail = newNode;
    return;
}


int main () {
	return 0;
}