// factorial.cpp
// By Antonio F. Huertas
// This program illustrates how to implement the factorial function
// using two methods: recursion and iteration (loops).

// NOTE: A negative result means overflow!

#include <iostream>
using namespace std;

// Prototypes
long factorial(int n);			// Recursive version
long factorial_iter(int n);		// Iterative version

int main()
{
	int number;

	cout << "Enter a non-negative integer: ";
	cin >> number;
	cout << endl;

	cout << "Calling the iterative version ..." << endl;
	cout << "The factorial of " << number << " is "
		<< factorial_iter(number) << endl;
	cout << endl;

	cout << "Calling the recursive version ..." << endl;
	cout << "The factorial of " << number << " is "
		<< factorial(number) << endl;
	cout << endl;

	return 0;
}

// This function computes the factorial of a non-negative
// integer (recursive version).
long factorial(int n)
{
	if (n == 0)
		return 1;
	else
		return n * factorial(n - 1);
}

// This function computes the factorial of a non-negative
// integer (iterative version).
long factorial_iter(int n)
{
	int i;
	long product = 1;

	for (i = 1; i <= n; i++)
		product = product * i;

	return product;
}