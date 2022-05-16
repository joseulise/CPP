// MyBSTTester.cpp
// By Antonio F. Huertas
// This program illustrates how to use the MyBST class.

#include "MyBST.h"

#include <iostream>
using namespace std;

int main()
{
	MyBST tree;

	cout << "Inserting some values ..." << endl;
	cout << "Values: 51, 14, 10, 65, 28, 62, 27, 87" << endl;
	tree.insert(51);
	tree.insert(14);
	tree.insert(10);
	tree.insert(65);
	tree.insert(28);
	tree.insert(62);
	tree.insert(27);
	tree.insert(87);

	cout << endl;

	cout << "Displaying the values using inorder traversal ..." << endl;
	tree.displayInorder();
	//tree.d
	cout << endl << endl;

	cout << "The number of nodes is " << tree.count() << endl;
	cout << "The sum of the node values is " << tree.sum() << endl;
	cout << "The maximum of the node values is " << tree.max() << endl;

	cout << "Checking if the tree contains the value 62 ..." << endl;
	if (tree.contains(62))
		cout << "The tree contains the value 62." << endl;
	else
		cout << "The tree DOES NOT contain the value 62." << endl;

	cout << endl;
	system("pause");

	return 0;
}