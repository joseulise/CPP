// ***********************************************************
// Source File: GradedCourse.cpp
// Author: Jose U. Figueroa Colon
// Student Number: 841-03-2641
// Date: October 22, 2007
// Purpose: Source file of class GradedCourse.
// ***********************************************************
//SIN THROW

#include "GradedCourse.h"
#include <cctype>

using namespace std;

GradedCourse::GradedCourse()// – inicializa el código del curso a “XXXX0000” y la cantidad de créditos a 3.
{
	code="XXXX0000";
	credits=3;
}

GradedCourse::GradedCourse(string aCode)// – inicializa el código del curso al valor indicado y la cantidad de créditos a 3.
{
	//name="XXX";
	code=aCode;
	credits=3;
}

void GradedCourse::setCode(string aCode)// – asigna el valor indicado al código del curso.
{
	code=aCode;
}

void GradedCourse::setCredits(int numCredits)// – asigna el valor indicado a la cantidad de créditos del curso.
{
	credits=numCredits;
}

void GradedCourse::setGrade(char aGrade)// – asigna el valor indicado a la nota del curso.
{
	grade=aGrade;
}

string GradedCourse::getCode() const// – devuelve el código del curso.
{
	return code;
}

int GradedCourse::getCredits() const// – devuelve la cantidad de créditos del curso.
{
	return credits;
}

char GradedCourse::getGrade() const// – devuelve la nota del curso.
{
	return grade;
}

int GradedCourse::calcHonorPoints() const// – devuelve la cantidad de puntos de honor del curso.  Se calcula multiplicando el equivalente numérico de la letra de la nota 
							//(‘A’ = 4, ‘B’ = 3, ‘C’ = 2, ‘D’ = 1, ‘F’ = 0) por la cantidad de créditos.
{
	switch(grade)
	{
	case 'A':
		return 4*credits;
		break;
	case 'B':
		return 3*credits;
		break;
	case 'C':
		return 2*credits;
		break;
	case 'D':
		return 1*credits;
		break;
	case 'F':
		return 0;
		break;
	default:
		return 0;
		break;
	}
}

bool GradedCourse::operator ==(GradedCourse anotherCourse) const
{
	if(code==anotherCourse.getCode())
		return true;
	else return false;
}

bool GradedCourse::operator !=(GradedCourse anotherCourse) const
{
	if(code!=anotherCourse.getCode())
		return true;
	else return false;
}

bool GradedCourse::operator <(GradedCourse anotherCourse) const
{
	if(code<anotherCourse.getCode())
		return true;
	else return false;
}

bool GradedCourse::operator <=(GradedCourse anotherCourse) const
{
	if(code<=anotherCourse.getCode())
		return true;
	else return false;
}

bool GradedCourse::operator >(GradedCourse anotherCourse) const
{
	if(code>anotherCourse.getCode())
		return true;
	else return false;
}

bool GradedCourse::operator >=(GradedCourse anotherCourse) const
{
	if(code>=anotherCourse.getCode())
		return true;
	else return false;
}

