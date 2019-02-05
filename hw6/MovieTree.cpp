#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "MovieTree.h"
using namespace std;

// Search for a specific node within the linked list     DONE!

MovieNodeLL* MovieTree::searchLL(MovieNodeLL* head, string title) {
	MovieNodeLL *temp = head;
	while (temp->title != title) {
	        if (!temp->next) {
				cout << "Movie not found.\n";
				return nullptr;
			}
			temp = temp->next;
	}
	return temp;
}
 
// Search for a leaf within the BST by given the name of the movie and the root   DONE!

MovieNodeBST* MovieTree::searchBST (MovieNodeBST *node, string title) {
	char c = title.at(0);
	while (c != node->letter) {
		if (c < node->letter) {
		    if (!node->leftChild) return nullptr;
			node = node->leftChild;
		}
		else {
		if (!node->rightChild) return nullptr;
			node = node->rightChild; 
		}
	}
	return node;
}

// Rent a movie and update the quantity    DONE!

void MovieTree::rentMovie(string title) {
	MovieNodeLL *tempLL;
	MovieNodeBST *tempBST;
	tempBST = searchBST(root, title);
	if (!tempBST) {
		cout << "Movie not found.\n";
		return;
	}
	tempLL = tempBST->head;
	MovieNodeLL *prevLL;
	while (tempLL->title != title) {
		prevLL = tempLL;
		tempLL = tempLL->next;
		if (!tempLL) {
			cout << "Movie not found.\n";
			return;
		}
	}	
	tempLL->quantity--;
	cout << "Movie has been rented." << endl;
	cout << "Movie Info:" << endl;
	cout << "===========" << endl;
	cout << "Ranking:" << tempLL->ranking << endl;
	cout << "Title:" << tempLL->title << endl;
	cout << "Year:" << tempLL->year << endl;
	cout << "Quantity:" << tempLL->quantity << endl; 
	if (!tempLL->quantity) deleteMovieNode(title);
	return;
}



// Find the minimum (leftmost) value in the tree    DONE!

MovieNodeBST* MovieTree::treeMinimum(MovieNodeBST *node) {
	MovieNodeBST *temp;
	temp = root;
	while (temp->leftChild) {
		temp = temp->leftChild;
	}
	return temp;
}


// Delete a movie node from the tree    DONE!

