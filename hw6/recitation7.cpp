#include <iostream>
#include "recitation7.h"
using namespace std;
/**
Create a node with key as data
**/
node* BST:: createNode(int data)
{
    node* nn = new node;
    nn->key = data;
    nn->left = nullptr;
    nn->right = nullptr;
    nn->parent = nullptr;
    return nn;
}

BST::BST()
{

}
/**
parameterized constructor. It will create the root and put the data in the root.
**/
BST::BST(int data)
{
    root = createNode(data);
}
/**
Destructor
**/
 BST::~BST(){

     destroyNode(root);

 }
/**
This function will destroy the subtree rooted at curNode.
Think about in what order should you destroy.
**/
 void BST:: destroyNode(node *curNode){
     if(root)
     {
         destroyNode(root->left);
         destroyNode(root->right);
         delete root;
         root = nullptr;
     }
 }

/** This function will search the data in a tree rooted at root
    We will call this function from searchKey.
    NOTE: As root is a private member of BST class, main function can not access root.
    So we need this helper function.
**/
 bool BST::searchKeyHelper(node* root, int data) {
    node * temp = root;
    if (data == root->key) return true;
    while (temp) {
        if (temp->key == data) return true;
        if (temp->key < data) { 
            temp = temp->right;
        }
        else {
            temp = temp->left;
        }
    }
    return false; 
 }
/**
This function will search the data in the tree
**/
bool BST::searchKey(int data){
    return searchKeyHelper(root, data);
}

/**
This function will add the data in the tree rooted at curNode.
We will call this function from insertNode.
NOTE: root is a private member of BST. As root is a private member of BST class, main function can not access root.
      So we need this helper function. Implement your code for inserting a node in this function.
**/
 node* BST:: insertNodeHelper(node* curNode, int data){
    if (!root) { 
        root = curNode;
    }
    node *temp = root;
    node *prev; 
    while (temp) {
        if (temp->key == data) {
            curNode = temp;
            return curNode;
        }
        if (temp->key > data) {
            prev = temp;
            temp = temp->left;
        }
        else {
            prev = temp;
            temp = temp->right;
        }   
    }
    curNode->parent = prev;
    curNode->key = data;
    if (prev->key > data) {
        prev->left = curNode;
    }
    else {
        prev->right = curNode;
    }
    return curNode;
 }

 node* BST:: insertNodeHelper(node* curNode, int data){
   while(curNode)
   {
        if(curNde->key>data)
        {
            prev = curNode;
            curNode = curNode->left;
        }
        else if()
   }
    if(prev->key>data)
        prev->left = createNode(data);
    else if()
    
 }

 node* BST:: insertNodeHelper(node* curNode, int data){
    if(curNode == nullptr)
        return createNode(data);
    if(curNode->key >data)
        curNode->left = insertNode(curNode->left,data);
    else if(curNode->key < data)
        curNode-right = insertNode(curNode->right, data);
    return curNode;
    
 }

/**
This function will insert the data in the tree. As this function can not access the root
it will call the insertNodeHelper function.
**/
void BST:: insertNode( int data){
    if(root == NULL) // if the BST is empty create the root
        root = createNode(data);
    else // insert the data in the tree rooted at root
        insertNodeHelper(root, data);
}

/** This function will traverse the tree in-order and print out the node elements.
printTree() function will call this function.
NOTE: As root is a private member of BST class, main function can not access root. So printTree will
call this helper function.
**/
 void BST:: printTreeHelper(node* curNode){
     if(curNode)
     {
            printTreeHelper( curNode->left);
            cout << " "<< curNode->key;
            printTreeHelper( curNode->right);
     }
 }

 void BST:: printTree(){
     printTreeHelper(root);
 }

 int main() {
    BST A(5);
    cout << "n";
    A.insertNode(4);
    A.insertNode(3);
    A.insertNode(6);
    A.insertNode(7);
    cout << "n";
    A.printTree();
    cout << "n";
    bool found = A.searchKey(4);
    cout << "4 found? " << found << endl;
    found = A.searchKey(8);
    cout << "8 found? " << found << endl;
    A.insertNode(1);
    A.printTree();
    A.insertNode(9);
    A.printTree();
    return 0;
 }
