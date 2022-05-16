// *********************************************************************
// Programa: videoclub.cpp
// Autor: Gerrick Rosado Vega      841-03-8381
// Curso: SICI 4036-KM1
// Fecha: 3 de octubre de 2005
// Prop�sito:  Este programa maneja los datos de un arreglo usando structs
// y permite manejar los datos de un club de v�deos
// *********************************************************************

#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cctype>

using namespace std;

//STRUCT
struct RentType
{
	string idClient;
	string rentDate;
};

struct VideoType
{
	string codeId;
	string title;
	int year;
	string genre;
	string directorName;
	string rating;
	int inventaryCopyQty;
	int rentedCopyQty;
	RentType copiasAlquiladas[5];
};

const int MAX_VIDEO_CAPACITY = 50;


//PROTOTYPES
void showMenu();
void processSelection(int myOption, int& videoAmount, VideoType videoRec[]);
void showVideoByCode(int videoTotal, VideoType videoRec[]);
void showVideoList(int videoTotal, VideoType videoRec[]);
void showVideoListByGenre(int videoTotal, VideoType videoRec[]);
void rentVideo(int videoTotal, VideoType videoRec[]);
void returnVideo(int videoAmount, VideoType videoRec[]);
void addVideo(VideoType videoRec[], int& videoAmount);
void deleteVideo(int& videoTotal, VideoType videoRec[]);
void getVideoInfo(ifstream& infile, VideoType& videoRec);
void loadFile(ifstream& infile, VideoType videoRec[], int& videoAmount);  
void writeFile(VideoType videoRec[], int videoAmount);
int  videoSearch(string& myOptionCode, int videoAmount, VideoType videoRec[]);
int  getSelection();

int main()
{
	VideoType videoRecord[MAX_VIDEO_CAPACITY];
	int cantidadVideo;  
	ifstream inData;
	int option;
	inData.open("videos.txt");
	if (!inData)
	{	
		cout<< "<<<<<<No se pudo abrir el archivo>>>>>>"<<endl;
		cout<< " "<<endl;
		return 1;
	}
	
	

	loadFile(inData, videoRecord, cantidadVideo);
	inData.close();

	do
	{
		cout <<endl;
		showMenu();
		option = getSelection();
		processSelection(option, cantidadVideo, videoRecord);
		
	}	while (option!=0);


	return 0;
}

void showMenu()
// ******************************************************************
// ESTA FUNCION MUESTRA EL MENU QUE MANEJARA EL SISTEMA
// 
// 
// 
// ******************************************************************

{
	system("cls");
	cout<<setw(44) << "<<<C++ VIDEO CLUB>>>"<<endl;
	cout<<setw(44) << "--------------------"<<endl;
	cout<<' '<<endl;
	cout<<"MENU:"<<endl;
	cout<<"1. Alquilar un video."<<endl;
	cout<<"2. Devolver un video."<<endl;
	cout<<"3. Anadir un video."<<endl;
	cout<<"4. Eliminar los datos de un video."<<endl;
	cout<<"5. Mostrar los datos de un video dado su codigo."<<endl;
	cout<<"6. Mostrar el listado de las peliculas."<<endl;
	cout<<"7. Mostrar el listado de las peliculas de un genero en particular."<<endl;
	cout<<"0. Salir."<<endl;
	
}

int getSelection()
// ******************************************************************
// ESTA FUNCION RECOJE LA RESPUESTA QUE ENTRE EL USUARIO
// Y LA DEVUELVE PARA LUEGO SER PROCESADA
// 
// 
// ******************************************************************
{
	int myOption;
	
	cout << "  " <<endl;
	cout<< "Ingrese el # de la opcion deseada: ";
	cin>> myOption;

	while (myOption<0 || myOption >7)
	{
		cout<<"Opcion invalida, Ingrese un valor entre 0 y 7: ";
		cin>> myOption;
	}
	return myOption;
}

void processSelection(int myOption, int& videoAmount, VideoType videoRec[])
// ******************************************************************
// ESTA FUNCION PROCESA LA RESPUESTA DEL USUARIO QUE FUE INGRESADA
// EN EL MODULO DE GETSELECTION
// 
// 
// ******************************************************************
{
	switch(myOption)
	{
	case 1: rentVideo(videoAmount, videoRec);
		break;
	case 2: returnVideo(videoAmount, videoRec);
		break;
	case 3: addVideo(videoRec, videoAmount);
		break;
	case 4: deleteVideo(videoAmount, videoRec);
		break;
	case 5: showVideoByCode(videoAmount, videoRec);
		break;
	case 6: showVideoList(videoAmount, videoRec);
		break;
	case 7: showVideoListByGenre(videoAmount, videoRec);
		break;
	case 0: writeFile(videoRec, videoAmount);
		break;
	}
}


