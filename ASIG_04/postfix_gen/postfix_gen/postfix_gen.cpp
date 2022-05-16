// ***********************************************************
// Source File: postfix_gen.cpp
// Author: Jose U. Figueroa Colon
// Student Number: 841-03-2641
// Date: October 31, 2007
// Purpose: Source file for postfix generation.
// ***********************************************************

//Header Files
#include "Stack_Arr_T.h"//para los templates de stack
#include <fstream>
#include <iostream>
#include <string>


using namespace std;

void readFile(ifstream& anInputFile, string& aString);//me devuelve la nueva ecuacion
void createOutputFile(string anArray[], int arrayCounter);
void updateArray(string anArray[], string aString, int& arrayCounter);

bool isOperator(char aChar);//para verificar si es un operador
bool isOperand(char aChar);
int checkPrecedence(char aChar);//para verificar la presedencia

int main()
{
	Stack<char> operatorStack;//stack de operadores
	//Stack<float> operandStack;
	string postfixString;
	string equationString;
	char tempChar;
	int item, element, arrayCount=0;//, length;
	string postfixArray[10];

	ifstream inputfile("infix.txt");
	if(!inputfile)
	{
		cout<<"Error opening file!!!"<<endl;
		system("pause");
		exit(1);
	}
	
	while(!inputfile.eof())
	{
		system("cls");
		equationString="";
		postfixString="";
		if(operatorStack.isFull()==false)
		{
			readFile(inputfile, equationString);
			cout<<equationString<<endl<<endl;//se muestra la ecuacion en pantalla
			system("pause");
			for(int count=0;count<equationString.length()+1;count++)
			{
				tempChar=equationString[count];//asigno el caracter a verificar
				//if(isOperator(tempChar))
				//{
					if(tempChar=='(')//si es (
					{
						operatorStack.push(tempChar);
						cout<<"Operator PUSHED in STACK."<<endl;
						//system("pause");
					}//if (
					if(tempChar==')')//si es )
					{
						operatorStack.peek();
						while(operatorStack.peek()!='(')
						{
							postfixString=postfixString+operatorStack.peek()+" ";//lo anado al string
							cout<<"Element added to POSTFIX string."<<endl;
							operatorStack.pop();//lo saco del stack
							cout<<"POP element."<<endl;
							operatorStack.peek();
						}//while not (
						operatorStack.pop();//lo que queda es el parentesis (
						cout<<"POP element."<<endl;
					}//if )
					if(isOperator(tempChar))
					{
						if(operatorStack.isEmpty()==false)//si el stack no esta vacio
						{
							operatorStack.peek();
							//element = checkPrecedence(tempChar);//item
							//item= checkPrecedence(operatorStack.peek());//elemento
							item = checkPrecedence(tempChar);//item
							element= checkPrecedence(operatorStack.peek());//elemento
							while(!operatorStack.isEmpty() && element >= item)
							{
								postfixString=postfixString+operatorStack.peek()+" ";
								cout<<"Operator added to POSTFIX string."<<endl;
								operatorStack.pop();
								cout<<"POP element."<<endl;
								/*if(!operatorStack.isEmpty())
								{
									operatorStack.peek();
									element = checkPrecedence(tempChar);//item
									item= checkPrecedence(operatorStack.peek());//elemento								
								}*/
							}//WHILE
							operatorStack.push(tempChar);//el operador
							cout<<"Operator PUSHED in STACK."<<endl;
						}//IF not empty
						else//si esta empty****************************NEW NEW NEW NEW NEW NEW NEW NEW 
						{
							operatorStack.push(tempChar);//NEW NEW NEW NEW NEW NEW NEW NEW NEW NEW 
							cout<<"Operator PUSHED in STACK."<<endl;
						}//else
					}//si es un operador
				if(isOperand(tempChar))//si es un digito
				{
					if(isOperand(equationString[count+1]))//si el proximo es un numero
					{
						while(isOperand(equationString[count+1]))//do//mientras sigan habiendo numeros
						{
							postfixString=postfixString+tempChar;//asigno el primer digito
							//postfixString=postfixString+equationString[count];
							cout<<"Element added to POSTFIX string."<<endl;
							count++;//incremento para no reevaluar el mismo digito
							tempChar=equationString[count];//asigno el nuevo valor al char
						}//while
						//postfixString=postfixString+tempChar;
						//postfixString=postfixString+" ";
					}//if

					/*
					if(isdigit(equationString[count+1]))//si el proximo es un numero
					{
						postfixString=postfixString+tempChar;
						cout<<"Element added to POSTFIX string."<<endl;
					}*/
					//else
					{
						//postfixString=postfixString+" ";
						postfixString=postfixString+tempChar+" ";
						cout<<"Element added to POSTFIX string."<<endl;
					}
				}//si es digito
			}//for
			while(!operatorStack.isEmpty())
			{
				//verificar aki
				operatorStack.peek();
				postfixString=postfixString+operatorStack.peek()+" ";
				cout<<"Element added to POSTFIX string."<<endl;
				operatorStack.pop();
				cout<<"POP element."<<endl;
			}//WHILE
			
			cout<<"The INFIX equation is: "<<equationString<<endl
				<<"The POSTFIX equation is: "<<postfixString<<endl<<endl;
			updateArray(postfixArray,postfixString, arrayCount);
			system("pause");
			//system("cls");
		}//if stack is not full
		else if(operatorStack.isFull())//si el stack esta lleno
		{
			cout<<"ERROR, STACK IS FULL!!!"<<endl<<endl;
			system("pause");
			inputfile.close();
			return 0;
		}
	}//while infile
	inputfile.close();
	cout<<"END OF FILE FOUND!!!"<<endl<<endl;
	createOutputFile(postfixArray, arrayCount);
	//system("pause");
	return 0;
}//MAIN


void readFile(ifstream& anInputFile, string& aString)
{
	getline(anInputFile, aString, '\n');//aqui se carga la ecuacion completa
}//string

void createOutputFile(string anArray[], int arrayCounter)
{
	ofstream outfile("postfix.txt");
	if(!outfile)
	{
		cout<<"Error opening file!!!"<<endl;
		system("pause");
		exit(1);
	}
	for(int count=0;count<arrayCounter;count++)
		outfile<<anArray[count]<<endl;
	cout<<"POSTFIX file created!!!(postfix.txt)"<<endl;
	system("pause");
	outfile.close();
}

void updateArray(string anArray[], string aString, int& arrayCounter)
{
	anArray[arrayCounter]=aString;
	arrayCounter++;
}

bool isOperator(char aChar)
{/*
	if(isalpha(aChar))//se verifica que sea un caracter
		return true;//si es cierto se devuelve cierto
	else return false;//de lo contrario se devuelve falso
	*/
	if(aChar=='+' || aChar=='-' || aChar=='*' || aChar=='/')
		return true;
	else return false;
}//bool

bool isOperand(char aChar)
{
	if(isdigit(aChar))
		return true;
	else return false;
}

int checkPrecedence(char aChar)
{
	int precedence=0; 

	switch (aChar)
	{
	  case '*':
		precedence = 1;
		  //return 1;
		break;
	  case '/':
		precedence = 1;
		  //return 1;
		break;
	  case '+':
		precedence = 0;
		  //return 0;
		break;
	  case '-':
		precedence = 0;
		  //return 0;
		break;
	  case '(':
		return -1;
		break;
	}
	return precedence;
}
