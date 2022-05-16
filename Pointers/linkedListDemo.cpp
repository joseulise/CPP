// Source File: linkedListDemo.cpp
// Author: Antonio F. Huertas
// Purpose: This program illustrates how to create and manipulate a singly linked list.

// Header files
#include <iostream>
#include <cstddef>		// for NULL
using namespace std;

// Definition of a node
struct Node
{
	int  item;
	Node* next;
};

// Function prototypes
void createList(Node*& headPtr);
void insertFirst(Node*& headPtr, int value);
void showList(Node* headPtr);
float calcAverage(Node* headPtr);
void destroyList(Node*& headPtr);

// Function definitions
int main()
{
	Node* listPtr;			// Pointer to the first node in the list

	createList(listPtr);
	cout << "List has been created." << endl;

	cout << "Contents of list:";
	showList(listPtr);

	cout << "First: " << listPtr->item << endl;
	cout << "Rest: ";
	showList(listPtr->next);

	cout << "The average is: " << calcAverage(listPtr) << endl;

	destroyList(listPtr);
	cout << "List has been destroyed." << endl;

	return 0;
}

void createList(Node*& headPtr)
// This function creates the following list 5->10->15->20->25.
{
	headPtr = NULL;
	insertFirst(headPtr, 25);
	insertFirst(headPtr, 20);
	insertFirst(headPtr, 15);
	insertFirst(headPtr, 10);
	insertFirst(headPtr,  5);
}

void insertFirst(Node*& headPtr, int value)
// This function creates a node and inserts it at the front of the list.
{
	Node* tempPtr;			// Temporary pointer for a node

	tempPtr = new Node;
	tempPtr->item = value;
	tempPtr->next = headPtr;
	headPtr = tempPtr;
}
	

void showList(Node* headPtr)
// This function shows the values in the linked list.
{
	Node* tempPtr;			// Temporary pointer for a node

    tempPtr = headPtr;
	while (tempPtr != NULL)
	{
		cout << ' ' << tempPtr->item;
		tempPtr = tempPtr->next;
	}
	cout << endl;
}

float calcAverage(Node* headPtr)
// This function calculates the average of the values in the linked
// list.
// Pre: The list is not empty.
{
	int sum = 0,			// Accumulator
		ctr = 0;			// Counter
	Node* tempPtr;			// Temporary pointer for a node

    tempPtr = headPtr;
	while (tempPtr != NULL)
	{
		sum += tempPtr->item;
		ctr ++;
		tempPtr = tempPtr->next;
	}

	return (float)sum / ctr;
}

void destroyList(Node*& headPtr)
// This function destroys the linked list.
{
	Node* tempPtr;			// Temporary pointer for a node

    while (headPtr != NULL)
	{
		tempPtr = headPtr;
		headPtr = headPtr->next;
		delete tempPtr;
		
	}
}
