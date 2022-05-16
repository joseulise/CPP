// ***********************************************************
// Source File: postfix_gen.cpp
// Author: Jose U. Figueroa Colon
// Student Number: 841-03-2641
// Date: October 31, 2007
// Purpose: Source file for postfix evaluator.
// ***********************************************************

//Header Files
#include "Stack_Arr_T.h"//para los templates de stack
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void readFile(ifstream& anInputFile, string& aString);
void updateOutputFile(int aResult, int aCounter);
//void updateArray(int anArray[], int aResult, int& aCounter);
void updateOutputFile(ofstream& aFile, int aResult);

bool isOperand(char aChar);
bool isOperator(char aChar);
int whichOperator(char aChar);

int main()
{
	char tempChar;//, tempFirstDigit, tempSecondDigit;
	string postfixEquation="", tempNumberString;
	Stack<int> operandStack;
	int operand1=0, operand2=0, tempResult=0, tempNumber;
	int tempCounter=0;

	//ARCHIVOS*******************************************************
	ifstream inputfile("postfix.txt");
	if(!inputfile)//si hay problemas con el archivo
	{
		cout<<"Error opening file!!!"<<endl;
		system("pause");
		exit(1);
	}
	ofstream outputfile("results.txt");
	if(!outputfile)//si hay problemas con el archivo
	{
		cout<<"Error opening file!!!"<<endl;
		system("pause");
		exit(1);
	}
	//****************************************************************

	while(!inputfile.eof())
	{
		if(operandStack.isFull()==false)
		{
			postfixEquation="";
			readFile(inputfile, postfixEquation);
			cout<<postfixEquation<<endl<<endl;
			system("pause");
			for(int count=0;count<postfixEquation.length();count++)
			{
				tempChar=postfixEquation[count];//actualizo el caracter
				//cout<<postfixEquation<<endl<<endl;
				//system("pause");
				if(isOperand(tempChar))//si es un numero
				{
					if(isOperand(postfixEquation[count+1]))//si el proximo es un numero
					{
						tempNumberString="";//inicializo el string a null
						while(isOperand(tempChar))//mientras sigan habiendo numeros
						{
							tempNumberString+=tempChar;	
							count++;					
							//tempNumberString+=postfixEquation[count+1];//asigno el primer digito
							//incremento para no reevaluar el mismo digito
							tempChar=postfixEquation[count];//asigno el nuevo valor al chartempCounter++;
						}//while(isOperand(postfixEquation[count+1]));//while
						tempNumber=atoi(tempNumberString.c_str());//cambio el string a entero
						operandStack.push(tempNumber);//inserto el numero de varios digitos
						cout<<"Multiple Operand PUSHED in STACK."<<endl;
					}//if
					else
					{		
						tempNumberString=tempChar;
						tempNumber=atoi(tempNumberString.c_str());
						operandStack.push(tempNumber);//inserto el numero de un digito en el stack
						cout<<"Single Operand PUSHED in STACK."<<endl;
					}
				}
				if(!isOperand(tempChar) && isOperator(tempChar))//else//si es un operator
				{
					operand2=operandStack.peek();
					operandStack.pop();
					operand1=operandStack.peek();
					operandStack.pop();
					
					switch(whichOperator(tempChar))
					{
					case 1://suma
						tempResult=operand1 + operand2;
						break;
					case 2://resta
						tempResult=operand1 - operand2;
						break;
					case 3://mult
						tempResult=operand1 * operand2;
						break;
					case 4://divicion
						tempResult=operand1 / operand2;
						break;
					}//switch
					operandStack.push(tempResult);					
					cout<<"Result PUSHED in STACK."<<endl;
					//updateOutputFile(outputfile, tempResult);					
				}//else
			}//for
			if(inputfile)
			{
			tempResult = operandStack.peek();//asigo el resultado
			operandStack.pop();//saco el resultado del stack
			//the stack is now empty
			cout<<"Postfix equation: "<<postfixEquation<<endl;
			cout<<"Result: "<<tempResult<<endl;
			system("pause");
			system("cls");
			updateOutputFile(outputfile, tempResult);
			}
		}//if not full
		else if(operandStack.isFull())//si el stack esta lleno
		{
			cout<<"ERROR, STACK IS FULL!!!"<<endl<<endl;
			system("pause");
			inputfile.close();
			return 0;
		}
		
	}//while not end of file EOF
	cout<<"END OF FILE FOUND!!!"<<endl<<endl;
	cout<<"RESULTS file created!!!(results.txt)"<<endl;
	system("pause");
	inputfile.close();
	outputfile.close();
	return 0;
}

void readFile(ifstream& anInputFile, string& aString)
{
	getline(anInputFile, aString, '\n');//aqui se carga la ecuacion postfix completa
}//readFile

bool isOperand(char aChar)
{
	if(isdigit(aChar))
		return true;
	else return false;
}

bool isOperator(char aChar)
{
	if(aChar=='+' || aChar=='-' || aChar=='*' || aChar=='/')
		return true;
	else return false;
}//bool

int whichOperator(char aChar)
{
	int number=0;
	if(aChar=='+')
		number=1;
	else if(aChar=='-')
		number= 2;
	else if(aChar=='*')
		number= 3;
	else if(aChar=='/')
		number= 4;
	return number;
}

void updateOutputFile(ofstream& aFile, int aResult)
{
	aFile<<aResult<<endl;
}
