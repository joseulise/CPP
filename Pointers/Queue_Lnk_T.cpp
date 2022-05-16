// Header File: Queue_Lnk_T.cpp
// Author: Antonio F. Huertas
// Date: November 13, 2007
// Purpose: This is the implementation file for class template Queue.
//          It uses a linked list to store the items in the queue.

#include <cstddef>  // for NULL

// Constructor: Creates an empty queue.
template<class ItemType>
Queue<ItemType>::Queue()
{
	frontPtr = NULL;
	rearPtr = NULL;
}

// Copy Constructor: Creates a new queue as a copy of another.
template<class ItemType>
Queue<ItemType>::Queue(const Queue<ItemType>& original)
{
	copy(original);
}

// Observer: Returns true if the queue is empty.
template<class ItemType>
bool Queue<ItemType>::isEmpty() const
{
	return (frontPtr == NULL);
}

// Observer: Returns true if the queue is full.
template<class ItemType>
bool Queue<ItemType>::isFull() const
{
	return false;
}

// Observer: Returns the front item of the queue.
template<class ItemType>
ItemType Queue<ItemType>::peek() const
{
	return frontPtr->info;
}

// Transformer: Inserts an item at the rear of the queue.
template<class ItemType>
void Queue<ItemType>::enqueue(ItemType newItem)
{
	Node* tempPtr;

	tempPtr = new Node;
	tempPtr->info = newItem;
	tempPtr->next = NULL;

	if (frontPtr == NULL)
		frontPtr = tempPtr;
	else
		rearPtr->next = tempPtr;

	rearPtr = tempPtr;
}

// Transformer: Removes the front item of the queue.
template<class ItemType>
void Queue<ItemType>::dequeue()
{
	Node* tempPtr;

	tempPtr = frontPtr;
	frontPtr = frontPtr->next;

	if (frontPtr == NULL)
		rearPtr = NULL;

	delete tempPtr;
}

// Transformer: Overloads assignment operator for the queue.
template<class ItemType>
void Queue<ItemType>::operator = (const Queue& rhs)
{
	destroy();
	copy(rhs);
}

// Destructor: Deallocates memory for the the queue.
template<class ItemType>
Queue<ItemType>::~Queue()
{
	destroy();
}

// Transformer: Makes a deep copy of a queue.
template<class ItemType>
void Queue<ItemType>::copy(const Queue& original)
{
	if (original.frontPtr == NULL)
		frontPtr = NULL;
	else
	{
		// Copy the first node
		frontPtr = new Node;
		frontPtr->info = original.frontPtr->info;

		// Copy rest of the queue
		Node* copyPtr;	// Pointer to current node in copy queue
		Node* origPtr;	// Pointer to current node in original queue

		copyPtr = frontPtr;
		origPtr = original.frontPtr->next;
		while (origPtr != NULL)
		{
			copyPtr->next = new Node;
			copyPtr = copyPtr->next;
			copyPtr->info = origPtr->info;

			origPtr = origPtr->next;
		}

		copyPtr->next = NULL;
		rearPtr = copyPtr;
	}
}

// Transformer: Destroys the nodes of the queue.
template<class ItemType>
void Queue<ItemType>::destroy()
{
	Node* tempPtr;

	while (frontPtr != NULL)
	{
		tempPtr = frontPtr;
		frontPtr = frontPtr->next;
		delete tempPtr;
	}
	rearPtr = NULL;
}