// Source File: recordProcessor.cpp
// Author: Antonio F. Huertas
// Date: September 15, 2007
// Purpose: This program reads from a file the data for a group of
//          students and determines the corresponding average and
//          grade for each student.  It creates a file with the results.

// Header files
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Symbolic constant
const int NUM_EXAMS = 4;

// Structure declaration
struct Student
{
	string stNumber,
		   name;
	int examList[NUM_EXAMS];
	float average;
	char grade;
};

// Function prototypes
void readStudent(ifstream&, Student&);
float calcAverage(const int []);
char detGrade(float);
void showStudent(Student);
void writeResults(ofstream&, Student);

// Main function
int main()
{
	ifstream studentsFile;
	ofstream resultsFile;
	Student myStudent;

	studentsFile.open("students.txt");
	resultsFile.open("results.txt");

	if (! studentsFile)
	{
		cout << "Error opening students.txt" << endl;
		return 1;
	}

	if (! resultsFile)
	{
		cout << "Error opening results.txt" << endl;
		return 1;
	}
	
	readStudent(studentsFile, myStudent);
	while (studentsFile)
	{
		myStudent.average = calcAverage(myStudent.examList);
		myStudent.grade = detGrade(myStudent.average);
		showStudent(myStudent);
		system("pause");
		cout << endl;

		writeResults(resultsFile, myStudent);
		readStudent(studentsFile, myStudent);
	}

	return 0;
}

// This function reads a student from a file.
void readStudent(ifstream& inFile, Student& aStudent)
{
	inFile >> aStudent.stNumber;
	inFile.ignore(1);
	getline(inFile, aStudent.name, '#');
	for (int n = 0; n < NUM_EXAMS; n++)
		inFile >> aStudent.examList[n];
}

// This function calculates the average of a list of numbers.
float calcAverage(const int list[])
{
	int sum = 0;

	for (int n = 0; n < NUM_EXAMS; n++)
		sum += list[n];

	return (float)sum / NUM_EXAMS;
}

// This function receives a student average and determines the correspong
// letter grade.
char detGrade(float avg)
{
	if (avg >= 90.0F)
		return 'A';
	else if (avg >= 80.0F)
		return 'B';
	else if (avg >= 70.0F)
		return 'C';
	else if (avg >= 60.0F)
		return 'D';
	else
		return 'F';
}

// This function shows the data of a given student.
void showStudent(Student aStudent)
{
	cout << "Student Number: " << aStudent.stNumber << endl;
	cout << "Name: " << aStudent.name << endl;
	cout << "Exams:";
	for (int n = 0; n < NUM_EXAMS; n++)
		cout << ' ' << aStudent.examList[n];
	cout << endl;
	cout << fixed << showpoint << setprecision(3);
	cout << "Average: " << aStudent.average << endl;
	cout << "Grade: " << aStudent.grade << endl;
}

// This function writes the average and the grade to a file.
void writeResults(ofstream& outFile, Student aStudent)
{
	outFile << aStudent.stNumber << ' '
		<< fixed << showpoint << setprecision(3)
		<< aStudent.average << ' '
		<< aStudent.grade << endl;
}
