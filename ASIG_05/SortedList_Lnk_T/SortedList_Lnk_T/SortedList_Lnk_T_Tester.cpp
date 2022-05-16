// Header File: SortedList_Lnk_T.h
// Author: Jose U. Figueroa
// Date: November 28, 2007
// Purpose: Client file for the class
//			SortedList_Lnk_T.h

#include <iostream>
#include <string>
#include "SortedList_Lnk_T.h"
using namespace std;

struct Person
{
	string name;
	string id;
	int age;
};

char showMenu();
void insert(SortedList<Person>& aList);//1
void contains(SortedList<Person> aList);//2
void retrieve(SortedList<Person> aList);//3
void getLength(SortedList<Person> aList);//4
void remove(SortedList<Person>& aList);//5
void copy(SortedList<Person> aList, SortedList<Person>& anotherList);//6
void isFull(SortedList<Person> aList);//7
void isEmpty(SortedList<Person> aList);//8
void clear(SortedList<Person>& aList);//9
//void destroy();//
bool validateAge(string anAge);
bool validateId(string anId);

int main()
{
	SortedList<Person> myList;
	SortedList<Person> otherList;

	char menuOption = showMenu();

	while(showMenu()!='0')
	{
		system("cls");
		switch(menuOption)
		{
		case '1':
			insert(myList);//1
			break;
		case '2':
			contains(myList);//2
			break;
		case '3':
			retrieve(myList);//3
			break;
		case '4':
			getLength(myList);//4
			break;
		case '5':
			remove(myList);//5
			break;
		case '6':
			copy(myList, otherList);//6
			break;
		case '7':		
			isFull(myList);//7
			break;
		case '8':
			isEmpty(myList);//8
			break;
		case '9':
			clear(myList);//9
			break;
		default:
			cout<<"Invalid option!!!"<<endl
				<<"Try again."<<endl;
			system("pause");
			break;
		}//SWITCH
		showMenu();
	}//WHILE
	cout<<"EXIT"<<endl;
	system("pause");
	return 0;
}

char showMenu()
{
	char tempAnswer;
	cout<<"SORTED LIST MENU"<<endl
		<<"DOUBLE LINKED LISTS"<<endl<<endl
		<<"1) Insert an item"<<endl
		<<"2) Verify an item existance"<<endl
		<<"3) Retrieve an item info"<<endl
		<<"4) Get the length of the list"<<endl
		<<"5) Remove an item"<<endl
		<<"6) Copy a list"<<endl
		<<"7) Check if the list is full"<<endl
		<<"8) Check if the list is empty"<<endl
		<<"9) Empty the lsit"<<endl
		<<"0) EXIT"<<endl
		<<"-";
	cin>>tempAnswer;
	return tempAnswer;
}

//Metodo para insertar un item en la lista
void insert(SortedList<Person>& aList)
{
	cout<<"SORTED LIST MENU"<<endl
		<<"DOUBLE LINKED LISTS"<<endl
		<<"INSERT"<<endl<<endl;
	if(!aList.isFull())//si la lista no esta llena
	{
		
		Person tempPerson;
		string tempName, tempAge, tempId;
	
		cout<<"Enter the data"<<endl;
		cout<<"Enter the Person name: ";
		cin.ignore();
		getline(cin,tempName);
		//cin.ignore(1);
		//getline(cin, tempPerson.name, '\n');
		//cin>>tempPerson.name;
		do
		{
			cout<<"Enter the Person age: ";
			cin>>tempAge;
			if(!validateAge(tempAge))
			{
				cout<<"Invalid age entered!!!"<<endl;
				system("pause");
			}
			else
				tempPerson.age=atoi(tempAge.c_str());//cambio el string a entero
		}while(!validateAge(tempAge));
		do
		{
			cout<<"Enter the Person id: ";
			cin>>tempId;
			if(!validateId(tempId))
			{
				cout<<"Invalid id entered!!!"<<endl;
				system("pause");
			}
			else
				tempPerson.id=tempId;
		}while(!validateId(tempId));

		aList.insert(tempPerson);
		cout<<"Item '"<<tempPerson.id<<"' succesfully inserted!!!"<<endl;
		system("pause");

	}//IF
	else
	{
		cout<<"The list is full!!!"<<endl
			<<"Delete some items first!!!"<<endl;
		system("pause");
	}//else
}//INSERT

void contains(SortedList<Person> aList)
{
	string tempId;
	Person tempPerson;

	do
	{
		system("cls");
		cout<<"SORTED LIST MENU"<<endl
			<<"DOUBLE LINKED LISTS"<<endl
			<<"CONTAINS"<<endl<<endl;
		cout<<"Enter a Person id to look up:";
		cin>>tempId;
		if(!validateId(tempId))
		{ 
			cout<<"Invalid id entered!!!";
			system("pause");
		}
	}while(!validateId(tempId));
	//cin>>tempPerson;
	tempPerson.id=tempId;
	if(aList.contains(tempPerson))
	{
		cout<<"The list contains the item '"<<tempPerson.id<<"' !!!"<<endl;
		system("pause");
	}
	else
	{
		cout<<"The list does not contains the item '"<<tempPerson.id<<"' !!!"<<endl;
		system("pause");
	}
}//CONTAINS

