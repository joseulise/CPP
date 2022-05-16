// ***********************************************************
// Source File: StudentListManager.cpp
// Author: Jose U. Figueroa Colon
// Student Number: 841-03-2641
// Date: October 22, 2007
// Purpose: Client code for clases Student, GradedCOurse.
// ***********************************************************

#include "Student.h"
#include "GradedCourse.h"
#include "SortedList_Arr_T.h"
#include <iostream>
#include <cctype>
#include <fstream>
#include <string>
#include<iomanip>

void readFile(SortedList<Student>& sList);
char showMenu();
void addStudent(SortedList<Student>& sList);
void deleteStudent(SortedList<Student>& sList);
void showStudentInfo(SortedList<Student> sList);
void showStudentList(SortedList<Student> sList);
void updateFile(SortedList<Student> sList);

//VALIDATION FUNCTIONS
bool validateName(string aName);
bool validateIdContains(string anId, SortedList<Student> sList);//para validar si esta en la lsita para add
bool validateId(string anId, SortedList<Student> sList);
bool validateNumOfCourses(int aNumber);
void convertCode(string& aCode);
bool validateCourseCode(string aCode);
bool validateCourseCredits(int numCredits);
bool validateCourseGrade(char aGrade);


using namespace std;

int main() 
{
	char menuOption;
	SortedList<Student> studentList;

	readFile(studentList);
	
	do{
		system("cls");
		menuOption=showMenu();
		switch(menuOption)
		{
		case '1':
			addStudent(studentList);
			break;
		case '2':
			deleteStudent(studentList);
			break;
		case '3':
			showStudentInfo(studentList);
			break;
		case '4':
			showStudentList(studentList);
			break;
		case '5':
			cout<<"EXIT"<<endl;
			system("pause");
			updateFile(studentList);
			return 0;
		default:
			cout<<"Invalid selection!!!"<<endl;
			system("pause");
			break;
		}//SWITCH
	}while(menuOption!=5);
	//updateFile(studentList);
	return 0;
}//MAIN

void readFile(SortedList<Student>& sList)
{
	Student tempStudent;

	string tempName, tempId, tempCode;
	int tempNum, tempCredits;
	char tempGrade;

	GradedCourse tempCourse;
	UnsortedList<GradedCourse> tempCourseList;
	
	ifstream infile("students.txt");

	if(infile.fail())//verifico que el archivo abrio
	{
		cout<<"Error opening file!!!\n";
		system("pause");
		exit(1);
	}

	sList.reset();//Inicializo la cantidad de cursos a -1
	sList.getNextItem().getCourseList().reset();
	//tempCourseList.reset();
	infile>>tempId;//PRIMAL READ

	while(infile)
	{
		infile.ignore(1);
		getline(infile, tempName, '#');
		infile>>tempNum;
		tempStudent.setId(tempId);
		tempStudent.setName(tempName);
		tempStudent.setNumOfCourses(tempNum);

		for(int a=0;a<tempNum;a++)
		{
			infile>>tempCode>>tempCredits>>tempGrade;//recojo los valores
			tempCourse.setCode(tempCode);//asigo el code en var temporera
			tempCourse.setCredits(tempCredits);//asigo el credits en var temporera
			tempCourse.setGrade(tempGrade);//asigo el grade en var temporera
			tempCourseList.insert(tempCourse);//inserto el curso en la lista de cursos
		}//FOR

		tempStudent.setCourseList(tempCourseList);	
		sList.insert(tempStudent);
		infile>>tempId;
	}//WHILE INFILE
	infile.close();
}


