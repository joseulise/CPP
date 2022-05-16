/*********************************************************************
* Programa: seating_sys.cpp
* Autor: Jose U. Figueroa Colon #841-03-2641
* Curso: SICI 4036-LA1
* Fecha: 24 de septiembre de 2007
* Propósito:  Este programa lee un archivo de asientos disponibles y permite
* la reservacoin y cancelacion de asaientos ademas de mostrarlos en pantalla
**********************************************************************/

/*Librerias definidas*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cctype>

using namespace std;

//Constantes para arreglo bidimencional
const int COLS=6, ROWS=13;

//Este modulo es para leer el archivo y pasarlo a arreglo bidimencional
//Recibe el arreglo bidimencional
void readFile(char array[][COLS]);

//Este modulo es para mostrar el menu principal en pantalla
//Devuelve el valor escogido en el nombre de la funcion
int showMenu();

//Este modulo es para reservar un asiento
//Recibe el arreglo bidimencional
void reserveSeat(char array[][COLS]);

//Este modulo es para cancelar reservacion
//Recibe el arreglo bidimencional
void cancelReserve(char array[][COLS]);

//Este modulo es para mostrar los asientos en pantalla
//Recibe el arreglo bidimencional
void showSeats(const char array[][COLS]);

//Este modulo es para actualizar el archivo de asientos
//Recibe el arreglo bidimencional
void updateFile(const char array[][COLS]);

//Este modulo es para cambiar la letra de la fila por un nunmero entero
//Recibe la variable de la columna temporera
int changeLetter(char tempColumn);

int main()
{	
	//VARIABLES LOCALES DE MAIN
	char seatArray[ROWS][COLS];
	int opcionMenu;

	readFile(seatArray);	//LEO EL ARCHIVO
	
	do
	{
		system("cls");
		opcionMenu=showMenu();	//MUESTRO MENU Y HAGO LA LLAMDA PERTINENETE
		if(opcionMenu==1)
			reserveSeat(seatArray);
		if(opcionMenu==2)
			cancelReserve(seatArray);
		if(opcionMenu==3)
			showSeats(seatArray);
	}while(opcionMenu!=4);

	updateFile(seatArray);

	return 0;
}//MAIN
//*****************************************************************************************
void readFile(char array[][COLS])
{
	ifstream infile("dist.txt");//ABRO EL ARCHIVO
	if(!infile)					//SI NO ABRE
	{
		cout<<"Error opening file!"<<endl;
		exit(1);
	}
	while(infile)				//CICLO PARA LEER ARCHIVO
	{
		for(int r=0;r<ROWS;r++)
		{
			for(int c=0;c<COLS;c++)
				infile>>array[r][c];
		}
	}
	infile.close();
}//VOID READFILE

//*****************************************************************************************
int showMenu()
{
	int selection;	//VARIABLE LOCAL
	
	system("cls");
    cout<<"Airline Menu:"<<endl<<endl;
	cout<<"1) Reserve seat\n"
		<<"2) Cancel reservation\n"
		<<"3) Show seats\n"
		<<"4) Exit\n\n"
		<<"Selection: ";
	cin>>selection;
	switch(selection)	//CASE PARA LA SELECCION
	{
	case 1:
		return 1;
		break;
	case 2:
		return 2;
		break;
	case 3:
		return 3;
		break;
	case 4:
		return 4;			
		break;
	default:
		cout<<"Invalid selection!!!"<<endl;// SI LA SELECCION ESTA INCORRECTA
		system("pause");
		return 5;
		break;
	}//SWITCH
}//SHOWMENU

//*****************************************************************************************
void reserveSeat(char array[][COLS])
{
	//VARIABLES LOCALES
	char section;
	int tempRow, letterChange;
	char tempCol, another;

	do 
	{
		system("cls");
		cout<<"Seat Reservoir"<<endl<<endl;//PRIMERA O SEGUNDA CLASE
		cout<<"Select:"<<endl<<"A. First Class\nB. Economic Class"<<endl;
		cin>>section;
		section=toupper(section);
		while(section!='A' && section!='B')
		{
			cout<<"Wrong selection!!!"<<endl;
			system("pause");
			system("cls");
			cout<<"Seat Reservoir"<<endl<<endl;//PRIMERA O SEGUNDA CLASE
			cout<<"Select:"<<endl<<"A. First Class\nB. Economic Class"<<endl;
			cin>>section;
			section=toupper(section);
		}//WHILE
	}while(section!='A' && section!='B');//DOWHILE
		
		if(section=='A')//SI ES PRIMERA CLASE
		{
			do
			{
				system("cls");
				cout<<"First Class"<<endl<<"No Smoking Area"<<endl<<endl;
				cout<<"ROWS 1 & 2"<<endl<<"COLUMNS A to F"<<endl;
				cout<<"Enter the ROW number and COLUMN letter: ";
				cin>>tempRow>>tempCol;
				tempCol=toupper(tempCol);
				letterChange=changeLetter(tempCol);		//CONVIERTO LA LETRA EN NUMERO
				if(tempRow<1 || tempRow>2)				//VALIDO TODOS LOS CAMPOS
				{
					cout<<"Wrong ROW number!!!"<<endl;
					system("pause");
				}
				else if(letterChange<0 || letterChange>13)
				{
					cout<<"Wrong COLUMN letter!!!"<<endl;
					system("pause");
				}
				else if(array[tempRow-1][letterChange]=='*')	
				{
					array[tempRow-1][letterChange]='X';
					cout<<"Seat Reserved!!!"<<endl<<endl;
					system("pause");
				}
				else //if(array[tempRow-1][letterChange]=='X')//SI ESTA OCUPADO
				{
					cout<<"That seat is already reserved!"<<endl;
					system("pause");
				}
				cout<<"Reserve another seat?"<<endl<<"(Y/N): ";
				cin>>another;
				another=toupper(another);
			}while(another=='Y');
		}											//IF SECTION A
		//else									//SI ES CLASE ECONOMICA
		if(section=='B')
		{
			do
			{
				system("cls");
				cout<<"Seat Reservoir"<<endl;
				cout<<"Economic Class"<<endl<<endl;
				cout<<"A.Smoking area\nB.Non-Smoking area"<<endl;
				cin>>section;
				section=toupper(section);
				//while(section!='A' && section!='B')//VALIDACION
				//	cout<<"Wrong option!!!"<<endl;
				while(section!='A' && section!='B')
				{
					cout<<"Wrong selection!!!"<<endl;
					system("pause");
					system("cls");
					cout<<"Seat Reservoir"<<endl;//PRIMERA O SEGUNDA CLASE
					cout<<"Economic Class"<<endl<<endl;
					cout<<"A.Smoking area\nB.Non-Smoking area"<<endl;
					cin>>section;
					section=toupper(section);
				}//WHILE
			}while(section!='A' && section!='B');//DO
				
			if(section='A')						//SMOKING AREA
			{
				do{
					system("cls");
					cout<<"Economic Class"<<endl;
					cout<<"Smoking Area"<<endl<<endl;
					cout<<"Select from ROWS 8 to 13 "<<"COLUMNS A to F"<<endl;
					cout<<"Enter the ROW number and COLUMN letter: ";
					cin>>tempRow>>tempCol;
					tempCol=toupper(tempCol);
					letterChange=changeLetter(tempCol);		//CONVIERTO LA LETRA EN NUMERO
					if(tempRow<8 || tempRow>13)
					{
						cout<<"Wrong ROW number!!!"<<endl;
						system("pause");
					}
					else if(letterChange<0 || letterChange>12)
					{
						cout<<"Wrong COLUMN letter!!!"<<endl;
						system("pause");
					}
					else if(array[tempRow-1][letterChange]=='*')	
					{
						array[tempRow-1][letterChange]='X';
						cout<<"Seat reserved!"<<endl;
						system("pause");
					}
					else
					{
						cout<<"That seat is already reserved!"<<endl;
						system("pause");
					}
					cout<<"Reserve another seat?"<<endl<<"(Y/N): ";
					cin>>another;
					another=toupper(another);
				}while(another=='Y');
				//}while(array[tempRow-1][letterChange]!='*');//DO WHILE
			}											//IF SMOKING AREA
			else										//NON-SMOKING AREA
			{
				do
				{
					system("cls");
					cout<<"Economic Class"<<endl;
					cout<<"Non-Smoking Area"<<endl<<endl;
					cout<<"Select from ROWS 3 to 7 "<<endl<<"COLUMNS A to F"<<endl;
					cout<<"Enter the ROW number and COLUMN letter: ";
						cin>>tempRow>>tempCol;
						tempCol=toupper(tempCol);
						letterChange=changeLetter(tempCol);		//CONVIERTO LA LETRA EN NUMERO
					if(tempRow<3 || tempRow>7)
					{
						cout<<"Wrong ROW number!!!"<<endl;
						system("pause");
					}
					if(letterChange<0 || letterChange>12)
					{
						cout<<"Wrong COLUMN letter!!!"<<endl;
						system("pause");
					}
					if(array[tempRow-1][letterChange]=='*')		//VERIFICAR SI NECESITO VARIABLE PARA ESTO
						array[tempRow-1][letterChange]='X';
					else
					{
						cout<<"That seat is already reserved!"<<endl;
						system("pause");
					}
					cout<<"Reserve another seat?"<<endl<<"(Y/N): ";
					cin>>another;
					another=toupper(another);
				}while(another=='Y');
				//1}while(array[tempRow-1][letterChange]!='*');	//DO WHILE
			}													//ELSE NON SMOKING AREA
		}//ELSE CALSE ECONOMICA

}//VOID




//*****************************************************************************************
void cancelReserve(char array[][COLS])
{
	//VARIABLES LOCALES
	int tempRow, letterChange;
	char tempCol, option, option2;
	do
	{
		system("cls");
		cout<<"Cancel Reserve"<<endl<<endl;
		cout<<"Enter the ROW number and COLUMN letter \nof seat to be canceled: ";
				cin>>tempRow>>tempCol;
				tempCol=toupper(tempCol);
				letterChange=changeLetter(tempCol);
				if(tempRow<1 || tempRow>13)
				{
					cout<<"Wrong ROW number!!!"<<endl;
					system("pause");
				}
				if(letterChange<0 || letterChange>12)
				{
					cout<<"Wrong COLUMN letter!!!"<<endl;
					system("pause");
				}
				if(array[tempRow-1][letterChange]=='X')		//VERIFICAR SI NECESITO VARIABLE PARA ESTO
				{
					cout<<"Are you sure to cancel reservation: "<<tempRow<<' '<<tempCol<<" ?"<<endl
						<<"Y/N: ";
					cin>>option2;
					option2=toupper(option2);
					if(option2=='Y')
					{
						array[tempRow-1][letterChange]='*';
						cout<<"Cancel made!"<<endl;
						system("pause");
					}
					else
					{
					cout<<"Cancel Aborted!"<<endl;
					system("pause");
					}
				}
				else
					cout<<"That seat is not reserved!"<<endl;
				cout<<"Do you want to make another cancelation?"<<endl<<"(Y/N): ";
				cin>>option;
				option=toupper(option);
			}while(option=='Y');//DO WHILE
}//VOID

//*****************************************************************************************
void showSeats(const char array[][COLS])
{
	system("cls");
	cout<<"		COLUMNS"<<endl<<"         A   B   C   D   E   F"<<endl;

		for(int r=0;r<ROWS;r++)
		{
			if(r<=8)
				cout<<endl<<"Row "<<"0"<<r+1;
			else
				cout<<endl<<"Row "<<r+1;
			for(int c=0;c<COLS;c++)
				cout<<"   "<<array[r][c];
		}//FOR
		cout<<"\n\n";
	system("pause");
}//VOID



//*****************************************************************************************
int changeLetter(char tempColumn)
{
	if(tempColumn=='a' || tempColumn=='A')
		return 0;
	else if(tempColumn=='b' || tempColumn=='B')
		return 1;
	else if(tempColumn=='c' || tempColumn=='C')
		return 2;
	else if(tempColumn=='d' || tempColumn=='D')
		return 3;
	else if(tempColumn=='e' || tempColumn=='E')
		return 4;
	else if(tempColumn=='f' || tempColumn=='F')
		return 5;
	else
		return 6;
}
//*****************************************************************************************
void updateFile(const char array[][COLS])
{
	ofstream outfile("dist.txt");//ABRO EL ARCHIVO DE MODO LOCAL

	if(!outfile)//VERIFICO SI EL ARCHIVO ABRIO
	{
		cout<<"Error updating file!!!"<<endl<<endl;
		system("pause");
		exit(1);
	}

	for(int r=0;r<ROWS;r++)//CICLO PARA VACIAR ARREGLO EN ARCHIVO
		{
			for(int c=0;c<COLS;c++)
                outfile<<array[r][c];
			outfile<<endl;
		}//FOR
}//VOID
