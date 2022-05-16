// Header File: Queue_Lnk_T.h
// Author: Antonio F. Huertas
// Date: November 13, 2007
// Purpose: This is the specification file for class template Queue.
//          It uses a linked list to store the items in the queue.

#ifndef QUEUE_H
#define QUEUE_H

// Class template declaration
template <typename ItemType>
class Queue
{
public:
	// Constructor: Creates an empty queue.
	Queue();

	// Copy Constructor: Creates a new queue as a copy of another.
	// Pre: Original queue exists.
	Queue(const Queue& original);
	
	// Observer: Returns true if the queue is empty.
	bool isEmpty() const;

	// Observer: Returns true if the queue is full.
	bool isFull() const;

	// Observer: Returns the front item of the queue.
	// Pre: The queue is not empty.
	ItemType peek() const;
	
	// Transformer: Inserts an item at the rear of the queue.
	// Pre: The queue is not full.
	// Post: The new item is at the rear of the queue.
	void enqueue(ItemType newItem);

	// Transformer: Removes the front item of the queue.
	// Pre: The queue is not empty.
	// Post: The queue does not contains the item.
	void dequeue();

	// Transformer: Overloads assignment operator for the queue.
	// Pre: Right-hand side queue exists.
	// Post: Stack is a deep copy of original queue.
	void operator = (const Queue& rhs);

	// Destructor: Deallocates memory for the the queue.
	~Queue();

private:
	// Definition for the structure of a queue node.
	struct Node
	{
		ItemType info;
		Node* next;
	};
		
	// Attribute: Pointer to front item in queue.
	Node* frontPtr;

	// Attribute: Pointer to rear item in queue.
	Node* rearPtr;

	// Transformer: Makes a deep copy of a queue.
	void copy(const Queue& original);

	// Transformer: Destroys the nodes of the queue.
	void destroy();
};

#include "Queue_Lnk_T.cpp"

#endif