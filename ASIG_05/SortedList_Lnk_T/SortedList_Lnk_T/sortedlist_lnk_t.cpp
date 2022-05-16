// Header File: SortedList_Lnk_T.cpp
// Author: Jose U. Figueroa
// Date: November 28, 2007
// Purpose: Implementation file for class template SortedList.
//          The list is stored in a double linked list.

#include <cstddef>		// contains definition of NULL

// Constructor: Creates an empty list.
template <typename ItemType>
SortedList<ItemType>::SortedList()
{
	headPtr=NULL;
	rearPtr=NULL;
	length=0;
	
}

// Copy Constructor: Creates a new list as a copy of another.
template <typename ItemType>
SortedList<ItemType>::SortedList(const SortedList<ItemType>& original)
{
	copy(original);
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
	return (headPtr == NULL);//no cambia
}

// Observer: Returns true if the list is full.
template <typename ItemType>
bool SortedList<ItemType>::isFull() const
{
	return false;//asumimos que es falso
}

//CAMBIOS????
// Observer: Returns true if the list contains the item.
template <typename ItemType>
bool SortedList<ItemType>::contains(ItemType anItem) const
{
	Node* location;		// Pointer to traverse the list
	bool found = false;

	location = headPtr;			
	while (location != NULL && anItem > location->info)
		location = location->next;

	if (location != NULL && anItem == location->info)
		found = true;

	return found;
}

// Observer: Retrieves the stored copy of a given item.
template <typename ItemType>
ItemType SortedList<ItemType>::retrieve(ItemType anItem) const
{
	Node* location;
	Node* predLoc;

	findPosition(anItem, location, predLoc);
	return location->info;
}

// Transformer: Inserts an item into the list.
template <typename ItemType>
void SortedList<ItemType>::insert(ItemType anItem)
{
	Node* location;
	Node* predLoc;
	Node* tempPtr;

	tempPtr = new Node;
	tempPtr->info = anItem;

	findPosition(anItem, location, predLoc);

	if(headPtr==NULL)//quiere decir que la lista esta vacia
	{
		tempPtr->previous=NULL;
		tempPtr->next=NULL;
		headPtr=tempPtr;
		rearPtr=tempPtr;
	}
	else if(location==headPtr)//significa que tempPtr va al principio
	{
		tempPtr->next=location;
		tempPtr->previous=NULL;
		location->previous=tempPtr;
		headPtr=tempPtr;
	}
	else if(location==NULL)//significa que tempPtr se insertara al final
	{
		tempPtr->previous=predLoc;
		tempPtr->next=NULL;
		predLoc->next=tempPtr;
		rearPtr=tempPtr;
	}
	
	else//nodo interior
	{
		tempPtr->next=location;
		tempPtr->previous=predLoc;
		predLoc->next=tempPtr;
		location->previous=tempPtr;
	}
	length++;
}
	
// Transformer: Removes an item from the list.
template <typename ItemType>
void SortedList<ItemType>::remove(ItemType anItem)
{
	Node* location;
	Node* predLoc;
	Node* postLoc;


	findPosition(anItem, location, predLoc);
	postLoc=location->next;
	if(location==headPtr)//el primero
	{
		if(location->next!=NULL)
		{
			headPtr=postLoc;
			postLoc->previous=NULL;
		}
		else//si es el unico
		{
			rearPtr=NULL;
			headPtr=NULL;
		}
	}
	else if(location==rearPtr)//quiero remover el ultimo
	{
		predLoc->next=NULL;
		rearPtr=predLoc;
	}
	else//interior node
	{
		postLoc->previous=predLoc;
		predLoc->next=postLoc;
	}
	delete location;
	length--;
}

// Transformer: Clears the contents of the list.
template <typename ItemType>
void SortedList<ItemType>::clear()
{
	destroy();
	length = 0;
}

// Transformer: Overloads assignment operator for the list.
template <typename ItemType>
void SortedList<ItemType>::operator = (const SortedList<ItemType>& rhs)
{
	destroy();
	copy(rhs);
}

// Iterator: Resets the list so it can be traversed form left to rigth.
template <typename ItemType>
void SortedList<ItemType>::resetForward()
{
	currentPtr = NULL;
}

// Iterator: Returns the next item in the list.
template <typename ItemType>
ItemType SortedList<ItemType>::getNextItem()
{
	if (currentPtr == NULL)//si es esta antes del primero
		currentPtr = headPtr;//apunta el primero
	else
		currentPtr = currentPtr->next;

	return currentPtr->info;
}

// Iterator: Resets the list so it can be traversed from rigth to left.
template <typename ItemType>
void SortedList<ItemType>::resetBackward()
{
	currentPtr=NULL;
}

// Iterator: Returns the previous item in the list.
template <typename ItemType>
ItemType SortedList<ItemType>::getPreviousItem()
{
	if(currentPtr==NULL)//si esta al final
		currentPtr=rearPtr;//apunto al ultimo nodo
	else//si no esta apuntando algun nodo
		currentPtr=currentPtr->previous;
	
	return currentPtr->info;
}

// Destructor: Deallocates memory for the the list.
template <typename ItemType>
SortedList<ItemType>::~SortedList()
{
	destroy();
}

// Observer: Returns a pointer to the node in the list that contains an item
//           and a pointer to the predecessor of that node.  If the list does
//           not contain the item, location will point to the place where the
//           item should be located.
template <typename ItemType>
void SortedList<ItemType>::findPosition(ItemType anItem, Node*& location, Node*& predLoc) const
{
	predLoc = NULL;
	location = headPtr;
	while (location != NULL && anItem > location->info)
	{
		predLoc = location;
		location = location->next;
	}
}

// Transformer: Makes a deep copy of the list.
template <typename ItemType>
void SortedList<ItemType>::copy(const SortedList<ItemType>& original)
{
	if (original.headPtr == NULL)	// if original list is empty
	{
		headPtr = NULL;
		rearPtr = headPtr;
	}
	else	// if original list is not empty
	{
		Node* origPtr;	// Pointer to current node in original list
		Node* copyPtr;	// Pointer to current node in copy list
		Node* tempPtr;	// Pointer to previous node in copy list

		// Copy first node.
		origPtr = original.headPtr;
		copyPtr = new Node;
		copyPtr->info = origPtr->info;
		copyPtr->previous = NULL;
		headPtr = copyPtr;

		// Copy rest of the list.
		origPtr = origPtr->next;
		while (origPtr != NULL)
		{
			copyPtr->next = new Node;
			tempPtr = copyPtr;
			copyPtr = copyPtr->next;
			copyPtr->info = origPtr->info;
			copyPtr->previous = tempPtr;
			origPtr = origPtr->next;
		}
		copyPtr->next = NULL;
		rearPtr = copyPtr;
	}

	length = original.length;
}

// Transformer: Destroys the nodes of the list.
template <typename ItemType>
void SortedList<ItemType>::destroy()
{
	Node* tempPtr;

	while (headPtr != NULL)
	{
		tempPtr = headPtr;
		headPtr = headPtr->next;
		delete tempPtr;
	}
	//NEW
	//rearPtr=NULL;
}