void updateFile(SortedList<Student> sList)
{

	Student tempStudent;
	//SortedList<Student> tempSList = sList;

	GradedCourse tempCourse;
	UnsortedList<GradedCourse> tempCourseList;

	ofstream outfile("students.txt");
	if(!outfile)
	{
		cout<<"Error opening file!!!\n";
		system("pause");
		exit(1);
	}
	sList.reset();//Inicializo la cantidad de cursos a -1
	//tempCourseList.reset();//reset para atravezar la lista
	for(int a=0;a<sList.getLength();a++)
	{
		tempStudent=sList.getNextItem();
		//tempStudent.getCourseList().reset();
		tempCourseList=tempStudent.getCourseList();//recojo la lista de cursos
		tempCourseList.reset();//reset para atravezar la lista
		outfile<<tempStudent.getId()<<" "<<tempStudent.getName()<<"# "
			<<tempStudent.getNumOfCourses()<<" ";
		for(int b=0;b<tempStudent.getNumOfCourses();b++)
		{
			tempCourse=tempCourseList.getNextItem();
			outfile<<tempCourse.getCode()<<" "<<tempCourse.getCredits()<<" "
				<<tempCourse.getGrade()<<" ";
		}//FOR CANTIDAD DE CURSOS
		outfile<<endl;
	}//FOR CANTIDAD DE ESTUDIANTES
	outfile.close();
}//VOID


char showMenu()
{
	char tempAnswer;

		system("cls");
		cout<<"Student List Manager"<<endl<<endl;
		cout<<"Menu:"<<endl;
		cout<<" 1. ADD a Student"<<endl
			<<" 2. DELETE a Student"<<endl
			<<" 3. SHOW Student info"<<endl
			<<" 4. SHOW Student List"<<endl
			<<" 5. EXIT"<<endl<<endl<<"_";
		cin>>tempAnswer;
		if(!isdigit(tempAnswer))
			return '0';
		else
		return tempAnswer;
}//CHAR SHOW MENU



void addStudent(SortedList<Student>& sList)
{
	Student tempStudent;
	string tempName;
	string tempId;
	int tempNum;

	GradedCourse tempCourse;
	string tempCode;
	int tempCredits;
	char tempGrade;

	UnsortedList<GradedCourse> tempCourseList;

	if(!sList.isFull())//verifico si no esta llena la lista primero
	{
		system("cls");
		cout<<"Student List Manager"<<endl;
		cout<<"Add Student"<<endl<<endl;

		//VALIDACION PARA EL NOMBRE
		do{
			cout<<"Student NAME: ";
			//verificar esto para recojer string
			//cin>>tempName;
			cin.ignore();
			getline(cin,tempName);			
			if(!validateName(tempName))
			{
				cout<<"Invalid NAME!!!\n";
				system("pause");
			}
		}while(validateName(tempName)==false);
		tempStudent.setName(tempName);
		//VALIDACION PARA EL ID

		
		do{
			cout<<"\nStudent ID: #";
			cin>>tempId;
			if(!validateId(tempId, sList))
			{
				cout<<"Invalid ID!!!\n";
				system("pause");
			}
			if(validateIdContains(tempId, sList))
			{
				cout<<"This ID is already reserved!!!"<<endl;
				system("pause");
			}
		}while(validateId(tempId, sList)==false || validateIdContains(tempId, sList));
		tempStudent.setId(tempId);
		//validacion para el numero de cursos
		
		do{
			cout<<"\nNumber of courses: ";
			cin>>tempNum;
			if(!validateNumOfCourses(tempNum))
			{
				cout<<"Invalid number!!!\n";
				system("pause");
			}
		}while(validateNumOfCourses(tempNum)==false);
		tempStudent.setNumOfCourses(tempNum);
		//ciclo para recojer todos los cursos y sus notas
		if(tempStudent.getNumOfCourses()!=0)
		{
			for(int counter=1;counter<=tempNum;counter++)
			{
				do{
					cout<<"Enter the #"<<counter<<" course code: ";
					cin>>tempCode;
					validateCourseCode(tempCode);
					if(!validateCourseCode(tempCode))
					{
						cout<<"Invalid COURSE CODE!!!\n";
						system("pause");
					}
				}while(validateCourseCode(tempCode)==false);
				convertCode(tempCode);//cambio el codigo a mayusculas
				tempCourse.setCode(tempCode);
	
				do{
					cout<<"Enter the course credits: ";
					cin>>tempCredits;
					validateCourseCredits(tempCredits);
					if(!validateCourseCredits(tempCredits))
					{
						cout<<"Invalid COURSE CREDITS!!!\n";
						system("pause");
					}
				}while(validateCourseCredits(tempCredits)==false);
				tempCourse.setCredits(tempCredits);

				do{
					cout<<"Enter the course grade: ";
					cin>>tempGrade;
					tempGrade=toupper(tempGrade);//mayusculas
					validateCourseGrade(tempGrade);
					if(!validateCourseGrade(tempGrade))
					{
						cout<<"Invalid COURSE GRADE!!!"<<endl;
						system("pause");
					}
				}while(!validateCourseGrade(tempGrade));
				cout<<endl;
				tempCourse.setGrade(tempGrade);

				//despus que recojo toda la data la inserto al estudiante
				tempCourseList.insert(tempCourse);
				//tempStudent.setCourseList(tempCourseList);
			}//FOR CANTIDAD DE CURSOS
			tempStudent.setCourseList(tempCourseList);//cuando ya tengo la lista se la asigno al estudiante
			sList.insert(tempStudent);//aki mismo se incrementa y lo inserta donde corresponde
		}//IF ALGUN CURSO
	}//IF NOT FULL
	else
	{
		cout<<"The list is full!!!\n";
		system("pause");
	}
}//FUNCTION



