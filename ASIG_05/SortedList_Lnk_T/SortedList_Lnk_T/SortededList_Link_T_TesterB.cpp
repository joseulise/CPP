// Header File: SortedList_Lnk_T.h
// Author: Jose U. Figueroa
// Date: November 28, 2007
// Purpose: Client file for the class
//			SortedList_Lnk_T.h

#include <iostream>
#include <string>
#include "SortedList_Lnk_T.h"
using namespace std;

//Metodo para mostrar el menu
char showMenu();

//Metodo para insertar un item en la lista
void insertItem(SortedList<char>& aList);//1

//Metodo para verificar si una lista contiene un item
void containsItem(SortedList<char> aList);//2

//metodo para recoger la informacion de un item
void retrieveItem(SortedList<char> aList);//3

//Metodo para mostrar el largo de la lista
void getLengthItem(SortedList<char> aList);//4

//metodo para remover un item de la lista
void removeItem(SortedList<char>& aList);//5

//metodo para copiar una lista
void copyItem(SortedList<char> aList, SortedList<char>& anotherList);//6

//metodo para ver si una lista esta llena
void isFullItem(SortedList<char> aList);//7

//metodo para ver si una lista esta vacia
void isEmptyItem(SortedList<char> aList);//8

//metodo para borrar los elementos de una lista
void clearItems(SortedList<char>& aList);//9

//metodo para mostrar una lista de menor a mayor
void minorToGreater(SortedList<char> aList);

//metodo para mostrar una lista de mayor a menor
void greaterToMinor(SortedList<char> aList);

//void destroy();

