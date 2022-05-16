// ***********************************************************
// Source File: Complex.h
// Author: Jose U. Figueroa Colon
// Student Number: 841-03-2641
// Date: October 3, 2007
// Purpose: Header file of class Complex.
// ***********************************************************


#ifndef COMPLEX_H
#define COMPLEX_H

#include <string>
#include <sstream>
using namespace std;

class Complex
{
private:
	float realPart;//la parte real del n�mero complejo
	float imaginaryPart;//la parte imaginaria del n�mero complejo

public:

	Complex();										// inicializa tanto la parte real como la imaginaria a 0.0F.

	Complex(float aRealPart, float anImaginaryPart);//inicializa el n�mero complejo con los valores indicados.

	void setRealPart(float newRealPart);			//asigna a la parte real el valor indicado.

	void setImaginaryPart(float newImaginaryPart);	//asigna a la parte imaginaria el valor indicado.

	float getRealPart()const;						//devuelve la parte real del n�mero complejo

	float getImaginaryPart()const;					//devuelve la parte imaginaria del n�mero complejo

	Complex operator+(Complex anotherComplex)const;//devuelve la suma de dos n�meros complejos seg�n la siguiente f�rmula (asumiendo que a+bi es el primer n�mero y que c+di es el otro n�mero):
													//(a + bi) + (c + di) = (a + c) + (b + d)i
													//Recomendaci�n: declare variables temporeras para almacenar la parte entera y la parte imaginaria del resultado (tempReal y tempImaginary).
													//Cuando calcule el resultado, use return Complex(tempReal, tempImaginary); para devolver la suma de los n�meros complejos como un nuevo n�mero complejo. 		

	Complex operator-(Complex anotherComplex)const;//� devuelve la resta de dos n�meros complejos seg�n la siguiente f�rmula (asumiendo que a+bi es el primer n�mero y que c+di es el otro n�mero):
													//(a + bi) - (c + di) = (a - c) + (b - d)i

	Complex operator*(Complex anotherComplex)const;//devuelve la multiplicaci�n de dos n�meros complejos seg�n la siguiente f�rmula
													//(asumiendo que a+bi es el primer n�mero y que c+di es el otro n�mero):
													//(a + bi) * (c + di) = (a*cb*d) + (a*d + b*c)i

	bool operator==(Complex anotherComplex)const;//devuelve true si ambos n�meros complejos son iguales seg�n la siguiente f�rmula 
													//(asumiendo que a+bi es el primer n�mero y que c+di es el otro n�mero):
													//(a + bi) == (c + di) si y s�lo si a == c y b == d

	bool operator!=(Complex anotherComplex)const;//devuelve true si ambos n�meros complejos son diferentes seg�n la siguiente f�rmula
													//(asumiendo que a+bi es el primer n�mero y que c+di es el otro n�mero):
													//(a + bi) != (c + di) si si a != c � b != d

	string toString()const;						//devuelve un string que servir� para mostrar el n�mero complejo como expresi�n de la forma a + bi. 
};
#endif