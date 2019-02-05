#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include "Graph.h"
using namespace std;

void Graph::addEdge(string v1, string v2, int weight) {
	// cycle through all vertices for the two cities
    for (int i = 0; i < vertices.size(); i++){
        if (vertices[i].name == v1){
            for (int j = 0; j < vertices.size(); j++){
                if (vertices[j].name == v2 && i != j){
                	// once found, add the vertex with its assigned weight 
                    adjVertex temp;
                    temp.weight = weight;
                    temp.v = &vertices[j];
                    vertices[i].adj.push_back(temp);
                    /*adjVertex temp2;
                    temp2.weight = weight;
                    temp2.v = &vertices[i];
                    vertices[j].adj.push_back(temp2);*/
                }
            }
        }
    }
    return;
}

void Graph::addVertex (string n) {
    bool found = false;
    // search to see if the string is already in the list
    for (int i = 0; i < vertices.size(); i++){
        if (vertices[i].name == n){
            found = true;
            cout << vertices[i].name << " already in the graph.\n";
        }
    }
    // if not found, simply add it
    if (!found){
        vertex temp;
        temp.name = n;
        vertices.push_back(temp);

    }
    return;
}

int Graph::isAdjacent(std::string v1, std::string v2) {
    for (int i = 0; i < vertices.size(); i++) {
    	if (vertices[i].name == v1) {
    		for (int j = 0; j < vertices[i].adj.size(); j++) {
    			if (vertices[i].adj[j].v->name == v2) return 1;
    		}
    	}
    }
    return 0;
}

void Graph::displayEdges() {
    // go through the list of all vertices
    for (int i = 0; i < vertices.size(); i++) {
    	// for each one, print out its adjacent edges
        cout << vertices[i].name << "-->";
        int j;
        for (j = 0; j < vertices[i].adj.size()-1; j++) {
            cout << vertices[i].adj[j].v->name << "***";
        }
        cout << vertices[i].adj[j].v->name << endl;
    }
    return;
}

void printMenu() {
	cout << "======Main Menu======\n";
	cout << "1. Print vertices\n";
	cout << "2. Vertex adjacent\n";
	cout << "3. Quit\n"; 
	return;
}

int main(int argc, char * argv[]) { 
	Graph G;
	ifstream myfile;                          
    myfile.open(argv[1]); 
    string city;
    // vector of vertices
    vector<string> arr;                   
    if (myfile.is_open()) {
        string line;
        getline(myfile, line);
        stringstream ss(line);
        string curr;
        getline(ss, curr, ',');
        vector<string> arr;
        while (getline(ss, curr,',')) {
            G.addVertex(curr);
            arr.push_back(curr);
        }

        while (getline(myfile, line)) {
            stringstream ss(line);
            string src;
            getline(ss, src, ',');
            int i = 0;
            string newWord;
            while (getline(ss, newWord,',')) {
            	if (stoi(newWord) != -1) {
	                G.addEdge (src, arr[i], stoi(newWord));
	            }
	            i++;
	        }
        }
    }
	printMenu();
	int x = 1; 
	int userchoice;
	while (x) {
		cin >> userchoice;
		cin.ignore();
		if (userchoice == 1) {
			G.displayEdges();
		}
		if (userchoice == 2) {
			string v1, v2;
			cout << "Enter first city:\n";
			getline(cin, v1, '\n');
			cout << "Enter second city:\n";
			getline(cin, v2, '\n');
			if (G.isAdjacent(v1,v2)) cout << "True\n";
			else cout << "False\n";
		}
		if (userchoice == 3) {
			cout << "Goodbye!\n";
			return 0;
		}
		printMenu();
	}
	return 0;
}