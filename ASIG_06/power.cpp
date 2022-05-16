// power.cpp
// By Antonio F. Huertas
// This program illustrates how to implement the power function
// using two methods: recursion and iteration (loops).

// NOTE: A negative result means overflow!

#include <iostream>
using namespace std;

// Prototypes
long power(int base, int exponent);			// Recursive version
long power_iter(int base, int exponent);	// Iterative version

int main()
{
	int theBase, theExponent;

	cout << "Enter an integer for the base: ";
	cin >> theBase;
	cout << "Enter a non-negative integer for the exponent: ";
	cin >> theExponent;
	cout << endl;

	cout << "Calling the iterative version ..." << endl;
	cout << "power_iter(" << theBase << ", " << theExponent
		<< ") is " << power_iter(theBase, theExponent) << endl;
	cout << endl;

	cout << "Calling the recursive version ..." << endl;
	cout << "power(" << theBase << ", " << theExponent << ") is "
		<< power_iter(theBase, theExponent) << endl;
	cout << endl;

	return 0;
}

// This function computes the power (recursive version).
long power(int base, int exponent)
{
	if (exponent == 0)
		return 1;
	else
		return base * power(base, exponent - 1);
}

// This function computes the power (recursive version).
long power_iter(int base, int exponent)
{
	int i;
	long product = 1;

	for (i = 1; i <= exponent; i++)
		product = product * base;

	return product;
}