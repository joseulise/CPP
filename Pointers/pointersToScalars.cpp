// pointersToScalars.cpp
// By Antonio F. Huertas
// This program illustrates how to use pointers to scalar values.

#include <iostream>
#include <cstddef>		// for definition of NULL
using namespace std;

int main()
{
	// Using static memory allocation
	int  value1 = 7;
	int* ptr1;
	int* ptr2;

	ptr1 = &value1;

	cout << "ptr1 has the address of value1" << endl;
	cout << "value1 = " << value1 << endl;
	cout << "ptr1 = " << ptr1 << endl;
	cout << "*ptr1 = " << *ptr1 << endl;
	system("pause");
	cout << endl;

	*ptr1 = *ptr1 * 3;
	cout << "After '*ptr1 = *ptr1 * 3'..." << endl;
	cout << "value1 = " << value1 << endl;
	cout << "ptr1 = " << ptr1 << endl;
	cout << "*ptr1 = " << *ptr1 << endl;
	system("pause");
	cout << endl;

	// Using dynamic memory allocation
	ptr2 = new int;
	*ptr2 = 4;
	cout << "After 'ptr2 = new int' and '*ptr2 = 4'..."
		<< endl;
	cout << "ptr2 = " << ptr2 << endl;
	cout << "*ptr2 = " << *ptr2 << endl;
	system("pause");
	cout << endl;

	ptr1 = ptr2;
	cout << "After 'ptr1 = ptr2'..." << endl;
	cout << "ptr1 = " << ptr1 << endl;
	cout << "*ptr1 = " << *ptr1 << endl;
	cout << "ptr2 = " << ptr2 << endl;
	cout << "*ptr2 = " << *ptr2 << endl;
	system("pause");
	cout << endl;


	*ptr1 = *ptr1 + 9;
	cout << "After '*ptr1 = *ptr1 + 9'..." << endl;
	cout << "ptr1 = " << ptr1 << endl;
	cout << "*ptr1 = " << *ptr1 << endl;
	cout << "ptr2 = " << ptr2 << endl;
	cout << "*ptr2 = " << *ptr2 << endl;
	system("pause");
	cout << endl;

	ptr2 = new int;
	*ptr2 = 5;
	cout << "After 'ptr2 = new int' and '*ptr2 = 5'..."
		<< endl;
	cout << "ptr1 = " << ptr1 << endl;
	cout << "*ptr1 = " << *ptr1 << endl;
	cout << "ptr2 = " << ptr2 << endl;
	cout << "*ptr2 = " << *ptr2 << endl;
	system("pause");
	cout << endl;

	ptr1 = &value1;
	cout << "After 'ptr1 = &value1'..." << endl;
	cout << "ptr1 = " << ptr1 << endl;
	cout << "*ptr1 = " << *ptr1 << endl;
	cout << "ptr2 = " << ptr2 << endl;
	cout << "*ptr2 = " << *ptr2 << endl;
	cout << "There has been a memory leak..." << endl;
	system("pause");
	cout << endl;

	delete ptr2;
	cout << "After 'delete ptr2'..." << endl;
	cout << "ptr1 = " << ptr1 << endl;
	cout << "*ptr1 = " << *ptr1 << endl;
	cout << "ptr2 = " << ptr2 << endl;
	cout << "*ptr2 = " << *ptr2 << endl;
	system("pause");
	cout << endl;

	cout << "After setting ptr1 and ptr2 to NULL..." << endl;
	ptr1 = NULL;
	ptr2 = NULL;
	cout << "ptr1 = " << ptr1 << endl;
	// cout << "*ptr1 = " << *ptr1 << endl;  (KABOOM!!!!)
	cout << "ptr2 = " << ptr2 << endl;
	// cout << "*ptr2 = " << *ptr2 << endl;  (KABOOM!!!!)
	system("pause");
	
	return 0;
}




	
