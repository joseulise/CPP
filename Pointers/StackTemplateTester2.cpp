// Source File: StackTemplateTester2.cpp
// Author: Antonio F. Huertas
// Date: November 13, 2007
// Purpose: Client application to test class template Stack.

// Header files
#include "Stack_Dyn_Arr_T.h"

#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
void showStackData(Stack<char> s);

int main()
{
	 // Creates an empty stack with a capacity of five characters
	Stack<char> myCharStack(5);

	cout << "A stack of characters was created ..." << endl;
	cout << "Its capacity is five (5) characters ..." << endl;
	if (myCharStack.isEmpty())
		cout << "The stack is empty." << endl;
	else
		cout << "The stack is NOT empty." << endl;

	myCharStack.push('a');
	myCharStack.push('b');
	myCharStack.push('c');
	myCharStack.push('d');
	myCharStack.push('e');
	
	cout << endl << "Five characters (a, b, c, d and e) were pushed ..." << endl;
	if (myCharStack.isEmpty())
		cout << "The stack is empty." << endl;
	else
		cout << "The stack is NOT empty." << endl;

	if (myCharStack.isFull())
		cout << "The stack is full." << endl;
	else
		cout << "The stack is NOT full." << endl;

	cout << endl << setw(30) << "Stack Contents" << endl << endl;
	showStackData(myCharStack);
	
	system("pause");
	
	cout << endl;
	cout << "Removing top character ..." << endl;
	myCharStack.pop();

	cout << endl << setw(30) << "Stack Contents" << endl << endl;
	showStackData(myCharStack);
	return 0;
}

// This function displays the data of a stack.
void showStackData(Stack<char> s)
{
	while (! s.isEmpty())
	{
		cout << s.peek() << endl;
		s.pop();
	}
}