#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <sstream>
#include <fstream>
#include "Graph.h"
using namespace std;

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
    if (!found) {
        vertex temp;
        temp.name = n;
        temp.districtID = -1;
        vertices.push_back(temp);
    }
    return;
}

vertex* Graph::findVertex(string name) {
	for (int i = 0; i < vertices.size(); i++) {
		if (vertices[i].name == name) {
			return &vertices[i];
		}
	}
	return NULL;
}

void Graph::addEdge(string v1, string v2, int weight) {
	vertex* temp1 = findVertex(v1);
	vertex* temp2 = findVertex(v2);
	adjVertex temp;
	temp.v = temp2;
	temp.weight = weight;
	temp1->adj.push_back(temp);
	return;
}

void Graph::displayEdges() {
	int j = 0;
	for (int i = 0; i < vertices.size(); i++) {
		cout << vertices[i].districtID << ":" << vertices[i].name << "->";
		for (j = 0; j < vertices[i].adj.size()-1; j++) {
			cout << vertices[i].adj[j].v->name << "**";
		}
		cout << vertices[i].adj[j].v->name << endl;
	}
	return;
}


void Graph::DFSLabel(string startingCity, int distID) {
	vertex *vStart;
    for (int i = 0; i < (int)vertices.size(); i++) {
        //cout << vertices[i].name << endl;
        if (vertices[i].name == startingCity) {
            vStart = &vertices[i];
        }
    }
    if (!vStart) return;
    vStart->visited = true;
    vStart->districtID = distID;
    queue<vertex*> q;
    q.push(vStart);
    vertex *n;
    while(!q.empty()) {
        n = q.front();
        q.pop();
        // scan adjacency list of each element in Queue
        for (int x = 0; x < (int)n->adj.size(); x++) {
            if (!n->adj[x].v->visited) {
                int *temp = &n->adj[x].v->districtID;
                *temp = distID;
            	// cout << n->adj[x].v->districtID;
                n->adj[x].v->visited = true;
                q.push(n->adj[x].v);
            }
        }
    }
}

void Graph::assignDistricts() {
	int district = 1;
	for (int i = 0; i < vertices.size(); i++) {
		if (vertices[i].districtID == -1) {
			DFSLabel(vertices[i].name, district);
			district++;
		}
	}
	return;
}


void Graph::shortestPath(string startingCity, string endingCity) {
	vertex *vStart = NULL;
    for (int i = 0; i < (int)vertices.size(); i++) {
        //cout << vertices[i].name << endl;
        if (vertices[i].name == startingCity) {
            vStart = &vertices[i];
        }
    }
    int x = 0;
    for (int i = 0; i < (int)vertices.size(); i++) {
        if (vertices[i].name == endingCity) {
            x = 1;
        }
    }
    if (!vStart || !x) {
        cout << "One or more cities doesn't exist\n";
        return;
    }
    for (int i = 0; i < (int)vertices.size(); i++) {
        vertices[i].visited = false;
    }
    if (!vStart) return;
    vStart->visited = true;
    vStart->unweightedDistance = 0;
    vStart->parent = NULL;
    queue<vertex*> q;
    q.push(vStart);
    vertex *n;
    while(!q.empty()) {
        n = q.front();
        q.pop();
        for (int i = 0; i < n->adj.size(); i++) {
        	if (!n->adj[i].v->visited) {
        	    q.push(n->adj[i].v);
        		n->adj[i].v->parent = n;
        		n->adj[i].v->visited = true;
        		n->adj[i].v->unweightedDistance = n->unweightedDistance + 1;
        		if (n->adj[i].v->name == endingCity) {
        			cout << n->adj[i].v->unweightedDistance;
        			vertex* temp = n->adj[i].v;
        			vector<string> printt;
        			while (temp) {
        				printt.push_back(temp->name);
        				temp = temp->parent;
        			}
        			for (int k = printt.size()-1; k > -1; k--) {
        			    cout << ", " << printt[k];
        			}
        			cout << endl;
        			return;
        		}
        	}
        }
    }
    cout << "No safe path between cities\n";
    return;
}

