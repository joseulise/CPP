// Header File: Stack_Dyn_Arr_T.h
// Author: Antonio F. Huertas
// Date: November 13, 2007
// Purpose: This is the specification file for class template Stack.
//          It uses a dynamically allocated array to store the items in 
//          the stack.

#ifndef STACK_H
#define STACK_H

template <typename ItemType>
class Stack
{
public:
	// Default Constructor: Creates an empty stack.
	Stack();

	// Parameterized Constructor: Creates a stack with the given size.
	// Pre: max > 0.
	Stack(int max);

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
	void push(ItemType anItem);

	// Transformer: Removes the item on top of the stack.
	// Pre: The stack is not empty.
	// Post: The stack does not contains the item.
	void pop();

	// Transformer: Overloads assignment operator for the stack.
	// Pre: Right-hand side stack exists.
	// Post: Stack is a deep copy of original Stack.
	void operator = (const Stack& original);
	
	// Destructor: Deallocates memory for the the stack.
	~Stack();
	
private:
	// Attribute: Maximum size of stack.
	int maxSize;
	
	// Attribute: Pointer to array of stack items.
	ItemType* items;

	// Attribute: Index of top stack item.
	int top;

	// Transformer: Makes a deep copy of a stack.
	void copy(const Stack& original);
};

#include "Stack_Dyn_Arr_T.cpp"

#endif