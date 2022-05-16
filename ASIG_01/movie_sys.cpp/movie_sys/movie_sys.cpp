#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>

using namespace std;

const int LIMIT=5;
const int CLIENTLIMIT=200;
const int MOVIESLIMIT=50;

struct Movies
{
	string movieCode, movieTitle, movieDate;
	int movieQuantity, moviesReserved;
};

struct Client
{
	string clientAccountNumber, clientName, clientMovieList[LIMIT];
	int clientReserveQuantity;
};


void readClientFile(Client clientList[], int& quantityClients);
void readMoviesFile(Movies movieList[], int& quantityMovies);
int showMenu();
void reserveMovie(Movies movieList[], Client clientList[], int quantityClients,  int quantityMovies);
void cancelReserve(Movies movieList[], Client clientList[], int quantityClients);
void showMovies(Movies movieList[], int quantityMovies);
void updateClient(/*Movies movieList[],*/ Client clientList[], int& quantityClients/*,  int quantityMovies*/);

void addClient(Client clientList[], int& quantityClients);
void removeClient(Client clientList[], int& quantityClients);
void showClientInfo(Client clientList[], int quantityClients);
void showClientList(Client clientList[], int quantityClients);


int main()
{
	//int client[LIMIT];
	int opcionMenu, sizeClients=0, sizeMovies=0;
	//Movies movieList[];
	Client clientInfo[CLIENTLIMIT];
	Movies movieInfo[MOVIESLIMIT];
	
	
	readClientFile(clientInfo, sizeClients);
	readMoviesFile(movieInfo, sizeMovies);
	
	do
	{
		system("cls");
		//showMenu();
		opcionMenu=showMenu();
		if(opcionMenu==1)
			reserveMovie(movieInfo, clientInfo, sizeClients, sizeMovies);
		else if(opcionMenu==2)
			cancelReserve(movieInfo, clientInfo, sizeClients);
		else if(opcionMenu==3)
			showMovies(movieInfo, sizeMovies);
		else if(opcionMenu==4)
			updateClient(clientInfo, sizeClients);
	}while(opcionMenu!=5);
//	updateClientFile();

	return 0;
}

void readClientFile(Client clientList[], int& quantityClients)
{
	int a=0;
	ifstream infile("clients.txt");

	if(!infile)
	{
		cout<<"Error opening file!!!"<<endl;
		system("pause");
		exit(1);
	}
	while(!infile.eof() && a<CLIENTLIMIT)
	{
		infile>>clientList[a].clientAccountNumber;
		infile.ignore(1);
		getline(infile, clientList[a].clientName, '#');
		infile>>clientList[a].clientReserveQuantity;
		for(int n=0; n<clientList[a].clientReserveQuantity; n++)
			infile>>clientList[a].clientMovieList[n];
		quantityClients++;
		a++;
	}//while
	infile.close();
}//VOID
void readMoviesFile(Movies movieList[], int& quantityMovies)
{
	int a=0;
	ifstream infile("schedule.txt");

	if(!infile)
	{
		cout<<"Error opening file!!!"<<endl;
		system("pause");
		exit(1);
	}	
	while(!infile.eof() && a<MOVIESLIMIT)
	{
		infile>>movieList[a].movieCode;
		infile.ignore(1);
		getline(infile, movieList[a].movieTitle,'#');
		infile>>movieList[a].movieDate;
		infile>>movieList[a].movieQuantity;
		infile>>movieList[a].moviesReserved;
		quantityMovies++;
		a++;
	}//WHILE INFILE
	infile.close();
}//VOID

int showMenu()
{
	int selection;

	system("cls");
	
    cout<<"Video Club Menu:"<<endl<<endl;
	cout<<"1) Reserve movie\n"
		<<"2) Cancel reservation\n"
		<<"3) Show movies\n"
		<<"4) Update Client\n"
		<<"5) Exit\n\n"
		<<"Selection: ";
	cin>>selection;
	if(selection>5 || selection <1)
	{
		cout<<"Invalid selection!!!"<<endl<<endl;
		system("pause");
		return 6;
	}
	else
		return selection;
}//SHOWMENU


