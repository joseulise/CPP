// recursionArrays.cpp
// By Antonio F. Huertas
// This program illustrates the use of recursion to process arrays.

#include <iostream>
using namespace std;

// Prototypes
void display(const int theArray[], int length);		// Recursive version
void display_iter(const int theArray[], int length);	// Iterative version

void displayRev(const int theArray[], int length);	// Recursive version
void displayRev_iter(const int theArray[], int length);	// Iterative version

int sum(const int theArray[], int length);			// Recursive version
int sum_iter(const int theArray[], int length);			// Iterative version

int binarySearch(int target, const int theArray[],
		int lo, int hi);					// Recursive version
int binarySearch_iter(int target, const int theArray[],
		int lo, int hi);					// Iterative version

// Function definitions
int main()
{
	const SIZE = 8;
	int myArray[SIZE] = {10, 14, 27, 48, 51, 62, 65, 87};

	cout << "Calling the iterative version ..." << endl;
	cout << "The contents of the array are ";
	display_iter(myArray, SIZE);
	cout << "Calling the recursive version ..." << endl;
	cout << "The contents of the array are ";
	display(myArray, SIZE);
	cout << endl;

	cout << endl;

	cout << "Calling the iterative version ..." << endl;
	cout << "The contents of the array, in reverse order, are ";
	displayRev_iter(myArray, SIZE);
	cout << "Calling the recursive version ..." << endl;
	cout << "The contents of the array, in reverse order, are ";
	displayRev(myArray, SIZE);

	cout << endl;

	cout << "Calling the iterative version ..." << endl;
	cout << "The sum of the elements is " 
		<< sum_iter(myArray, SIZE) << endl;
	cout << "Calling the recursive version ..." << endl;
	cout << "The sum of the elements is " 
		<< sum(myArray, SIZE) << endl;

	cout << endl;

	cout << "Calling the iterative version ..." << endl;
	cout << "Searching for 62 in the array, index is "
		<< binarySearch_iter(62, myArray, 0, SIZE - 1) << endl;
	cout << "Calling the recursive version ..." << endl;
	cout << "Searching for 62 in the array, index is "
		<< binarySearch(62, myArray, 0, SIZE - 1) << endl;

	cout << endl;

	cout << "Calling the iterative version ..." << endl;
	cout << "Searching for 39 in the array, idex is "
		<< binarySearch_iter(39, myArray, 0, SIZE - 1) << endl;
	cout << "Calling the recursive version ..." << endl;
	cout << "Searching for 39 in the array, idex is "
		<< binarySearch(39, myArray, 0, SIZE - 1) << endl;

	return 0;
}

// This function displays the contents of an array (recursive version).
void display(const int theArray[], int length)
{
	if (length == 0)
		cout << endl;
	else
	{
		display(theArray, length - 1);
		cout << theArray[length - 1] << " ";
	}
}

// This function displays the contents of an array (iterative version).
void display_iter(const int theArray[], int length)
{
	for (int n = 0; n < length; n ++)
		cout << theArray[n] << " ";
	cout << endl;
}

// This function displays the contents of an array in reverse order
// (recursive version).
void displayRev(const int theArray[], int length)
{
	if (length == 0)
		cout << endl;
	else
	{
		cout << theArray[length - 1] << " ";
		displayRev(theArray, length - 1);
	}
}

// This function displays the contents of an array in reverse order
// (iterative version).
void displayRev_iter(const int theArray[], int length)
{
	for (int n = length - 1; n >= 0; n --)
		cout << theArray[n] << " ";
	cout << endl;
}

// This function sums the elements of an array (recursive version).
int sum(const int theArray[], int length)
{
	if (length == 0)
		return 0;
	else
		return theArray[length - 1] + sum(theArray, length - 1);
}


// This function sums the elements of an array (iterative version).
int sum_iter(const int theArray[], int length)
{
	int total = 0;
	for (int n = 0; n < length; n ++)
		total = total + theArray[n];
	return total;
}

// This function implemets the binary search (recursive version).
// Returns the index if found, -1 otherwise.
int binarySearch(int target, const int theArray[], int lo, int hi)
{
	int mid;

	if (lo > hi)
		return -1;				// item is not present
	else
	{
		mid = (lo + hi) / 2;
		if (theArray[mid] == target)		// found it!
			return mid;
		else if (target < theArray[mid])	// must search in 1st half
			return binarySearch(target, theArray, lo, mid - 1);
		else						// must search in 2nd half
			return binarySearch(target, theArray, mid + 1, hi);
	}
}

// This function implemets the binary search (iterative version).
// Returns the index if found, -1 otherwise.
int binarySearch_iter(int target, const int theArray[], int lo, int hi)
{
	int mid;

	while (lo <= hi)
	{
		mid = (lo + hi) / 2;
		if (theArray[mid] == target)		// found it!
			return mid;
		else if (target < theArray[mid])	// must search in 1st half
			hi = mid - 1;
		else						// must search in 2nd half
			lo = mid + 1;
	}

	return -1;						// item is not present
}