void MovieTree::deleteMovieNode(std::string title) {
	char c = title.at(0);
	MovieNodeLL *tempLL;
	MovieNodeBST *tempBST = searchBST(root, title);
	tempLL = tempBST->head;
	MovieNodeLL *prevLL;
	while (tempLL->title != title) {
	        if (!tempLL->next) {
				cout << "Movie not found.\n";
				return;
			}
			prevLL = tempLL;
			tempLL = tempLL->next;
	}
	// If the movie is pointing to another movie, and isn't the head
	if (tempLL->next && (tempLL != tempBST->head)) {
		prevLL->next = tempLL->next;
		delete tempLL;
		return;
	}
	// If the movie isn't pointing to another movie, and it isn't the head
	else if ((!tempLL->next) && (tempLL != tempBST->head)) {
		prevLL->next = nullptr;
		delete tempLL;
		return;
	}
	// If the movie is the head, but has an element after it
	else if (tempLL->next && (tempLL == tempBST->head)) {
		tempBST->head = tempLL->next;
		delete tempLL; 
		return;
	}
	// If the movie is the last movie in the list, delete the entire node (aka, you're fucked)
	else {
		// If its the root, handle that case by finding the right-most node in the left side of the tree
		// 		NOTE: this would also work for the leftmost node in the right of the tree
		if (tempBST == root) {
			MovieNodeBST *curr = root->leftChild;
			while (curr->rightChild) {
				curr = curr->rightChild;
			}
			if (curr->leftChild) {
				curr->parent->rightChild = curr->leftChild;
			}
			else {
				curr->parent->rightChild = nullptr;
			}
			curr->leftChild = root->leftChild;
			curr->rightChild = root->rightChild;
			root = curr;
			return;
		}
		// If it has no children, just delete that bitch
		if (!tempBST->leftChild && !tempBST->rightChild) {
			if (tempBST == tempBST->parent->rightChild) tempBST->parent->rightChild = nullptr;
			if (tempBST == tempBST->parent->leftChild) tempBST->parent->leftChild = nullptr;
			delete tempBST;
			return;
		}
		// If it onlt has a right child, assign the node's parent to the right child
		//      NOTE: this, as well as all the next cases, will be dependant upon whether the node being deleted is the left or right child of its parent
		if (!tempBST->leftChild && tempBST->rightChild) {
			if (tempBST == tempBST->parent->rightChild) {
				tempBST->parent->rightChild = tempBST->rightChild;
				tempBST->rightChild->parent = tempBST->parent;
				delete tempBST;
				return;

			}
			if (tempBST == tempBST->parent->leftChild) {
				tempBST->parent->leftChild = tempBST->rightChild;
				tempBST->rightChild->parent = tempBST->parent;
				delete tempBST;
				return;
			}
		}
		// If it only has a left child, assign that left child to the node's parent
		if (tempBST->leftChild && !tempBST->rightChild) {
			if (tempBST == tempBST->parent->rightChild) {
				tempBST->parent->rightChild = tempBST->leftChild;
				tempBST->leftChild->parent = tempBST->parent;
				delete tempBST;
				return;
			}
			if (tempBST == tempBST->parent->leftChild) {
				tempBST->parent->leftChild = tempBST->leftChild;
				tempBST->leftChild->parent = tempBST->parent;
				delete tempBST;
				return;
			}
		}
		// Here's where things get wilddd
		if (tempBST->leftChild && tempBST->rightChild) {
			// If its the right child of the parent, you want to find the rightmost child within this subtree
			// then replace the node being deleted with this rightmost node
			// HOWEVER, what if the rightmost node has a left child? Handle that case by assigning the rightmost node's parent to this left node
			if (tempBST == tempBST->parent->rightChild) {
				MovieNodeBST *curr;
				curr = tempBST->leftChild;
				while (curr->rightChild) {
					curr = curr->rightChild;
				}
				tempBST->parent->rightChild = curr;
				if (curr->leftChild) {
					curr->parent->rightChild = curr->leftChild;
				}
				else {
					curr->parent->rightChild = nullptr;
				}	
				curr->parent = tempBST->parent;
				delete tempBST;
				return;
			}
			// Pretty much do the same shit as above, remembering the case that the node being moved has a RIGHT child in this case
			if (tempBST == tempBST->parent->leftChild) {
				MovieNodeBST *curr = treeMinimum(tempBST->rightChild);
				tempBST->parent->leftChild = curr;
				if (curr->rightChild) {
					curr->parent->leftChild = curr->rightChild;
				}
				else {
					curr->parent->leftChild = nullptr;
				}
				curr->parent = tempBST->parent;
				delete tempBST;
				return;
			}

		}
	}
	return;
}

// Find a given movie within the tree, print its contents     DONE!

void MovieTree::findMovie(string title) {
	char c = title.at(0);
	MovieNodeLL *tempLL;
	if (root->letter == c) {
		tempLL = root->head;
		while (tempLL->title != title) {
		    if (!tempLL->next) {
				cout << "Movie not found.\n";
				return;
			}
			tempLL = tempLL->next;
		}
		cout << "Movie Info:\n" << "===========\n";
		cout << "Ranking:" << tempLL->ranking << endl;
		cout << "Title:" << tempLL->title << endl;
		cout << "Year:" << tempLL->year << endl;
		cout << "Quantity:" << tempLL->quantity << endl;
		return;
	}
	MovieNodeBST *tempBST = searchBST(root, title);
	if (!tempBST) return;
	tempLL = tempBST->head;
	tempLL = searchLL(tempLL, title);
	if (!tempLL) return;
	cout << "Movie Info:\n" << "===========\n";
	cout << "Ranking:" << tempLL->ranking << endl;
	cout << "Title:" << tempLL->title << endl;
	cout << "Year:" << tempLL->year << endl;
	cout << "Quantity:" << tempLL->quantity << endl;
	return;
}

