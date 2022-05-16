// SimpleLinkedList.h
// By Antonio F. Huertas
// This is the specification and implementation of a simple
// linked list of integers ADT.

#ifndef SIMPLELIST_H
#define SIMPLELIST_H

#include "Stack_Lnk_T.h"

#include <iostream>
#include <cstddef>				// for NULL
using namespace std;

class SimpleLinkedList
{
public:
	SimpleLinkedList();
	void insertAtFront(int aValue);
	int length() const;
	int sum() const;
	void display() const;
	void displayReverse() const;
	~SimpleLinkedList();
private:
	struct Node
	{
		int item;
		Node* next;
	};

	// Atribute: Pointer to the first node.
	Node* firstPtr;
};

// This method creates an empty linked list.
SimpleLinkedList::SimpleLinkedList()
{
	firstPtr = NULL;
}

// This method inserts a value at the front of the linked list.
void SimpleLinkedList::insertAtFront(int aValue)
{
	Node* tempPtr;

	tempPtr = new Node;
	tempPtr->item = aValue;
	tempPtr->next = firstPtr;
	firstPtr = tempPtr;
}

// This method computes the length of the linked list.
int SimpleLinkedList::length() const
{
	int count = 0;
	Node* tempPtr = firstPtr;

	while (tempPtr != NULL)
	{
		count ++;
		tempPtr = tempPtr->next;
	}

	return count;
}

// This method computes the sum of the elements of the linked list.
int SimpleLinkedList::sum() const
{
	int total = 0;
	Node* tempPtr = firstPtr;

	while (tempPtr != NULL)
	{
		total = total + tempPtr->item;
		tempPtr = tempPtr->next;
	}

	return total;
}

// This method displays the contents of the linked list.
void SimpleLinkedList::display() const
{
	Node* tempPtr = firstPtr;

	while (tempPtr != NULL)
	{
		cout << tempPtr->item << " ";
		tempPtr = tempPtr->next;
	}
}

// This method displays the contents of the linked list, in reverse order.
// NOTE: This method requires a temporary stack.
void SimpleLinkedList::displayReverse() const
{
	Stack<int> tempStack;
	Node* tempPtr = firstPtr;

	while (tempPtr != NULL)
	{
		tempStack.push(tempPtr->item);
		tempPtr = tempPtr->next;
	}

	while (! tempStack.isEmpty())
	{
		cout << tempStack.peek() << " ";
		tempStack.pop();
	}
}

// This methods destroys the linked list.
SimpleLinkedList::~SimpleLinkedList()
{
	Node* tempPtr;

	while (firstPtr != NULL)
	{
		tempPtr = firstPtr;
		firstPtr = firstPtr->next;
		delete tempPtr;
	}
}

#endif
