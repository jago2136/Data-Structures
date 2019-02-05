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

int parse(Item array[], int size, string filename) {
	int count = 0;
	ifstream myfile;                          
	myfile.open(filename);  
	string line;     
	int itemsInArray = 0;                
	if(myfile.is_open()) 
	{
		while(getline(myfile, line)) {
			string splitline[3];
			// cout << line << endl;
			istringstream ss(line);
			string token;
			count = 0;

			while(getline(ss, token, ',')) {
   				// cout << token << '\n';
   				splitline[count] = token;
   				count++;
			}
			splitline[1].erase(0,1);
			// cout << splitline[1] << endl;
			int pricetemp = stoi(splitline[2]);
			bool forsaletemp;
			bool isFound = false;
			int position;
			if (splitline[1] == "for sale")
			{
				forsaletemp = true;
				 }
			else
			 {
				forsaletemp = false;
			}
			// cout << itemsInArray << endl;
			for (int i = 0; i < itemsInArray; i++) {
					if ((array[i].type == splitline[0]) && (!forsaletemp == array[i].forsale) && (array[i].price <= pricetemp) && (array[i].forsale == true)) {
						isFound = true; 
						position = i;
						// cout << array[i].type << splitline[0] << endl;
						break;
					}
					if ((array[i].type == splitline[0]) && (!forsaletemp == array[i].forsale) && (array[i].price >= pricetemp) && (array[i].forsale == false)) {
						isFound = true; 
						position = i;
						break;
				}
			}
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
			else {

			array[itemsInArray].type = splitline[0];
			array[itemsInArray].price = pricetemp;
			array[itemsInArray].forsale = forsaletemp;
			// cout << array[itemsInArray].type << endl;
			itemsInArray++;
			}

		}
		cout << "#" << endl;
		for (int i = 0; i < itemsInArray; i++) {
			if (array[i].forsale == 1)
				cout << array[i].type << ", " << "for sale" << ", " << array[i].price << endl;
			else
				cout << array[i].type << ", " << "wanted" << ", " << array[i].price << endl; // ", " << str(array[i].forsale) << ", " << str(array[i].price) << endl;
		}
		cout << "#" << endl;
		return 0;





	/*
		string newtype, forSale, newprice;        // temp variables 
		int price;
		getline(myfile, newtype, ',');
		array[0].type = newtype;                  // set type equal to what is for sale
		getline(myfile, forSale, ',');
		forSale = forSale.erase(0,1);             //.erase(int first_position, int length), becuase of the space
		if (forSale == "for sale") {
			array[0].forsale = true;              // set a Boolean value for whether true or not
		}
		else {
			array[0].forsale = false;             // set a Boolean value for whether true or not
		}
		getline(myfile, newprice, '\n');
		newprice = newprice.erase(0,1);          
		price = stoi(newprice);                   //stoi converts the string to an int, only strings can be read from a text file
		array[0].price = price;                   
		count++;     
		bool isFound;                             // know number of elements in the array
		bool forsale1;
		while (getline(myfile, newtype, ',')) {
			getline(myfile, forSale, ',');
			getline(myfile, newprice, '\n');
			price = stoi(newprice);
			if (forSale == "for sale") {
				forsale1 = true; 
			}
			else { forsale1 = false;
			}
			int position;

			for (int i = 0; i < count; i++) {
					if ((array[i].type == newtype) && (!forsale1 == array[i].forsale) && (array[i].price <= price) && (array[i].forsale == true)) {
						isFound = true; 
						position = i;
						break;
					}
					if ((array[i].type == newtype) && (!forsale1 == array[i].forsale) && (array[i].price >= price) && (array[i].forsale == false)) {
						isFound = true; 
						position = i;
						break;
				}
			}
			if (isFound == true) {
				if (array[position].forsale == true){
					cout << array[position].type << " " << array[position].price << endl;
				}
				else {
					cout << newtype << " " << price << endl;
				}
				for (int j = position; j <= count - 2; j++) {
					array[j] = array[j+1];
				}
				count--;
			}
			else {
				array[count].type = newtype;
				array[count].forsale = forsale1;
				array[count].price = price;
				count++;
			}


		}
		return count;*/
	}
	else {
		return -1;
	}


}
int main (int argc, char * argv[]) {


	Item sale[100];
	int count = parse(sale, 100, argv[1]);
	// cout << "#" << endl;
	for (int i = 0; i < count; i++) {
		if (sale[i].forsale) {
			cout << sale[i].type << ", for sale, " << sale[i].price << endl;
		}
		else {
			cout << sale[i].type << ", wanted, " << sale[i].price << endl;
		}
	}
	// cout << "#" << endl;
	return 0;
}
