// MyLinkedList.cpp
// By Antonio F. Huertas
// This is the specification file of a simple linked list of integers ADT.
// It uses helper recursive methods in all methods that need to traverse
// the list.

#include "MyLinkedList.h"


// Auxiliary function needed by greaterHelper().
// NOTE: This function IS NOT a member of class HomeworkBST.
int maximum(int n1, int n2)
{
	return (n1 > n2)? n1 : n2;	// return n1 if n1 > n2; otherwise, return n2
}

// ****************************** PUBLIC METHODS ****************************

// This method creates an empty linked list.
MyLinkedList::MyLinkedList()
{
	firstPtr = NULL;
}

// This method computes the length of the linked list.
int MyLinkedList::length() const
{
	return lengthHelper(firstPtr);
}

// This method computes the sum of the elements of the linked list.
int MyLinkedList::sum() const
{
	return sumHelper(firstPtr);
}

// This method computes the maximum of the elements of the linked list.
int MyLinkedList::max() const
{
	return maxHelper(firstPtr);
}

// This method determines if the linked list contains the value.
bool MyLinkedList::contains(int aValue) const
{
	return containsHelper(firstPtr, aValue);
}

// This method displays the contents of the linked list.
void MyLinkedList::display() const
{
	displayHelper(firstPtr);
}

// This method inserts a value in the linked list.
void MyLinkedList::insert(int aValue)
{
	insertHelper(firstPtr, aValue);
}

// This method removes a value from the linked list.
void MyLinkedList::remove(int aValue)
{
	removeHelper(firstPtr, aValue);
	
}

// This methods destroys the linked list.
MyLinkedList::~MyLinkedList()
{
	destructorHelper(firstPtr);
}

// ************************  RECURSIVE PRIVATE METHODS **********************

// This method recursively computes the length of the linked list.
int MyLinkedList::lengthHelper(Node* listPtr) const
{
	if (listPtr == NULL)
		return 0;
	else
		return 1 + lengthHelper(listPtr->next);
}

// This method recursively computes the sum of the elements of the
// linked list.
int MyLinkedList::sumHelper(Node* listPtr) const
{
	if (listPtr == NULL)
		return 0;
	else
		return listPtr->item + sumHelper(listPtr->next);
}

// This method recursively computes the maximum of the elements of the
// linked list.
int MyLinkedList::maxHelper(Node* listPtr) const
{
	if(listPtr==NULL)//listPtr==NULL)
		return 0;//case base
	else if(listPtr->item > maxHelper(listPtr->next))
			return listPtr->item;
}

// This method recursively determines if the linked list contains the value.
bool MyLinkedList::containsHelper(Node* listPtr, int aValue) const
{
	if(listPtr==NULL)
		return false;
	if(listPtr->item==aValue)
		return true;
	else
		containsHelper(listPtr->next, aValue);
						// COMPLETE THIS METHOD
}

// This method recursively displays the contents of the linked list.
// The base case is when listPtr == NULL.  Since nothing needs to
// be done in this case, we only need to check for the recursive
// case.
void MyLinkedList::displayHelper(Node* listPtr) const
{
	if (listPtr != NULL)
	{
		cout << listPtr->item << " ";
		displayHelper(listPtr->next);
	}
}

// This method recursively inserts a value in the linked list.
void MyLinkedList::insertHelper(Node*& listPtr, int aValue)
{
	if (listPtr == NULL || aValue < listPtr->item)
	{
		Node* tempPtr = listPtr;

		listPtr = new Node;
		listPtr->item = aValue;
		listPtr->next = tempPtr;
	}
	else
		insertHelper(listPtr->next, aValue);
}

// This method recursively removes a value from the linked list.
void MyLinkedList::removeHelper(Node*& listPtr, int aValue)
{
	if (aValue == listPtr->item)
	{
		Node* tempPtr = listPtr;
		listPtr = listPtr->next;
		delete tempPtr;
	}
	else
		removeHelper(listPtr->next, aValue);
}

// This methods recursively destroys the linked list.
void MyLinkedList::destructorHelper(Node*& listPtr)
{
	if (listPtr != NULL)
	{
		destructorHelper(listPtr->next);
		delete listPtr;
	}
}
