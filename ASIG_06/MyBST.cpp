// MyBST.cpp
// By Antonio F. Huertas and <your name>
// Date: <the date>
// This is the implementation file of a simple binary search tree of 
// integers ADT.  It uses helper recursive methods in all methods
// that need to traverse the tree.

#include "MyBST.h"
#include <cstddef>
using namespace std;

// Auxiliary function needed by greaterHelper().
// NOTE: This function IS NOT a member of class MyBST.
int maximum(int n1, int n2)
{
	return (n1 > n2)? n1 : n2;
}

// ****************************** PUBLIC METHODS ****************************

// This method creates an empty BST.
MyBST::MyBST()
{
	rootPtr = NULL;
}

// This method computes the count of the BST.
int MyBST::count() const
{
	return countHelper(rootPtr);
}

// This method computes the sum of the elements of the BST.
int MyBST::sum() const
{
	return sumHelper(rootPtr);
}

// This method computes the maximum of the elements of the BST.
int MyBST::max() const
{
	return maxHelper(rootPtr);
}

// This method determines if the BST contains the value.
bool MyBST::contains(int aValue) const
{
	return containsHelper(rootPtr, aValue);
}

// This method displays the contents of the BST using inorder traversal.
void MyBST::displayInorder() const
{
	displayInorderHelper(rootPtr);
}

// This method inserts a value in the BST.
void MyBST::insert(int aValue)
{
	insertHelper(rootPtr, aValue);
}

// This methods destroys the BST.
MyBST::~MyBST()
{
	destructorHelper(rootPtr);
}

// ************************  RECURSIVE PRIVATE METHODS **********************

// This method recursively computes the count of the BST.
int MyBST::countHelper(TreeNode* treePtr) const
{
	if(treePtr==NULL)
		return 0;						// COMPLETE THIS METHOD
	else
		return (1 + (countHelper(treePtr->right))+(countHelper(treePtr->left)));
}

// This method recursively computes the sum of the elements of the BST.
int MyBST::sumHelper(TreeNode* treePtr) const
{
	if(treePtr==NULL)
		return 0;						// COMPLETE THIS METHOD
	else
		return (treePtr->item+(sumHelper(treePtr->left))+(sumHelper(treePtr->right)));//RAIZ IZQ DER
}

// This method recursively computes the maximum of the elements of the BST.
int MyBST::maxHelper(TreeNode* treePtr) const
{
	if(treePtr==NULL)
		return 0;
	else if(treePtr->item > maxHelper(treePtr->right))
		return treePtr->item;
		// COMPLETE THIS METHOD
}

// This method recursively determines if the BST contains the value.
bool MyBST::containsHelper(TreeNode* treePtr, int aValue) const
{
	if (treePtr == NULL)
		return false;
	else if (aValue == treePtr->item)
		return true;
	else if (aValue < treePtr->item)
		return containsHelper(treePtr->left, aValue);
	else
		return containsHelper(treePtr->right, aValue);
}

// This method recursively displays the contents of the BST.
// The base case is when treePtr == NULL.  Since nothing needs to
// be done in this case, we only need to check for the recursive
// case.
void MyBST::displayInorderHelper(TreeNode* treePtr) const
{
	if (treePtr != NULL)
	{
		displayInorderHelper(treePtr->left);			// display left subtree
		cout << treePtr->item << " ";					// display item
		displayInorderHelper(treePtr->right);			// display right subtree
	}
}

// This method recursively inserts a value in the BST.
void MyBST::insertHelper(TreeNode*& treePtr, int aValue)
{
	if (treePtr == NULL)								// insert item as a leaf
	{
		treePtr = new TreeNode;
		treePtr->left = NULL;
		treePtr->item = aValue;
		treePtr->right = NULL;
	}
	else if (aValue < treePtr->item)					// search left subtree
		insertHelper(treePtr->left, aValue);
	else												// search right subtree because
        insertHelper(treePtr->right, aValue);			// aValue > treePtr->item
}

// This methods recursively destroys the BST.
void MyBST::destructorHelper(TreeNode*& treePtr)
{
	if (treePtr != NULL)
	{
		destructorHelper(treePtr->left);				// destroy left subtree
		destructorHelper(treePtr->right);				// destroy right subtree
		delete treePtr;									// destroy node
	}
}