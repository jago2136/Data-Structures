#include <iostream>
#include <string>
#include <fstream> 
#include <sstream>
#include <vector>
#include "priorityQueueH.h"
using namespace std;

Node createNode(string name, int priority, int treatement) {
	Node temp;
	temp.name = name;
	temp.priority = priority;
	temp.treatment = treatement;
	return temp;
}

MinHeap::MinHeap(int cap) {
    currentSize = 0;
    capacity = cap; 
    heap = new Node[capacity];
}

MinHeap::~MinHeap() {
    delete [] heap;
}

void MinHeap::printHeap() {
    cout << "The heap array is currently:\n";
    for (int i = 0; i < currentSize; i++) 
    {
        cout << i << ": " << heap[i].name << " " << heap[i].priority << " " << heap[i].treatment << endl;
    }
    return;
}

void MinHeap::push(Node k) {
    if (currentSize == capacity) {
        cout << "At capacity, cannot insert key.\n";
    }
    int i = currentSize;
    currentSize++;
    heap[i] = k;  
    while (i != 0 && heap[parent(i)].priority >= heap[i].priority) {
    	if (heap[parent(i)].priority == heap[i].priority && heap[parent(i)].treatment >= heap[i].treatment) {
	        swap(&heap[i], &heap[parent(i)]);
	        i = parent(i);
	        //MinHeapify(0);
	    }
	    else {
		    swap(&heap[i],&heap[parent(i)]);
	        i = parent(i);
    	} 
    //MinHeapify(0);
    }
}

Node MinHeap::pop() {
	Node poppedVal;
    if (currentSize <= 0) return poppedVal;
    if (currentSize == 1){
        currentSize--;
        return heap[0];
    }
    poppedVal = heap[0];
    heap[0] = heap[currentSize-1];
    currentSize--;
    MinHeapify(0);
    return poppedVal;
}

void MinHeap::MinHeapify(int number) {
    /*Node leftChild = heap[left(i)];
    Node rightChild = heap[right(i)];
    Node smallest = heap[i];
    if (left(i) < currentSize && leftChild.priority < heap[i].priority)
        smallest = leftChild;
    if (right(i) < currentSize && rightChild.priority < smallest.priority)
        smallest = rightChild;
    if (smallest.name != heap[i].name) {
    	if (smallest.name == rightChild.name) {
    		swap(&heap[i], &smallest);
    		MinHeapify(right(i));
    	}
    	if (smallest.name == leftChild.name) {
    		swap(&heap[i], &smallest);
    		MinHeapify(i);
    	}
    }
    return;*/
    int lC = left(number);
    int rC = right(number);
    int smallest = number;
    //int diff = 0;
    if (lC < currentSize && heap[lC].priority == heap[number].priority) {
        if (heap[lC].treatment < heap[number].treatment) {
        	//diff = heap[number].treatment - heap[lC].treatment;
            smallest = lC;
        }
    }
    if (rC < currentSize && heap[rC].priority == heap[smallest].priority) {
        if (heap[rC].treatment < heap[number].treatment) {
        	/*if ((heap[number].treatment - heap[rC].treatment) >= diff) {
            	smallest = rC;
            }*/
            smallest = rC;
        }
    }
    //diff = 0;
    if (lC < currentSize && heap[lC].priority < heap[number].priority) {
        smallest = lC;
    }
    if (rC < currentSize && heap[rC].priority < heap[smallest].priority) {
        smallest = rC;
    }
    if (smallest != number) {
        swap(&heap[number], &heap[smallest]);
        MinHeapify(smallest);
    }
}


void MinHeap::swap(Node *x, Node *y) {
    Node temp = *x;
    *x = *y;
    *y = temp;
}

void mainHeap (string file) {
	clock_t start;
    start = clock();
    int j = 0; 
	//while (j < 500) {
		ifstream data(file);                          
		string info[3];
		int x = 0;
		MinHeap Heap(880); 
		if(data.is_open()) {
			while(data.good() /*&& k < 100*/) {
				getline(data, info[0], ',');
				getline(data, info[1], ',');
				getline(data, info[2], '\r');
				if(x > 0) {
					Node temp = createNode(info[0], stoi(info[1]), stoi(info[2]));
					Heap.push(temp);
				}
				x++;
			}
		}
		x--;
		Node temp;
		int i = 1;
		//Heap.printHeap();
		while (x) {
			temp = Heap.pop();
			cout << i << ": " << temp.name << " " << temp.priority << " " << temp.treatment << endl;
			x--;
			i++;
		}
		j++;
	//}
	cout << endl << "Time: " << (clock() - start) / (double)(CLOCKS_PER_SEC) << " seconds\n" << endl;
	return;
}
 

 