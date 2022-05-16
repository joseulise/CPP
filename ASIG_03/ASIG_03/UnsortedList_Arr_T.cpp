// Source File: UnsortedList_Arr_T.cpp
// Author: Antonio F. Huertas
// Date: October 11, 2007
// Purpose: Implementation file for class template UnsortedList.

// Constructor: Creates an empty list.
template <typename ItemType>
UnsortedList<ItemType>::UnsortedList()
{
	length = 0;
}

// Observer: Returns the length of the list.
template <typename ItemType>
int UnsortedList<ItemType>::getLength() const
{
	return length;
}

// Observer: Returns true if the list is empty.
template <typename ItemType>
bool UnsortedList<ItemType>::isEmpty() const
{
	return (length == 0);
}

// Observer: Returns true if the list is full.
template <typename ItemType>
bool UnsortedList<ItemType>::isFull() const
{
	return (length == MAX_UNSORTED_SIZE);
}

// Observer: Returns true if the list contains the item.
template <typename ItemType>
bool UnsortedList<ItemType>::contains(ItemType anItem) const
{
	for (int index = 0; index < length; index ++)
		if (anItem == items[index])
			return true;

	return false;	// Return false if not found
}

// Observer: Retrieves the stored copy of a given item.
template <typename ItemType>
ItemType UnsortedList<ItemType>::retrieve(ItemType anItem) const
{
	int index = findPosition(anItem);
	return items[index];
}

// Transformer: Inserts an item into the list.
template <typename ItemType>
void UnsortedList<ItemType>::insert(ItemType anItem)
{
	items[length] = anItem;
	length ++;
}

// Transformer: Removes an item from the list.
template <typename ItemType>
void UnsortedList<ItemType>::remove(ItemType anItem)
{
	int index = findPosition(anItem);

	length --;
	items[index] = items[length];
}

// Transformer: Clears the contents of the list.
template <typename ItemType>
void UnsortedList<ItemType>::clear()
{
	length = 0;
}

// Iterator: Resets the list so it can be traversed.
template <typename ItemType>
void UnsortedList<ItemType>::reset()
{
	currPosition = -1;
}

// Iterator: Returns the next item in the list.
template <typename ItemType>
ItemType UnsortedList<ItemType>::getNextItem()
{
	currPosition ++;
	return items[currPosition];
}

// Observer: Returns the position for an item in the list.
template <typename ItemType>
int UnsortedList<ItemType>::findPosition(ItemType anItem) const
{
	for (int index = 0; index < length; index ++)
		if (anItem == items[index])
			return index;
}
