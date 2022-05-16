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
//inicializa el número complejo con los valores indicados
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


//devuelve la parte real del número complejo
float Complex::getRealPart() const
{
	return realPart;
}


//devuelve la parte imaginaria del número complejo
float Complex::getImaginaryPart()const
{
	return imaginaryPart;
}


//devuelve la suma de dos números complejos según la siguiente fórmula (asumiendo que a+bi es el primer número y que c+di es el otro número):
//(a + bi) + (c + di) = (a + c) + (b + d)i
//Recomendación: declare variables temporeras para almacenar la parte entera y la parte imaginaria del resultado (tempReal y tempImaginary).
//Cuando calcule el resultado, use return Complex(tempReal, tempImaginary); para devolver la suma de los números complejos como un nuevo número complejo. 		
Complex Complex::operator+(Complex anotherComplex)const
{
	float tempReal=0; 
	float tempImaginary=0;

	tempReal = realPart + anotherComplex.getRealPart();
	tempImaginary = imaginaryPart + anotherComplex.getImaginaryPart();

	return Complex(tempReal, tempImaginary);
}

//– devuelve la resta de dos números complejos según la siguiente fórmula
//(asumiendo que a+bi es el primer número y que c+di es el otro número):
//(a + bi) - (c + di) = (a - c) + (b - d)i
Complex Complex::operator-(Complex anotherComplex)const
{
	float tempReal=0; 
	float tempImaginary=0;
	
	tempReal = realPart - anotherComplex.getRealPart();
	tempImaginary = imaginaryPart - anotherComplex.getImaginaryPart();

	return Complex(tempReal, tempImaginary);
}

//devuelve la multiplicación de dos números complejos según la siguiente fórmula 
//(asumiendo que a+bi es el primer número y que c+di es el otro número):
//(a + bi) * (c + di) = (a*cb*d) + (a*d + b*c)i
Complex Complex::operator*(Complex anotherComplex)const
{
	float tempReal=0;
	float tempImaginary=0;

	tempReal = (realPart * anotherComplex.getRealPart() * imaginaryPart * anotherComplex.getImaginaryPart()); 
	tempImaginary = (realPart * anotherComplex.getImaginaryPart() + imaginaryPart * anotherComplex.getRealPart());
    
	return Complex(tempReal, tempImaginary);
}


//devuelve true si ambos números complejos son iguales según la siguiente fórmula 
//(asumiendo que a+bi es el primer número y que c+di es el otro número):
//devuelve true si ambos números complejos son iguales según la siguiente fórmula (asumiendo que a+bi es el primer número y que c+di es el otro número):
bool Complex::operator==(Complex anotherComplex)const
{
	if(realPart==anotherComplex.getRealPart() && imaginaryPart==anotherComplex.getImaginaryPart())
		return true;
	else
		return false;
}
//devuelve true si ambos números complejos son diferentes según la siguiente fórmula 
//(asumiendo que a+bi es el primer número y que c+di es el otro número):
//(a + bi) != (c + di) si si a != c ó b != d

bool Complex::operator!=(Complex anotherComplex)const
{
	if(realPart!=anotherComplex.getRealPart() && imaginaryPart!=anotherComplex.getImaginaryPart())
		return true;
	else
		return false;
}

//devuelve un string que servirá para mostrar el número complejo como expresión de la forma a + bi
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