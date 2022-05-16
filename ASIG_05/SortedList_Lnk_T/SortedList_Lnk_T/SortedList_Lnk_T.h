// Header File: SortedList_Lnk_T.h
// Author: Jose U. Figueroa
// Date: November 28, 2007
// Purpose: Specification file for class template SortedList.
//			The list is stored in a double linked list.

#ifndef SORTEDLIST_LNK_H
#define SORTEDLIST_LNK_H

template <typename ItemType>
class SortedList
{
private:
	struct Node
	{
		Node* previous;
		ItemType info;
		Node* next;
	};

	Node* headPtr;// – apuntador al primer nodo de la lista.
	Node* rearPtr;// – apuntador al último nodo de la lista.  ¡Añadido!	
	Node* currentPtr;// – apuntador al nodo actual durante un recorrido de la lista.
	int length;// – contiene la cantidad de artículos en la lista.
	
	

	//Métodos Privados:
	void findPosition(ItemType anItem, Node*& location, Node*& predLoc) const;// – devuelve un apuntador al nodo que contiene el valor buscado y un apuntador al nodo anterior.  Si el valor buscado no se encuentra, location apuntará al nodo que está donde le correspondería estar el valor buscado.
	void copy(const SortedList& original);// – crea una copia profunda de una lista.
	void destroy();//– destruye los nodos de la lista.
	//NOTA: Cada nodo de la lista es un récord que tiene el siguiente formato:
	
public:

	// Constructor: Creates an empty list.
	// Post: The length is 0.
	SortedList();// – crea una lista ordenada vacía.

	// Copy Constructor: Creates a new list as a copy of another.
	// Pre: Original list exists.
	SortedList(const SortedList& original);// – crea una lista ordenada como una copia de otra lista.

	// Observer: Returns the length of the list.
	int getLength() const;// – devuelve la cantidad de artículos en la lista.

	// Observer: Returns true if the list is empty.
	bool isEmpty() const;// – devuelve true si la lista está vacía; false en caso contrario.

	// Observer: Returns true if the list is full.
	bool isFull() const;// – devuelve true si la lista está llena; false en caso contrario.

	// Observer: Returns true if the list contains the item.
	bool contains(ItemType anItem) const;// – devuelve true si la lista contiene el artículo indicado; false en caso contrario.

	// Observer: Retrieves the stored copy of a given item.
	// Pre: The list is not empty and contains the item.
	ItemType retrieve(ItemType anItem) const;// – devuelve la copia tal como está almacenada en la lista del artículo indicado.

	// Transformer: Inserts an item into the list.
	// Pre: The list is not full and does not contain the item.
	// Post: The list contains the item, it is sorted and length
	//       is increased by 1.
	void insert(ItemType anItem);// – añade el artículo indicado a la lista manteniendo un orden ascendente.

	// Transformer: Removes an item from the list.
	// Pre: The list is not empty and contains the item.
	// Post: The list no longer contains the item, it is sorted and
	//       length is decreased by 1.
	void remove(ItemType anItem);// – remueve el artículo indicado de la lista manteniendo un orden ascendente.

	// Transformer: Clears the contents of the list.
	// Post: The list is empty (length is 0)
	void clear();//– borra el contenido de la lista.

	// Transformer: Overloads assignment operator for the list.
	// Pre: Right-hand side list exists.
	// Post: List is a deep copy of original list.
	void operator = (const SortedList& rhs);// – sobrecarga el operador de asignación para asignarle a la lista el contenido de otra lista.

	// Iterator: Resets the list so it can be traversed from left to rigth.
	// Post: The current front position is before the first item in the list.
	void resetForward();//– prepara la lista para que pueda ser recorrida de izquierda a derecha. ¡Añadido!

	// Iterator: Returns the next item in the list.
	// Pre: This list has been reset and item in current position
	//      is not the last one.
	// Post: The current position is updated to the next item in the list.
	ItemType getNextItem();//– devuelve el próximo artículo de la lista durante un recorrido de izquierda a derecha.

	// Iterator: Resets the list so it can be traversed from rigth to left.
	// Post: The current rear position is after the last item in the list.
	void resetBackward();//– prepara la lista para que pueda ser recorrida de derecha a izquierda. ¡Añadido!

	// Iterator: Returns the previous item in the list.
	// Pre: This list has been reset and item in current position
	//      is not the first one.
	// Post: The current position is updated to the next item in the list.
	ItemType getPreviousItem();//– devuelve el artículo anterior de la lista durante un recorrido de derecha a izquierda. ¡Añadido!

	// Destructor: Deallocates memory for the the list.
	~SortedList();//– destruye la lista.
};

#include "SortedList_Lnk_T.cpp"
#endif


