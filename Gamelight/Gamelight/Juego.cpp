#include <iostream>
#include "Juego.h"
#include "Jugadores.h"
#include "Estadisticas.h"

#include <conio.h>
#include <windows.h>
#include <stdlib.h>

#define Up 119
#define Down 115
#define Left3 97
#define Right3 100
#define Pause 112


#define Up2 72
#define Down2 80
#define Left2 75
#define Right2 77
#define Pause2 27

int nx = 15, ny = 15, m = 0, X = 17, Y = 17, score = 0, x22[100], y22[100], i, l;
using namespace std;
int x = 10, y = 10;
int x2 = 40, y2 = 30;
int x3 = 40, y3 = 30;

int xc = 30, yc = 15;
int tama = 10;
int tama2 = 10;
int tama3 = 10;
int luz[300][2];
int luz2[300][2];
int luz3[300][2];
char teclado;
char teclado2;
int RastrodeLuz=1;
int velocidad = 40;
int velopoten = 3000;
int dir = 3;
int dir2= 3;
int dir3 = 3;


void Pantalla();
//int score=0;
int vidasingle=3;
int vidamulti = 3;
Juego StartPlayingSingle();
Juego StartPlayingMulti();
void actualizar();
void marco();
void JugadorPlayerPrincipal();
void JugadorPlayerPrincipal2();
int potenciadores=0;
void Potenciar();
void carrito2();
void Pausa();


//Probar hacer con herencia


void gotoxy(int x,int  y) 
{
	HANDLE hCon;
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hCon, dwPos);

	CONSOLE_SCREEN_BUFFER_INFO csbi;

	GetConsoleScreenBufferInfo(hCon, &csbi);
	COORD scrollbar = {
		csbi.srWindow.Right - csbi.srWindow.Left + 1,
		csbi.srWindow.Bottom - csbi.srWindow.Top + 1
	};

	SetConsoleScreenBufferSize(hCon, scrollbar);



}






void clearPlayer2()
{
	gotoxy(x2, y2); printf("  ");

}


void clear()
{
	gotoxy(x, y); printf("  ");

}



bool game_over()
{
	if (y == 2 || y == 42 || x == 2 || x == 117)
	
		return false;

		{

			for (int j = tama - 1; j > 0; j--) {
				if (luz[j][0] == x && luz[j][1] == y)
					
					return false;
			
			}
			return true;
		}


	
}
void SavePcarrito() {
	luz[RastrodeLuz][0] = x;luz[RastrodeLuz][1] = y; RastrodeLuz++;
	if (RastrodeLuz == tama) 
		RastrodeLuz = 1;
}

void Potenciadores()
{
	if (x == xc && y == yc)
	{
		xc = (rand() % 73) + 5;
		yc = (rand() % 19) + 5;


		gotoxy(xc, yc);
		printf("%c", 169);

	}
}
void Potenciar()
{
	if ((x == xc) && (y == yc))
	{
		potenciadores = potenciadores + 20;
		if (potenciadores >= 20) {

			Sleep(0.0003);
		}
	}
}

void acumuladorPotenci()
{
	if (potenciadores == 20 && Pause2)
	{ 
	
	}
}
void carrito()
{

	for (int i = 1; i < tama; i++) {
		
		gotoxy(luz[i][0], luz[i][1]); 


		printf("%c", 254);
	}
	Potenciar();
	//gotoxy(x, y);
	

}



void SavePcarrito2() {
	luz2[RastrodeLuz][0] = x2; luz2[RastrodeLuz][1] = y2; RastrodeLuz++;
	if (RastrodeLuz == tama)
		RastrodeLuz = 1;
}


void carrito2()
{

	for (int i = 1; i < tama2; i++) {

		gotoxy(luz2[i][0], luz2[i][1]);


		printf("%c", 254);
	}
	Potenciar();


}

