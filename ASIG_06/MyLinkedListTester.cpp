// MyLinkedList.cpp
// By Antonio F. Huertas
// This program illustrates how to use the MyLinkedList class.

#include "MyLinkedList.h"

#include <iostream>
using namespace std;

int main()
{
	MyLinkedList list;

	cout << "Inserting some values ..." << endl;
	cout << "Values: 51, 14, 10, 65, 28, 62, 27, 87" << endl;
	list.insert(51);
	list.insert(14);
	list.insert(10);
	list.insert(65);
	list.insert(28);
	list.insert(62);
	list.insert(27);
	list.insert(87);

	cout << endl;

	cout << "Displaying the values ..." << endl;
	list.display();
	cout << endl << endl;

	cout << "The number of nodes is " << list.length() << endl;
	cout << "The sum of the node values is " << list.sum() << endl;
	cout << "The maximum of the node values is " << list.max() << endl;

	cout << endl;

	cout << "Checking if the list contains the value 62 ..." << endl;
	if (list.contains(62))
		cout << "The list contains the value 62." << endl;
	else
		cout << "The list DOES NOT contain the value 62." << endl;

	cout << endl;

	cout << "Deleting 14 and 62 ..." << endl;
	list.remove(14);
	list.remove(62);

	cout << endl;

	cout << "Displaying the values ..." << endl;
	list.display();
	cout << endl;

	system("pause");
	return 0;
}