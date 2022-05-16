// Header File: Stack_Arr_T.h
// Author: Antonio F. Huertas
// Date: October 22, 2007
// Purpose: This is the specification file for class template Stack.
//          It uses and array to store the items in the stack.

#ifndef STACK_H
#define STACK_H

// Maximum number of items allowed in the stack.
const int MAX_STACK_SIZE = 10;

template <typename ItemType>
class Stack
{
public:
	// Constructor: Creates an empty stack.
	Stack();

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
	void push(ItemType anItem);

	// Transformer: Removes the item on top of the stack.
	// Pre: The stack is not empty.
	// Post: The stack does not contains the item.
	void pop();

private:
	// Attribute: Array that holds the stack items.
	ItemType items[MAX_STACK_SIZE];

	// Attribute: Index of top item.
	int top;
};

#include "Stack_Arr_T.cpp"

#endif





