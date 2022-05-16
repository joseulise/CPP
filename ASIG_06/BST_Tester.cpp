// Source File: BST_Tester.cpp
// Author: Antonio F. Huertas
// Date: December 2, 2007
// Purpose: Client application to test class template BinarySearchTree.

#include "Person.h"
#include "BinarySearchTree_T.h"

#include <iostream>
#include <iomanip>
using namespace std;

// Prototypes
void displayTree(BinarySearchTree<Person> aTree, TreeOrder traversalOrder);
void displayPerson(Person aPerson);

int main()
{
	BinarySearchTree<Person> myTree;
	
	if (myTree.isEmpty())
		cout << "The list is empty." << endl;
	else
		cout << "The list is NOT empty." << endl;

	cout << endl;

	cout << "Inserting some items ..." << endl;
	myTree.insert(Person("654", "Juan", 25));
	cout << "654, ";
	myTree.insert(Person("763", "Maria", 18));
	cout << "763, ";
	myTree.insert(Person("972", "Pedro", 35));
	cout << "972, ";
	myTree.insert(Person("123", "Teresa", 42));
	cout << "123, ";
	myTree.insert(Person("390", "Rosa", 26));
	cout << "390" << endl;
	
	cout << endl;

	cout << "Contents of tree using inorder: " << endl << endl;
	displayTree(myTree, IN_ORDER);
	cout << endl << endl;

	system("pause");

	cout << "Contents of tree using preorder: " << endl << endl;
	displayTree(myTree, PRE_ORDER);
	cout << endl << endl;

	system("pause");

	cout << "Contents of tree using postorder: " << endl << endl;
	displayTree(myTree, POST_ORDER);
	cout << endl << endl;

	system("pause");

	if (myTree.isFull())
		cout << "The list is full." << endl;
	else
		cout << "The list is NOT full." << endl;

	cout << endl;

	cout << "Removing 654 and 972 ..." << endl;
	myTree.remove(Person("654"));
	myTree.remove(Person("972"));
	
	cout << endl;

	cout << "Contents of tree using inorder: " << endl << endl;
	displayTree(myTree, IN_ORDER);
	cout << endl << endl;

	system("pause");

	if (myTree.isEmpty())
		cout << "The list is empty." << endl;
	else
		cout << "The list is NOT empty." << endl;

	cout << endl;
	system("pause");

	cout << "Searching for 654 ..." << endl;
	if (myTree.contains(Person("654")))
		displayPerson(myTree.retrieve(Person("654")));
	else
		cout << "654 is NOT in the list" << endl;

	cout << endl;

	cout << "Searching for 123 ..." << endl;
	if (myTree.contains(Person("123")))
		displayPerson(myTree.retrieve(Person("123")));
	else
		cout << "654 is NOT in the list" << endl;

	cout << endl;

	cout << "Emptying the list ..." << endl;
	myTree.clear();

	cout << endl;

	if (myTree.isEmpty())
		cout << "The list is empty." << endl;
	else
		cout << "The list is NOT empty." << endl;
	
	return 0;
}

// This function displays a BST using the specified traversal method.
void displayTree(BinarySearchTree<Person> aTree, TreeOrder traversalOrder)
{
	Person aPerson;

	cout << left;
	cout << setw(4) << "ID" << setw(15) << "Name" << setw(5) << "Age" << endl;
	cout << setw(4) << "--" << setw(15) << "----" << setw(5) << "---" << endl;
	aTree.reset(traversalOrder);
	for (int n = 0; n < aTree.getNodeCount(); n++)
	{
		aPerson = aTree.getNextItem();
		cout <<  setw(4) << aPerson.getId() << setw(15) << aPerson.getName()
			<< setw(5) << aPerson.getAge() << endl;
	}
	cout << right;
}

// This function displays a person.
void displayPerson(Person aPerson)
{
	cout << "Name:" << aPerson.getName() << endl;
	cout << "Age:" << aPerson.getAge() << endl;
}