void loadFile(ifstream& infile, VideoType videoRec[], int& videoAmount)
// ******************************************************************
// ESTA FUNCION LLAMA A LA FUNCION GETVIDEOINFO PARA CARGAR LOS DATOS AL ARCHIVO
// 
// 
// 
// ******************************************************************
{
	VideoType temp;

	videoAmount = 0;
	
	getVideoInfo(infile,temp);

	while(!infile.eof() && videoAmount<MAX_VIDEO_CAPACITY)
	{

		videoRec[videoAmount] = temp;
		videoAmount++;
		getVideoInfo(infile,temp);
		
	}

	if(!infile.eof())
	{	cout<<"Quedaron datos sin leer en el archivo. Contacte a su programador."<<endl;
		system("pause");
		exit(1);
	}
}

void getVideoInfo(ifstream& infilefile, VideoType& videoRec)
{
// ******************************************************************
// ESTA FUNCION ES LLAMADA POR LA FUNCION LOADFILE PARA ALMACENAR
// LOS DATOS DE UN SOLO RECORD A LA VES
// 
// 
// ******************************************************************
	infilefile>> videoRec.codeId;
	infilefile.ignore(1);
	getline(infilefile, videoRec.title,'#');
	infilefile>>videoRec.year;
	infilefile>>videoRec.genre;
	infilefile.ignore(1);
	getline(infilefile, videoRec.directorName,'#');
	infilefile>>videoRec.rating;
	infilefile>>videoRec.inventaryCopyQty;
	infilefile>>videoRec.rentedCopyQty;

	for(int k=0;k<videoRec.rentedCopyQty;k++)
	{
		infilefile>>videoRec.copiasAlquiladas[k].idClient;
		infilefile>>videoRec.copiasAlquiladas[k].rentDate;
	}
}
void addVideo(VideoType videoRec[], int& videoAmount)
// ******************************************************************
// ESTA FUNCION VALIDA Y AGREGA UN NUEVO TITULO (VIDEO) Y SUS
// PROPIEDADES INCLUYENDO CANTIDAD EN EL INVENTARIO, AL SISTEMA
// 
// 
// ******************************************************************
{
	string temp, temp3, myStr;
	int temp2, n;
	string::size_type len;
	char char1;
	char char2;
	
	if (videoAmount > 50)
	{
		system("cls");
		cout<<"No se pueden anadir videos, el almacen esta lleno."<<endl;
		system("pause");
		system("cls");
	}
	else if (videoAmount <= 50)
	{
		system("cls");
		cout<<"Ingrese el codigo de la pelicula: ";
		cin>>temp;
		cout<<"  "<<endl;
		n = videoSearch(temp, videoAmount, videoRec);
		if (n!=99)
		{
			cout<<"Se encontro la pelicula, no puden haber duplicados."<<endl;
			system("pause");
			system("cls");
		}
		else
		{
			len = (temp.length());
			/*----------1------------------*/
			while (len <4 || len >4)
			{
				cout<<"El codigo debe ser de cuatro caracteres."<<endl;
				cout<<"Ingrese el codigo de la pelicula: ";
				cin>>temp;
				cout<<"  "<<endl;
				len = temp.length();
			}
			videoRec[videoAmount].codeId = temp;
			cout<<"  "<<endl;
			system("cls");
			/*----------2------------------*/
			cin.ignore(80, '\n');
			temp = "  ";
			len = 20;
			cout<<"Ingrese el titulo de la pelicula, maximo 20 caracteres: ";
			getline(cin,temp);
			len = temp.length();
			while (len <1 || len >20)
			{
				cout<<"El titulo debe ser de hasta un maximo de 20 caracteres."<<endl;
				cout<<"Ingrese el titulo de la pelicula: ";
				cin>>temp;
				cout<<"  "<<endl;
				len = temp.length();
			}
			videoRec[videoAmount].title = temp;
			cout<<"  "<<endl;
			system("cls");
			/*----------3------------------*/
			cout<<"Ingrese el ano de la pelicula: ";
			cin>>temp2;
			while (temp2 <1990 || temp2 >2005)
			{
				cout<<"El ano de la pelicula debe estar entre el 1990 y el 2005."<<endl;
				cout<<"Ingrese el ano de la pelicula: ";
				cin>>temp2;
				cout<<"  "<<endl;
			}
			videoRec[videoAmount].year = temp2;
			cout<<"  "<<endl;
			system("cls");
			/*----------4------------------*/
			cout<<"GENEROS: AC = accion, DR = drama, CO = comedia, HO = horror"<<endl;
			cout<<"Ingrese el codigo para el genero de la pelicula: ";
			cin>>temp;
			cout<<"  "<<endl;
			len = temp.length();
			while (len <2 || len >2)
			{
				cout<<"Debe ingresar el codigo especificado para el genero, 2 caracteres maximo."<<endl;
				cout<<"Ingrese el codigo para el genero de la pelicula: ";
				cin>>temp;
				cout<<"  "<<endl;
				len = temp.length();
			}
			
			do
			{
				char1 = toupper(temp[0]);
				char2 = toupper(temp[1]);
				if (char1 == 'A' && char2 =='C')
					videoRec[videoAmount].genre = "AC";
				else if (char1 == 'D' && char2 == 'R')
					videoRec[videoAmount].genre = "DR";
				else if (char1 == 'C' && char2 == 'O')
					videoRec[videoAmount].genre = "CO";
				else if (char1 == 'H' && char2 == 'O')
					videoRec[videoAmount].genre = "HO";
				else 
				{
					cout<<"Debe ingresar el codigo especificado."<<endl;
					cout<<"Ingrese el codigo para el genero de la pelicula: ";
					cin>>temp;
					cout<<"  "<<endl;
					len = 3;
				}
			}while(len == 3);
			cout<<"  "<<endl;
			system("cls");
		/*----------5------------------*/
			cin.ignore(80, '\n');
			temp = "  ";
			len = 20;
			cout<<"Ingrese el nombre del director: ";
			getline(cin, temp);
			len = temp.length();
			while (len <1 || len >20)
			{
				cout<<"El nombre debe ser de hasta un maximo de 20 caracteres."<<endl;
				cout<<"Ingrese el nombre del director: ";
				cin>>temp;
				cout<<"  "<<endl;
				len = temp.length();
			}
			videoRec[videoAmount].directorName = temp;
			cout<<"  "<<endl;
			system("cls");
			/*----------6------------------*/
			cout<<"Clasificacion (G, PG, PG-13, R)"<<endl;
			cout<<"Ingrese la clasificacion de la pelicula: ";
			cin>>temp;
			cout<<"  "<<endl;
			len = temp.length();
			if (len == 2)
			{
				char1 = toupper(temp[0]);
				char2 = toupper(temp[1]);
				temp3 = (char1 + char2);
				if(temp3 == "PG")
					videoRec[videoAmount].rating = "PG";
			}
			else if (len == 4)
			{
				myStr = temp.substr(2,3);
				char1 = toupper(temp[0]);
				char2 = toupper(temp[1]);
				///////////////////////////////
				string char1a, char2a;
				char1a = char1;
				char2a = char2;
				///////////////////////////////
				if (temp3 == "PG-13")
					videoRec[videoAmount].rating = "PG-13";
			}
			else if(len == 1)
			{
				if(temp == "G")
					videoRec[videoAmount].rating = "G";
				if(temp == "R")
					videoRec[videoAmount].rating = "R";
			}
			cout<<"  "<<endl;
			system("cls");
			/*----------7------------------*/
			cout<<"Ingrese la cantidad de copias en Inventario: ";
			cin>>temp2;
			cout<<"  "<<endl;
			while(temp2 < 1 || temp2 > 5)
			{
				cout<<"La cantidad debe estar entre 1 y 5."<<endl;
				cout<<"Ingrese la cantidad de copias en Inventario: ";
				cin>>temp2;
				cout<<"  "<<endl;
			}
			videoRec[videoAmount].inventaryCopyQty = temp2;
			cout<<"  "<<endl;
			system("cls");

	videoRec[videoAmount].rentedCopyQty = 0;
	cout<<"Se agrego el video: "<<videoRec[videoAmount].title <<"a la lista."<<endl;
	cout<<"Cantidad de copias en Inventario: "<<videoRec[videoAmount].inventaryCopyQty<<endl;
	videoAmount++;
	system("pause");
		}
	}
}

