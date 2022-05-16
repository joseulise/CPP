// ***********************************************************
// Source File: CylinderTester.cpp
// Author: Jose U. Figueroa Colon
// Student Number: 841-03-2641
// Date: October 3, 2007
// Purpose: Client application to test class Cylinder.
// ***********************************************************


// Header files
#include "Cylinder.h"

#include <iostream>

using namespace std;

//Este modulo muestra en pantalla el cilindro especificado
void showCylinderData(Cylinder cylinder1);
//modulo para mostrar menu
char showMenu();
//esta funcion le permite escojer al usuario que cilindro quiere ver
void askCylinder(Cylinder cylinder1);
//etse modulo es para cambiar la altura
void changeHeight();
//este modulo es para cambiar la base que es un circulo
void changeBase();
//modulo para comparar cilindros
void compareCylinders(Cylinder cylinder1, Cylinder cylinder2);

int main()
{

	Cylinder c1,							// height = 0, radius of base = 0, center of base = (0, 0)
		c2(6.5),							// height = 6.5, radius of base = 0, center of base = (0, 0)
		c3(3.5, Circle(3)),					// height = 6.5, radius of base = 3, center of base = (0, 0)
		c4(4.5, Circle(2, Point(4, 5)));	// height = 6.5, radius of base = 3, center of base = (4, 5)
	char menuOption;

	do
	{
		system("cls");
		menuOption=showMenu();
		switch(menuOption)
		{
		case 'A':
			showCylindersData(Cylinder cylinder1, Cylinder cylinder2);
			break;
		case 'B':
			changeHeight();
			break;
		case 'C':
			changeBase();
			break;
		case 'D':
			compareCylinders(Cylinder cylinder1, Cylinder cylinder2);
			break;
		case'X':
			cout<<"EXIT"<<endl;
			system("pause");
			return 0;
		default:
			cout<<"Invalid selection!!!"<<endl;
			system("pause");
			break;
		}//SWITCH
	}while(menuOption!='X');
	return 0;
}
	
	/*
	do{
		if(counter<5)
		{			
			if(counter==1)
			{
				showCylinderData(c1, counter);
				//c1 comparisons
				if (c1.compareTo(c2) == 0)
					cout<<"c1 = c2"<<endl;
				if (c1.compareTo(c2)<0)
					cout<<"c1 < c2"<<endl;
				if (c1<=c2)
					cout<<"c1 <= c2"<<endl;
				if (c1>c2)
					cout<<"c1 > c2"<<endl;
				if (c1>=c2)
					cout<<"c1 >= c2"<<endl;
				if (c1.compareTo(c2)!=0)
					cout<<"c1 != c2"<<endl;				
			}
			else if(counter==2)
			{
				showCylinderData(c2, counter);
				//c2 comparisons
				if (c2.compareTo(c3) == 0)
					cout<< "c2 = c3" << endl;
				if (c2<c3)
					cout<<"c2 < c3"<<endl;
				if (c2<=c3)
					cout<<"c2 <= c3"<<endl;
				if (c2>c3)
					cout<<"c2 > c3"<<endl;
				if (c2>=c3)
					cout<<"c2 >= c3"<<endl;
				if (c2!=c3)
					cout<<"c2 != c3"<<endl;
			}
			else if(counter==3)
			{
				showCylinderData(c3, counter);
				//c3 comparisons
				if (c3.compareTo(c1) == 0)
					cout << "c3 = c1" << endl;
				if (c3<c1)
					cout<<"c3 < c1"<<endl;
				if (c3<=c1)
					cout<<"c3 <= c1"<<endl;
				if (c3>c1)
					cout<<"c3 > c1"<<endl;
				if (c3>=c1)
					cout<<"c3 >= c1"<<endl;
				if (c3!=c1)
					cout<<"c3 != c1"<<endl;
			}
			else
			{
				showCylinderData(c4, counter);
				//c4 comparisons
				if (c4.compareTo(c2) == 0)
					cout << "c4 = c2" << endl;
				if (c4<c2)
					cout<<"c4 < c2"<<endl;
				if (c4<=c2)
					cout<<"c4 <= c2"<<endl;
				if (c4>c2)
					cout<<"c4 > c2"<<endl;
				if (c4>=c2)
					cout<<"c4 >= c2"<<endl;
				if (c4!=c2)
					cout<<"c4 != c2"<<endl;	
			}

		cout<<"\nDo you want to continue?"<<endl
			<<"(Y\\N): ";
		cin>>answer;
		answer=toupper(answer);
		counter++;
		}//IF
		else
		{
			cout<<"There are no more cylinders!!!"<<endl<<endl;
			system("pause");
			return 0;
		}
	}while(answer!='N');

	return 0;*/
}

void askCylinder(Cylinder cylinder1)
{
	char selection;

	system("cls");
	cout<<"Show cylinder"<<endl<<endl;
	cout<<"Enter the selection for the cylinder you want to see: "<<endl;
	cout<<" A. Cylinder 1"<<endl
		<<" B. Cylinder 2"<<endl
		<<" C. Cylinder 3"<<endl
		<<" D. Cylinder 4"<<endl
		<<" X. RETURN"<<endl<<endl;
	cin>>selection;
	selection=toupper(selection);


void showCylinderData(Cylinder cylinder1))
{
	system("cls");
	cout<<"Cylinders Application"<<endl<<endl;
	cout<<"Cylinder #"<<cont<<endl;
	cout<<"Surface Area: "<<c.calcSurfaceArea()<<endl;
	cout<<"Volume: " <<c.calcVolume()<<endl;
	cout << "Height: " << c.getHeight() << endl;
	cout << "Radius of Base: " << c.getBase().getRadius() << endl;
	cout << "Center of Lower Base: " << c.getBase().getCenter().getX() << ", "
		<< c.getBase().getCenter().getY() << endl;
}


char showMenu()
{
	char tempAnswer;

		system("cls");
		cout<<"Cylinder Tester"<<endl<<endl;
		cout<<"Menu:"<<endl;
		cout<<" A. Show Cylinders"<<endl
			<<" B. Change Cylinder Height"<<endl
			<<" C. Change Cylinder Base"<<endl
			<<" D. Compare Cylinders"<<endl
			<<" X. EXIT"<<endl<<endl<<"_";
		cin>>tempAnswer;
		tempAnswer=toupper(tempAnswer);
		return tempAnswer;
}//CHAR SHOW MENU
