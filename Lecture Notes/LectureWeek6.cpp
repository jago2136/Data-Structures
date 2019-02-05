#include <iostream>
#include <string>
using namespace std;

/*
Trees:
	Binary trees only have two options for each branch
	In nodes we had next, previous, and data
	In trees we have left and right, which either point to null or another node
		- To start, we'll assume you can't go back up the tree, if you can you have a parent node
		- A binary search tree can be navigated very easily
		- When you put a node in, its replacing a null pointer
		- The order we add to a tree can really affect the shape
			~ As far left as you can go has to be the smallest
			~ Largest node had to be the largest
		- We use these because searching through them is much much faster

Day 2, Trees:
	Like with linked lists, the nodes ooint to nodes of the same type
	Each node has 2 next pointers, one previous, and then data
	Each node has 0, 1, or 2 chilren (bottom has 0)
	EXCEPT for the root node, every node has a parent node
	Heirarchical data structure (as opposed to linear
	The top of the tree is the root, parent of the root is null

	Subtrees:
		- The whole tree is defined by its subtrees
		- Subtrees can be seen whenever there's a new node, a subtree is everything below a given node
		- Self-similarity: the thing is similar to a part of itself
		- Why is this important?
			* We can observe smaller and smaller subtrees starting at the root until the whole thing is traversed
	Recursive Structures:
		- This is a struct defined in terms of itself
			* A tree defined by smaller and smaller trees
		- A recursive algorithm is an algorithm that calls itself
			* with each call the input usually gets smaller and smaller, until a base case is reached

	void rc(Node * n) {
		print key
		if (n->leftChild != NULL) {
			rc(n->leftChild);
		}								// Think about when the function is called, when your functions stat to return you have
		if (n->rightChild != NULL) {       to continue from there!
			rc(n->rightChild);
		}
	}

	Back to Binary Search Tree:
		For and nodes in the tree, the nodes in the left branch have smaller values than the parent node value
		Nodes on the right side have values greater than OR equal to the parent node value

		As an absrract data type:
			private:
				root;
				searchRecursive;
			public:
				init() // constructor, empty tree, null pointers
				insert(value);
				search(value);
				display (); // use recursive traversal
				delete(value); 
				deleteTree // destructor

*/

struct Node {
	int id = -1;
	Node * left = nullptr;
	Node * right = nullptr;
	Node * parent = nullptr;
};

class BST {

public:
	BST();
	~BST();
	bool addNode(int); // use bool because if the number already exists, return false
	bool removeNode(int);
	int findSmallest();
	int findLargest();

private:
	Node * root = nullptr;
	Node * createNode(int,Node*,Node*,Node*); // pass in an item id, left, right, and parent
};

BST::BST() {

}

BST::BST() {
	// clear all nodes, dont worry about that code for now
}

Node* BST::createNode(int itemToAdd, Node * parentNode, Node * leftChild, Node * rightChild) {
	Node * newNode = new Node;
	newNode->id = itemToAdd;
	newNode->left = leftChild;
	newNode->right = rightChild;
	newNode->parent = parentNode;
}

int BST::findLargest() {
	Node * tempNode = root;
	while (tempNode->right) {
		tempNode = tempNode->right;
	}
	return tempNode->id;
}

int BST::findSmallest() {
	Node * tempNode = root;
	while (tempNode->left) {
		tempNode = tempNode->left;
	}
	return tempNode->id;
}


int main() {
	
	return 0;
}