int main()
{
	SortedList<char> myList;
	SortedList<char> otherList;

	char menuOption = showMenu();
	//menuOption=toupper(menuOption);

	while(menuOption!='X')
	{
		system("cls");
		switch(menuOption)
		{
		case 'A':
			insertItem(myList);//1
			break;
		case 'B':
			containsItem(myList);//2
			break;
		case 'C':
			retrieveItem(myList);//3
			break;
		case 'D':
			getLengthItem(myList);//4
			break;
		case 'E':
			removeItem(myList);//5
			break;
		case 'F':
			copyItem(myList, otherList);//6
			break;
		case 'G':		
			isFullItem(myList);//7
			break;
		case 'H':
			isEmptyItem(myList);//8
			break;
		case 'I':
			clearItems(myList);//9
			break;
		case 'J':
			minorToGreater(myList);
			break;
		case 'K':
			greaterToMinor(myList);
			break;
		default:
			//cout<<"Invalid option!!!"<<endl
			//	<<"Try again."<<endl;
			//system("pause");
			break;
		}//SWITCH
		system("cls");
		menuOption=showMenu();
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
		<<"A) Insert an item"<<endl
		<<"B) Verify an item existance"<<endl
		<<"C) Retrieve an item info"<<endl
		<<"D) Get the length of the list"<<endl
		<<"E) Remove an item"<<endl
		<<"F) Copy a list"<<endl
		<<"G) Check if the list is full"<<endl
		<<"H) Check if the list is empty"<<endl
		<<"I) Empty the list"<<endl
		<<"J) Show from minor to greater"<<endl
		<<"K) Show from greater to minor"<<endl
		<<"X) EXIT"<<endl
		<<"-";
	cin>>tempAnswer;
	tempAnswer=toupper(tempAnswer);
	return tempAnswer;
}

//Metodo para insertar un item en la lista
void insertItem(SortedList<char>& aList)
{
	char tempChar;
	string tempString;

	system("cls");
	cout<<"SORTED LIST MENU"<<endl
		<<"DOUBLE LINKED LISTS"<<endl
		<<"INSERT"<<endl<<endl;
	cout<<"Enter a character: ";
	cin>>tempString;
	tempChar=tempString[0];

	if(!aList.isFull() && !aList.contains(tempChar))//si la lista no esta llena y no contiene el caracter
	{
		aList.insert(tempChar);
		cout<<"Item succesfully inserted!!!"<<endl;
		system("pause");
	}
	else if(aList.isFull())//si la lista esta llena
	{
	cout<<"The list is full!!!"<<endl
		<<"Delete some items first!!!"<<endl;
	system("pause");
	}//else
	else//si el item ya se encuentra en la lista
	{
		cout<<"The list already contains the character '"<<tempChar<<"' !!!"<<endl;
		system("pause");
	}
}//INSERT

//Metodo para verificar si una lista contiene un item
void containsItem(SortedList<char> aList)
{
	string tempString;
	char tempChar;

	system("cls");
	cout<<"SORTED LIST MENU"<<endl
		<<"DOUBLE LINKED LISTS"<<endl
		<<"CONTAINS"<<endl<<endl;
	cout<<"Enter a character to look up:";
	cin>>tempString;
	tempChar=tempString[0];
	if(aList.contains(tempChar))
	{
		cout<<"The list contains the character '"<<tempChar<<"' !!!"<<endl;
		system("pause");
	}
	else
	{
		cout<<"The list does not contains the character '"<<tempChar<<"' !!!"<<endl;
		system("pause");
	}
}//CONTAINS

//metodo para recoger la informacion de un item
void retrieveItem(SortedList<char> aList)
{
	char tempChar;
	string tempString;
	
	system("cls");
	cout<<"SORTED LIST MENU"<<endl
		<<"DOUBLE LINKED LISTS"<<endl
		<<"RETRIEVE"<<endl<<endl;
	cout<<"Enter the character to retrieve: ";
	cin>>tempString;
	tempChar=tempString[0];
	if(aList.contains(tempChar))
	{
		tempChar=aList.retrieve(tempChar);
		cout<<"Item found!!!"<<endl;
		system("pause");
		cout<<"INFO"<<endl
			<<"Character: "<<tempChar<<endl;
		system("pause");
	}
	else
	{
		cout<<"The character "<<'"'<<tempChar<<'"'<<" can not be ound in the list!!!"<<endl;
		system("pause");
	}
}//RETRIEVE

//Metodo para mostrar el largo de la lista
void getLengthItem(SortedList<char> aList)
{
	system("cls");
	cout<<"SORTED LIST MENU"<<endl
		<<"DOUBLE LINKED LISTS"<<endl
		<<"GET LENGTH"<<endl<<endl;
	cout<<"There are "<<aList.getLength()<<" item(s) in the list!!!"<<endl;
	system("pause");
}

//metodo para remover un item de la lista
void removeItem(SortedList<char>& aList)
{
	char tempChar;
	string tempString;
	char confirmation='N';

	if(!aList.isEmpty())
	{
		system("cls");
			cout<<"SORTED LIST MENU"<<endl
				<<"DOUBLE LINKED LISTS"<<endl
				<<"REMOVE"<<endl<<endl;
			cout<<"Enter the character to remove: ";
			cin>>tempString;
			tempChar=tempString[0];
			
		if(aList.contains(tempChar))//si la lista lo contiene
		{
			do
			{
				system("cls");
				cout<<"SORTED LIST MENU"<<endl
					<<"DOUBLE LINKED LISTS"<<endl
					<<"REMOVE"<<endl<<endl;
				cout<<"INFO"<<endl
					<<"Character: "<<tempChar<<endl;
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
				aList.remove(tempChar);
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
			cout<<"The list does not contains the char "<<"'"<<tempChar<<"'"<<"!!!"<<endl;
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

//metodo para copiar una lista
void copyItem(SortedList<char> aList, SortedList<char>& anotherList)
{
	system("cls");
	cout<<"SORTED LIST MENU"<<endl
		<<"DOUBLE LINKED LISTS"<<endl
		<<"COPY"<<endl<<endl;
	anotherList=aList;
	cout<<"List #1"<<endl;
	system("pause");
	minorToGreater(aList);
	cout<<"List #2"<<endl;
	system("pause");
	minorToGreater(anotherList);
	/*aList.resetForward();
	anotherList.resetForward();
	cout<<"List #1"<<endl;
	for(int a=0;a<aList.getLength();a++)
			cout<<"Pos."<<a+1<<':'<<aList.getNextItem()<<endl;
	cout<<"List #2"<<endl;
	for(int b=0;b<anotherList.getLength();b++)
			cout<<"Pos."<<b+1<<':'<<anotherList.getNextItem()<<endl;*/
	cout<<"List copied succesfully!!!"<<endl;
	system("pause");
}

//metodo para ver si una lista esta llena
void isFullItem(SortedList<char> aList)
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

//metodo para ver si una lista esta vacia
void isEmptyItem(SortedList<char> aList)
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

//metodo para borrar los elementos de una lista
void clearItems(SortedList<char>& aList)
{
	char confirmation='N';
	do
	{
		system("cls");
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

//metodo para mostrar una lista de menor a mayor
void minorToGreater(SortedList<char> aList)
{
	//char tempChar;
	system("cls");
	cout<<"SORTED LIST MENU"<<endl
		<<"DOUBLE LINKED LISTS"<<endl
		<<"MINOR TO GREATER"<<endl<<endl;
	if(!aList.isEmpty())
	{
		aList.resetForward();
		cout<<"Item list"<<endl<<endl;		
		for(int a=0;a<aList.getLength();a++)
			cout<<"Pos."<<a+1<<':'<<aList.getNextItem()<<endl;
	
		cout<<endl<<"Total Items: "<<aList.getLength()<<endl;
		system("pause");
	}
	else//si la lista esta vacia
	{
		cout<<"The list is empty!!!"<<endl
			<<"Insert some items first!!!"<<endl;
		system("pause");
	}
}

//metodo para mostrar una lista de mayor a menor
void greaterToMinor(SortedList<char> aList)
{
	system("cls");
	cout<<"SORTED LIST MENU"<<endl
		<<"DOUBLE LINKED LISTS"<<endl
		<<"GREATER TO MINOR"<<endl<<endl;
	if(!aList.isEmpty())
	{
		aList.resetBackward();
		cout<<"Item list"<<endl<<endl;		
		for(int a=aList.getLength();a>0;a--)
			cout<<"Pos."<<a<<':'<<aList.getPreviousItem()<<endl;
	
		cout<<endl<<"Total Items: "<<aList.getLength()<<endl;
		system("pause");
	}
	else//si la lista esta vacia
	{
		cout<<"The list is empty!!!"<<endl
			<<"Insert some items first!!!"<<endl;
		system("pause");
	}
}