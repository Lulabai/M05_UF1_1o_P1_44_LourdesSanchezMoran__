#include <iostream>
using namespace std;


#define CONSOLE_HEIGHT 29 //eje y filas
#define CONSOLE_WIDTH 119 // eje x columnas
#define BORDER_X 1
#define BORDER_Y 2

int main();
void crearMapa();
void imprimirMapa();
void inputs();
void logica();


enum MAP_TILES { EMPTY = ' ', WALL = '#', POINT = '.' };
enum USER_INPUTS { NONE, UP, DOWN, RIGHT, LEFT, QUIT };


MAP_TILES ConsoleScreen[CONSOLE_HEIGHT][CONSOLE_WIDTH];
char personaje = 'O';
int personaje_posicion_x = 10;
int personaje_posicion_y = 5;
USER_INPUTS input = USER_INPUTS::NONE;
bool run = true;


int main()
{
	crearMapa();
	imprimirMapa();
	while (run) {
		inputs();
		logica();
		imprimirMapa();
	}
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


void inputs()
{
	char input_raw;
	cin >> input_raw;
	switch (input_raw)
	{
	case 'W':
	case 'w':
		input = USER_INPUTS::UP;
		break;
	case 'A':
	case 'a':
		input = USER_INPUTS::LEFT;
		break;
	case 'S':
	case 's':
		input = USER_INPUTS::DOWN;
		break;
	case 'D':
	case 'd':
		input = USER_INPUTS::RIGHT;
		break;
	case 'Q':
	case 'q':
		input = USER_INPUTS::QUIT;
		break;
	default:
		input = USER_INPUTS::NONE;
		break;
	}

}

void logica()
{
	int personaje_y_new = personaje_posicion_y;
	int personaje_x_new = personaje_posicion_x;


	switch (input)
	{
	case NONE:
		break;
	case UP:
		personaje_y_new--;
		break;
	case DOWN:
		personaje_y_new++;
		break;
	case RIGHT:
		personaje_x_new++;
		break;
	case LEFT:
		personaje_x_new--;
		break;
	case QUIT:
		run = false;
		break;
	default:
		break;
	}
	if (ConsoleScreen[personaje_y_new][personaje_x_new] == MAP_TILES::WALL) {
		personaje_y_new = personaje_posicion_y;
		personaje_x_new = personaje_posicion_x;
	}
	personaje_posicion_y = personaje_y_new;
	personaje_posicion_x = personaje_x_new;
}