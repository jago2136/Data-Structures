#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

struct CarData {
	string make;
	string model;
	string year;
};

int main (int argc, char *argv[]) {
	if (argc < 4) 
	{
		cout << "Incorrect number of arguments\n";
		return -1;
		}
	string infilename = argv[1];
	int lines = stoi(argv[2]);
	string outfilename = argv[3];
	ifstream myfile;
	myfile.open(infilename);
	CarData carArray[lines];
	if (myfile.is_open())
	 {
	 	int i = 0;
	 	while (getline(infilename, carArray[i].make,' '))
	 	{
	 		getline(infilename, carArray[i].model,' ');
	 		getline(infilename, carArray[i].model,'\n');
	 		i++;
	 	}

	}
	int j = 0;
	while (j < lines) {
	cout << "make:" << carArray[i].make << "model:" << carArray[i].model << "year:" << carArray[i].year << endl;
	i++;
}
	ofstream myfile;
	

	return 0;
}