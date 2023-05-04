/* RedBlackTree.cpp
* Source file for RedBlackTree
*
*
* RedBlackTree.cpp
* Name: Joubert Marion O. Trias
* Account number: cs1257
* Class Section: CS 210-07
* Date: 9 December 2022
* 
*/

#include "RedBlackTree.h"

// Default constructor for RedBlackTree
RedBlackTree::RedBlackTree() {
   root = nullptr;
}

//Inserts a value into the tree and performs the necessary balancing
void RedBlackTree::add(int value) {
   Node* node = new Node(value);

   //Main Insertion algorithm
   //Insert if tree is empty
   if(root == nullptr) {
      root = node;
   }

   //Else Insert values into the tree from left to right
   else {

   }

   //Balance the tree somehow

}

//Removes a value from the tree if present and performs the necessary balancing
void RedBlackTree::remove(int value) {
   //Prepare the node/value for removal
   //May/May not have to prepare for every case


   //Actual Remove Algorithm

   
   //After removal, tree must be rebalanced somehow
}

//Returns true if the tree contains the specified value
bool RedBlackTree::contains(int value) {
  Node* currNode = get(value);
  bool flag = false;
  
   /*
  if(value == currNode->val){
      flag = true;
  }
   */
  return flag;
}

//Returns Node containing specified value
Node* RedBlackTree:: get(int value) {
   Node* currNode = root;

   while (currNode != nullptr) {
      if (currNode->val == value) {
         return currNode;
      }
      //Go the left to find the value
      else if (value < currNode->val) {
         //Reiterates the function until it hits nullptr or found
         currNode = currNode->left;
         }
         else {
            //Go to the right to find the value
            currNode = currNode->right;
         }
   }
   //Return nullptr if not found
   return nullptr;
}

// Helper Methods
// You may remove these methods or add more if needed

//Rotate node to the left
void leftRotate(Node* x) {
   //Start to rotate 
   if (x->parent) {
      x->parent;
   }
   else {

   }
}

//Rotate node to the right
void rightRotate(Node* x) {
   //Start to rotate 
   if (x->parent) {
      x->parent;
   }
   else {

   }
}

//Fixes/Balances red on red nodes
void fixRedRed(Node* x) {

}

//Fixes/Balances black on black nodes
void fixBlackBlack(Node* x) {

}
