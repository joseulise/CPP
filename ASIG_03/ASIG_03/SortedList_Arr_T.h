// Header File: SortedList_Arr_T.h
// Author: Antonio F. Huertas
// Date: October 11, 2007
// Purpose: Specification file for class template SortedList.
//          The list is stored in an array.

#ifndef SORTEDLIST_H
#define SORTEDLIST_H

// This is the maximum number of items.
const int MAX_SORTED_SIZE = 10;

template <typename ItemType>
class SortedList
{
public:
	// Constructor: Creates an empty list.
	// Post: The length is 0.
	SortedList();

	// Observer: Returns the length of the list.
	int getLength() const;

	// Observer: Returns true if the list is empty.
	bool isEmpty() const;

	// Observer: Returns true if the list is full.
	bool isFull() const;

	// Observer: Returns true if the list contains the item.
	bool contains(ItemType anItem) const;

	// Observer: Retrieves the stored copy of a given item.
	// Pre: The list is not empty and contains the item.
	ItemType retrieve(ItemType anItem) const;

	// Transformer: Inserts an item into the list.
	// Pre: The list is not full and does not contain the item.
	// Post: The list contains the item, it is sorted and length
	//       is increased by 1.
	void insert(ItemType anItem);

	// Transformer: Removes an item from the list.
	// Pre: The list is not empty and contains the item.
	// Post: The list no longer contains the item, it is sorted and
	//       length is decreased by 1.
	void remove(ItemType anItem);

	// Transformer: Clears the contents of the list.
	// Post: The list is empty (length is 0).
	void clear();

	// Iterator: Resets the list so it can be traversed.
	// Post: The current position is before the first item in the list.
	void reset();

	// Iterator: Returns the next item in the list.
	// Pre: This list has been reset and item in current position
	//      is not the last one.
	// Post: The current position is updated to the next item in the list.
	ItemType getNextItem();

private:
	// Attributes
	ItemType items[MAX_SORTED_SIZE];
	int length;
	int currPosition;

	// Observer: Returns the position for an item in the list, if list
	//           contains the item.  Otherwise, returns the position where
	//           item should be placed.
	int findPosition(ItemType anItem) const;
};

// IMPORTANT: Implementation file for a class template MUST be included in
// the specification (header) file and MUST NOT be part of the project.
#include "SortedList_Arr_T.cpp"

#endif