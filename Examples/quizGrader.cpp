// Source File: quizGrader.cpp
// Author: Antonio F. Huertas
// Date: September 10, 2007
// Purpose: This program grades a group of quizes based on a key read
//          from a file.  It creates a file with the score for each quiz.

// Header files
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

// Symbolic constant
const int NUM_QUESTIONS = 10;

// Function prototypes
void readKey(char []);
void readStudent(ifstream&, string&, char []);
int gradeQuiz(const char [], const char []);
void writeResults(ofstream&, string, int);

// Main function
int main()
{
	ifstream answersFile;
	ofstream resultsFile;
	string studentID;
	char quizKey[NUM_QUESTIONS], studentAnswers[NUM_QUESTIONS];
	int studentScore;

	readKey(quizKey);

	answersFile.open("answers.txt");
	resultsFile.open("results.txt");

	if (answersFile.fail())
	{
		cout << "Error opening answers.txt!" << endl;
		return 1;
	}

	if (resultsFile.fail())
	{
		cout << "Error opening results.txt!" << endl;
		return 1;
	}

	readStudent(answersFile, studentID, studentAnswers);
	while (! answersFile.eof())
	{
		studentScore = gradeQuiz(studentAnswers, quizKey);
		writeResults(resultsFile, studentID, studentScore);
		readStudent(answersFile, studentID, studentAnswers);
	}
	return 0;
}

// Function to read the key from a file
void readKey(char key[])
{
	ifstream keyFile;

	keyFile.open("key.txt");

	if (keyFile.fail())
	{
		cout << "Error opening key.txt!" << endl;
		exit(1);
	}

	for (int n = 0; n < NUM_QUESTIONS; n++)
		keyFile >> key[n];

	keyFile.close();
}

// Function to read the student's data from a file.  It returns the student ID
// and the student's answers
void readStudent(ifstream& inFile, string& id, char answers[])
{
	inFile >> id;
	for (int n = 0; n < NUM_QUESTIONS; n++)
		inFile >> answers[n];
}

// Function to grade a quiz (10 multiple-selection questions)
int gradeQuiz(const char answers[], const char key[])
{
	int score = 0;

	for (int n = 0; n < NUM_QUESTIONS; n++)
		if (answers[n] == key[n])
			score++;

	return score;
}

// Function to write the score of a given student to a file
void writeResults(ofstream& outFile, string id, int score)
{
	outFile << id << ' ' << score << endl;
}


