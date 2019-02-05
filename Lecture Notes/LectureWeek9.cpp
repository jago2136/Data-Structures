#include <iostream>
#include <string>
using namespace std;

/*
RedBlackInsert (root, x) {
	- slightly modified version of BST insert
		* traverse the tree checkig=ng whether less than, or greater than/equal to and 
		  going left or right based on that
	- need to color the new node (red) 
	- instead of nullptrs, we have a "null node"
	- call rbBalance(root, newNode) within your BST
	

	rbBalance (root, newNode) {
		while newNode.color == red
			if parent of newNode == LeftChild
				go check uncle
				uncle = newNode.parent.parent.righChild
					if uncle is red
						CASE 1
						- recolor parent and uncle to black
						- recolor grandparent to red
						- set newNode to grandparent	
					else is black 
						if new node is rightChild
							CASE 2
							- set x = x.parent
							- rotate left around x
								- left rotate swaps parent node with its right child
						CASE 3 (newNode is leftChild)
						- set x.parent to black
						- set x.parent.parent to red
						- right rotation about x.parent.parent
			else parent of newNode == rightChild
				same steps as above , except change all lefts to right
		if the root color is red, recolor it to black 
	}
	- with insertion we care about the uncle!!!
--------------------------------------------------------------------------------------------------------

	InsertNode

	redBlackInsert(value){
		x = insert(value) //add a node to the tree as a red node
		while(x != root and x.parent.color == red){
			If(parent == x.parent.parent.left){
				uncle = x.parent.parent.right
				if(uncle.color == red){
					x.parent.color = black
					uncle.color = black
					x.parent.parent.color = red
					x = x.parent.parent
				}
				else {
					if(x == x.parent.right){
						x = x.parent
						leftRotate(x)
					}
					x.parent.color = black
					x.parent.parent.color = red
					rightRotate(x.parent.parent)
				}
			}
			else {
				//x.parent is a right child. Swap left and right for algorithm
			}
		}
		root.color = black
	}


	AND


	Delete Node

	rbDeleteFunction 
		node = search(value)
		nodeColor = node.color
		if(node != root){
			if(node.leftChild == nullNode and node.rightChild == nullNode){ //no children
			 	node.parent.leftChild = nullNode
				x = node.leftChild
 			}
	 		else if(node.leftChild != nullNode and node.rightChild != nullNode){ //two children
	 			min = treeMinimum(node.rightChild)
	 			nodeColor = min.color //color of replacement
	 			x = min.rightChild
	 			if (min == node.rightChild){
	 				node.parent.leftChild = min
	 				min.parent = node.parent
	 				min.leftChild = node.leftChild
	 				min.leftChild.parent = min
				}
				else{
					min.parent.leftChild = min.rightChild
					min.rightChild.parent = min.parent
	 				min.parent = node.parent
	 				node.parent.leftChild = min
	 				min.leftChild = node.leftChild
	 				min.rightChild = node.rightChild
					node.rightChild.parent = min
					node.leftChild.parent = min
				}
 				min.color = node.color //replacement gets nodes color
			}
			else { //one child
	 			x = node.leftChild
	 			node.parent.leftChild = x
	 			x.parent = node.parent
		}
		else{
		//repeat cases of 0, 1, or 2 children
 		//replacement node is the new root
 		//parent of replacement is nullNode
		}
		if (nodeColor == BLACK){
			RBBalance(x)
		}
		delete node
	} 


	AND

	Rebalance After Delete

	RBBalance(x){
		while (x != root and x.color == BLACK){
			if (x == x.parent.leftChild){
		 		s = x.parent.rightChild
		 		if (s.color == RED){ //Case 1
		 			s.color = BLACK
		 			x.parent.color = RED
		 			leftRotate(x.parent)
		 			s = x.parent.rightChild
		 		}
				if (s.leftChild.color == BLACK and s.rightChild.color == BLACK){ //Case 2
				 	s.color = RED
					x = x.parent
		 		}
		 		else if(s.leftChild.color == RED and s.rightChild.color == BLACK){ //Case 3
		 			s.leftChild.color = BLACK
		 			s.color = RED
		 			rightRotate(s)
		 			s = x.parent.rightChild
		 		}
		 		else {
		 			s.color = x.parent.color //Case 4
		 			x.parent.color = BLACK
					s.rightChild.color = BLACK
		 			leftRotate(x.parent)
		 			x = root
				}
		 	}
		 	else {
		 		//x is a right child
		 		//exchange left and right
			}
		}
		x.color = BLACK
	}

	
*/







int main() {
	return 0;
}