// Add a movie node to the tree

void MovieTree::addMovieNode(int ranking, string title, int releaseYear, int quantity) {
	if (!root) {
		MovieNodeLL *newNode = new MovieNodeLL;
		MovieNodeBST *newBSTNode = new MovieNodeBST;
		newNode->ranking = ranking;
		newNode->title = title;
		newNode->year = releaseYear;
		newNode->quantity = quantity;
		newNode->next = nullptr;
		newBSTNode->letter = title.at(0);
		newBSTNode->head = newNode;
		newBSTNode->parent = nullptr;
		newBSTNode->leftChild = nullptr;
		newBSTNode->rightChild = nullptr;
		root = newBSTNode;
		return;
	}
	MovieNodeBST *tempBST = root;
	MovieNodeLL *newNode = new MovieNodeLL;
	MovieNodeLL *tempLL, *prevLL;
	newNode->ranking = ranking;
	newNode->title = title;
	newNode->year = releaseYear;
	newNode->quantity = quantity;
	newNode->next = nullptr;
	char c = title.at(0);
	while (c != tempBST->letter) {
		if (c > tempBST->letter) {
		    if (!tempBST->rightChild) {
		    	MovieNodeBST *newLeaf = new MovieNodeBST;
		        newLeaf->letter = c;
		        tempBST->rightChild = newLeaf;
		        newLeaf->parent = tempBST;
		        newLeaf->head = newNode;
		        newLeaf->leftChild  = nullptr;
		        newLeaf->rightChild = nullptr;
		        return;
		    }
			tempBST = tempBST->rightChild;
		}
		else {
		    if (!tempBST->leftChild) {
		    	MovieNodeBST *newLeaf = new MovieNodeBST;
		        newLeaf->letter = c;
		        tempBST->leftChild = newLeaf;
		        newLeaf->parent = tempBST;
		        newLeaf->head = newNode;
		        newLeaf->leftChild  = nullptr;
		        newLeaf->rightChild = nullptr;
		        return;
		    }
			tempBST = tempBST->leftChild; 
		}
	}
	tempLL = tempBST->head;
	if (!tempLL->next) {
		if (tempLL->title < title) {
			tempLL->next = newNode;
			return;
		}
		else {
			newNode->next = tempLL;
			tempLL->next = nullptr;
			tempBST->head = newNode;
			return;
		}
	}
	if (title < tempLL->title) {
		newNode->next = tempLL;
		tempBST->head = newNode;
		return;
	}
	prevLL = tempLL;
	while ((title > tempLL->title) && (tempLL->next)) {
		prevLL = tempLL;
		tempLL = tempLL->next;
	}
	if (title < tempLL->title) {
		newNode->next = prevLL->next;
		prevLL->next = newNode;
		return;
	}
	tempLL->next = newNode;
	return;
}


// Count total number of movies in tree (not quantities)    DONE!

void MovieTree::countMovieNodes(MovieNodeBST *node, int *c) {
	if(node) {
		countMovieNodes(node->leftChild, c);
		MovieNodeLL *temp = node->head;
		while(temp) {
			*c =  *c +1;;
			temp=temp->next;
		}
		countMovieNodes(node->rightChild, c);
	}
}

// Calls the recursive function   DONE

int MovieTree::countMovieNodes() {
	int count = 0;
	countMovieNodes(root, &count);
	return count;
}

// Delete the entire tree, call in the destructor

