#include <iostream>
#include <string>
using namespace std;

/*

A priority queue is one where:
	- new elements get added in the order they're received
	- when an element is requested, the one with the highest priority gets pulled
	- priority is indicated by some comparable component
		e.g. highest number equals highest priority

Stack vs. Queue vs. Priority Queue
	- Stack works, first in->last out, like a stack of plates
		input a,b,c and draw off c,b,a
	- Queue works, first in->first out, like a line at the supermarket
		input a,b,c and draw off a,b,c
	- Priority Queue, highest priority comes out first
		Can define our priority queue with...
			* highest numner = highest priority
			* lowest number = highest priority
			...
		What are some uses?
			* Scheduling jobs in operating system
			* emergency room patient priority
			* load balancing on a server
			* Dijkstra's - find shortest, then give it highest priority
Priority Queue Implementations
	- Most use cases for queues, we eventually remove everything we've added
	- Need to consider the cpst of add and delete (enqueue and dequeue)
	- Array (unsorted)
		cost of adding is just O(1), simply keep track of the end
		cost of dequing is O(n), have to iterate through every element
	- Array (unsorted)
		cost of enqueue, we have to do a search for the highest, O(n)
		cost of dequeue, we just grab the first element O(1)
	- Turns out the best we can do for a LL is the same, O(n) at some point of time
	- There's a data structure called a binary heap, that is most often used for priority queue implementations
	Heap:
		- stored in a complete binary tree
			* the difference in height between two branches is no more than one
			* NOT a binary search tree, no search
			* relationship defined between parent and children nodes
		- Min-heap
			root always has min value, all children are greater than
		- Max-heap
			root always has max value, all children are less than
		- If you need a structure for removing the element with the highest priority, then heap is a good choice
			the dequeue removal is an O(1) search
Building a Heap
	- we can store a complete binary tree in an array, by storing the root in the first index[0], and 
	  the remaining elements in a defined heirarchical order
Storing a tree in an array
	- root of the tree goes in element 0
	- for any element at index x
		LC index = 2x + 1
		RC index = 2x + 2
		current index = floor((x-1)/2)
Min Heap ADT
	public:
		MinHeap();
		push(value);
		int pop();
		int peek();
		void printHeap();
	private:
		int *heap // pointer
		int capacity // max heap size
		int currentSize // keep track
		void currentSize // keep track of # elements
		void minHeapify(index) // recursive method to fix heap
		int parent(index) { return((i-1)/2) }
		int leftC(index) { return (2*i + 1)}
		int rightChild(index) { return (2*i + 2)})
		void swap (int *x, int *y)
	Constructor
		minHeap(int cap) {
			currentSize = 0;
			capacit = cap;
			heap = new int[capacity]
		}


	Push(value) {
		if (currentSize == capacity) {
			cout << an error;
			return;
		}
		else {
			currentSize++;
			i = currentSize - 1;
			heap[i] = value; //enqueue new key at the tail
			while (i != 0 && heap[parent(i)] > heap[i])	{
				swap(&heap[i], &heap[parent(i)]);
				i = parent(i);
			}
		}

	}

	