void SavePcarrito3() {
	luz3[RastrodeLuz][0] = x3; luz3[RastrodeLuz][1] = y3; RastrodeLuz++;
	if (RastrodeLuz == tama)
		RastrodeLuz = 1;
}


void carrito3()
{

	for (int i = 1; i < tama3; i++) {

		gotoxy(luz3[i][0], luz3[i][1]);


		printf("%c", 254);
	}
	Potenciar();


}

/*
void EraseCarrito() {
	gotoxy(luz[RastrodeLuz][0], luz[RastrodeLuz][1]);
	printf(" ");
}

*/
void lose()
{
	if (game_over() == false)
	{
		
		

		actualizar();
		vidasingle--;
		
	}
	
}

	
	



void actualizar()
{
	cout << "\t VIDAS ---> " << vidasingle<< "\t" << "\t" << "\t \t \t                                      PUNTAJE --->" << endl;
	marco();
	cout << "\tPOTENCIADOR --->5" << "\t" << "\t" << "\t \t \t                            VELOCIDADES---> 00" << endl;
	JugadorPlayerPrincipal();
	carrito();
	
}





void JugadorPlayerPrincipal()
{
	
	
	
	do {
		//gotoxy(xc, yc); printf("%c", 169);
		SavePcarrito();
		carrito();
		if (_kbhit())
		{
			teclado = _getch();
			Potenciadores();
			//SaveP();
			//CreateCar();
			//clear();
			switch (teclado)
			{
			case Left3:
				

				x--;
				break;
			case Right3:

				x++;
				break;
			case Up:
				
					y--;
				
				break;
			case Down:


				y++;
				break;
			case Pause:

				break;
			}

			carrito();

			//Sleep(velocidad);
		}
	} while (teclado != Pause && game_over());
	lose();
}


void Pausa()
{

	Sleep(10);
}
/*
void JuegoRealSingle()
{
	gotoxy(nx,ny); 
printf("O" ); 
usuario=getch(); 
}while(usuario!=27); 
return 0; 

	


}
*/
/*
void JugadorPlayerPrincipal2()
{



	do {
		//gotoxy(xc, yc); printf("%c", 4);
		if (_kbhit())
		{
			teclado2 = _getch();


			//SaveP();
			//CreateCar();
			//comida();
		

			//clear();
			switch (teclado2)
			{
			case Left2:
				x--;
				break;
			case Right2:
				x++;
				break;
			case Up2:
				y--;
				break;
			case Down2:
				y++;
				break;
			case Pause2:

				break;
			}

			carrito2();


		}
	} while (teclado2 != Pause && game_over());
	
}
*/


void marco() 
{
	// x is perfect
	for (int i = 2; i < 117; i++) {
		gotoxy(i, 2);
		printf("%c", 205);
		gotoxy(i, 42);
		printf("%c", 205);
		

	}
	
 // y is perfect
	for (int j = 3; j < 43; j++) {
		gotoxy(2, j);
		printf("%c", 186);
		gotoxy(117, j);
		printf("%c", 186);
	}
	
	gotoxy(2, 2); printf("%c", 201);
	gotoxy(2, 42); printf("%c", 200);
	gotoxy(117, 2); printf("%c", 187);
	gotoxy(117, 42); printf("%c", 188);
	
	
}
void Pantalla()
{

	cout << endl;
	Potenciar();

	SetWindowPos(GetConsoleWindow(), NULL, 400, 100, 750, 600, 0);

	marco();


	cout << endl;

	 cout << "\tPOTENCIADOR --->" << potenciadores<<"\t" << "\t" << "\t \t \t                            VELOCIDADES---> 00" << endl;


}
void Pantalla2()
{

	cout << endl;
	Potenciar();

	SetWindowPos(GetConsoleWindow(), NULL, 400, 100, 750, 600, 0);

	marco();


	cout << endl;

	cout << "\tPOTENCIADOR --->" << potenciadores << "\t" << "\t" << "\t \t \t                            VELOCIDADES---> 00" << endl;


}

