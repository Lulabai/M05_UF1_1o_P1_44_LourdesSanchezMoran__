#include <iostream>
using namespace std;

//podemos usar MACROS para buscar y reemplazar:
#define CONSOLE_HEIGHT 29 //eje y
#define CONSOLE_WIDTH 119 // eje x
#define BORDER_X 3
#define BORDER_Y 5

char ConsoleScreen[CONSOLE_HEIGHT][CONSOLE_WIDTH];
char personaje = 'O';
int personaje_posicion_x = 100;
int personaje_posicion_y = 20;
bool run = true;


void imprimirMapa()
{
	for (int y = 0; y < CONSOLE_HEIGHT; y++)
	{
		for (int x = 0; x < CONSOLE_WIDTH; x++)
		{

			if (personaje_posicion_x == x && personaje_posicion_y == y) {
				cout << personaje;
			}
			else {
				cout << ConsoleScreen[y][x];
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

				ConsoleScreen[y][x] = '#';
			}
			else {
				//Acceder a los elementos del array
				ConsoleScreen[y][x] = '-'; //y filas, x columnas
			}
		}
	}
}

void inputs()
{
	char input;
	cin >> input;
	switch (input)
	{
	case 'W':
	case 'w':
		personaje_posicion_y++; // es lo mismo que: personaje_posicion_y=personaje_posicion_y+1; o es lo mismo que: personaje_posicion_y += 1;
		break;
	case 'A':
	case 'a':
		personaje_posicion_x--;
		break;
	case 'S':
	case 's':
		personaje_posicion_y--;
		break;
	case 'D':
	case 'd':
		personaje_posicion_x++;
		break;
	default:
		break;
	}

}

int main()
{
	crearMapa();
	imprimirMapa();
	while (run) {
		inputs();
		imprimirMapa();
	}
}