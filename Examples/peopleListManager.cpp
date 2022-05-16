// Source File: peopleListManager.cpp
// Author: Antonio F. Huertas
// Date: September 15, 2007
// Purpose: This program allows the user to manage a list of people.
//          The list is stored in an array of records.

// Header files
#include <cctype>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Symbolic constants
const int MAX_LIST_SIZE = 50;
const int SS_LENGTH = 11;
const int MAX_NAME_LENGTH = 30;
const int MAX_AGE_LENGTH = 3;

// Structure declaration
struct Person
{
	string socialSecurity;
	string fullName;
	int age;
};

// Function prototypes
void loadListFromFile(Person [], int&);
void showMenu(int&);
void processMenu(int, Person [], int&);
void saveListIntoFile(const Person [], int);

void addPersonToList(Person [], int&);
void removePersonFromList(Person [], int&);
void showList(const Person [], int);
void showPersonInList(const Person [], int);

void readPerson(ifstream&, Person&);
void writePerson(ofstream&, Person);

void searchPersonInList(string, const Person [], int, bool&, int&);

void getSocialSecurity(string&);
void getName(string&);
void getAge(int&);

void showPersonDetails(Person);

// Main function
int main()
{
	Person personList[MAX_LIST_SIZE];
	int listSize, menuSelection;

	loadListFromFile(personList, listSize);
	
	do
	{
		system("cls");
		showMenu(menuSelection);
		processMenu(menuSelection, personList, listSize);
		system("pause");
	} while (menuSelection != 0);

	saveListIntoFile(personList, listSize);

	return 0;
}

// This function loads the list from a file
void loadListFromFile(Person list[], int& size)
{
	ifstream peopleFile;
	Person tempPerson;

	size = 0;
	peopleFile.open("people.txt");

	if (! peopleFile)
	{
		cout << "Error opening people.txt to load list." << endl;
		exit(1);
	}

	readPerson(peopleFile, tempPerson);
	while (peopleFile && size < MAX_LIST_SIZE)
	{
		list[size] = tempPerson;
		size++;
		readPerson(peopleFile, tempPerson);
	}

	if (peopleFile)
	{
		cout << "Error. There are more people in file than "
			 << "the maximum number allowed (" << MAX_LIST_SIZE
			 << ")." << endl;
		exit(1);
	}

	peopleFile.close();
}

// This function shows the menu and returns the user's selection.
void showMenu(int& sel)
{
	cout << setw(45) << "MAIN MENU" << endl << endl;
	cout << "1. Add a person to the list" << endl;
	cout << "2. Remove a person from the list" << endl;
	cout << "3. Show person in the list" << endl;
	cout << "4. Show list" << endl;
	cout << "0. Exit" << endl;
	cout << endl << "Enter your selection: ";
	cin >> sel;

	cin.ignore(1); // To remove '\n' from input buffer
}

// This function process the user's selection from the menu.
void processMenu(int sel, Person list[], int& size)
{
	switch (sel)
	{
	case 1:
		addPersonToList(list, size);
		break;
	case 2:
		removePersonFromList(list, size);
		break;
	case 3:
		showPersonInList(list, size);
		break;
	case 4:
		showList(list, size);
		break;
	case 0:
		cout << "Thank you for using this program." << endl;
		break;
	default:
		cout << "Error. Menu options are 1-4 and 0." << endl;
	}
}

// This function save the list into a file.
void saveListIntoFile(const Person list[], int size)
{
	ofstream peopleFile;

	peopleFile.open("people.txt");
	if (! peopleFile)
	{
		cout << "Error opening people.txt to save changes." << endl;
		exit(1);
	}

	for (int n = 0; n < size; n++)
		writePerson(peopleFile, list[n]);

	peopleFile.close();
}

// This function add a person to the list.
void addPersonToList(Person list[], int& size)
{
	Person tempPerson;
	bool found;
	int index;
		
	system("cls");
	cout << "Option: Add a person to the list" << endl;

	if (size == MAX_LIST_SIZE)
	{
		cout << "The list is full." << endl;
		return;
	}

	getSocialSecurity(tempPerson.socialSecurity);
	searchPersonInList(tempPerson.socialSecurity, list, size, found, index);
	if (found)
		cout << "Error. Person is already on the list." << endl;
	else
	{
		getName(tempPerson.fullName);
		getAge(tempPerson.age);

		list[size] = tempPerson;
		size++;
		cout << "Person has been added to the list." << endl;
	}
}