void rentVideo(int videoTotal, VideoType videoRec[])
// ******************************************************************
// ESTA FUNCION PERMITE ALQUILAR UNA COPIA DE UN VIDEO
// VALIDA SI NO HAY COPIAS DISPONIBLES DEL VIDEO SELECCIONADO
// 
// 
// ******************************************************************
{
	int k;
	int n;
	string searchCode;
	int inventary;
	int rented;
	int available;
	string idClient;
	string rentDate;
	string::size_type len;
	
	system("cls");
	cout<<"Entre el codigo de 4 digitos deseado : ";
	cin>>searchCode;
	len = searchCode.length();
	while (len <4 || len >4)
	{
		cout<<"El codigo debe ser de cuatro caracteres.";
		cout<<"Ingrese el codigo de la pelicula: ";
		cin>>searchCode;
		len = searchCode.length();
	}

	n = videoSearch(searchCode, videoTotal, videoRec);
	if(n==99)
	{
		cout<<"no se encontro"<<endl;
		system("pause");
	
	}
	else
	{
		system("cls");
		cout<<setw(44)<<"C++ VIDEO CLUB"<<endl;
		cout<<setw(54)<<"LISTADO DE PELICULAS EN EL SISTEMA"<<endl;
		cout<<' '<<endl;
		cout<<setw(8)<<left<<"CODIGO"<<setw(22)<<"TUTULO"<<setw(4)<<right<<"ANO"<<"  "<<setw(8)<<left<<"GENERO";
		cout<<setw(22)<<left<<"DIRECTOR"<<setw(8)<<"CLAS."<<setw(6)<<right<<"DISP."<<setw(6)<<right<<"ALQ."<<endl;
		cout<<setw(8)<<left<<"======"<<setw(22)<<"======"<<setw(4)<<right<<"==="<<"  "<<setw(8)<<left<<"======";
		cout<<setw(22)<<left<<"========"<<setw(8)<<"====="<<setw(6)<<right<<"====="<<setw(6)<<right<<"===="<<endl;

		cout<<setw(8)<<left<<videoRec[n].codeId<<setw(22)<<videoRec[n].title;
		cout<<setw(4)<<right<<videoRec[n].year<<"  "<<left<<setw(8)<<videoRec[n].genre;
		cout<<setw(22)<<left<<videoRec[n].directorName<<setw(8)<<videoRec[n].rating;
		cout<<setw(6)<<right<<videoRec[n].inventaryCopyQty<<setw(6)<<right<<videoRec[n].rentedCopyQty<<endl;

		cout<<' '<<endl;
				

		inventary=videoRec[n].inventaryCopyQty;
		rented=videoRec[n].rentedCopyQty;
		available=inventary-rented;
		if(available==0)
		{
			cout<<"No quedan copias disponibles para alquiler."<<endl;
		
		}
		else
		{
			k=rented;
			cout<<"Entre el id del cliente: "; 
			cin>>idClient;
			len = (idClient.length());
			/*----------1------------------*/
			while (len <4 || len >4)
			{
				cout<<"El id debe ser de cuatro caracteres."<<endl;
				cout<<"Ingrese el id del cliente: ";
				cin>>idClient;
				cout<<"  "<<endl;
				len = idClient.length();
			}


			videoRec[n].copiasAlquiladas[k].idClient=idClient;
			
			cout<<"Entre la fecha del alquiler (mm/dd/yyyy): ";
			cin>>rentDate;
			len = rentDate.length();
			while (len <10 || len >10)
			{
				cout<<"La fecha debe ser en este formato (mm/dd/yyyy)."<<endl;
				cout<<"Ingrese la fecha nuevamente: ";
				cin>>rentDate;
				cout<<"  "<<endl;
				len = rentDate.length();
			}
			videoRec[n].copiasAlquiladas[k].rentDate=rentDate;
			videoRec[n].rentedCopyQty++;
		}	
		cout<<' '<<endl;
		/*-----------------------*/
		
		system("pause");
		system("cls");
	}

}