void reserveMovie(Movies movieList[], Client clientList[], int quantityClients,  int quantityMovies)
{
	string clientNumber, movieNumber;
	char option='Y';
	int a=0, b=0, c=0;

	do
	{
		system("cls");
		cout<<"Movie Reservation"<<endl<<endl;
		cout<<"Enter the client number: #";
		cin>>clientNumber;
		
		//for(int a=0;a<quantityClients;a++)//PARA BUSCAR EN ARREGLO DE STRUCTS
		do
		{
			
				if(clientNumber == clientList[a].clientAccountNumber)//IF CLIENTNUMBER = ARREGLO NUMBER
				{ 
					if(clientList[a].clientReserveQuantity>=LIMIT)
					{
						system("cls");
						cout<<"Movie Reservation"<<endl<<endl;
						cout<<"The client has reached the reservation limit!!!"<<endl<<endl;
						system("pause");
					}
					else//SI LE QUEDA RESERVACIONES DISPONIBLES
					{
						cout<<"Enter the movie code: ";//pido pelicula
						cin>>movieNumber;
						//for(int b=0;b<clientList[a].clientReserveQuantity;b++)//verifico si la pelicula existe
						//int b=0;
						do
						{
							if(movieNumber == movieList[b].movieCode)//SI LA PELICULA EXISTE
							{
								//for(int c=0; c<=clientList[a].clientReserveQuantity;/*; c++*/)//busco si la tiene alquilada
								//int c=0;
								do
								{
									
									if(clientList[a].clientMovieList[c]==movieNumber)//si ya la tiene alquilada es un error
									{
										cout<<"The client has already reserved that movie!!!"<<endl<<endl;
										system("pause");
									}//if
									else//si no la tiene alquilada se la alquilo
									{
										clientList[a].clientMovieList[c+1]=movieNumber;
										clientList[a].clientReserveQuantity++;
										movieList[b].movieQuantity--;
										movieList[b].moviesReserved++;
										cout<<"Movie reserved!!!"<<endl<<endl;
										system("pause");
									}//else
									c++;
								}while((c<=clientList[a].clientReserveQuantity) || (clientList[a].clientMovieList[c]==movieNumber));//DO WHILE
							}//IF
							else if(b==quantityMovies)
							{
								system("cls");
								cout<<"Movie Reservation"<<endl<<endl;
								cout<<"The movie code entered is invalid!!!"<<endl<<endl;
								system("pause");
							}//else
							b++;
						}while(b<clientList[a].clientReserveQuantity || (b==quantityMovies /*&& movieNumber!=movieList[b].movieCode*/));//FOR
					}//ELSE
				}//if
				else if(a==quantityClients)
				{
					system("cls");
					cout<<"Movie Reservation"<<endl<<endl;
					cout<<"The client number entered is invalid!!!"<<endl<<endl;
					system("pause");
				}//else
				a++;
		}while(a<quantityClients /* && */);
		do
		{
			system("cls");
			cout<<"Movie Reservation"<<endl<<endl;
			cout<<"Do you want to make another reservation?"<<endl
				<<"(Y/N): ";
			cin>>option;
			option=toupper(option);
			if(option!='Y' && option!='N')
			{
				system("cls");
				cout<<"Movie Reservation"<<endl<<endl;
				cout<<"Invalid option!!!"<<endl<<endl;
				system("pause");
			}//if
		}while(option!='Y' && option!='N');//while
	}while(option=='Y');
}//VOID




								
								//{
									//if(clientList[a].clientMovieList[c]!=movieNumber)
									//	c++
									/*
							if(movieList[b].movieQuantity>movieList[b].moviesReserved && clientList[a].clientReserveQuantity<LIMIT)//VERIFICO QUE QUEDEN DISPONIBLES Y QUE EL CLIENTE TENGA RESERVACIONES DISP
							{
								
									if(clientList[a].clientMovieList[c] != movieNumber)//COMPARANDO SI LA TIENE RESERVADA
									{
										clientList[a].clientReserveQuantity = clientList[a].clientReserveQuantity+1;
										clientList[a].clientMovieList[c+1] = movieNumber;
								}//IF
								else
								{
									cout<<"The client has already reserved that movie!!!"<<endl<<endl;
									system("pause");
								}
								/*{
									cout<<"This client has reached the reservation limit!!!"<<endl<<endl;//SI YA TIENE LLENO LAS RESERVACIONES
									system("pause");
								}
							}//FOR
						}
						else
						{
							cout<<"The client "<< clientList[a].clientName<<" has already reserved that movie!!!"<<endl<<endl;//SI YA LA TIENE RESERVADA
							system("pause");
						}
					}
					else
					{
						cout<<"The movie code entered is incorrect!!!"<<endl<<endl;//SI EL CODIGO ESTA INCORRECTO
						system("pause");
					}
				}//FOR
			}//IF
		}//FOR
		do
		{	
			system("cls");
			cout<<"Movie Reservation"<<endl<<endl;
			cout<<"Do you want to reserve another movie?"<<endl;
			cout<<"(Y/N): ";
			cin>>option;
			option=toupper(option);
			if(option!='Y' && option!='N')
			{
				cout<<"Invalid option!!!"<<endl<<endl;
				system("pause");
			}//IF
		}while(option!='Y' && option!='N');
	}while(option=='Y');//DO

}//VOID*/


