// Header File: Stack_Lnk_T.h
// Author: Antonio F. Huertas
// Date: November 13, 2007
// Purpose: This is the specification file for class template Stack.
//          It uses a linked list to store the items in the stack.

#ifndef STACK_H
#define STACK_H

// Class template declaration
template <typename ItemType>
class Stack
{
public:
	// Constructor: Creates an empty stack.
	Stack();

	// Copy Constructor: Creates a new Stack as a copy of another.
	// Pre: Original Stack exists.
	Stack(const Stack& original);
	
	// Observer: Returns true if the stack is empty.
	bool isEmpty() const;

	// Observer: Returns true if the stack is full.
	bool isFull() const;

	// Observer: Returns the item on top of the stack.
	// Pre: The stack is not empty.
	ItemType peek() const;

	// Transformer: Inserts an item on top of the stack.
	// Pre: The stack is not full.
	// Post: The new item is at the top of the stack.
	void push(ItemType newItem);

	// Transformer: Removes the item on top of the stack.
	// Pre: The stack is not empty.
	// Post: The stack does not contains the item.
	void pop();

	// Transformer: Overloads assignment operator for the stack.
	// Pre: Right-hand side stack exists.
	// Post: Stack is a deep copy of original Stack.
	void operator = (const Stack& rhs);

	// Destructor: Deallocates memory for the the stack.
	~Stack();

private:
	// Definition for the structure of a stack node.
	struct Node
	{
		ItemType info;
		Node* next;
	};
		
	// Attribute: Pointer to top item in stack
	Node* topPtr;

	// Transformer: Makes a deep copy of a stack.
	void copy(const Stack& original);

	// Transformer: Destroys the nodes of the stack.
	void destroy();
};

#include "Stack_Lnk_T.cpp"

#endif