void returnVideo(int videoAmount, VideoType videoRec[])
// ******************************************************************
// ESTA FUNCION SE ENCARGA DE PROCESAR UN VIDEO DEVUELTO
// ACTUALIZA LA LISTA DE VIDEOS Y AL CLIENTE. HACE VALIDACION SI NO HAY 
// COPIAS ALQUILADAS.
// 
// ******************************************************************
{
	int j;
	int k;
	int n;
	int found=0;
	string searchCode;
	string selection;
	string idBuscado;
	string::size_type len;
	
	system("cls");
	cout<<"Entre el codigo de 4 digitos deseado :";
	cin>>searchCode;
	len = searchCode.length();
	while (len <4 || len >4)
	{
		cout<<"El codigo debe ser de cuatro caracteres.";
		cout<<"Ingrese el codigo de la pelicula: ";
		cin>>searchCode;
		len = searchCode.length();
	}

	n = videoSearch(searchCode, videoAmount, videoRec);
	if(n==99)
	{
		cout<<"No se encontro la pelicula."<<endl;
		system("pause");
		found = 1;
	}
	else
	{
		system("cls");
		cout<<setw(44)<<"C++ VIDEO CLUB"<<endl;
		cout<<setw(54)<<"PELICULA DESEADA EN EL SISTEMA "<<endl;
		cout<<' '<<endl;
		cout<<setw(8)<<left<<"CODIGO"<<setw(22)<<"TUTULO"<<setw(4)<<right<<"ANO"<<"  "<<setw(8)<<left<<"GENERO";
		cout<<setw(22)<<left<<"DIRECTOR"<<setw(8)<<"CLAS."<<setw(6)<<right<<"DISP."<<setw(6)<<right<<"ALQ."<<endl;
		cout<<setw(8)<<left<<"======"<<setw(22)<<"======"<<setw(4)<<right<<"==="<<"  "<<setw(8)<<left<<"======";
		cout<<setw(22)<<left<<"========"<<setw(8)<<"====="<<setw(6)<<right<<"====="<<setw(6)<<right<<"===="<<endl;

		cout<<setw(8)<<left<<videoRec[n].codeId<<setw(22)<<videoRec[n].title;
		cout<<setw(4)<<right<<videoRec[n].year<<"  "<<left<<setw(8)<<videoRec[n].genre;
		cout<<setw(22)<<left<<videoRec[n].directorName<<setw(8)<<videoRec[n].rating;
		cout<<setw(6)<<right<<videoRec[n].inventaryCopyQty<<setw(6)<<right<<videoRec[n].rentedCopyQty<<endl;
		cout<<' '<<endl;
		cout<<left<<setw(10)<<"CLIENTES"<<setw(10)<<"FECHA"<<endl;
		cout<<setw(10)<<"========"<<setw(10)<<"====="<<endl;
		for(k=0;k<videoRec[n].rentedCopyQty;k++)
		{
			cout<<setw(10)<<videoRec[n].copiasAlquiladas[k].idClient;
			cout<<setw(10)<<videoRec[n].copiasAlquiladas[k].rentDate<<endl;
		}
			
		cout<<' '<<endl;



		if(videoRec[n].rentedCopyQty!=0)
		{
			j=videoRec[n].rentedCopyQty;
			j--;
			cout<<' '<<endl;
			cout<<"Entre el codigo del cliente que esta devolviendo la pelicula en mayuscula: ";
			
			cin>>selection;
			len = selection.length();
			while (len <4 || len >4)
			{
				cout<<"El codigo debe ser de cuatro caracteres";
				cout<<"Ingrese el codigo del cliente: ";
				cin>>selection;
				len = selection.length();
			}

			for(k=0;k<=j;k++)                      
			{
				idBuscado=videoRec[n].copiasAlquiladas[k].idClient;
				if(idBuscado==selection)
				{
					found=1;
					if(k==j)//es para verificar si el cliente esta en la ultima posicion del arreglo
					{
						videoRec[n].rentedCopyQty--;
						videoRec[n].inventaryCopyQty++;
						cout<<"Copia de video devuelta."<<endl;
						system("pause");
					}
					else
					{
						videoRec[n].copiasAlquiladas[k].idClient=videoRec[n].copiasAlquiladas[j].idClient;
						videoRec[n].copiasAlquiladas[k].rentDate=videoRec[n].copiasAlquiladas[j].rentDate;
						videoRec[n].rentedCopyQty--;
						videoRec[n].inventaryCopyQty++;
						cout<<"Copia de video devuelta."<<endl;
						system("pause");
					}
				}				
			}
		}
		else
		{
			cout<<"no se puede por que no hay copias alquiladas de esa pelicula"<<endl;
			system("pause");
			found=1;
		}
	}
	if(found==0)
	{
		cout<<"no se encontro ese id de cliente"<<endl;
		system("pause");
	}
}
void deleteVideo(int& videoAmount, VideoType videoRec[])
// ******************************************************************
// ESTA FUNCION ELIMINA DE LA LISTA DE VIDEOS UN VIDEO SELECIONADO
// POR EL USUARIO. HACE VALIDACIO POR SI EL VIDEO NO SE EXISTE
// 
// 
// ******************************************************************
{
	int k;
	int n;
	string searchCode;
	int selection;
	string::size_type len;
	
	system("cls");
	cout<<"Entre el codigo de 4 digitos deseado : ";
	cin>>searchCode;
	len = searchCode.length();
	while (len <4 || len >4)
	{
		cout<<"El codigo debe ser de cuatro caracteres"<<endl;
		cout<<"Ingrese el codigo de la pelicula: ";
		cin>>searchCode;
		len = searchCode.length();
	}

	n = videoSearch(searchCode, videoAmount, videoRec);
	if(n==99)
	{
		system("cls");
		cout<<"No se encontro."<<endl;
		system("pause");
	
	}
	else
	{
		system("cls");
		cout<<setw(44)<<"C++ VIDEO CLUB"<<endl;
		cout<<setw(54)<<"PELICULA DESEADA EN EL SISTEMA "<<endl;
		cout<<' '<<endl;
		cout<<setw(8)<<left<<"CODIGO"<<setw(22)<<"TUTULO"<<setw(4)<<right<<"ANO"<<"  "<<setw(8)<<left<<"GENERO";
		cout<<setw(22)<<left<<"DIRECTOR"<<setw(8)<<"CLAS."<<setw(6)<<right<<"DISP."<<setw(6)<<right<<"ALQ."<<endl;
		cout<<setw(8)<<left<<"======"<<setw(22)<<"======"<<setw(4)<<right<<"==="<<"  "<<setw(8)<<left<<"======";
		cout<<setw(22)<<left<<"========"<<setw(8)<<"====="<<setw(6)<<right<<"====="<<setw(6)<<right<<"===="<<endl;

		cout<<setw(8)<<left<<videoRec[n].codeId<<setw(22)<<videoRec[n].title;
		cout<<setw(4)<<right<<videoRec[n].year<<"  "<<left<<setw(8)<<videoRec[n].genre;
		cout<<setw(22)<<left<<videoRec[n].directorName<<setw(8)<<videoRec[n].rating;
		cout<<setw(6)<<right<<videoRec[n].inventaryCopyQty<<setw(6)<<right<<videoRec[n].rentedCopyQty<<endl;
	
	
		if(videoRec[n].rentedCopyQty==0)
		{
			cout<<' '<<endl;
			cout<<"Esta seguro que desea borrar el video seleccionado."<<endl;
			cout<<"Entre 0 para borrar, entre 1 para cancelar la accion: ";
			cin>>selection;
			
			if(selection!=0)
			{
				cout<<"No fue borrado el record."<<endl;
				system("pause");
			}
			else
			{
				videoAmount--;
				if(n==videoAmount)
					videoAmount--;
				else
				{
					k=videoAmount;
					videoRec[n].codeId=videoRec[k].codeId;
					videoRec[n].title=videoRec[k].title;
					videoRec[n].year=videoRec[k].year;
					videoRec[n].genre=videoRec[k].genre;
					videoRec[n].directorName=videoRec[k].directorName;
					videoRec[n].rating=videoRec[k].rating;
					videoRec[n].inventaryCopyQty=videoRec[k].inventaryCopyQty;
					videoRec[n].rentedCopyQty=videoRec[k].rentedCopyQty;
					videoAmount--;
				}
				cout<<"Archivo borrado."<<endl;
				videoAmount++;
				system("pause");
			}
		}
		else
		{
			cout<<"No se puede por que hay copias alquiladas"<<endl;
			system("pause");
		}
	}
}



