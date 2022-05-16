// Header File: Stack_Lnk_T.cpp
// Author: Antonio F. Huertas
// Date: November 13, 2007
// Purpose: This is the implementation file for class template Stack.
//          It uses a linked list to store the items in the stack.

#include <cstddef>		// contains definition of NULL

// Constructor: Creates an empty stack.
template <typename ItemType>
Stack<ItemType>::Stack()
{
	topPtr = NULL;
}

// Copy Constructor: Creates a new Stack as a copy of another.
template <typename ItemType>
Stack<ItemType>::Stack(const Stack<ItemType>& original)
{
	copy(original);
}

// Observer: Returns true if the stack is empty.
template <typename ItemType>
bool Stack<ItemType>::isEmpty() const
{
	return (topPtr == NULL);
}

// Observer: Returns true if the stack is full.
template <typename ItemType>
bool Stack<ItemType>::isFull() const
{
	return false;
}

// Observer: Returns the item on top of the stack.
template <typename ItemType>
ItemType Stack<ItemType>::peek() const
{
	return topPtr->info;
}

// Transformer: Inserts an item on top of the stack.
template <typename ItemType>
void Stack<ItemType>::push(ItemType newItem)
{
	Node* tempPtr;

	tempPtr = new Node;
	tempPtr->info = newItem;
	tempPtr->next = topPtr;
	topPtr = tempPtr;
}

// Transformer: Removes the item on top of the stack.
template <typename ItemType>
void Stack<ItemType>::pop()
{
	Node* tempPtr;

	tempPtr = topPtr;
	topPtr = topPtr->next;
	delete tempPtr;
}

// Transformer: Overloads assignment operator for the stack.
template <typename ItemType>
void Stack<ItemType>::operator = (const Stack& rhs)
{
	destroy();
	copy(rhs);
}

// Destructor: Deallocates memory for the the stack.
template<typename ItemType>
Stack<ItemType>::~Stack()
{
	destroy();
}

// Transformer: Makes a deep copy of a stack.
template<typename ItemType>
void Stack<ItemType>::copy(const Stack& original)
{
	if (original.topPtr == NULL)
		topPtr = NULL;
	else
	{
		// Copy first node.
		topPtr = new Node;
		topPtr->info = original.topPtr->info;

		// Copy rest of the stack.
		Node* copyPtr;	// Pointer to current node in copy stack
		Node* origPtr;	// Pointer to current node in original stack
				
		copyPtr = topPtr;
		origPtr = original.topPtr->next;
		while (origPtr != NULL)
		{
			copyPtr->next = new Node;
			copyPtr = copyPtr->next;
			copyPtr->info = origPtr->info;

			origPtr = origPtr->next;
		}

		copyPtr->next = NULL;
	}
}

// Transformer: Destroys the nodes of the stack.
template<typename ItemType>
void Stack<ItemType>::destroy()
{
	Node* tempPtr;

	while (topPtr != NULL)
	{
		tempPtr = topPtr;
		topPtr = topPtr->next;
		delete tempPtr;
	}
}