void cancelReserve(Movies movieList[], Client clientList[], int quantityClients)
{
	string clientNumber, movieNumber;

	system("cls");
	cout<<"Cancel Reserve"<<endl<<endl;
	cout<<"Enter the client account number: #";
	cin>>clientNumber;
	for(int a=0;a<quantityClients;a++)//PARA BUSCAR EN ARREGLO DE STRUCTS
	{
		if(clientNumber == clientList[a].clientAccountNumber)//IF CLIENTNUMBER = ARREGLO NUMBER
			{
				cout<<"Enter the movie code: ";
				cin>>movieNumber;
				//for(int b=0;b<LIMIT;b++)//PARA BUSCAR EN ARREGLO DE STRUCTS DE PELICULAS
				for(int b=0;b<clientList[a].clientReserveQuantity;b++)
				{
					if(movieNumber == clientList[a].clientMovieList[b])//SI ENCUeNTRA LA PELICULA en el arreglo de las peliculas de los clientes
					{
						clientList[a].clientMovieList[b] = clientList[a].clientMovieList[clientList[a].clientReserveQuantity];//VERIFICAR ESTO
						clientList[a].clientReserveQuantity = clientList[a].clientReserveQuantity-1;
					}
					else
						cout<<"The client "<<clientList[a].clientAccountNumber<<" has no reservations of the movie "<<movieNumber<<"."<<endl; 
				}//FOR
			}
		else
			cout<<"The account number entered is invalid!!!"<<endl;
	}//FOR
}//VOID

void showMovies(Movies movieList[], int quantityMovies)
{
	system("cls");
	cout<<"Movie Schedule"<<endl<<endl;
	cout<<"CODE      TITLE                 RENT DATE       LIM.    RES."<<endl<<endl;
	for(int b=0;b<quantityMovies;b++)
	{
        cout<<movieList[b].movieCode
		<<"	"<<movieList[b].movieTitle
		<<"	"<<movieList[b].movieDate
		<<"	"<<movieList[b].movieQuantity
		<<"	"<<movieList[b].moviesReserved
		<<"\n";
	}//FOR
	cout<<"\n";
	system("pause");
}//VOID

void updateClient(/*Movies movieList[],*/ Client clientList[], int& quantityClients/*,  int quantityMovies*/)
{
	int selection;

	do
	{
		cout<<"Client Update"<<endl<<endl;
		cout<<"1) Add client"<<endl
			<<"2) Remove client"<<endl
			<<"3) Show client data"<<endl
			<<"4) Show client list"<<endl
			<<"5) Return to main menu"<<endl<<endl;
		cin>>selection;
			switch(selection)
			{
				case 1:
					addClient(clientList, quantityClients);
					break;
				case 2:
					removeClient(clientList, quantityClients);
					break;
				case 3:
					showClientInfo(clientList, quantityClients);
					break;
				case 4:
					showClientList(clientList, quantityClients);
					break;
				default:
					cout<<"Invalid selection!!!"<<endl<<endl;
					break;
			}//SWITCH
	}while(selection<1 || selection>5);
}//VOID UPDATE CLIENT