// This function removes a person from the list.
void removePersonFromList(Person list[], int& size)
{
	Person tempPerson;
	bool found;
	int index;
	char answer;
		
	system("cls");
	cout << "Option: Remove a person from the list" << endl;

	if (size == 0)
	{
		cout << "The list is empty." << endl;
		return;
	}

	getSocialSecurity(tempPerson.socialSecurity);
	searchPersonInList(tempPerson.socialSecurity, list, size, found, index);
	if (! found)
		cout << "Error. Person is not on the list." << endl;
	else
	{
		tempPerson = list[index];
		showPersonDetails(tempPerson);
		cout << endl;
		cout << "Are you sure you want to remove this person (Y/N)?: ";
		cin >> answer;
		answer = toupper(answer);
		if (answer == 'Y')
		{
			size--;
			list[index] = list[size];
			cout << "Person has been removed from the list." << endl;
		}
		else
			cout << "Remove operation was canceled." << endl;
	}
}

// This function shows a specific person in the list based on the social
// security.
void showPersonInList(const Person list[], int size)
{
	Person tempPerson;
	bool found;
	int index;
			
	system("cls");
	cout << "Option: Show person in the list" << endl;

	if (size == 0)
	{
		cout << "The list is empty." << endl;
		return;
	}

	getSocialSecurity(tempPerson.socialSecurity);
	searchPersonInList(tempPerson.socialSecurity, list, size, found, index);
	if (! found)
		cout << "Error. Person is not on the list." << endl;
	else
	{
		tempPerson = list[index];
		showPersonDetails(tempPerson);
	}
}

// This function shows the list of people.
void showList(const Person list[], int size)
{
	system("cls");
	cout << "Option: Show person in the list" << endl;

	if (size == 0)
	{
		cout << "The list is empty." << endl;
		return;
	}

	cout << endl << setw(40) << "List of People" << endl << endl;
	
	cout << left;
	cout << setw(SS_LENGTH + 2) << "Social Sec."
		 << setw(MAX_NAME_LENGTH + 2) << "Name"
		 << setw(MAX_AGE_LENGTH) << "Age" << endl;
	cout << setw(SS_LENGTH + 2) << "-----------"
		 << setw(MAX_NAME_LENGTH + 2) << "----"
		 << setw(MAX_AGE_LENGTH) << "---" << endl;
	cout << right;

	for (int n = 0; n < size; n++)
	{
		cout << left;
		cout << setw(SS_LENGTH + 2) << list[n].socialSecurity
			 << setw(MAX_NAME_LENGTH + 2) << list[n].fullName
			 << right
			 << setw(MAX_AGE_LENGTH) << list[n].age << endl;
	}

	cout << endl << "Number of people: " << size << endl;
}

// This function reads a person from a file.
void readPerson(ifstream& inFile, Person& aPerson)
{
	inFile >> aPerson.socialSecurity;
	inFile.ignore(1);
	getline(inFile, aPerson.fullName, '#');
	inFile >> aPerson.age;
}

// This function writes a person into a file.
void writePerson(ofstream& outFile, Person aPerson)
{
	outFile << aPerson.socialSecurity << ' '
		    << aPerson.fullName << '#' << ' '
			<< aPerson.age << endl;
}

// This function searches a person in the list based on the social security.
void searchPersonInList(string key, const Person list[], int size,
						bool& found, int& index)
{
	found = false;
	index = 0;
	while (! found && index < size)
	{
		if (key == list[index].socialSecurity)
			found = true;
		else
			index++;
	}
}

// This function gets a social security from the user.  Format: ###-##-####
void getSocialSecurity(string& value)
{
	bool valid;

	do
	{
		valid = true;
		cout << "Enter the social security (###-##-####): ";
		cin >> value;
		cin.ignore(1);
		
		if (value.length() != SS_LENGTH)
		{
			cout << "Error. Wrong social security length." << endl;
			valid = false;
		}
	} while (! valid);
}

// This function gets a name from the user.
void getName(string& value)
{
	bool valid;

	do
	{
		valid = true;
		cout << "Enter the full name: ";
		getline(cin, value, '\n');
		
		if (value.length() < 1 || value.length() > MAX_NAME_LENGTH)
		{
			cout << "Error. Wrong name length." << endl;
			valid = false;
		}
	} while (! valid);
}

// This function gets an age from the user.
void getAge(int& value)
{
	bool valid;

	do
	{
		valid = true;
		cout << "Enter the age (0-100): ";
		cin >> value;
		cin.ignore(1);

		if (value < 0 || value > 120)
		{
			cout << "Error. Wrong age range." << endl;
			valid = false;
		}
	} while (! valid);
}

// This function shows the details of a person.
void showPersonDetails(Person aPerson)
{
	cout << "Social Security: " << aPerson.socialSecurity << endl;
	cout << "Name: " << aPerson.fullName << endl;
	cout << "Age: " << aPerson.age << endl;
}