void retrieve(SortedList<Person> aList)
{
	Person tempPerson;
	string tempId;
	do
	{
		system("cls");
		cout<<"SORTED LIST MENU"<<endl
			<<"DOUBLE LINKED LISTS"<<endl
			<<"RETRIEVE"<<endl<<endl;
		cout<<"Enter the Person id to retrieve the info: ";
		cin>>tempId;
		if(!validateId(tempId))//si la id es invalida
		{
			cout<<"Invalid id entered!!!"<<endl
				<<"Try again!!!"<<endl;
			system("pause");
		}
	}while(!validateId(tempId));
	tempPerson.id=tempId;
	if(aList.contains(tempPerson))
	{
		tempPerson=aList.retrieve(tempPerson);
		cout<<"Item found!!!"<<endl;
		system("pause");
		cout<<"PERSON INFO"<<endl
			<<"Name: "<<tempPerson.name<<endl
			<<"Id: "<<tempPerson.id<<endl
			<<"Age: "<<tempPerson.age<<endl<<endl;
		system("pause");
	}
	else
	{
		cout<<"The Person with the id "<<'"'<<tempPerson.id<<'"'<<" can not be ound in the list!!!"<<endl;
		system("pause");
	}
}//RETRIEVE

void getLength(SortedList<Person> aList)
{
	system("cls");
	cout<<"SORTED LIST MENU"<<endl
		<<"DOUBLE LINKED LISTS"<<endl
		<<"GET LENGTH"<<endl<<endl;
	cout<<"There are "<<aList.getLength()<<" item(s) in the list!!!"<<endl;
	system("pause");
}

void remove(SortedList<Person>& aList)
{
	Person tempPerson;
	string tempId;
	char confirmation='N';

	if(!aList.isEmpty())
	{
		do
		{
			system("cls");
			cout<<"SORTED LIST MENU"<<endl
				<<"DOUBLE LINKED LISTS"<<endl
				<<"REMOVE"<<endl<<endl;
			cout<<"Enter the Person id to remove: ";
			cin>>tempId;
			if(!validateId(tempId))//si la id es invalida
			{
				cout<<"Invalid id entered!!!"<<endl
					<<"Try again!!!"<<endl;
				system("pause");
			}
		}while(!validateId(tempId));
		tempPerson.id=tempId;
		if(aList.contains(tempPerson))//si la lista lo contiene
		{
			do
			{
				system("cls");
				cout<<"SORTED LIST MENU"<<endl
					<<"DOUBLE LINKED LISTS"<<endl
					<<"REMOVE"<<endl<<endl;
				cout<<"Person Info"<<endl
					<<"Name: "<<tempPerson.name
					<<"Id: "<<tempPerson.id
					<<"Age: "<<tempPerson.age<<endl;
				cout<<"OK to delete?(Y/N)_";
				cin>>confirmation;
				confirmation=toupper(confirmation);
				if(confirmation!='N' && confirmation!='Y')
				{
					cout<<"Invalid selection!!!"<<endl
						<<"Try again!!!"<<endl;
					system("pause");
				}
			}while(confirmation!='N' && confirmation!='Y');
			if(confirmation=='Y')
			{
				aList.remove(tempPerson);
				cout<<"Item removed from the list!!!"<<endl;
				system("pause");
			}//IF
			else
			{
				cout<<"Item remove canceled!!!"<<endl;
				system("pause");
			}
		}//IF CONTAINS
		else
		{
			cout<<"The list does not contains the Person with the id "<<'"'<<tempPerson.id<<'"'<<"!!!"<<endl;
			system("pause");
		}//ELSE DON'T CONTAINS
	}
	else
	{
		cout<<"The list is empty!!!"<<endl
			<<"There is nothing to delete!!!";
		system("pause");
	}
}//REMOVE

void copy(SortedList<Person> aList, SortedList<Person>& anotherList)
{
	system("cls");
	cout<<"SORTED LIST MENU"<<endl
		<<"DOUBLE LINKED LISTS"<<endl
		<<"COPY"<<endl<<endl;
	anotherList=aList;
	cout<<"List copied succesfully!!!"<<endl;
	system("pause");
}

void isFull(SortedList<Person> aList)
{
	cout<<"SORTED LIST MENU"<<endl
		<<"DOUBLE LINKED LISTS"<<endl
		<<"IS FULL"<<endl<<endl;
	if(aList.isFull())
	{
		cout<<"The list is full!!!";
		system("pause");
	}
	else
	{
		cout<<"The list is not full!!!";
		system("pause");
	}
}

void isEmpty(SortedList<Person> aList)
{
	cout<<"SORTED LIST MENU"<<endl
		<<"DOUBLE LINKED LISTS"<<endl
		<<"IS EMPTY"<<endl<<endl;
	if(aList.isEmpty())
	{
		cout<<"The list is empty!!!";
		system("pause");
	}
	else
	{
		cout<<"The list is not empty!!!";
		system("pause");
	}
}

void clear(SortedList<Person>& aList)
{
	char confirmation='N';
	do
	{
		system("pause");
		cout<<"SORTED LIST MENU"<<endl
			<<"DOUBLE LINKED LISTS"<<endl
			<<"CLEAR"<<endl<<endl;
		cout<<"OK to clear the list?(Y/N)_";
		cin>>confirmation;
		confirmation=toupper(confirmation);
		if(confirmation!='N' && confirmation!='Y')
		{
			cout<<"Invalid selection!!!"<<endl
				<<"Try again!!!"<<endl;
			system("pause");
		}
	}while(confirmation!='N' && confirmation!='Y');
	if(confirmation=='Y')
	{
		aList.clear();
		cout<<"List cleared!!!"<<endl;
		system("pause");
	}
	else
	{
		cout<<"List clearing canceled!!!"<<endl;
		system("pause");
	}
}

bool validateAge(string anAge)
{
	int length=anAge.length();
	if(length<=3)
	{
		for(int a=0;a<length;a++)
		{
			if(!isdigit(anAge[a]))
				return false;
		}
		return true;
	}
	return false;
}

bool validateId(string anId)
{
	if(anId.length()==4)
	{
		for(int a=0;a<anId.length();a++)
		{
			if(!isdigit(anId[0]))
				return false;
		}
		return true;
	}
	return false;
}