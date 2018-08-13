#include <iostream>
using namespace std;
#include "Jugadores.h"
#include "play.h"
#include "Juego.h"

Juego StartPlayings;
play menu;
void Jugadores::TipodeJugadores() {
	int options=0;
	cout << endl;
	cout << endl;
	cout << "        ******** O P C I O N E S    D E     J U E G O S ******** " << endl;
	cout << endl;
	cout << "\n                             1.UNICO JUGADOR" << "\n                             2.MULTIJUGADOR" << endl;
	cout << endl;
	cout << "Presione 3 para volver al menú principal: " << endl;
	cout << "Ingrese un numero de acuerdo a la opcion que desee escoger: " << endl;
	

	do {
		cin >> options;
		switch (options) {
		
		case 1:
			system("cls");
			StartPlayings.StartPlayingSingle();
			break;

		case 2:
			system("cls");
			StartPlayings.StartPlayingMulti();
			break;

		case 3:
			system("cls");
			menu.played();
			break;

		}

		} while (options != 3);

}
