/************************
* Jose Figueroa Colon	*
* #841-03-2641			*
* Prof. Huertas			*
* sum_mat.cpp			*
*************************/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int COLS=3;
const int ROWS=2;

void readMatrix (int array[][COLS], ifstream infile);
void calcSum (int array[][COLS], int array2[][COLS], int array3[][COLS]);
void showMatrix (int array[][COLS]);
void writeMatrix(int array[][COLS], ofstream& outfile);

int main()
{
	int table[ROWS][COLS], table2[ROWS][COLS], table3[ROWS][COLS];
	ifstream inputfile;
	ofstream outputfile;

	inputfile.open("matrix.txt");
	outputfile.open("results.txt");

	if(inputfile.fail() || outputfile.fail())
	{
		cout<<"Error opening files!!!"<<endl;
		return 1;
	}//IF

	readMatrix(table, inputfile);
	readMatrix(table2, inputfile);
	calcSum(table, table2, table3);

	cout<<"First matrix: "<<endl;
	showMatrix(table);
	cout<<"Second matrix: "<<endl;
	showMatrix(table2);
	cout<<"Sum of matrix: "<<endl;
	showMatrix(table3);

	writeMatrix(table, outputfile);

	inputfile.close();
	outputfile.close();

	return 0;
}//MAIN

void readMatrix(int array[][COLS], ifstream infile)
{
	for(int f=0;f<ROWS;f++)
	{
		for(int c=0;c<COLS;c++)
			infile>>array[f][c];
	}//FOR
}//READMATRIX

void calcSum(int array[][COLS], int array2[][COLS], int array3[][COLS])
{
	for(int f=0;f<ROWS;f++)
	{
		for(int c=0;c<COLS;c++)
			array3[f][c]=array[f][c]+array2[f][c];
	}//FOR
}//CALCSUM

void showMatrix(int array[][COLS])
{
	for(int f=0;f<ROWS;f++)
	{
		for(int c=0;c<COLS;c++)
			cout<<array[f][c];
		cout<<endl;
	}//FOR
}//SHOWMATRIX

void writeMatrix(int array[][COLS], ofstream& outfile)
{
	for(int f=0;f<ROWS;f++)
	{
		for(int c=0;c<COLS;c++)
			outfile<<array[f][c];
		cout<<endl;
	}//FOR
}//WRITEMATRIX