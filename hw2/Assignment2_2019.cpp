//Name: William "Clay" Fricke
//Assignment: Assignment 1
//Due: Friday, Jan. 25, 2019
//Section: CSCI 2270-302
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

struct wordItem {
  string word;
  int count;
};

void getStopWords(const char *ignoreWordFileName, string ignoreWords[]) {
  ifstream myFile;
  myFile.open(ignoreWordFileName);
  string line;
  int i = 0;
  if(myFile.is_open()) {
    while(getline(myFile, line)) {
      ignoreWords[i] = line;
      i++;
    }
  }
}


bool isStopWord(string word, string ignoreWords[]) {
  for(int i = 0; i< 50; i++) {
    if(ignoreWords[i] == word) {
      return true;
    }
  }
  return false;
}

int getTotalNumberNonStopWords(wordItem uniqueWords[], int length) {
    int sum = 0;
    for(int i = 0; i< length; i++) {
        sum = uniqueWords[i].count + sum;

    }
    return sum;
}

void arraySort(wordItem uniqueWords[], int length) {
  wordItem temp;
  for(int i = 0; i< length; i++) {
    for(int j = 0; j< length-1; j++) {
      if(uniqueWords[j].count < uniqueWords[j+1].count) {
        temp = uniqueWords[j];
        uniqueWords[j] = uniqueWords[j+1];
        uniqueWords[j+1] = temp;
      }
    }
  }
}

void printTopN(wordItem uniqueWords[], int topN, int totalNumWords) {
    float percent;
    float num;
    float den;
    for(int i = 0; i< topN; i++) {
        num = (float)uniqueWords[i].count;
        den = (float)totalNumWords;
        percent = num / den;
        cout << fixed << setprecision(4) <<percent << " - " << uniqueWords[i].word << endl;
    }
}

int main(int argc, char * argv[]) {
  ifstream myFile;
  myFile.open(argv[2]);
  string line;
  int added = 0;                                      //Storing amount of wordItems to the array
  int curArraySize = 100;
  wordItem *words = new wordItem[curArraySize];
  string stopWords[50];
  getStopWords(argv[3], stopWords);
  int doubled = 0;
  if(myFile.is_open()) {
    while(myFile >> line) {

      bool flag = false;                              //If flag = true, then the word is already in the list
      if(isStopWord(line, stopWords) == false) {
        for(int i = 0; i< added; i++) {
          if(words[i].word == line) {
            words[i].count++;
            flag = true;
          }
        }

          if(flag == false) {                          //If flag = false, then the word needs to be added to the words array
            words[added].word = line;
            words[added].count = 1;
            added++;
          }
        }
        if(curArraySize == added) {
          doubled++;
          curArraySize = curArraySize * 2;
          wordItem *newArray = new wordItem[curArraySize];
          for(int i = 0; i< (curArraySize/2); i++) {
            newArray[i] = words[i];
          }
          delete [] words;
          words = newArray;
        }

    }

  }
  arraySort(words, added);
  int totNum = getTotalNumberNonStopWords(words, added);
  int reading = stoi(argv[1]);
  cout << "Array doubled: " << doubled << endl;
  cout << "#" << endl;
  cout << "Unique non-common words: " << added << endl;
  cout << "#" << endl;
  cout << "Total non-common words: " << totNum << endl;
  cout << "#" << endl;
  cout << "Probabilities of top " << reading << " most frequent words" << endl;
  cout << "---------------------------------------" << endl;
  printTopN(words, reading, totNum);
  /*
  for(int j = 0; j< added; j++) {
    cout << words[j].word;
    cout << words[j].count << endl;
}*/

}