void showVideoByCode(int videoTotal, VideoType videoRec[])
// ******************************************************************
// ESTA FUNCION MUESTRA LOS DATOS DE UN VIDEO DADO SU CODIGO
// VALIDA EL CODIGO DEL VIDEO Y SI EXISTE
// 
// 
// ******************************************************************
{
	int k;
	int n;
	string searchCode;
	string::size_type len;
	
	system("cls");
	cout<<"Entre el codigo de 4 digitos deseado : ";
	cin>>searchCode;
	len = searchCode.length();
	cout<<endl;
	while (len <4 || len >4)
	{
		cout<<"El codigo debe ser de cuatro caracteres."<<endl;
		cout<<"Ingrese el codigo de la pelicula: ";
		cin>>searchCode;
		cout<<"  "<<endl;
		len = searchCode.length();
	}
	n = videoSearch(searchCode, videoTotal, videoRec);
	if(n==99)
	{
		cout<<"No se encontro la pelicula."<<endl;
		system("pause");
	}
	else
	{
		system("cls");
		cout<<setw(44)<<"C++ VIDEO CLUB"<<endl;
		cout<<setw(54)<<"LISTADO DE PELICULAS EN EL SISTEMA"<<endl;
		cout<<' '<<endl;
		cout<<setw(8)<<left<<"CODIGO"<<setw(22)<<"TUTULO"<<setw(4)<<right<<"ANO"<<"  "<<setw(8)<<left<<"GENERO";
		cout<<setw(22)<<left<<"DIRECTOR"<<setw(8)<<"CLAS."<<setw(6)<<right<<"DISP."<<setw(6)<<right<<"ALQ."<<endl;
		cout<<setw(8)<<left<<"======"<<setw(22)<<"======"<<setw(4)<<right<<"==="<<"  "<<setw(8)<<left<<"======";
		cout<<setw(22)<<left<<"========"<<setw(8)<<"====="<<setw(6)<<right<<"====="<<setw(6)<<right<<"===="<<endl;

		cout<<setw(8)<<left<<videoRec[n].codeId<<setw(22)<<videoRec[n].title;
		cout<<setw(4)<<right<<videoRec[n].year<<"  "<<left<<setw(8)<<videoRec[n].genre;
		cout<<setw(22)<<left<<videoRec[n].directorName<<setw(8)<<videoRec[n].rating;
		cout<<setw(6)<<right<<videoRec[n].inventaryCopyQty<<setw(6)<<right<<videoRec[n].rentedCopyQty<<endl;

		cout<<' '<<endl;
		/*-----------------------*/
		cout<<"CANTIDAD DE TITULOS EN EL SISTEMA: "<<videoTotal<<endl;
		cout<<' '<<endl;
		cout<<"GENEROS: AC = accion, DR = drama, CO = comedia, HO = horror"<<endl;
		cout<<' '<<endl;
		cout<<' '<<endl;
		cout<<left<<setw(10)<<"CLIENTES"<<setw(10)<<"FECHA"<<endl;
		cout<<setw(10)<<"========"<<setw(10)<<"====="<<endl;
		for(k=0;k<videoRec[n].rentedCopyQty;k++)
		{
			cout<<setw(10)<<videoRec[n].copiasAlquiladas[k].idClient;
			cout<<setw(10)<<videoRec[n].copiasAlquiladas[k].rentDate<<endl;
		}	
		cout<<' '<<endl;
		/*-----------------------*/
		system("pause");
		system("cls");
	}
}


