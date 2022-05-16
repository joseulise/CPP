// Source File: studentProcessor.cpp
// Author: Antonio F. Huertas
// Date: September 10, 2007
// Purpose: This program asks the user for a list of scores and determines
//          the corresponding average and grade.

// Header files
#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
void getNumOfScores(int&);
void getScores(int, int&);
float calcAverage(int, int);
char detGrade(float);
void showResults(float, char);

// Main function
int main()
{
	int numOfScores, sumOfScores;
	float courseAverage;
	char courseGrade;

	getNumOfScores(numOfScores);
	getScores(numOfScores, sumOfScores);
	courseAverage = calcAverage(numOfScores, sumOfScores);
	courseGrade = detGrade(courseAverage);
	showResults(courseAverage, courseGrade);
	return 0;
}

// Function to get the number of scores from user
void getNumOfScores(int& num)
{
	cout << "Enter number of scores (1 - 10): ";
	cin >> num;
	while (num < 1 || num > 10)
	{
		cout << "Error! Number of scores must be between 1 and 10." << endl;
		cout << endl;
		cout << "Enter number of scores (1 - 10): ";
		cin >> num;
	}
}

// Function to get the scores from the user and return the sum
void getScores(int num, int& sum)
{
	int score;

	sum = 0;
	for (int n = 0; n < num; n++)
	{
		cout << "Enter score #" << (n + 1) << " (0 - 100):";
		cin >> score;
		while (score < 0 || score > 100)
		{
			cout << "Error! Score must be between 0 and 100." << endl;
			cout << endl;
			cout << "Enter score #" << (n + 1) << " (0 - 100):";
			cin >> score;
		}
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

// Function to show the average and the grade
void showResults(float avg, char grade)
{
	cout << fixed << showpoint << setprecision(3);
	cout << endl;
	cout << "The average is " << avg << endl;
	cout << "The grade is " << grade << endl;
}
