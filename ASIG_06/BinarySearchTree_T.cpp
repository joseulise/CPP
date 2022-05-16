// Source File: BinarySearchTree_T.cpp
// Author: Antonio F. Huertas
// Date: December 2, 2007
// Purpose: Implementation file for class template BinarySearchTree.

// Constructor: Creates an empty binary search tree.
template <class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree()
{
	rootPtr = NULL;
	nodeCount = 0;
}

// Copy Constructor: Creates a new binary search tree as a copy of another.
template <class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(
	const BinarySearchTree& originalTree)
{
	copyHelper(rootPtr, originalTree.rootPtr);
	nodeCount = originalTree.nodeCount;
}

// Observer: Returns the number of nodes in the binary search tree.
template <class ItemType>
int BinarySearchTree<ItemType>::getNodeCount() const
{
	return nodeCount;
}

// Observer: Returns true if the binary search tree is empty.
template <class ItemType>
bool BinarySearchTree<ItemType>::isEmpty() const
{
	return (rootPtr == NULL);
}

// Observer: Returns true if the binary search tree is full.
template <class ItemType>
bool BinarySearchTree<ItemType>::isFull() const
{
	return false;
}

// Observer: Returns true if the binary search tree contains the item.
template <class ItemType>
bool BinarySearchTree<ItemType>::contains(ItemType anItem) const
{
	return containsHelper(rootPtr, anItem);
}

// Observer: Retrieves the stored copy of a given item.
template <class ItemType>
ItemType BinarySearchTree<ItemType>::retrieve(ItemType anItem) const
{
	return retrieveHelper(rootPtr, anItem);
}

// Transformer: Inserts an item into the binary search tree.
template <class ItemType>
void BinarySearchTree<ItemType>::insert(ItemType anItem)
{
	insertHelper(rootPtr, anItem);
	nodeCount ++;
}

// Transformer: Removes an item from the binary search tree.
template <class ItemType>
void BinarySearchTree<ItemType>::remove(ItemType anItem)
{
	removeHelper(rootPtr, anItem);
	nodeCount --;
}

// Transformer: Clears the contents of the binary search tree.
template <class ItemType>
void BinarySearchTree<ItemType>::clear()
{
	destroyHelper(rootPtr);
	rootPtr = NULL;
	nodeCount = 0;
}

// Transformer: Overloads assignment operator for the binary search tree.
template <class ItemType>
void BinarySearchTree<ItemType>::operator = (const BinarySearchTree& rhs)
{
	destroyHelper(rootPtr);
	copyHelper(rootPtr, originalTree.rootPtr);
	nodeCount = originalTree.nodeCount;
}

// Iterator: Resets the binary search tree so it can be traversed.
template <class ItemType>
void BinarySearchTree<ItemType>::reset(TreeOrder traversalOrder)
{
	// Empty traversalQueue, in case it is not already empty.
	while (! traversalQueue.isEmpty())
		traversalQueue.dequeue();
	
	// Enqueue tree nodes using the selected traversal order. 
	switch (traversalOrder)
	{
		case PRE_ORDER  : preorderResetHelper(rootPtr);
            break;
		case IN_ORDER   : inorderResetHelper(rootPtr);
            break;
		case POST_ORDER : postorderResetHelper(rootPtr);
            break;
	}
}

// Iterator: Returns the next item in the binary search tree.
template <class ItemType>
ItemType BinarySearchTree<ItemType>::getNextItem()
{
	ItemType item = traversalQueue.peek();
	traversalQueue.dequeue();
	return item;
}

// Destructor: Deallocates memory for the the binary search tree.
template <class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree()
{
	destroyHelper(rootPtr);
}

// ************************  RECURSIVE PRIVATE METHODS **********************
template <class ItemType>
void BinarySearchTree<ItemType>::copyHelper(TreeNode*& treePtr, 
					 TreeNode* originalTreePtr)