void showVideoList(int videoTotal, VideoType videoRec[])
// ******************************************************************
// ESTA FUNCION MUESTRA LA LISTA COMPLETA DE VIDEOS EN EL
// SISTEMA
// 
// 
// ******************************************************************
{
	system("cls");
	cout<<setw(44)<<"C++ VIDEO CLUB"<<endl;
	cout<<setw(54)<<"LISTADO DE PELICULAS EN EL SISTEMA"<<endl;
	cout<<' '<<endl;
	cout<<setw(8)<<left<<"CODIGO"<<setw(22)<<"TUTULO"<<setw(4)<<right<<"ANO"<<"  "<<setw(8)<<left<<"GENERO";
	cout<<setw(22)<<left<<"DIRECTOR"<<setw(8)<<"CLAS."<<setw(6)<<right<<"DISP."<<setw(6)<<right<<"ALQ."<<endl;
	cout<<setw(8)<<left<<"======"<<setw(22)<<"======"<<setw(4)<<right<<"==="<<"  "<<setw(8)<<left<<"======";
	cout<<setw(22)<<left<<"========"<<setw(8)<<"====="<<setw(6)<<right<<"====="<<setw(6)<<right<<"===="<<endl;
	for(int n=0; n < videoTotal; n++)
		{
			cout<<setw(8)<<left<<videoRec[n].codeId<<setw(22)<<videoRec[n].title;
			cout<<setw(4)<<right<<videoRec[n].year<<"  "<<left<<setw(8)<<videoRec[n].genre;
			cout<<setw(22)<<left<<videoRec[n].directorName<<setw(8)<<videoRec[n].rating;
			cout<<setw(6)<<right<<videoRec[n].inventaryCopyQty<<setw(6)<<right<<videoRec[n].rentedCopyQty<<endl;
		}
	cout<<' '<<endl;
	/*-----------------------*/
	cout<<"CANTIDAD DE TITULOS EN EL SISTEMA: "<<videoTotal<<endl;
	cout<<' '<<endl;
	cout<<"GENEROS: AC = accion, DR = drama, CO = comedia, HO = horror"<<endl;
	system("pause");
	system("cls");

}


