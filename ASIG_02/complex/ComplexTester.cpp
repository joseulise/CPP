// ***********************************************************
// Source File: ComplexTester.cpp
// Author: Jose U. Figueroa Colon
// Student Number: 841-03-2641
// Date: October 3, 2007
// Purpose: Client application to test class Complex.
// ***********************************************************

// Header files
#include "Complex.h"
#include <iostream>

//modulo para mostrar menu
char showMenu();
//Este modulo muestra en pantalla los numeros comlpejos
void showComplex(Complex complex1, Complex complex2);
//etse modulo es para cambiar los valores
void changeComplex(Complex& complex1);
//modulo para sumar
void sumComplex(Complex complex1, Complex complex2);
//modulo para restar
void substractComplex(Complex complex1, Complex complex2);
//modulo para multiplicar
void multiplyComplex(Complex complex1, Complex complex2);
//modulo para comparar ==
void equalComplex(Complex complex1, Complex complex2);
//modulo para comparar!=
void notEqualComplex(Complex complex1, Complex complex2);

using namespace std;

int main()
{
	Complex c1(2, 1),	// c1 = 2 + i
		c2(3, 6);		// c2 = 3 + 6i
	Complex result;
	char menuOption;
	do
	{
		system("cls");
		menuOption=showMenu();
		switch(menuOption)
		{
		case 'A':
			showComplex(c1, c2);
			break;
		case 'B':
			changeComplex(c1);
			break;
		case 'C':
			changeComplex(c2);
			break;
		case 'D':
			sumComplex(c1, c2);
			break;
		case'E':
			substractComplex(c1, c2);
			break;
		case'F':
			multiplyComplex(c1, c2);
			break;
		case'G':
			equalComplex(c1, c2);
			break;
		case'H':
			notEqualComplex(c1, c2);
			break;
		case'I':
			cout<<"EXIT"<<endl;
			system("pause");
			return 0;
		default:
			cout<<"Invalid selection!!!"<<endl;
			system("pause");
			break;
		}//SWITCH
	}while(menuOption!='I');
	return 0;
}

char showMenu()
{
	char tempAnswer;

		system("cls");
		cout<<"Complex Tester"<<endl<<endl;
		cout<<"Menu:"<<endl;
		cout<<" A. Show Complex Numbers"<<endl
			<<" B. Change Complex Number c1"<<endl
			<<" C. Change Complex Number c2"<<endl
			<<" D. Sum Complex Numbers +"<<endl
			<<" E. Substract Complex Numbers -"<<endl
			<<" F. Multiply Complex Numbers *"<<endl
			<<" G. Compare Complex Numbers =="<<endl
			<<" H. Compare Complex Numbers !="<<endl
			<<" I. EXIT"<<endl<<endl<<"_";
		cin>>tempAnswer;
		tempAnswer=toupper(tempAnswer);
		return tempAnswer;
}//CHAR SHOW MENU



void showComplex(Complex complex1, Complex complex2)
{
	system("cls");
	cout<<"Show Complex Numbers"<<endl<<endl;
	cout<<"Complex number c1: "<<complex1.toString()<<endl;
	cout<<"Complex number c2: "<<complex2.toString()<<endl;
	system("pause");
}


void changeComplex(Complex& complex1)
{
	float tempRealPart, tempImaginaryPart;
	
	system("cls");
	cout<<"Change Complex Numbers"<<endl<<endl;
	cout<<"Enter the new real part: ";
	cin>>tempRealPart;
	complex1.setRealPart(tempRealPart);
	cout<<"Enter the new imaginary part: ";
	cin>>tempImaginaryPart;
	complex1.setImaginaryPart(tempImaginaryPart);
	cout<<"c1 has changed!!!"<<endl;
	system("pause");
}


void sumComplex(Complex complex1, Complex complex2)
{
	Complex tempComplex;

	system("cls");
	cout<<"Sum Complex Numbers"<<endl<<endl;
	tempComplex = complex1 + complex2;
	cout<<"c1 + c2 = "<<tempComplex.toString()<<endl;
	system("pause");
}


void substractComplex(Complex complex1, Complex complex2)
{
	Complex tempComplex;

	system("cls");
	cout<<"Substract Complex Numbers"<<endl<<endl;
	tempComplex = complex1 - complex2;
	cout<<"c1 - c2 = "<<tempComplex.toString()<<endl;
	system("pause");
}


void multiplyComplex(Complex complex1, Complex complex2)
{	
	Complex tempComplex;

	system("cls");
	cout<<"Multiply Complex Numbers"<<endl<<endl;
	tempComplex = complex1.operator *(complex2);
	//tempComplex = c1*c2;
	cout<<"c1 * c2 = "<<tempComplex.toString()<<endl;
	system("pause");
}


void equalComplex(Complex complex1, Complex complex2)
{
	system("cls");
	cout<<"Equal Complex Numbers"<<endl<<endl;
	if(complex1.operator==(complex2))
	{
		cout<<"c1 == c2"<<endl;
		system("pause");
	}
	else
	{
		cout<<"Both complex number aren't equal!!!"<<endl;
		system("pause");
	}
}

void notEqualComplex(Complex complex1, Complex complex2)
{
	system("cls");
	cout<<"Not Equal Complex Numbers"<<endl<<endl;
	if(complex1.operator!=(complex2))
	{
		cout<<"c1 != c2"<<endl;
		system("pause");
	}
	else
	{
		cout<<"Both complex number are equal!!!"<<endl;
		system("pause");
	}
}
