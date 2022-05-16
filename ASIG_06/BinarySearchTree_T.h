// Header File: BinarySearchTree_T.h
// Author: Antonio F. Huertas
// Date: December 2, 2007
// Purpose: Specification file for class template BinarySearchTree.

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "Queue_Lnk_T.h"		// for the traversal Queue

// Enumerated type for tree traversal order
enum TreeOrder {PRE_ORDER, IN_ORDER, POST_ORDER};

template <typename ItemType>
class BinarySearchTree
{
public:
	// Constructor: Creates an empty binary search tree.
	// Post: The length is 0.
	BinarySearchTree();

	// Copy Constructor: Creates a new binary search tree as a copy of another.
	// Pre: Original binary search tree exists.
	BinarySearchTree(const BinarySearchTree& originalTree);

	// Observer: Returns the number of nodes in the binary search tree.
	int getNodeCount() const;

	// Observer: Returns true if the binary search tree is empty.
	bool isEmpty() const;

	// Observer: Returns true if the binary search tree is full.
	bool isFull() const;

	// Observer: Returns true if the binary search tree contains the item.
	bool contains(ItemType anItem) const;

	// Observer: Retrieves the stored copy of a given item.
	// Pre: The binary search tree is not empty and contains the item.
	ItemType retrieve(ItemType anItem) const;

	// Transformer: Inserts an item into the binary search tree.
	// Pre: The binary search tree is not full and does not contain the item.
	// Post: The binary search tree contains the item and count is increased
	//       by 1.
	void insert(ItemType anItem);

	// Transformer: Removes an item from the binary search tree.
	// Pre: The binary search tree is not empty and contains the item.
	// Post: The binary search tree no longer contains the item and count
	//       is decreased by 1.
	void remove(ItemType anItem);

	// Transformer: Clears the contents of the binary search tree.
	// Post: The binary search tree is empty.
	void clear();

	// Transformer: Overloads assignment operator for the binary search tree.
	// Pre: Right-hand side binary search tree exists.
	// Post: binary search tree is a deep copy of original binary search tree.
	void operator = (const BinarySearchTree& rhs);

	// Iterator: Resets the binary search tree so it can be traversed.
	// Post: The current position is before the first item in the binary
	//       search tree.
	void reset(TreeOrder traversalOrder);

	// Iterator: Returns the next item in the binary search tree.
	// Pre: This binary search tree has been reset and item in current position
	//      is not the last one.
	// Post: The current position is updated to the next item in the binary search
	//       tree.
	ItemType getNextItem();

	// Destructor: Deallocates memory for the the binary search tree.
	~BinarySearchTree();

private:
	// Definition for the structure of a binary search tree node.
	struct TreeNode
	{
		TreeNode* left;
		ItemType info;
		TreeNode* right;
	};
		
	// Attribute: Pointer to the root in binary search tree
	TreeNode* rootPtr;

	// Attribute: Number of nodes in binary search tree
	int nodeCount;

	// Atribute: Auxiliary Queue for traversal
	Queue<ItemType> traversalQueue;

	// Auxiliary functions
	void copyHelper(TreeNode*& treePtr, TreeNode* originalTreePtr);
	void destroyHelper(TreeNode*& treePtr);

	bool containsHelper(TreeNode* treePtr, ItemType anItem) const;
	ItemType retrieveHelper(TreeNode* treePtr, ItemType anItem) const;

	void insertHelper(TreeNode*& treePtr, ItemType anItem);
	void removeHelper(TreeNode*& treePtr, ItemType anItem);

	void preorderResetHelper(TreeNode* treePtr);
	void inorderResetHelper(TreeNode* treePtr);
	void postorderResetHelper(TreeNode* treePtr);
		
	// Auxiliary functions for removeHelper
	void deleteANode(TreeNode*& treePtr);
	ItemType getSuccessor(TreeNode* treePtr);
};

#include "BinarySearchTree_T.cpp"

#endif