void showVideoListByGenre(int videoTotal, VideoType videoRec[])
// ******************************************************************
// ESTA FUNCION MUESTRA LA LISTA DE VIDEOS DADO UN GENERO EN PARTICULAR
// VALIDA EL GENERO QUE SE INGRESE
// 
// 
// ******************************************************************
{
	int k = 0;
	int n = 0;
	string searchGenre, genreName;
	char searchGenreL;
	string::size_type len;

	system("cls");
	cout<<"CODIGO PARA GENEROS: AC = accion, DR = drama, CO = comedia, HO = horror"<<endl;
	cout<<"Entre el genero deseado: ";
	cin>>searchGenre;
	
	len = searchGenre.length();
	while (len <2 || len >2)
	{
		cout<<endl;
		cout<<"El codigo debe ser de 2 caracteres"<<endl;
		cout<<"Entre el genero deseado: ";
		cin>>searchGenre;
		cout<<"  "<<endl;
		len = searchGenre.length();
	}
	
	system("cls");

	/*-----------------------*/
	
	searchGenreL = toupper(searchGenre[0]);
	
	switch(searchGenreL)
    {
      case 'A' :
        genreName = "Accion";
		searchGenre = "AC";
        break;
      case 'D':
        genreName = "Drama";
		searchGenre = "DR";
        break;
	  case 'C' :
        genreName = "Comedia";
		searchGenre = "CO";
		break;
	  case 'H' :
        genreName = "Horror";
		searchGenre = "HO";
		break;
    }

	/*-----------------------*/

	cout<<setw(44)<<"C++ VIDEO CLUB"<<endl;
	cout<<setw(54)<<"LISTADO DE PELICULAS EN EL SISTEMA"<<endl;
	cout<<' '<<endl;
	cout<<"Genero: "<<genreName<<endl;
	cout<<' '<<endl;
	cout<<setw(8)<<left<<"CODIGO"<<setw(22)<<"TUTULO"<<setw(4)<<right<<"ANO"<<"  ";
	cout<<setw(22)<<left<<"DIRECTOR"<<setw(8)<<"CLAS."<<setw(6)<<right<<"DISP."<<setw(6)<<right<<"ALQ."<<endl;
	cout<<setw(8)<<left<<"======"<<setw(22)<<"======"<<setw(4)<<right<<"==="<<"  ";
	cout<<setw(22)<<left<<"========"<<setw(8)<<"====="<<setw(6)<<right<<"====="<<setw(6)<<right<<"===="<<endl;
	while(n!=videoTotal)
		if(videoRec[n].genre != searchGenre)
			n++;
		else 
		{
			cout<<setw(8)<<left<<videoRec[n].codeId<<setw(22)<<videoRec[n].title;
			cout<<setw(4)<<right<<videoRec[n].year<<"  ";
			cout<<setw(22)<<left<<videoRec[n].directorName<<setw(8)<<videoRec[n].rating;
			cout<<setw(6)<<right<<videoRec[n].inventaryCopyQty<<setw(6)<<right<<videoRec[n].rentedCopyQty<<endl;
			n++;
			k++;
		}
	cout<<' '<<endl;
	/*-----------------------*/
	cout<<"CANTIDAD DE TITULOS EN EL SISTEMA: "<<videoTotal<<endl;
	cout<<"CANTIDAD DE TITULOS EN EL SISTEMA DEL GENERO " <<genreName<<": "<<k<<endl;
	system("pause");
	system("cls");
}


