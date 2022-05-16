// RecursiveLinkedList.h
// By Antonio F. Huertas
// This is the specification and implementation of a simple
// linked list of integers ADT.  It uses helper recursive methods
// in all methods that need to traverse the list.

#ifndef RECURSIVELIST_H
#define RECURSIVELIST_H

#include <iostream>
#include <cstddef>				// for NULL
using namespace std;

class RecursiveLinkedList
{
public:
	RecursiveLinkedList();
	int length() const;
	int sum() const;
	void display() const;
	void displayReverse() const;
	void insertAtFront(int aValue);
	~RecursiveLinkedList();
private:
	struct Node
	{
		int item;
		Node* next;
	};

	// Atribute: Pointer to the first node.
	Node* firstPtr;

	// Helper recursive methods.
	int lengthHelper(Node* listPtr) const;
	int sumHelper(Node* listPtr) const;
	void displayHelper(Node* listPtr) const;
	void displayReverseHelper(Node* listPtr) const;
	void destructorHelper(Node*& listPtr);
};

// ****************************** PUBLIC METHODS ****************************

// This method creates an empty linked list.
RecursiveLinkedList::RecursiveLinkedList()
{
	firstPtr = NULL;
}

// This method computes the length of the linked list.
int RecursiveLinkedList::length() const
{
	return lengthHelper(firstPtr);
}

// This method computes the sum of the elements of the linked list.
int RecursiveLinkedList::sum() const
{
	return sumHelper(firstPtr);
}

// This method displays the contents of the linked list.
void RecursiveLinkedList::display() const
{
	displayHelper(firstPtr);
}

// This method displays the contents of the linked list, in reverse order.
// NOTE: No stack is needed in this version!!!
void RecursiveLinkedList::displayReverse() const
{
	displayReverseHelper(firstPtr);
}

// This method inserts a value at the front of the linked list.
void RecursiveLinkedList::insertAtFront(int aValue)
{
	Node* tempPtr;

	tempPtr = new Node;
	tempPtr->item = aValue;
	tempPtr->next = firstPtr;
	firstPtr = tempPtr;
}

// This methods destroys the linked list.
RecursiveLinkedList::~RecursiveLinkedList()
{
	destructorHelper(firstPtr);
}

// ************************  RECURSIVE PRIVATE METHODS **********************

// This method recursively computes the length of the linked list.
int RecursiveLinkedList::lengthHelper(Node* listPtr) const
{
	if (listPtr == NULL)
		return 0;
	else
		return 1 + lengthHelper(listPtr->next);
}

// This method recursively computes the sum of the elements of the
// linked list.
int RecursiveLinkedList::sumHelper(Node* listPtr) const
{
	if (listPtr == NULL)
		return 0;
	else
		return listPtr->item + sumHelper(listPtr->next);
}

// This method recursively displays the contents of the linked list.
void RecursiveLinkedList::displayHelper(Node* listPtr) const
{
	if (listPtr == NULL)
		;		// do nothing
	else
	{
		cout << listPtr->item << " ";
		displayHelper(listPtr->next);
	}
}

// This method recursively displays the contents of the linked list,
// in reverse order.
// NOTE: Look mom, no stack!!!
void RecursiveLinkedList::displayReverseHelper(Node* listPtr) const
{
	if (listPtr == NULL)
		;		// do nothing
	else
	{
		displayReverseHelper(listPtr->next);
		cout << listPtr->item << " ";
	}
}

// This methods recursively destroys the linked list.
// The base case is when listPtr == NULL.  Since nothing needs to
// be done in this case, we only need to check for the recursive
// case.
void RecursiveLinkedList::destructorHelper(Node*& listPtr)
{
	if (listPtr != NULL)
	{
		destructorHelper(listPtr->next);
		delete listPtr;
	}
}

#endif
