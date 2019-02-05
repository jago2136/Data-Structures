#include <iostream>
#include <string>
using namespace std;

/*

Complexity:

	- Balanced vs Unbalanced 
		Number of tree nodes:
			Each level has the potential of 2^i (i being the level)
			Total number is the summation starting at 0, or (2^(h+1))-1
		Worst case scenario is the height h, or number of levels, log base 2 of N used to approximate the complexity
			* note that log base 2 (1000000) is only 19.9, compared to the million complexity of a linked list
		We only get this advantageous relationship if the tree is balanced
		The most unbalanced tree would be 
	- Tree Balancing
		Various algorithms, AVL, red-black, etc. 
		Work by having nodes w/ additional information (extra properties)
		We can perform rotations on the trees, in  a way that preserves the BST definition

		Red-Black Trees:
			Special case of a BST
				Parent
				leftChild
				rightChild
				key
				color
			The extra color property is a binary choice, referred to as red or black
			1) A new node is either red or black
			2) The root node is always black
			3) Every leaf node (node with null children) is black
			4) If a node is red, both its children have to be black
			5) For each node, all paths to leaf nodes contain the same number of black nodes
		RB Tree Operations:
			In order for a tree to self balance, certain operations are needed
				Recolor - change the node color 
				Rotation - change the height of the tree/subtree
						   change which node is root for tree/subtree
		Left and Right Rotations
			2 possible, on is the invserse of the other
				- Rotate Right alters the tree, Rotate Left brings it back to the original
				- See lecture notes for an example
		Inserting a Node into a RB Tree
		  Same as inserting a node into regular BST, w/ a few additonal steps
		  1) Instead of assigning nullptr in 1 or 0 pointers, we now insert a node with no information to preserve the properties
		  2) Set the color of the new node to red
		  3) Resolve any RB property violations by using recoloring and/or rotations

Example Building a Tree:

	insert(10) into an empty tree (ensure it has two empty leaf nodes, not null pointers)
	rule: new node is red
	violation: root of a tree must be black
	fix: re-color node to black

	insert(5)
	no violations

////////////////// NEW DAY

RB Trees:
	Leaf nodes store no data, assign the data to null
	Inserting a Node:
		1) Set the color od the new node to red
		2)Terminate the branch with the null ptr
		3)Fix any violations using rotations or recoloring

/////////////////// NEW DAY

Apply delete function to a RB tree to see what is violated
	






*/

int main() {
	return 0;
}