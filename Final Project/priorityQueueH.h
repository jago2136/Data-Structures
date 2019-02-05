#ifndef priorityQueueH_H
#define priorityQueueH_H
#include <iostream>
using namespace std;

struct Node {
    string name;
    int priority;
    int treatment;
    Node *next;
};

class MinHeap {
    public:
        MinHeap(int capacity);
        ~MinHeap();
        void push(Node k);
        Node pop();
        Node* peek() { 
        	return &heap[1]; 
        }
        void printHeap();
    private:
        Node* heap; // pointer to array of elements in heap
        int capacity; // maximum possible size of min heap
        int currentSize; // Current number of elements in min heap      
        void MinHeapify(int index);
        int parent(int i) {
        	return (i-1)/2; 
        }
        int left(int i) {
        	return (2*i+1);
        }
        int right(int i) { 
        	return (2*i + 2); 
        }
        void swap(Node* x, Node *y);
};


#endif