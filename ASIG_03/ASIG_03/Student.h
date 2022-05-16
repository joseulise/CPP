// ***********************************************************
// Header File: Student.h
// Author: Jose U. Figueroa Colon
// Student Number: 841-03-2641
// Date: October 22, 2007
// Purpose: Header file of class Student.
// ***********************************************************


#ifndef STUDENT_H
#define STUDENT_H


#include "GradedCourse.h"
#include "UnsortedList_Arr_T.h"
#include <string>

using namespace std;

class Student
{
private:
	//*********CHEKIAR ESTO*****************************
	UnsortedList<GradedCourse> courseList; // – la lista de cursos matriculados

	string id;// – la identificación del estudiante (string de 4 caracteres numéricos)
	string name;// – el nombre del estudiante (string de entre 3 y 20 caracteres)
	int numOfCourses;// – la cantidad de cursos matriculados (entero entre 0 y 6)
	
	
public:
	Student();// – inicializa la identificación a “0000”, el nombre a “XXX” y la 
				//cantidad de cursos matriculados a 0 .
	Student(string anId);// – inicializa la identificación al valor indicado, el nombre 
						//a “XXX” y la cantidad de cursos matriculados a 0 .
	void setId(string anID);// – asigna el valor indicado a la identificación.
	void setName(string aName);// – asigna el valor indicado al nombre.
	void setNumOfCourses(int aNumber);// – asigna el valor indicado a la cantidad 
										//de cursos matriculados.
	void setCourseList(UnsortedList<GradedCourse> aList);// – asigna la lista de cursos indicada.
	string getId() const;// – devuelve la identificación del estudiante
	string getName() const;// – devuelve el nombre del estudiante
	int getNumOfCourses() const;// – devuelve la cantidad de cursos matriculados
	UnsortedList<GradedCourse> getCourseList() const;// – devuelve la lista de cursos matriculados
	float calcGPA() const;// – devuelve el promedio académico (GPA) del 
							//estudiante.  El promedio se calcula como la suma de los puntos de honor de cada 
							//curso dividido por la cantidad de créditos.
	bool operator ==(Student anotherStudent) const;// – devuelve true si dos estudiantes tienen la misma identificación.
	bool operator !=(Student anotherStudent) const;// – devuelve true si dos estudiantes no tienen la misma identificación.
	bool operator <(Student anotherStudent) const;
	bool operator <=(Student anotherStudent) const;
	bool operator >(Student anotherStudent) const;
	bool operator >=(Student anotherStudent) const;
};

#endif

	