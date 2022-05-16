// Source File: studentProcessorFile.cpp
// Author: Antonio F. Huertas
// Date: September 10, 2007
// Purpose: This program reads from a file the data for a group of
//          students and determines the corresponding average and
//          grade for each student.  It creates a file with the results.

// Header files
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Function prototypes
void readStudent(ifstream&, string&, string&, int&, int&);
float calcAverage(int, int);
char detGrade(float);
void writeResults(ofstream&, string, string, float, char);

// Main function
int main()
{
	ifstream scoresFile;
	ofstream resultsFile;
	string studentID, courseCode;
	int numOfScores, sumOfScores;
	float courseAverage;
	char courseGrade;

	scoresFile.open("scores.txt");
	resultsFile.open("results.txt");

	if (scoresFile.fail())
	{
		cout << "Error opening scores.txt!" << endl;
		return 1;
	}

	if (resultsFile.fail())
	{
		cout << "Error opening results.txt!" << endl;
		return 1;
	}

	readStudent(scoresFile, studentID, courseCode, numOfScores, sumOfScores);
	while (! scoresFile.eof())
	{
		courseAverage = calcAverage(numOfScores, sumOfScores);
		courseGrade = detGrade(courseAverage);
		writeResults(resultsFile, studentID, courseCode, courseAverage, courseGrade);
		readStudent(scoresFile, studentID, courseCode, numOfScores, sumOfScores);
	}
	return 0;
}

// Function to read the student's data from a file.  It returns the student ID,
// the course code, the number of scores and their sum
void readStudent(ifstream& inFile, string& id, string& code, int& num, int& sum)
{
	int score;

	sum = 0;

	inFile >> id >> code >> num;
	for (int n = 0; n < num; n++)
	{
		inFile >> score;
		sum += score;
	}
}

// Function to calculate the average.  It receives the number of scores and
// their sum
float calcAverage(int num, int sum)
{
	return (float)sum / num;
}

// Function to determine the grade given an average
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

// Function to write the results of a student (average and grade) to a file
void writeResults(ofstream& outFile, string id, string code, float avg, char grade)
{
	outFile << fixed << showpoint << setprecision(3);
	outFile << id << ' ' << code << ' ' << avg << ' ' << grade << endl;
}