void addClient(Client clientList[], int& quantityClients)
{
	string newClientNumber, newClientName;

	if(quantityClients>=CLIENTLIMIT)//SI CABEN EN EL ARREGLO
	{
		cout<<"The client list is full!!!"<<endl<<"Please free some space!!!"<<endl;
		system("pause");
	}
	else
	{
		cout<<"Add Client"<<endl<<endl;
		cout<<"Enter the new client account number: #";
		cin>>newClientNumber;
		if(newClientNumber.length()>6)//VERIFICAR ESTO
			cout<<"Wrong account number!!!"<<endl;
		else
		{
			cout<<"Enter the client name: ";
			cin>>newClientName;
			
			quantityClients++;//ANADO 1 A LA CANTIDAD TOTAL
			clientList[quantityClients].clientAccountNumber = newClientNumber;
			clientList[quantityClients].clientName = newClientName;
		}//ELSE
	}//ELSE
}//VOID

void removeClient(Client clientList[], int& quantityClients)
{
	string removeAccountNumber;

	cout<<"Remove Client"<<endl<<endl;
	cout<<"Enter the account number to be deleted: #";
	cin>>removeAccountNumber;
	for(int a=0;a<quantityClients;a++)//PARA BUSCARLO
	{
		if(removeAccountNumber == clientList[a].clientAccountNumber)//SI LO ENCUENTRA
		{
			if(clientList[a].clientReserveQuantity!=0)//VERIFICO QUE NO TENGA PELICULAS ALQUILADAS
			{
				clientList[a] = clientList[quantityClients];//VERIFICAR SI PUEDO HACER ESTO
				/*
				clientList[a].clientAccountNumber = clientList[quantityClients].clientAccountNumber;
                clientList[a].clientName = clientList[quantityClients].clientName;
				clientList[a].clientReserveQuantity = clientList[quantityClients].clientReserveQuantity;
				for(int i=0;i<LIMIT;i++)
					clientList[a].clientMovieList[i] = clientList[quantityClients].clientMovieList[i];
					*/
				quantityClients--;//REDUSCO LA CANTIDAD DE CLIENTES
			}
			else
				cout<<"The client can't have movies reserved!!!"<<endl;
		}
		else
			cout<<"The account number entered doesn't match any client info!!!"<<endl;
	}//FOR
}//VOID


void showClientInfo(Client clientList[], int quantityClients)
{
	string clientSearch;

	cout<<"Show Client Info"<<endl<<endl;
	cout<<"Enter the client account number to search: ";
	cin>>clientSearch;
	for(int a=0;a<quantityClients;a++)
	{
		if(clientList[a].clientAccountNumber == clientSearch)
		{
			cout<<"Account Number: "<<clientList[a].clientAccountNumber<<endl;
			cout<<"Name: "<<clientList[a].clientName<<endl;
			cout<<"Amount Reserved: "<<clientList[a].clientReserveQuantity<<endl;
			cout<<"Movies Reserved: ";
				for(int c=0;c<clientList[a].clientReserveQuantity;c++)
					cout<<clientList[a].clientMovieList[c]<<" /t";
		}
		else
			cout<<"The account number doesn't match any client info!!!"<<endl;
	}//FOR
}//VOID

void showClientList(Client clientList[], int quantityClients)
{
	cout<<"Client List"<<endl<<endl;
    for(int a=0;a<quantityClients;a++)
	{
		cout<<"Client number: \t#"<<clientList[a].clientAccountNumber<<endl
			<<"Client name: \t"<<clientList[a].clientName<<endl
			<<"Movies reserved: \t"<<clientList[a].clientReserveQuantity<<endl;
			for(int b=0;b<clientList[a].clientReserveQuantity-1;b++)
				cout<<"Movie #"<<b+1<<":\t"<<clientList[a].clientMovieList[b];
			cout<<"\n\n";
	}//FOR
}//VOID

						