void teclear() {
	if (_kbhit()) {
		teclado = _getch();
		switch (teclado) {
		case Up:
			if (dir != 2) 
				dir = 1; 
			break;
		case Down:
			if (dir != 1) 
				dir = 2;
			break;
		case Right3: 
			if (dir != 4) 
				dir = 3; 
			break;
		case Left3: 
			if (dir != 3) 
				dir = 4;
			break;
		}
	}
}


void teclear2() {
	if (_kbhit()) {
		teclado2 = _getch();
		switch (teclado2) {
		case Up2:
			if (dir2 != 2)
				dir2= 1;
			break;
		case Down2:
			if (dir2 != 1)
				dir2 = 2;
			break;
		case Right2:
			if (dir2 != 4)
				dir2 = 3;
			break;
		case Left2:
			if (dir2 != 3)
				dir2 = 4;
			break;
		}
	}
}
void teclear3() {
	
	int num;
	   num = 1 + rand() % (5 - 1);
	   int suma = dir + 1;
	   if (suma <= 4)
	   {
		   dir3 = suma;
	   }
	   if (dir3 >= 4)
	   {
		   dir3 = 1;
	   }
	  // if (y == 2 || y == 42 || x == 2 || x == 117)
}


void Juego::StartPlayingSingle()
{
	Pantalla();
	gotoxy(xc, yc); printf("%c", 4);



		while (teclado != Pause && game_over())
		{
			if(vidasingle==3){
			//borrar_cuerpo();
				Potenciadores();
			SavePcarrito();

			SavePcarrito2();
			//guardar_posicion2();
			carrito();
			carrito2();
			//dibujar_cuerpo2();

			teclear();
			teclear2();
			//teclear2();
			//teclear2();
			if (dir == 1) y--;
			if (dir == 2) y++;
			if (dir == 3) x++;
			if (dir == 4) x--;

			
			if (dir2 == 1) y2--;
			if (dir2 == 2) y2++;
			if (dir2 == 3) x2++;
			if (dir2 == 4) x2--;

	

			

			Pantalla();
		}

			Sleep(velocidad);
			if (game_over == false)
			{
				
				vidasingle = vidasingle - 1;
			}


		}
}




void Juego::StartPlayingMulti()
{
	Pantalla();
	gotoxy(xc, yc); printf("%c", 4);



	while (teclado != Pause && game_over())
	{
		if (vidasingle == 3) {
			//borrar_cuerpo();
			Potenciadores();
			SavePcarrito();
			SavePcarrito3();

			//guardar_posicion2();
			carrito();
			carrito3();
			//dibujar_cuerpo2();

			teclear();
			teclear3();
			//teclear2();
			//teclear2();
			if (dir == 1) y--;
			if (dir == 2) y++;
			if (dir == 3) x++;
			if (dir == 4) x--;

			
			if (dir3 == 1) y3--;
			if (dir3 == 2) y3++;
			if (dir3 == 3) x3++;
			if (dir3 == 4) x3--;
			

			Pantalla();
		}

		Sleep(velocidad);
		if (game_over == false)
		{

			vidasingle = vidasingle - 1;
		}


	}
}
/*
	cout << endl;
	cout << endl;
	SetWindowPos(GetConsoleWindow(), NULL, 400, 100, 750, 600, 0);     // Posicionamiento y Tamaño de la pantalla

	cout << "\t VIDAS ---> " "\t" << "\t" << "\t \t \tPUNTAJE ---> " << endl;
	
								
	
	marco();
	JugadorPlayerPrincipal2();
	cout << endl;
	cout << "\tPOTENCIADOR --->"<<potenciadores << "\t" << "\t" << "\t \t \tVELOCIDADES---> 00" << endl;
	JugadorPlayerPrincipal();
	


}
*/
