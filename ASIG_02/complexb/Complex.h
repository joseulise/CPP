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
	float realPart;//la parte real del número complejo
	float imaginaryPart;//la parte imaginaria del número complejo

public:

	Complex();										// inicializa tanto la parte real como la imaginaria a 0.0F.

	Complex(float aRealPart, float anImaginaryPart);//inicializa el número complejo con los valores indicados.

	void setRealPart(float newRealPart);			//asigna a la parte real el valor indicado.

	void setImaginaryPart(float newImaginaryPart);	//asigna a la parte imaginaria el valor indicado.

	float getRealPart()const;						//devuelve la parte real del número complejo

	float getImaginaryPart()const;					//devuelve la parte imaginaria del número complejo

	Complex operator+(Complex anotherComplex)const;//devuelve la suma de dos números complejos según la siguiente fórmula (asumiendo que a+bi es el primer número y que c+di es el otro número):
													//(a + bi) + (c + di) = (a + c) + (b + d)i
													//Recomendación: declare variables temporeras para almacenar la parte entera y la parte imaginaria del resultado (tempReal y tempImaginary).
													//Cuando calcule el resultado, use return Complex(tempReal, tempImaginary); para devolver la suma de los números complejos como un nuevo número complejo. 		

	Complex operator-(Complex anotherComplex)const;//– devuelve la resta de dos números complejos según la siguiente fórmula (asumiendo que a+bi es el primer número y que c+di es el otro número):
													//(a + bi) - (c + di) = (a - c) + (b - d)i

	Complex operator*(Complex anotherComplex)const;//devuelve la multiplicación de dos números complejos según la siguiente fórmula
													//(asumiendo que a+bi es el primer número y que c+di es el otro número):
													//(a + bi) * (c + di) = (a*cb*d) + (a*d + b*c)i

	bool operator==(Complex anotherComplex)const;//devuelve true si ambos números complejos son iguales según la siguiente fórmula 
													//(asumiendo que a+bi es el primer número y que c+di es el otro número):
													//(a + bi) == (c + di) si y sólo si a == c y b == d

	bool operator!=(Complex anotherComplex)const;//devuelve true si ambos números complejos son diferentes según la siguiente fórmula
													//(asumiendo que a+bi es el primer número y que c+di es el otro número):
													//(a + bi) != (c + di) si si a != c ó b != d

	string toString()const;						//devuelve un string que servirá para mostrar el número complejo como expresión de la forma a + bi. 
};
#endif