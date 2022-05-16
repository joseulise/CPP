// Header File: Stack_Dyn_Arr_T.cpp
// Author: Antonio F. Huertas
// Date: November 13, 2007
// Purpose: This is the implementation file for typename template Stack.
//          It uses a dynamically allocated array to store the items in 
//          the stack.

// Default Constructor: Creates an empty stack.
template <typename ItemType>
Stack<ItemType>::Stack()
{
	maxSize = 10;
	items = new ItemType[maxSize];
	top = -1;
}

// Parameterized Constructor: Creates a stack with the given size.
template <typename ItemType>
Stack<ItemType>::Stack(int max)
{
	maxSize = max;
	items = new ItemType[maxSize];
	top = -1;
}

// Copy Constructor: Creates a new Stack as a copy of another.
template <typename ItemType>
Stack<ItemType>::Stack(const Stack& original)
{
	copy(original);
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
	return (top == maxSize - 1);
}

// Observer: Returns the item on top of the stack.
template <typename ItemType>
ItemType Stack<ItemType>::peek() const
{
	return items[top];
}

// Transformer: Inserts an item on top of the stack.
template <typename ItemType>
void Stack<ItemType>::push(ItemType newItem)
{
	top ++;
	items[top] = newItem;
}

// Transformer: Removes the item on top of the stack.
template <typename ItemType>
void Stack<ItemType>::pop()
{
	top --;
}

// Transformer: Overloads assignment operator for the stack.
template <typename ItemType>
void Stack<ItemType>::operator = (const Stack& rhs)
{
	delete [] items;	// Destroy left-hand side stack
	copy(original);		// Copy right-hand side to left-hand side stack
}

// Destructor: Deallocates memory for the the stack.
template <typename ItemType>
Stack<ItemType>::~Stack()
{
	delete [] items;
}

// Transformer: Makes a deep copy of a stack.
template <typename ItemType>
void Stack<ItemType>::copy(const Stack& original)
{
	// Set top and maxSize for new stack based on original.
	top = original.top;
	maxSize = original.maxSize;

	// Copy items from original stack to new stack.
	items = new ItemType[maxSize];
	for (int n = 0; n <= top; n++)
		items[n] = original.items[n];
}

