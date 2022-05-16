// MyBST.h
// By Antonio F. Huertas
// This is the specification file of a simple binary search tree of 
// integers ADT.  It uses helper recursive methods in all methods
// that need to traverse the tree.
#ifndef MYBST.H
#define MYBST.H
#include <iostream>
#include <cstddef>				// for NULL
using namespace std;

// Declaration of class MyBST.
class MyBST
{
public:
	MyBST();
	int count() const;
	int sum() const;
	int max() const;
	bool contains(int aValue) const;
	void displayInorder() const;
	void insert(int aValue);
	~MyBST();
private:
	// Definition of a tree TreeNode
	struct TreeNode
	{
		TreeNode* left;
		int item;
		TreeNode* right;
	};

	// Attributes
	TreeNode* rootPtr;				// Pointer to root TreeNode

	// Helper methods.
	int countHelper(TreeNode* treePtr) const;
	int sumHelper(TreeNode* treePtr) const;
	int maxHelper(TreeNode* treePtr) const;
	bool containsHelper(TreeNode* treePtr, int aValue) const;
	void displayInorderHelper(TreeNode* treePtr) const;
	void insertHelper(TreeNode*& treePtr, int aValue);
	void destructorHelper(TreeNode*& treePtr);
};

#endif