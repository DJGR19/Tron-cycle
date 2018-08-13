#include <iostream>
#include"play.h"
#include "Estadisticas.h"
#include "Jugadores.h"
#include "Juego.h"
#include "stdio.h"
#include <conio.h>
#include <windows.h>
using namespace std;

Estadisticas stadistics;
Jugadores playersnow;
Juego Startplay; 



void play::played() {
	cout << endl;
	cout << endl;
	cout << "         ****** T R O N  :  L I G H T   C Y C L E S   G A M E ************          " << endl;
	cout << endl;
	cout << "\n                                  1.JUGAR" << "\n                                  2.ESTADISTICAS" << "\n                                  3.SALIR" << endl;
	cout << endl;
	cout << "\n Ingrese un número para seleccionar la opcion que desea: " << endl;

}



int main() {

	
	SetWindowPos(GetConsoleWindow(), NULL, 400, 100, 600, 280, 0);
	int options=0;
		cout << endl;
		cout << endl;
		cout << "               ****** T R O N  :  L I G H T   C Y C L E S   G A M E ************          " << endl;
		cout << endl;
		cout << "\n                                       1.JUGAR" << "\n                                       2.ESTADISTICAS"<< "\n                                       3.SALIR"<<endl;
		cout << endl;
		cout << "\n                   Ingrese un numero para seleccionar la opcion que desea: " << endl;
		
		do {
			cin >> options;
			switch (options)
			{

			case 1:
				//función jugar
				system("cls");
				playersnow.TipodeJugadores();
				//playersnow.TipodeJugadores();
				break;
			case 2:
				system("cls");
				stadistics.Estadistics();
				break;
			case 3:

				break;


			}
	} while (options != 3);
}