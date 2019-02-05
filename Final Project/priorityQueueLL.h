#ifndef priorityQueueLL_H
#define priorityQueueLL_H
#include <iostream>
using namespace std;


/*struct Node {
    string name;
    int priority;
    int treatment;
    Node *next;
};*/



class LL {
public:
    LL();
    ~LL();
    Node* createNode(string name, int priority, int treatement);
    void enqueue(Node *node);
    bool dequeue();
    void printQueue();
    
protected:
private:
    Node *head;
    Node *tail;
    int quantity;
};

#endif