void deleteStudent(SortedList<Student>& sList)
{
	Student tempStudent;
	//string tempName;
	string tempId;
	//int tempNum;

	//GradedCourse tempCourse;
	//string tempCode;
	//int tempCredits;
	//char tempGrade;

	char option='N';

	if(!sList.isEmpty())//verifico si no esta vacia la lista primero
	{
		system("cls");
		cout<<"Student List Manager"<<endl;
		cout<<"Delete Student"<<endl<<endl;
		//VALIDACION PARA EL NOMBRE
		do{
			cout<<"Student ID: ";
			cin>>tempId;
			if(!validateId(tempId, sList))
				cout<<"Invalid ID!!!\n";
		}while(validateId(tempId, sList)==false);
		tempStudent.setId(tempId);//creo estudiante temporero para hacer la busqueda con el
		if(sList.contains(tempStudent))//aqui se hace la busqueda en la lista de estudiante con el id especificado
		{
			do{
				cout<<"Delete Student #"<<tempId<<"? ";
				cin>>option;
				option=toupper(option);
				if(option=='Y' && option=='N')
				{
					if(option=='Y')
					{
						sList.remove(tempStudent);
						cout<<"Student Deleted!!!\n";
						system("pause");
					}
					if(option=='N')
					{
						cout<<"Delete Aborted!!!\n";
						system("pause");
					}
					else
					{
						cout<<"Invalid selection!!!\n";
						system("pause");
					}
				}//IF
			}while(option!='Y' && option!='N');
		}//IF LIST CONTAINS ITEM
		else//si no esta
		{
			cout<<"The student is not in the list!!!"<<endl;
			system("pause");
		}
	}//IF LIST IS NOT EMPTY
	else//si la lista esta vacia
	{
		cout<<"The student list is empty!!!\n";
		system("pause");
	}
}//FUNCTION



void convertCode(string& aCode)
{
	for(int a=0;a<4;a++)
		aCode[a]=toupper(aCode[a]);
}


void showStudentInfo(SortedList<Student> sList)
{
	Student tempStudent;
	string tempId;

	GradedCourse tempCourse;
	UnsortedList<GradedCourse> tempCourseList;

	sList.reset();
	//sList.getNextItem().getCourseList().reset();
	//tempCourseList.reset();//chekiar esto

	system("cls");
	cout<<"Student List Manager"<<endl;
	cout<<"Show Student Info"<<endl<<endl;

	do{
		cout<<"Enter the student id to search: #";
		cin>>tempId;
		//validateId(tempId, sList);
		if(!validateId(tempId, sList))
		{
			cout<<"Invalid ID!!!"<<endl;
			system("pause");
		}
	}while(validateId(tempId, sList)==false);

	tempStudent.setId(tempId);//cuando este correcto lo asigno
	if(sList.contains(tempStudent))
	{
		//sList.findPosition(tempStudent);//verificar esto tambien
		tempStudent=sList.retrieve(tempStudent);//verificar esto
		tempCourseList=tempStudent.getCourseList();
		tempCourseList.reset();//reset aki despues de buscar la que era
		cout<<"Student found!!!\n\n";
		cout<<"ID: #"<<tempStudent.getId()<<endl
			<<"Name: "<<tempStudent.getName()<<endl
			<<"Amount of Courses: "<<tempStudent.getNumOfCourses()<<endl
			<<"Courses: "<<endl;
		for(int a=0;a<tempStudent.getNumOfCourses();a++)
		{
			tempCourse=tempCourseList.getNextItem();
			cout<<"Code: "<<tempCourse.getCode()<<endl
				<<"Credits: "<<tempCourse.getCredits()<<endl
				<<"Grade: "<<tempCourse.getGrade()<<endl;
		}
		cout<<setprecision(3)<<"GPA: "<<tempStudent.calcGPA()<<endl<<endl;
		system("pause");
	}//IF el estudiante esta
}

