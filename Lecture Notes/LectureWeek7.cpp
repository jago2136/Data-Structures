#include <iostream>
#include <string>
using namespace std;

/*

Binary Search Tree:
	For and nodes in the tree, the nodes in the left branch have smaller values than the parent node value
	Nodes on the right side have values greater than OR equal to the parent node value

	As an absrract data type:
		private:
			root;
			node *searchRecursive; // other methods can make use of
		public:
			init()            // constructor, empty tree, null pointers
			insert(value);
			node *search(value);  // root abstracted
			display();       // use recursive traversal
			delete(value); 
			deleteTree        // destructor
			getMin();
			getMax();
			getSize();
	
	Implement insert method:
		Loop until we find first empty spot in the tree
		void insert (newValue) {
			Node *temp = root;
			Node *newNode = new Node;
			newNode->key = newValue;
			Node *prev = NULL;
			while (temp != NULL) {
				prev = temp;
				if (newNode->key < temp->key) {    // check which way to traverse
					temp = temp->leftChild;
				} 
				else {
					temp = temp->rightChild;
				}
			}
			if (prev == NULL) {     // if empty tree
				root = newNode;
			}
			else if (newNode->key < prev->key) {   // append to left child of node
				prev->leftChild = newNode;  // ass newNode to tree
				newNode->parent = prev;

			}
			else {                   // append to right child of node
				prev->rightChild = newNode;
				newNode->oarent = prev
			}
		}

		Implement Search:
			node *search(searchkey) {
				return searchRecursive(node, key);
			}
			
			// Recursive
			node *searchRecursive(node, skey) {
				if (node != NULL) {
					if (node.key == skey) return node;
					else if (node->key > skey) {
						searchRecursive (node->leftChild, skey);
					}
					else searchRecursive (node->rightChild, skey)
				}
				else return NULL;
			}

			// Iteratively
			node * searchIterative(node, key) {
				while (node != NULL) {
					if (node.key > skey) 
						node = node->leftChild;
					else if (node->key < skey)
						node = node->rightChild;
					else return node;
				}
				return NULL;
			}

		Implement finding the min value:
			// Just keep going left until you can't anymore
			Node *getMin(Node *root) {
				Node *temp = root;
				while (temp->leftChild != NULL) {
					temp = temp->leftChild;
				}
				return temp;
			}

		Delete Node:
			// Assume node to be deleted is already found
			// When deleting a node there are 3x2 possible cases.
				- node had no children
				- node has one child
				- node has 2 children

				- node is the root
				- node isnt the root

		Algorithms:
			displayPreOrder(Node) {
				cout << Node->key << endl;
				if (n->LC != NULL) {
					displayPreOrder(n->LL) 
				if (n->RC != NULL) 
					displayPreORder(Node->RC)
				}		
			displayInOrder(n) {
				if (n->LC != NULL) 
					displayInOrder(n->LL)
				cout << n->key << endl;
				if (n->RC != NULL) 
					displayInOrder(n->RC)
			}

			1) Find Node
			2) Check for Children
				Case 1: Node has no children
					if (node->LC == NULL && node->RC == NULL) {
						if (node == node->parent->LC)
							node->parent->LC = NULL;
						else node->parent->RC = NULL;
					}
				Case 2: Two Children
					else if ((node->LC != NULL) && (node->RC != NULL)) {
						// approach: find the min node in the rught branch and use it 
									 to replace the deleted node 
						*min = getMin(node);
						if (min == node->rightChild)
					}


*/  

int main() {
	return 0;
}