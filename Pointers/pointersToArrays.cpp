// pointersToArrays.cpp
// By Antonio F. Huertas
// This program illustrates how to use pointers to arrays.

#include <iostream>
#include <cstddef>		// for definition of NULL
using namespace std;

int main()
{
	// Using static memory allocation
	int list[5] = {2, 4, 6, 8, 10};
	int* ptr1;
	int* ptr2;

	ptr1 = &(list[0]);
	cout << "ptr1 has the base address of list" << endl;
	cout << "ptr1 = " << ptr1 << endl;
	cout << "list = ";
	for (int n = 0; n < 5; n ++)
		cout << list[n] << " ";
	cout << endl;
	cout << "*ptr1 = " << *ptr1 << endl;
	cout << "Showing list indirectly using ptr1: ";
	for (n = 0; n < 5; n++)
		cout << *(ptr1 + n) << " ";
	cout << endl;
	system("pause");
	cout << endl;

	ptr2 = list;
	cout << "ptr2 has the base address of list" << endl;
	cout << "ptr2 = " << ptr2 << endl;
	cout << "*ptr2 = " << *ptr2 << endl;
	cout << "Showing list indirectly using ptr2: ";
	for (n = 0; n < 5; n++)
		cout << *(ptr2 + n) << " ";
	cout << endl;
	system("pause");
	cout << endl;


	// Using dynamic memory allocation
	ptr2 = new int[7];
	for (n = 0; n < 7; n++)
		*(ptr2 + n) = 10 + n;
	cout << "After 'ptr2 = new int[7]' and putting some values..."
		<< endl;
	cout << "ptr2 = " << ptr2 << endl;
	cout << "Showing array pointed by ptr2: ";
	for (n = 0; n < 7; n++)
		cout << *(ptr2 + n) << " ";
	cout << endl;
	system("pause");
	cout << endl;

	ptr1 = ptr2;
	cout << "After 'ptr1 = ptr2'..." << endl;
	cout << "ptr1 = " << ptr1 << endl;
	ptr1[3] = 99;
	cout << "After 'ptr1[3] = 99'..." << endl;
	cout << "ptr1[3] = " << ptr1[3] << endl;
		cout << "Showing array pointed by ptr2: ";
	for (n = 0; n < 7; n++)
		cout << ptr2[n] << " ";
	cout << endl;
	system("pause");
	cout << endl;
	
	delete [] ptr1;
	ptr1 = NULL;
	ptr2 = NULL;
	cout << "After 'delete [] ptr1' and setting ptr1 and ptr2 to NULL..." 
		<< endl;
	cout << "ptr1 = " << ptr1 << endl;
	cout << "ptr2 = " << ptr2 << endl;
	system("pause");
	
	return 0;
}



