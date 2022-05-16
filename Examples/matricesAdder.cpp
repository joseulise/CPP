// Source File: sumaMatrices.cpp
// Author: Antonio F. Huertas
// Date: September 15, 2007
// Purpose: This program calculates the sum of two matrices that were read
//          from a file.

// Header files
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

// Symbolic constants
const int ROWS = 3;
const int COLS = 4;

// Function prototypes
void readMatrix(ifstream&, int [][COLS]);
void calcSumMatrices(const int [][COLS], const int [][COLS], int [][COLS]);
void showMatrix(const int array[][COLS]);

// Main function
int main()
{
	ifstream matricesFile;
	int firstMatrix[ROWS][COLS],
		secondMatrix[ROWS][COLS],
		resultMatrix[ROWS][COLS];

	matricesFile.open("matrices.txt");
	if (! matricesFile)
	{
		cout << "Error opening matrices file\n";
		return 1;
	}
	
	readMatrix(matricesFile, firstMatrix);
	readMatrix(matricesFile, secondMatrix);
		
	calcSumMatrices(firstMatrix, secondMatrix, resultMatrix);

	cout << "First matrix: " << endl;
	showMatrix(firstMatrix);
	cout << "\nSecond matrix: " << endl;
	showMatrix(secondMatrix);
	cout << "\nResult matrix:" << endl;
	showMatrix(resultMatrix);

	return 0;
}

// This function reads a matrix from a file
void readMatrix(ifstream& inFile, int aMatrix[][COLS])
{
	for (int m = 0; m < ROWS; m++)
		for (int n = 0; n < COLS; n++)
			inFile >> aMatrix[m][n];
}

// This function sums two matrices and returns the resultant matrix
void calcSumMatrices(const int matrix1[][COLS], const int matrix2[][COLS],
					 int matrix3[][COLS])
{
	for (int m = 0; m < ROWS; m++)
		for (int n = 0; n < COLS; n++)
			matrix3[m][n] = matrix1[m][n] + matrix2[m][n];
}

// This function shows a matrix
void showMatrix(const int aMatrix[][COLS])
{
	for (int m = 0; m < ROWS; m++)
	{
		for (int n = 0; n < COLS; n++)
			cout << setw(6) << aMatrix[m][n] << " ";
		cout << endl;
	}
}
