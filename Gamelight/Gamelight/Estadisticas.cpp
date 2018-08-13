#include <iostream>
#include "Estadisticas.h"
#include "play.h"
using namespace std;


void Estadisticas::Estadistics()
{
	play menuprincipal;
	int option = 0;
	cout << endl;
	cout << endl;
	cout << "  ******** E S T A D I S T I C A S **********    " << endl;

	cout << "\nUltimos 10 resultados del Single Player" << endl;

	cout << "                   530                     " << endl;
	cout << "                   120                     " << endl;
	cout << "                   30                     " << endl;
	cout << "                   20                     " << endl;
	cout << "                   15                     " << endl;
	cout << "                   10                     " << endl;

	cout << endl;
	cout << endl;
	cout << "Presione el número 1 para volver al menú principal" << endl;
	cin >> option;
	//I´m still working on this warning
	do {
		if (option == 1) {
			system("cls");
			menuprincipal.played();

		}
		else {
			cout << "Ingrese una opcion que sea valida: "<<endl;
			cin >> option;
			
		}
	} while (option !=1);

	}


