
#ifndef MYLINKEDLIST_H
#define MYLINKEDLIST_H

#include <iostream>
#include <cstddef>				// for NULL
using namespace std;

class MyLinkedList
{
public:
	MyLinkedList();
	int length() const;
    int sum() const;
	int max() const;
	bool contains(int aValue) const;
	void display() const;
	void insert(int aValue);
	void remove(int aValue);
	~MyLinkedList();
private:
	struct Node
	{
		int item;
		Node* next;
	};

	// Atribute
	Node* firstPtr;			// Pointer to the first node.
	
	// Helper recursive methods.
	int lengthHelper(Node* listPtr) const;
	int sumHelper(Node* listPtr) const;
	int maxHelper(Node* listPtr) const;
	bool containsHelper(Node* listPtr, int aValue) const;
	void displayHelper(Node* listPtr) const;
	void insertHelper(Node*& listPtr, int aValue);
	void removeHelper(Node*& listPtr, int aValue);
	void destructorHelper(Node*& listPtr);
};

#endif