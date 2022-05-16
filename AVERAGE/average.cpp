/****************************************************************
* average.cpp													*
* Jose Figueroa Colon     841-03-2641							*
* SICI 4036														*
*****************************************************************/
#include <iostream>
#include <iomanip>

using namespace std;

const int MAX=10;										//constante

void getNumOfExams(int& num);							//declaracion de funciones
void getExamScore(int ctr, int& score);
float calcAverage(int sum, int num);
char defGrade(int avg);
void showResults(int num, float avg, char grade);

int main()												//main body
{
	int numOfExams, examScore, sumScores=0;				//lista de variables
	float average=0;
	char grade;

	getNumOfExams(numOfExams);							//llamado de funcion
	for(int n=0;n<numOfExams;n++)						//ciclo para recojer puntuaciones
	{
		getExamScore(n, examScore);
		sumScores+=examScore;							//acumulo las puntuaciones
	}
	average=calcAverage(sumScores, numOfExams);			//llamado a funcion de promedio
	grade=defGrade(average);							//llamado a funcion de nota
	showResults(numOfExams, average, grade);			//muestra de resultados
	return 0;
}
/**********************************************************************/

void getNumOfExams(int& numOfExams)						//funcion para cantidad de examenes
{											
	do
	{
		cout<<"Enter the amount of exams: ";			//pedido de cantidad
		cin>>numOfExams;						
		if(numOfExams<0 || numOfExams>10)				//validacion
			cout<<"A number between 1 and 10 must be entered!\n";	//mensaje de error
	}while(numOfExams<1 || numOfExams>10);
}
/**********************************************************************/

void getExamScore(int n, int& examScore)				//funcion para recojer puntuaciones
{
	do
	{
		cout<<"Enter the score for exam #"<<n+1<<": ";	//recojido de puntuacion
		cin>>examScore;
		if(examScore<0 || examScore >100)
			cout<<"A number between 0 and 100 must be entered!\n";	//mensaje de error
	}while(examScore<0 || examScore>100);				
}
/**********************************************************************/

float calcAverage(int sumScores, int numOfExams)
{
	return sumScores/numOfExams;						//calculo y devuelvo el promedio
}
/**********************************************************************/

char defGrade(int average)
{														//if anidado para asignar nota
	if(average<=100 && average>=90)	
		return 'A';
		else if(average<=89 && average>=80)
			return 'B';
			else if(average<=79 && average>=70)
				return 'C';
				else if(average<=69 && average>=60)
					return 'D';
					else return 'F';
}
/**********************************************************************/

void showResults(int numOfExams, float average, char grade)
{														//se muestra en pantalla 
	cout<<fixed<<showpoint<<setprecision(3);			//los resultados finales
	cout<<"Average: %"<<average<<endl;
	cout<<"Grade: "<<grade<<endl;
	system("pause");
}