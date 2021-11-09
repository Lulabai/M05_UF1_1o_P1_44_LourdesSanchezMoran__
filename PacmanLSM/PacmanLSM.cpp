#include <iostream>
using namespace std;


#define CONSOLE_HEIGHT 29 //eje y filas
#define CONSOLE_WIDTH 119 // eje x columnas
#define BORDER_X 1
#define BORDER_Y 2

int main();
void crearMapa();
void imprimirMapa();


enum MAP_TILES { EMPTY = ' ', WALL = '#', POINT = '.' };


MAP_TILES ConsoleScreen[CONSOLE_HEIGHT][CONSOLE_WIDTH];
char personaje = 'O';
int personaje_posicion_x = 10;
int personaje_posicion_y = 5;


int main()
{
	crearMapa();
	imprimirMapa();
}


void imprimirMapa()
{
	system("CLS");
	for (int y = 0; y < CONSOLE_HEIGHT; y++)
	{
		for (int x = 0; x < CONSOLE_WIDTH; x++)
		{

			if (personaje_posicion_x == x && personaje_posicion_y == y) {
				cout << personaje;
			}
			else {
				cout << (char)ConsoleScreen[y][x];
			}
		}
		cout << endl;
	}
}

void crearMapa()
{
	for (int y = 0; y < CONSOLE_HEIGHT; y++)
	{
		for (int x = 0; x < CONSOLE_WIDTH; x++)
		{
			// BORDER_TOP = y < BORDER_X
			// BORDER_BOTTOM = y >= CONSOLE_HEIGHT - BORDER_X
			// BORDER_LEFT = x < BORDER_Y
			// BORDER_RIGHT = x >= CONSOLE_WIDTH - BORDER_Y
			if (y < BORDER_X || y >= CONSOLE_HEIGHT - BORDER_X || x < BORDER_Y || x >= CONSOLE_WIDTH - BORDER_Y) {
				// OTRA FORMA: if (y  == 0 || y == CONSOLE_HEIGHT - 1 || x == 0 || x >= CONSOLE_WIDTH - 1) {} --> aquí hace un marco de uno por cada lado

				ConsoleScreen[y][x] = MAP_TILES::WALL;
			}
			else {
				ConsoleScreen[y][x] = MAP_TILES::EMPTY;
			}
		}
	}
}