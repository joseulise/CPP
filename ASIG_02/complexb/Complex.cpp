// ***********************************************************
// Source File: Complex.cpp
// Author: Jose U. Figueroa Colon
// Student Number: 841-03-2641
// Date: October 3, 2007
// Purpose: Source file of class Complex.
// ***********************************************************


// Header files
#include "Complex.h"

using namespace std;

//Default constructor
// inicializa tanto la parte real como la imaginaria a 0.0f
Complex::Complex()
{
		realPart=0.0;
		imaginaryPart=0.0f;
}
//Parameterized constructor
//inicializa el n�mero complejo con los valores indicados
Complex::Complex(float aRealPart, float anImaginaryPart)
{
	if(anImaginaryPart>=0)
		imaginaryPart=anImaginaryPart;	
	else
		imaginaryPart=0;
	if(aRealPart>=0)
		realPart=aRealPart;	
	else
		realPart=0;

}


//asigna a la parte real el valor indicado
void Complex::setRealPart(float newRealPart)
{
	realPart=newRealPart;
}


//asigna a la parte imaginaria el valor indicado
void Complex::setImaginaryPart(float newImaginaryPart)
{
	imaginaryPart=newImaginaryPart;
}


//devuelve la parte real del n�mero complejo
float Complex::getRealPart() const
{
	return realPart;
}


//devuelve la parte imaginaria del n�mero complejo
float Complex::getImaginaryPart()const
{
	return imaginaryPart;
}


//devuelve la suma de dos n�meros complejos seg�n la siguiente f�rmula (asumiendo que a+bi es el primer n�mero y que c+di es el otro n�mero):
//(a + bi) + (c + di) = (a + c) + (b + d)i
//Recomendaci�n: declare variables temporeras para almacenar la parte entera y la parte imaginaria del resultado (tempReal y tempImaginary).
//Cuando calcule el resultado, use return Complex(tempReal, tempImaginary); para devolver la suma de los n�meros complejos como un nuevo n�mero complejo. 		
Complex Complex::operator+(Complex anotherComplex)const
{
	float tempReal=0; 
	float tempImaginary=0;

	tempReal = realPart + anotherComplex.getRealPart();
	tempImaginary = imaginaryPart + anotherComplex.getImaginaryPart();

	return Complex(tempReal, tempImaginary);
}

//� devuelve la resta de dos n�meros complejos seg�n la siguiente f�rmula
//(asumiendo que a+bi es el primer n�mero y que c+di es el otro n�mero):
//(a + bi) - (c + di) = (a - c) + (b - d)i
Complex Complex::operator-(Complex anotherComplex)const
{
	float tempReal=0; 
	float tempImaginary=0;
	
	tempReal = realPart - anotherComplex.getRealPart();
	tempImaginary = imaginaryPart - anotherComplex.getImaginaryPart();

	return Complex(tempReal, tempImaginary);
}

//devuelve la multiplicaci�n de dos n�meros complejos seg�n la siguiente f�rmula 
//(asumiendo que a+bi es el primer n�mero y que c+di es el otro n�mero):
//(a + bi) * (c + di) = (a*cb*d) + (a*d + b*c)i
Complex Complex::operator*(Complex anotherComplex)const
{
	float tempReal=0;
	float tempImaginary=0;

	tempReal = (realPart * anotherComplex.getRealPart() * imaginaryPart * anotherComplex.getImaginaryPart()); 
	tempImaginary = (realPart * anotherComplex.getImaginaryPart() + imaginaryPart * anotherComplex.getRealPart());
    
	return Complex(tempReal, tempImaginary);
}


//devuelve true si ambos n�meros complejos son iguales seg�n la siguiente f�rmula 
//(asumiendo que a+bi es el primer n�mero y que c+di es el otro n�mero):
//devuelve true si ambos n�meros complejos son iguales seg�n la siguiente f�rmula (asumiendo que a+bi es el primer n�mero y que c+di es el otro n�mero):
bool Complex::operator==(Complex anotherComplex)const
{
	if(realPart==anotherComplex.getRealPart() && imaginaryPart==anotherComplex.getImaginaryPart())
		return true;
	else
		return false;
}
//devuelve true si ambos n�meros complejos son diferentes seg�n la siguiente f�rmula 
//(asumiendo que a+bi es el primer n�mero y que c+di es el otro n�mero):
//(a + bi) != (c + di) si si a != c � b != d

bool Complex::operator!=(Complex anotherComplex)const
{
	if(realPart!=anotherComplex.getRealPart() && imaginaryPart!=anotherComplex.getImaginaryPart())
		return true;
	else
		return false;
}

//devuelve un string que servir� para mostrar el n�mero complejo como expresi�n de la forma a + bi
string Complex::toString()const
{
	ostringstream outString; // An output string stream

	outString << realPart;
	
	if(imaginaryPart>0)
	{
		if(imaginaryPart==1)
			outString<<"+"<<"i";
		else
			outString<<"+"<<imaginaryPart<<"i";
	}
	else
	{
		if(imaginaryPart<0)
			outString<<imaginaryPart<<"i";
	}
	return outString.str();
}