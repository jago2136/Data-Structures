#include <iostream>
#include <string>
using namespace std;

/*
void MinHeap::(push(int k) {
	if (currSize == capacity) print error
	else {
		currSize++;
		int i = currSize - 1;
		heap[i] = k;
		while (i != 0 && heap[parent(i)] > heap[i]) {
			swap (&heap[i], &heap[parent(i)]);
			i = parent(i);
		}
		// because the heap is a partially ordered tree, simply iteration will preserve
		   the heap's properties
		// complexity of push() is log(n), worst case
		// if the tree has height h, the operation will require h comparisons.. h = log(n) = big-
	}
}

Getting the highest priority item is simple, you just take the root
What takes complexity is restoring the heap property

If size == 1, just take that element
Store the root value in a local variable
Swap the root with the "last" value in the tree
Resotre tree properties

int MinHeap::pop() {
	if currsize <= 0 return -1
	if currSize == 1 
		currSize--
		return heap[0]
	int poppedVal = heap[0]
	heap[0] = heap[currentSize - 1]
	currSize--
	MinHeapify(0)
	return poppedVal
}

void MinHeap::MinHeapify(int i) {
	int leftChild = left(i)
	int rightChild = right(i)
	int smallest = i
	if (leftChild < currSize && heap[leftChild] < heap[i])
		smallest = leftChild
	if (rightChild < currSize && heap[rightChild] < heap[smallest])
		smallest = rightChild
	if (smallest != i) {
		swap(&heap[i], &heap[smallest])
		MinHeapify(smallest)
	}

}


*/