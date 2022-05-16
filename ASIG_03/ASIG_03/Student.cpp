// ***********************************************************
// Source File: Student.cpp
// Author: Jose U. Figueroa Colon
// Student Number: 841-03-2641
// Date: October 22, 2007
// Purpose: Source file of class Student.
// ***********************************************************

#include "Student.h"
#include <cctype>

using namespace std;

Student::Student()
{
	id="0000";
	name="XXX";
	numOfCourses=0;
}

Student::Student(string anId)
{
	id=anId;//anId;
	name="XXX";
	numOfCourses=0;
}

void Student::setId(string anId)
{
	id=anId;
}

void Student::setName(string aName)
{
	name=aName;
}

void Student::setNumOfCourses(int aNumber)
{
	numOfCourses=aNumber;
}

void Student::setCourseList(UnsortedList<GradedCourse> aList)
{
	/*
	if(!courseList.isFull())
	{
		if(!aList.isEmpty())//si la nueva lista esta vacia
		{
			//throw ListIsEmptyExeption();
			//throw string("The new list is empty!!!")
*/	
	courseList=aList;
//	}
//	}
	//else
}

string Student::getId() const
{
	return id;
}

string Student::getName() const
{
	return name;
}

int Student::getNumOfCourses() const
{
	return numOfCourses;
}


UnsortedList<GradedCourse> Student::getCourseList() const
{
	return courseList;
}

float Student::calcGPA() const//VERIFICAR ESTE MODULO!!!!
{
	float tempAcumPoints=0.0;
	int tempAcumCredits=0;
	int tempLength = courseList.getLength();

	UnsortedList<GradedCourse> courseListTemp = courseList;
	
	GradedCourse tempCourse;

	courseListTemp.reset();
	for(int a=0;a<tempLength;a++)
	{
		tempCourse = courseListTemp.getNextItem();
		tempAcumPoints=tempAcumPoints + tempCourse.calcHonorPoints();
		tempAcumCredits=tempAcumCredits + tempCourse.getCredits();
	}
	return tempAcumPoints / tempAcumCredits;
}

bool Student::operator ==(Student anotherStudent) const
{
	if(id==anotherStudent.getId())
		return true;
	else return false;
}

bool Student::operator !=(Student anotherStudent) const
{
	if(id!=anotherStudent.getId())
		return true;
	else return false;
}

bool Student::operator <(Student anotherStudent) const
{
	if(id<anotherStudent.getId())
		return true;
	else return false;
}
	
bool Student::operator <=(Student anotherStudent) const
{
	if(id<=anotherStudent.getId())
		return true;
	else return false;
}

bool Student::operator >(Student anotherStudent) const
{
	if(id>anotherStudent.getId())
		return true;
	else return false;
}

bool Student::operator >=(Student anotherStudent) const
{
	if(id<anotherStudent.getId())
		return true;
	else return false;
}