void Graph::shortestWeightedPath(string startingCity, string endingCity) {
	vertex *vStart = NULL;
    for (int i = 0; i < (int)vertices.size(); i++) {
        if (vertices[i].name == startingCity) {
            vStart = &vertices[i];
        }
    }
    int x = 0;
    for (int i = 0; i < (int)vertices.size(); i++) {
        if (vertices[i].name == endingCity) {
            x = 1;
            if (vertices[i].districtID == -1) {
                cout << "Please identify the districts before checking distances\n";
                return;
            }
        }
    }
    if (!vStart || !x) {
        cout << "One or more cities doesn't exist\n";
        return;
    }
    int one = 0, two = 0;
    for (int i = 0; i < (int)vertices.size(); i++) {
        if (vertices[i].name == endingCity) {
        	one = vertices[i].districtID;
        }
        if (vertices[i].name == startingCity) {
        	two = vertices[i].districtID;
        }
    }
    if (one != two) {
    	cout << "No safe path between cities\n";
    	return;
    }
    for(int i=0; i<vertices.size();i++) {
        //vertices[i].weightedDistance = 2147483647;
        vertices[i].parent = NULL;
        vertices[i].visited = false;
    }
    if (!vStart) return;
    vStart->visited = true;
    vStart->parent = NULL;
    queue<vertex*> q;
    q.push(vStart);
    vertex *n;
    int totDistance = 0;
    while(!q.empty()) {
        n = q.front();
        q.pop();
        vector<vertex*> least;
        for (int i = 0; i < n->adj.size(); i++) {
        	if (!n->adj[i].v->visited) {
        	    least.push_back(n->adj[i].v);
        		n->adj[i].v->parent = n;
        		n->adj[i].v->visited = true;
        		if (n->adj[i].v->name == endingCity) {
        			vertex* temp = n->adj[i].v;
        			vector<string> printt;
        			vector<int> total;
        			while (temp) {
        				printt.push_back(temp->name);
        				//printt.push_back(temp->weightedDistance);
        				cout << (temp->weightedDistance);
        				temp = temp->parent;
        			}
        			cout << totDistance;
        			for (int k = printt.size()-1; k > -1; k--) {
        			    cout << ", " << printt[k];
        			}
        			cout << endl;
        			return;
        		}
        	}
        }
        vertex* leastt = least[0];
        for (int i = 0; i < least.size(); i++) {
            if (least[i]->weightedDistance < leastt->weightedDistance) {
                leastt = least[i];
            }
        }
        totDistance = totDistance + leastt->weightedDistance;
        q.push(leastt);
    }
    cout << "No safe path between cities\n";
    return;
}

Graph::Graph() {

}

Graph::~Graph() {

}

void printMenu() {
	cout << "======Main Menu======\n";
	cout << "1. Print vertices\n";
	cout << "2. Find districts\n";
	cout << "3. Find shortest path\n";
	cout << "4. Find shortest weighted path\n";
	cout << "5. Quit\n";
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
            		//cout << src << arr[i];
            		//cout << newWord << endl;
	                G.addEdge (src, arr[i], stoi(newWord));
	            }
	            i++;
	        }
        }
    }
	int x = 1; 
	int userchoice;
	printMenu();
	while (x) {
		cin >> userchoice;
		cin.ignore();
		if (userchoice == 1) {
			G.displayEdges();
		}
		if (userchoice == 2) {
			G.assignDistricts();
		}
		if (userchoice == 3) {
			string choice1, choice2;
			cout << "Enter a starting city:" << endl;
			getline(cin, choice1, '\n');
			cout << "Enter an ending city:" << endl;;
			getline(cin, choice2, '\n');
			G.shortestPath(choice1, choice2);
		}
		if (userchoice == 4) {
			string choice1, choice2;
			cout << "Enter a starting city:" << endl;
			getline(cin, choice1, '\n');
			cout << "Enter an ending city:\n";
			getline(cin, choice2, '\n');
			G.shortestWeightedPath(choice1, choice2);
		}
		if (userchoice == 5) {
			cout << "Goodbye!\n";
			return 0;
		}
		printMenu();
		
	}
}