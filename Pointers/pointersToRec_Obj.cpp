// pointersToRec_Obj.cpp
// By Antonio F. Huertas
// This program illustrates how to use pointers to records and
// objects.

#include "Simple.h"		// Declaration of class Simple

#include <iostream>
#include <string>
#include <cstddef>		// for definition of NULL
using namespace std;

struct Point			// Declaration of struct Point
{
	int x, y;
};

int main()
{
	Point p;
	Simple s("123", "something");

	Point* ptr1;
	Simple* ptr2;

	p.x = 5;
	p.y = 7;
	
	cout << "Point p: " << p.x << ", " << p.y << endl;
	cout << "p.x = " << p.x << "; " << "p.y = " << p.y << endl;
	
	ptr1 = &p;
	cout << "After 'ptr1 = &p'..." << endl;
	cout << "ptr1 = " << ptr1 << endl;

	cout << "Using notation '(*pointerToStruct).field'... ";
	cout << "(*ptr1).x = " << (*ptr1).x << "; " 
		<< "(*ptr1).y = " << (*ptr1).y << endl;

	cout << "Using notation 'pointerToStruct->field'... ";
	cout << "ptr1->x = " << ptr1->x << "; " 
		<< "ptr1->y = " << ptr1->y << endl;
	system("pause");
	cout << endl;

	ptr1 = new Point;
	ptr1->x = 10;
	ptr1->y = 20;
	cout << "After 'ptr1 = new Point', 'ptr1->x = 10', and 'ptr1->y = 20'..."
		<< endl;
	cout << "Point p: " << p.x << ", " << p.y << endl;
	cout << "ptr1 = " << ptr1 << endl;
	cout << "ptr1->x = " << ptr1->x << "; " 
		<< "ptr1->y = " << ptr1->y << endl;
	system("pause");
	cout << endl;

	delete ptr1;
	ptr1 = NULL;
	cout << "After 'delete ptr1' and 'ptr1 = NULL'..." << endl;
	cout << "ptr1 = " << ptr1 << endl;
	system("pause");
	cout << endl;

	ptr2 = &s;
	cout << "s is an object of class Simple..." << endl;
	cout << "s.getId() = " << s.getId() << "; " 
		<< "s.getValue() = " << s.getValue() << endl;
	cout << "ptr2 has the address of s." << endl;
	cout << "ptr2 = " << ptr2 << endl;
	cout << "Using notation 'pointerToObject->method'..." << endl;
	cout << "ptr2->getId() = " << ptr2->getId() << "; " 
		<< "ptr2->getValue() = " << ptr2->getValue() << endl;
	system("pause");
	cout << endl;

	ptr2 = new Simple("345", "nothing");
	cout << "After 'ptr2 = new Simple(\"345\", \"nothing\")'..." << endl;
	cout << "ptr2 = " << ptr2 << endl;
	cout << "ptr2->getId() = " << ptr2->getId() << "; " 
		<< "ptr2->getValue() = " << ptr2->getValue() << endl;
	system("pause");
	cout << endl;

	ptr2->setValue("anything!");
	cout << "After 'ptr2->setValue(\"anything!\")'..." << endl;
	cout << "ptr2 = " << ptr2 << endl;
	cout << "ptr2->getId() = " << ptr2->getId() << "; " 
		<< "ptr2->getValue() = " << ptr2->getValue() << endl;
	system("pause");
	cout << endl;

	delete ptr2;
	ptr2 = NULL;
	cout << "After 'delete ptr2' and 'ptr2 = NULL'..." << endl;
	cout << "ptr2 = " << ptr2 << endl;
	system("pause");
	cout << endl;

	return 0;
}

