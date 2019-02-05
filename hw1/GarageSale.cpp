#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;



struct Item {
	string type;   // what's for sale
	int price;     // price, initially a string, have to convert to an int
	bool forsale;  // whether true or not, when looking for a match make sure they're opposite
	}; 



int parse(Item array[], int size, string filename) 
{
	int count = 0;
	ifstream myfile;                          
	myfile.open(filename);  
	string line;     
	int itemsInArray = 0;   

	// open the file and rename, set the current number of items in left-over array to 0

	if(myfile.is_open()) 
	{
		while(getline(myfile, line)) {
			string splitline[3];
			istringstream ss(line);
			string token;
			count = 0;

			// this while loop runs through every line in the array, storing each line in "line"

			while(getline(ss, token, ',')) {
   				splitline[count] = token;
   				count++;
			}

			// each time the main while loop encounters the next line, it will split up the line into the three
			// parts so they can all be handled differently, all currently stored as strings within splitline[]

			splitline[1].erase(0,1);

			// this method produces a space before the price and forsale value, in order to read easier we erase that space

			int pricetemp = stoi(splitline[2]);

			// the third element is a string that needs to be compared as an integer, so we use stoi to convert it

			bool forsaletemp;
			bool isFound = false;
			int position;

			// create a temp forsale varible to set whether true or not, also create a bool for whether or not a match is found

			if (splitline[1] == "for sale")
			{
				forsaletemp = true;
				 }
			else
			 {
				forsaletemp = false;

				// convert the forsale strings to actual bools for comparison

			}
			for (int i = 0; i < itemsInArray; i++) {
					if ((array[i].type == splitline[0]) && (!forsaletemp == array[i].forsale) && (array[i].price <= pricetemp) && (array[i].forsale == true)) {
						isFound = true; 
						position = i;
						break;
					}
					if ((array[i].type == splitline[0]) && (!forsaletemp == array[i].forsale) && (array[i].price >= pricetemp) && (array[i].forsale == false)) {
						isFound = true; 
						position = i;
						break;
				}
			}

			// this for loop checks for both possibilities of a match, and if a match is found, we change our previously declared bool to true
			// note how we compare for the same types, opposite forsale bools, and an agreeable price
			// this conditional may not be easy on the eyes but it gets the job done

			if (isFound) {
				if (array[position].forsale == true){
					cout << array[position].type << " " << array[position].price << endl;
				}
				else {
					cout << splitline[0] << " " << pricetemp << endl;
				}
				for (int j = position; j <= itemsInArray - 2; j++) {
					array[j] = array[j+1];
				}
				itemsInArray--;

			}

			// if it is found, add it to the sold array and shift the original one accordingly (using the shift function provided)

			else {

			array[itemsInArray].type = splitline[0];
			array[itemsInArray].price = pricetemp;
			array[itemsInArray].forsale = forsaletemp;
			itemsInArray++;
			}

			// if no match is found, keep it in the array

		}
		cout << "#" << endl;
		for (int i = 0; i < itemsInArray; i++) {
			if (array[i].forsale == 1)
				cout << array[i].type << ", " << "for sale" << ", " << array[i].price << endl;
			else
				cout << array[i].type << ", " << "wanted" << ", " << array[i].price << endl; 
		cout << "#" << endl;
		return 0;

		// format the output as specifiec in the writeup

	}
}

	else {
		return -1;
	}

}


int main (int argc, char * argv[]) {

	//use command line arguments to determine the file that is being searched

	Item sale[100];

	// assume a size of 100 products

	int count = parse(sale, 100, argv[1]);
	for (int i = 0; i < count; i++) {
		if (sale[i].forsale) {
			cout << sale[i].type << ", for sale, " << sale[i].price << endl;
		}
		else {
			cout << sale[i].type << ", wanted, " << sale[i].price << endl;
		}
	}

	// print leftovers
	
	return 0;
}