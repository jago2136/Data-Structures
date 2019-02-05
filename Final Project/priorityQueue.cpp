#include <iostream>
#include <string>
#include <fstream> 
#include <sstream>
#include <queue>
#include <vector>
#include "priorityQueue.h"
using namespace std;


/*Node* createNode(string name, int priority, int treatment) {
	Node *temp = new Node;
	temp->name = name;
	temp->priority = priority;
	temp->treatment = treatment;
	return temp;
}*/
int mainSTL (string file) {
	clock_t start;
    start = clock();
    int i = 0;
    //while (i < 500) {
    	priority_queue<Node, vector<Node>, compare> pq;
		ifstream data(file);                          
		string info[3];
		int x = 0, k = 0;  
		if(data.is_open()) {
			while(data.good() /*&& k < 100*/) {
				getline(data, info[0], ',');
				getline(data, info[1], ',');
				getline(data, info[2], '\r');
				if(x > 0) {
					Node temp = createNode(info[0], stoi(info[1]), stoi(info[2]));
					//cout << temp->name << ' ' << temp->priority << ' ' << temp->treatement << endl;
					pq.push(temp);
				}
				x = 1;
				k++;
			}
		}
		while(!pq.empty()) {
			cout << x << ":\t" << pq.top().name << "  " << pq.top().priority << "  " << pq.top().treatment << endl;
			pq.pop();
			x++;
			//if (x > 900) break;
		}
		i++;
	//}
	cout << endl << "Time: " << (clock() - start) / (double)(CLOCKS_PER_SEC) << " seconds\n" << endl;
	return 0;
}