void MovieTree::DeleteAll(MovieNodeBST * node) {
	if (!node) return;
	DeleteAll(node->leftChild);
	DeleteAll(node->rightChild);
	MovieNodeLL*temp;
	temp = node->head;
	while (temp) {
		cout << "Deleting: " << temp->title << endl;
		temp = temp->next;
	}
	delete node;
	return;
}

// Constructor

MovieTree::MovieTree() {
	root = new MovieNodeBST;
}

MovieTree::~MovieTree() {
	DeleteAll(root);
}

void MovieTree::printMovieInventory(MovieNodeBST * node) {
	if (!node) return;
	printMovieInventory(node->leftChild);
	MovieNodeLL*temp;
	temp = node->head;
	while (temp) {
		cout << "Movie: " << temp->title << " " << temp->quantity << endl;
		temp = temp->next;
	}
	printMovieInventory(node->rightChild);
	return;
}

void MovieTree::printMovieInventory() {
	printMovieInventory(root);
	return;
}


// Menu displayed initially, as well as after each user choice     DONE!

void displayMenu() {
	cout << "======Main Menu======\n";
	cout << "1. Find a movie\n";
	cout << "2. Rent a movie\n";
	cout << "3. Print the inventory\n";
	cout << "4. Delete a movie\n";
	cout << "5. Count the movies\n";
	cout << "6. Quit\n";
	return;
}





int main (int argc, char* argv[]) {
	MovieTree Tree;
	ifstream myfile;                          
	myfile.open(argv[2]);  
	string line;
	int x = 1, count;
	if(myfile.is_open()) 
	{
		while(getline(myfile, line)) {
			count = 0;
			MovieNodeLL *newNode = new MovieNodeLL;
			//if (x) {
				string splitline[4];
				// cout << line << endl;
				istringstream ss(line);
				string token;
				count = 0;
				while(getline(ss, token, ',')) {
	   				// cout << token << '\n';
	   				splitline[count] = token;
	   				count++;
				}
				//newNode->ranking = stoi(splitline[0]);
				//newNode->title = splitline[1];
				//char c = newNode->title.at(0);
				//newNode->year = stoi(splitline[2]);
				//newNode->quantity = stoi(splitline[3]);
				//x = 0;
				Tree.addMovieNode(stoi(splitline[0]),splitline[1],stoi(splitline[2]),stoi(splitline[3]));
			//}
			/*else {
				string splitline[4];
				// cout << line << endl;
				istringstream ss(line);
				string token;
				count = 0;
				while(getline(ss, token, ',')) {
	   				// cout << token << '\n';
	   				splitline[count] = token;
	   				count++;
				}
				newNode->ranking = stoi(splitline[0]);
				newNode->title = splitline[1];
				newNode->year = stoi(splitline[2]);
				newNode->quantity = stoi(splitline[3]);
			}
			*/cout << stoi(splitline[0]) << ' ' << splitline[1] << ' ' << stoi(splitline[2]) << ' ' << stoi(splitline[3]) << endl;
		}
	}
	displayMenu();
	int userinput;
	x = 1;
	while (x) {
		cin >> userinput;
		if (userinput == 1) {
			string title;
			cout << "Enter title:\n";
			getline(cin, title, '\n');
			Tree.findMovie(title);
		}
		if (userinput == 2) {
			string title;
			cout << "Enter title:\n";
			getline(cin, title, '\n');
			Tree.rentMovie(title);
		}
		if (userinput == 3) {
			Tree.printMovieInventory();
		}
		if (userinput == 4) {
			string title;
			cout << "Enter title:\n";
			getline(cin, title, '\n');
			Tree.deleteMovieNode(title);
		}
		if (userinput == 5) {
			cout<< "Tree contains: " << Tree.countMovieNodes() << " movies.\n"; 
		}
		if (userinput == 6) {
			cout << "Goodbye!\n";
			return 0;
		}
		displayMenu();
	}
	return 0;
}