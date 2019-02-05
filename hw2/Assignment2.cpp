#include <iostream>
#include <string>
#include <fstream> 
using namespace std;


// Struct containing the word, along with a count of the currentObjectArrayLength of times it has occurred.

struct wordItem {
	string word;             // Store the word.
	int count;               // Store the number of occurences for that word.
};



// Read stop word list into file and store into array.

void getStopWords(char *ignoreWordFileName, string ignoreWords[]) {

	// Open the file, write to the array that is passed, incrementing by one for each word read.

	string word;
	ifstream myfile;                          
	myfile.open(ignoreWordFileName);  
	int i = 0;
	if (myfile.is_open()) {
		while (getline(myfile, word, '\n')) {
			ignoreWords[i] = word;
			i++;
		}
	}
	// Test loop.
	/*for (int j = 0; j < 50; j++) {
			cout << ignoreWords[j] << '.';
		}*/
	return;
}



// See if a word is a stop word. Compare to all 50 elements in the stop array.

bool isStopWord (string word, string ignoreWords[]) {
	for (int i = 0; i < 50; i++) {
		if (ignoreWords[i] == word) {
			return false;
		}
	}
	return true;
}



// compute total currentObjectArrayLength of words saved in the words array
int getTotalNonStopWords (wordItem list[], int length) {
	int total = 0;
	for (int i = 0; i < length; i++) {
		total += list[i].count;
	}
	return total;
}

// sort an array of word items, increasing, by their count fields
void arraySort (wordItem list[], int length) {
	int curr = 0, pre = 1000, index;
	wordItem sortArray[length];
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			if ((list[j].count > curr) && (list[j].count < pre)) {
				index = j;
				curr = list[j].count;
			}
		}
		sortArray[i].count = list[index].count;
		sortArray[i].word = list[index].word;
		pre = curr;
		curr = 0;
	}
	for (int i = 0; i < length; i++) {
		list[i].count = sortArray[i].count;
		list[i].word = sortArray[i].word;
	}
	return;
}



// Print top N high frequency words.

void printTopN (wordItem wordItemList[], int length) {
	for (int i = 0; i < length; i++) {
		cout << wordItemList[i].count << " - " << wordItemList[i].word << endl;
	}
	return;
}




int main (int argc, char *argv[]) {
	string stopWords[50];
	getStopWords(argv[3], stopWords);
	ifstream myfile;                          
	myfile.open(argv[2]);  
	// These words need to be skipped if encountered, including a newline char and empty strings.
	string word, pass1 = "\n", pass2 = "";
	int count = 0; 
	int i = 0;
	// Initiate an array of string to store the entire file in (this file will exclude stop words).
	string words[65000];
	if (myfile.is_open()) {
		while (getline(myfile, word, ' ')) {
			// Fist check for pass words, skip if they are.
			if ((word != pass1) && (word != pass2)) {
				// The file given had new line character attached to the words, trime those off (front then back).
				if (word.substr(0,1) == "\n") {
					word.erase(0,1);
				}
				if (word.substr(word.length()-1,1) == "\n") {
					word.erase(word.length()-1,1);
				}
				// If it isnt a stop word, add it to the array!
				if (isStopWord(word, stopWords)){
					words[i] = word;
					count++;
					i++;
				}
			}
		}
		// Test loop.
		for (int j = 0; j < 130; j++) {
			//cout << words[j] << '.';
		}

	}
	else {
		return -1;
	}


	// The original capacity should be 100, doubling each time it fills.
	int capacity = 100, doubled = 0;
	// Allocate memory for array to store structs.
	wordItem *objarray = new wordItem[capacity];
	// Current amount of objects in the array
	int currentObjectArrayLength = 0;
	// Count is total number of words in the original array (one w/out common words).
	for (int j = 0; j < count; j++) {
		// Test loop.
		// cout << j << endl;
		// Reallocate memory, doubling in size and erasing old array.
		//if (capacity-1 == j) {
			//for (int j = 1; j < capacity; j++) {
				if (currentObjectArrayLength == capacity) {
					// Record it doubled. 
					doubled += 1;
					capacity *= 2;
					wordItem *newarray = new wordItem[capacity];
					for (i = 0; i < (capacity/2); i++) 
					{
						newarray[i] = objarray[i];
					}
					delete [] objarray;
					objarray = newarray;
				//}
			//}
			// Test loop
			// cout << "double" << endl;
		}
		// If the wprd is not new, it will match, and we need to store this index. 
		int indexMatch;
		bool isNewWords = true;
		// Check through the current object array for whether the current word already exists.
		for (i = 0; i < currentObjectArrayLength; i++) 
		{
			if (objarray[i].word == words[j]) {
				// Test 
				//cout << "new word" << endl;
				// If it is, save the index and set isNewWord to false
				indexMatch = i;	
				isNewWords = false;
				break;
			}
		}	
		// If it is a new word...
		if (isNewWords) 
		{
			// Test
			//cout << "adding word" << endl;
			/*wordItem w = new wordItem;
			w.word = words[j];
			w.count = 1;
			objarray[currentObjectArrayLength] = w; */
			objarray[currentObjectArrayLength].word = words[j];
			objarray[currentObjectArrayLength].count = 1;
			currentObjectArrayLength++;
			// Test
			//cout << objarray[currentObjectArrayLength].word << ' ' << objarray[currentObjectArrayLength].count << endl;
	
		} 
		else {
			// Test 
			//cout << "increment word" << endl;
			objarray[indexMatch].count += 1;
			// Test
			//cout << objarray[indexMatch].word << ' ' << objarray[indexMatch].count << endl;
	
		} 

	}
	// Test loop
	//for (int j = 0; j < 100; j++) {
	//	cout << objarray[j].word << ' ' << objarray[j].count << endl;
	//}

	//cout << count << endl;
	int userN = stoi(argv[1]);
	arraySort(objarray, currentObjectArrayLength);
	for (int i = 0; i < userN; i++) {
		cout << objarray[i].count << " - " << objarray[i].word << endl;
	}
	cout << "#" << endl;
	cout << "Array doubled: " << doubled << endl;
	cout << "#" << endl;
	cout << "Unique non-common words: " << currentObjectArrayLength << endl << "#" << endl;
	int unique = getTotalNonStopWords (objarray, currentObjectArrayLength);
	cout << "Total non-common words: " << count << endl;
	return 0;
}