void showStudentList(SortedList<Student> sList)
{
	Student tempStudent;
	GradedCourse tempCourse;
	int flag=0;

	sList.reset();//para recorrer la lista
	//tempStudent.getCourseList().reset();//para atravezar esta lista

	

	if(!sList.isEmpty())
	{
		while(flag<sList.getLength())
		{
			system("cls");
			cout<<"Student List Manager"<<endl;
			cout<<"Show Student List"<<endl<<endl;
			tempStudent=sList.getNextItem();
			cout<<"ID #"<<tempStudent.getId()<<endl
			<<"Name: "<<tempStudent.getName()<<endl;
			//<<"Amount of Courses: "<<tempStudent.getNumOfCourses()<<endl
			//<<"Courses: "<<endl;
			/*for(int a=0;a<tempStudent.getNumOfCourses();a++)
			{
				//tempCourse=tempStudent.getCourseList().getNextItem();
				tempCourse=tempCourseList.getNextItem();
				cout<<"Code: "<<tempCourse.getCode()<<endl;
				cout<<"Credits: "<<tempCourse.getCredits()<<endl;
				cout<<"Grade: "<<tempCourse.getGrade()<<endl;
			}*/
			cout<<setprecision(3)<<"GPA: "<<tempStudent.calcGPA()<<endl<<endl;
			system("pause");
			flag++;//actualizo el contador
		}//WHILE
	}//SI LA LISTA CONTIENE ALGO
	else
	{
		cout<<"The list is empty!!!"<<endl;
		system("pause");
	}//ELSE
}//show student list


		
//VALIDATION FUNCTIONS****************************************************
//************************************************************************
bool validateName(string aName)
{
	//bool ok=true;
	
	if(aName.length()<3 || aName.length()>20)
		return false;	
	/*else
	{
		for(int a=1;a <= aName.length();a++)
		{
			if(isdigit(aName[a]))
				return false;
		}
	}*/
		return true;
}

bool validateId(string anId, SortedList<Student> sList)
{

	Student tempStudent;
	
	
		if(anId.length()==4)
		{

			for(int a=0;a<4;a++)
			{
				if(isalpha(anId[a]))
					return false;
			}//FOR
			//tempStudent.setId(anId);//asigno el valor para realizar la busqueda
			//if(!sList.contains(tempStudent))
				return true;//si esta bien
		}//IF
	return false;//si length no es 4
}

bool validateNumOfCourses(int aNumber)
{
	if(aNumber>=0 && aNumber<=6)
		return true;
	else
		return false;
}

bool validateCourseCode(string aCode)
{
	bool ok=true;
	
	if(aCode.length()==8)
	{
		for(int a=0;a<8;a++)
		{
			if(a<4)
			{
				if(isalpha(aCode[a]))
					continue;
				else
					ok=false;
			}//ELSE
			else
			{
				if(isdigit(aCode[a]))
					continue;
				else
					ok=false;
			}//ELSE
		}//FOR
	}//IF
	else
		ok=false;
	return ok;
}

bool validateCourseCredits(int numCredits)
{
	if(numCredits<0 || numCredits >5)
		return false;
	return true;
}

bool validateCourseGrade(char aGrade)
{
	if(aGrade=='A' || aGrade=='B' || aGrade=='C' || aGrade=='D' || aGrade=='F')
		return true;
	return false;
}

bool validateIdContains(string anId, SortedList<Student> sList)
{
	Student tempStudent;
	tempStudent.setId(anId);
	if(sList.contains(tempStudent))
		return true;
	return false;
}
	