{
	if (originalTreePtr == NULL)
		treePtr = NULL;
	else
	{
		treePtr = new TreeNode;
		treePtr->info = originalTreePtr->info;		
		copyHelper(treePtr->left, originalTreePtr->left);
		copyHelper(treePtr->right, originalTreePtr->right);
	}
}

template <class ItemType>
void BinarySearchTree<ItemType>::destroyHelper(TreeNode*& treePtr)
{
	if (treePtr != NULL)
	{
		destroyHelper(treePtr->left);
		destroyHelper(treePtr->right);
		delete treePtr;
	}
}

template <class ItemType>
bool BinarySearchTree<ItemType>::containsHelper(TreeNode* treePtr,
						ItemType anItem) const
{
	if (treePtr == NULL)
		return false;
	else if (anItem == treePtr->info)
		return true;
	else if (anItem < treePtr->info)
		return containsHelper(treePtr->left, anItem);
	else
		return containsHelper(treePtr->right, anItem);
}

template <class ItemType>
ItemType BinarySearchTree<ItemType>::retrieveHelper(TreeNode* treePtr,
						ItemType anItem) const
{
	if (anItem == treePtr->info)
		return treePtr->info;
	else if (anItem < treePtr->info)
		return retrieveHelper(treePtr->left, anItem);
	else
		return retrieveHelper(treePtr->right, anItem);
}

template <class ItemType>
void BinarySearchTree<ItemType>::insertHelper(TreeNode*& treePtr,
						ItemType anItem)
{
	if (treePtr == NULL)
	{
		treePtr = new TreeNode;
		treePtr->left = NULL;
		treePtr->info = anItem;
		treePtr->right = NULL;
	}
	else if (anItem < treePtr->info)
		insertHelper(treePtr->left, anItem);
	else
        insertHelper(treePtr->right, anItem);
}

template <class ItemType>
void BinarySearchTree<ItemType>::removeHelper(TreeNode*& treePtr,
						ItemType anItem)
{
	if (anItem == treePtr->info)
		deleteANode(treePtr);
	else if (anItem < treePtr->info)
		removeHelper(treePtr->left, anItem);
	else
		removeHelper(treePtr->right, anItem);
}

template <class ItemType>
void BinarySearchTree<ItemType>::preorderResetHelper(TreeNode* treePtr)
{
	if (treePtr != NULL)
	{
		traversalQueue.enqueue(treePtr->info);
		preorderResetHelper(treePtr->left);
		preorderResetHelper(treePtr->right);
	}
}

template <class ItemType>
void BinarySearchTree<ItemType>::inorderResetHelper(TreeNode* treePtr)
{
	if (treePtr != NULL)
	{
		inorderResetHelper(treePtr->left);
		traversalQueue.enqueue(treePtr->info);
		inorderResetHelper(treePtr->right);
	}
}

template <class ItemType>
void BinarySearchTree<ItemType>::postorderResetHelper(TreeNode* treePtr)
{
	if (treePtr != NULL)
	{
		postorderResetHelper(treePtr->left);
		postorderResetHelper(treePtr->right);
		traversalQueue.enqueue(treePtr->info);
	}
}

// ***************** Auxiliary Functions for removeHelper *******************
template <class ItemType>
void BinarySearchTree<ItemType>::deleteANode(TreeNode*& treePtr)
{
	TreeNode* tempPtr = treePtr;

	if (treePtr->left == NULL)	// Node doesn't have left child
	{
		treePtr = treePtr->right;
		delete tempPtr;
	}
	else if (treePtr->right == NULL) // Node doesn't have right child
	{
		treePtr = treePtr->left;
		delete tempPtr;
	}
	else	// Node has two children
	{
		ItemType data = getSuccessor(treePtr->right);
		treePtr->info = data;
		removeHelper(treePtr->right, data);
	}
}

template <class ItemType>
ItemType BinarySearchTree<ItemType>::getSuccessor(TreeNode* treePtr)
{
	while (treePtr->left != NULL)
		treePtr = treePtr->left;
	return treePtr->info;
}