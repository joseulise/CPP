// Source File: Stack_Arr_T.cpp
// Author: Antonio F. Huertas
// Date: October 22, 2007
// Purpose: This is the implementation file for class template Stack.

// Constructor: Creates an empty stack.
template <typename ItemType>
Stack<ItemType>::Stack()
{
	top = -1;
}

// Observer: Returns true if the stack is empty.
template <typename ItemType>
bool Stack<ItemType>::isEmpty() const
{
	return (top == -1);
}

// Observer: Returns true if the stack is full.
template <typename ItemType>
bool Stack<ItemType>::isFull() const
{
	return (top == MAX_STACK_SIZE - 1);
}


// Observer: Returns the item on top of the stack.
template <typename ItemType>
ItemType Stack<ItemType>::peek() const
{
	return items[top];
}

// Transformer: Inserts an item on top of the stack.
template <typename ItemType>
void Stack<ItemType>::push(ItemType anItem)
{
	top++;
	items[top] = anItem;
}

// Transformer: Removes the item on top of the stack.
template <typename ItemType>
void Stack<ItemType>::pop()
{
	top--;
}