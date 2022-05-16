// ***********************************************************
// Source File: Complex.h
// Author: Jose U. Figueroa Colon
// Student Number: 841-03-2641
// Date: October 22, 2007
// Purpose: Header file of class GradedCourse.
// ***********************************************************


#ifndef GRADEDCOURSE_H
#define GRADEDCOURSE_H

#include <string>
//#include "
using namespace strd;
 
class GradedCourse
{
private:
	string code;// � el c�digo del curso (string de 8 caracteres num�ricos, por ejemplo: �SICI4036�)
	int credits;// � la cantidad de cr�ditos del curso (entero entre 1 y 5)
	char grade;// � la letra de la nota del curso (caracter �A�, �B�, �C�, �D� o �F�)

public:
	GradedCourse();// � inicializa el c�digo del curso a �XXXX0000� y la cantidad de cr�ditos a 3.
	GradedCourse(string aCode);// � inicializa el c�digo del curso al valor indicado y la cantidad de cr�ditos a 3.
	void setCode(string aCode);// � asigna el valor indicado al c�digo del curso.
	void setCredits(int numCredits);// � asigna el valor indicado a la cantidad de cr�ditos del curso.
	void setGrade(char aGrade);// � asigna el valor indicado a la nota del curso.
	string getCode() const;// � devuelve el c�digo del curso.
	int getCredits() const;// � devuelve la cantidad de cr�ditos del curso.
	char getGrade() const;// � devuelve la nota del curso.
	int calcHonorPoints() const;// � devuelve la cantidad de puntos de honor del curso.
								//Se calcula multiplicando el equivalente num�rico de la letra de la nota
								//(�A� = 4, �B� = 3, �C� = 2, �D� = 1, �F� = 0) por la cantidad de cr�ditos.
	bool operator ==(Course anotherCourse) const;// � devuelve true si dos cursos tienen el mismo c�digo.
	bool operator !=(Course anotherCourse) const;// � devuelve true si dos cursos no tienen el mismo c�digo.

