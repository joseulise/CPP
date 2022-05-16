// Source File: SortedList_Arr_T.cpp
// Author: Antonio F. Huertas
// Date: October 11, 2007
// Purpose: Implementation file for class template SortedList.

// Constructor: Creates an empty list.
template <typename ItemType>
SortedList<ItemType>::SortedList()
{
	length = 0;
}

// Observer: Returns the length of the list.
template <typename ItemType>
int SortedList<ItemType>::getLength() const
{
	return length;
}

// Observer: Returns true if the list is empty.
template <typename ItemType>
bool SortedList<ItemType>::isEmpty() const
{
	return (length == 0);
}

// Observer: Returns true if the list is full.
template <typename ItemType>
bool SortedList<ItemType>::isFull() const
{
	return (length == MAX_SORTED_SIZE);
}

// Observer: Returns true if the list contains the item.
template <typename ItemType>
bool SortedList<ItemType>::contains(ItemType anItem) const
{
	int low = 0;
	int high = length - 1;
	int mid;

	while (low <= high)
	{
		mid = (low + high) / 2;

		if (anItem < items[mid])
			high = mid - 1;
		else if (anItem > items[mid])
			low = mid + 1;
		else	// anItem == items[mid]
			return true;
	}

	return false;	// Return false if not found
}

// Observer: Retrieves the stored copy of a given item.
template <typename ItemType>
ItemType SortedList<ItemType>::retrieve(ItemType anItem) const
{
	int index = findPosition(anItem);
	return items[index];
}

// Transformer: Inserts an item into the list.
template <typename ItemType>
void SortedList<ItemType>::insert(ItemType anItem)
{
	int index = findPosition(anItem);

	for (int k = length; k > index; k--)
		items[k] = items[k - 1];

	items[index] = anItem;
	length++;
}

// Transformer: Removes an item from the list.
template <typename ItemType>
void SortedList<ItemType>::remove(ItemType anItem)
{
	int index = findPosition(anItem);

	for (int k = index + 1; k < length; k++)
		items[k - 1] = items[k];

	length--;
}

// Transformer: Clears the contents of the list.
template <typename ItemType>
void SortedList<ItemType>::clear()
{
	length = 0;
}

// Iterator: Resets the list so it can be traversed.
template <typename ItemType>
void SortedList<ItemType>::reset()
{
	currPosition = -1;
}

// Iterator: Returns the next item in the list.
template <typename ItemType>
ItemType SortedList<ItemType>::getNextItem()
{
	currPosition ++;
	return items[currPosition];
}

// Observer: Returns the position for an item in the list, if list
//           contains the item.  Otherwise, returns the position where
//           item should be placed.
template <typename ItemType>
int SortedList<ItemType>::findPosition(ItemType anItem) const
{
	int low = 0;
	int high = length - 1;
	int mid;

	while (low <= high)
	{
		mid = (low + high) / 2;

		if (anItem < items[mid])
			high = mid - 1;
		else if (anItem > items[mid])
			low = mid + 1;
		else	// anItem == items[mid]
			return mid;
	}

	return low;	// Return low if not found.  This is the position 
				// where item should be placed.
}
