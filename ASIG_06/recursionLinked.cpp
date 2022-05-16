// recursionLinked.cpp
// By Antonio F. Huertas
// This program illustrates the use of recursion to process linked lists.

#include "SimpleLinkedList.h"
#include "RecursiveLinkedList.h"

#include <iostream>
using namespace std;

void initializeSimpleList(SimpleLinkedList& aList);
void initializeRecursiveList(RecursiveLinkedList& aList);

int main()
{
	SimpleLinkedList mySimpleList;
	RecursiveLinkedList myRecursiveList;

	initializeSimpleList(mySimpleList);
	initializeRecursiveList(myRecursiveList);

	cout << "Calling the iterative version ..." << endl;
	cout << "The contents of the list are ";
	mySimpleList.display(); cout << endl;
	cout << "Calling the recursive version ..." << endl;
	cout << "The contents of the list are ";
	myRecursiveList.display(); cout << endl;

	cout << endl;

	cout << "Calling the iterative version ..." << endl;
	cout << "The contents of the list, in reverse order, are ";
	mySimpleList.displayReverse(); cout << endl;
	cout << "Calling the recursive version ..." << endl;
	cout << "The contents of the list, in reverse order, are ";
	myRecursiveList.displayReverse(); cout << endl;

	cout << endl;

	cout << "Calling the iterative version ..." << endl;
	cout << "The length of the list is " 
		<< mySimpleList.length() << endl;
	cout << "Calling the recursive version ..." << endl;
	cout << "The length of the list is " 
		<< myRecursiveList.length() << endl;

	cout << endl;

	cout << "Calling the iterative version ..." << endl;
	cout << "The sum of the items is " 
		<< mySimpleList.sum() << endl;
	cout << "Calling the recursive version ..." << endl;
	cout << "The sum of the items is " 
		<< myRecursiveList.sum() << endl;
	
	return 0;
}

// Function to insert some numbers in a SimpleLinkedList.
void initializeSimpleList(SimpleLinkedList& aList)
{
	aList.insertAtFront(10);
	aList.insertAtFront(14);
	aList.insertAtFront(27);
	aList.insertAtFront(48);
	aList.insertAtFront(51);
	aList.insertAtFront(62);
	aList.insertAtFront(65);
	aList.insertAtFront(87);
}

// Function to insert some numbers in a RecursiveLinkedList.
void initializeRecursiveList(RecursiveLinkedList& aList)
{
	aList.insertAtFront(10);
	aList.insertAtFront(14);
	aList.insertAtFront(27);
	aList.insertAtFront(48);
	aList.insertAtFront(51);
	aList.insertAtFront(62);
	aList.insertAtFront(65);
	aList.insertAtFront(87);
}