int videoSearch(string& searchCode, int videoAmount, VideoType videoRec[])
// ******************************************************************
// ESTA FUNCION SE ENCARGA DE BUSCAR LOS RECORDS
// DEVUELVE UN VALOR 99 PARA UN RECORD NO ENCONTRADO
// Y UN VALOR N (INDICE DEL RECORD) DONDE SE ENCUENTRA EL RECORD BUSCADO
// 
// ******************************************************************

{
	int foundCodePosition=99;    //devuelve la posicion de el record en el arreglo
	int n; 

	for(n=0;n<videoAmount;n++)                      
	{
		if(videoRec[n].codeId==searchCode)
			foundCodePosition=n;
	}


	return foundCodePosition;

}


void writeFile(VideoType videoRec[], int videoAmount)
// ******************************************************************
// ESTA FUNCION SE ENCARGA DE ESCRIBIR LOS TODOS LOS CAMBIOS, DATOS
// EXISTENTES Y NUEVOS QUE HAY EN EL SISTEMA. AL SELECIONAR LA OPCION
// DE SALIDA.
// 
// ******************************************************************
{
	VideoType temp;
	ofstream outFile;
	outFile.open("videos.txt");
	if (!outFile)
	{
		cout << "Error al abrir el archivo" << endl;
		exit(1);
	}

	for (int n = 0; n < videoAmount; n ++)
	{
		temp = videoRec[n];
		
		outFile << temp.codeId << ' ' << temp.title << "# ";
		outFile<< temp.year << ' ' << temp.genre << ' ' ;
		outFile	<< temp.directorName << "# " << temp.rating << ' '; 
		outFile	<< temp.inventaryCopyQty << ' ' << temp.rentedCopyQty<<' ';
		if(temp.rentedCopyQty>0)
		{
			for(int k=0;k<temp.rentedCopyQty;k++)
			{
				outFile<<temp.copiasAlquiladas[k].idClient<<' ';
				outFile<<temp.copiasAlquiladas[k].rentDate<<' ';
			}
		}
		outFile<<endl;
	}
	outFile.close();
	cout<< "<<<<Gracias por usar el Sistema>>>>"<<endl;
	system("pause");
}