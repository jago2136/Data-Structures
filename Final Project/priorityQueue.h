#ifndef priorityQueue_H
#define priorityQueue_H
#include <iostream>
using namespace std;


/*struct Node {
    string name;
    int priority;
    int treatment;
};*/

class compare {
public:
	bool operator() (const Node& a, const Node& b) {
		if (a.priority == b.priority) {
			return a.treatment > b.treatment;
		}
		return a.priority > b.priority;
	}
};
#endif