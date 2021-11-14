#include <iostream>
#include <conio.h>
#include <Windows.h>


using namespace std;

#define CONSOLE_HEIGHT 29 //eje y filas
#define CONSOLE_WIDTH 119 // eje x columnas
#define BORDER_X 1
#define BORDER_Y 1


int main();
void crearMapa();
void crearPuertasMapa();
void crearPointMaps();
void imprimirMapa();
void inputs();
void logica();
void imprimirScore();
void winTheGame();



enum MAP_TILES { EMPTY = ' ', WALL = '#', POINT_MAP = char(248) };
enum USER_INPUTS { NONE, UP, DOWN, RIGHT, LEFT, QUIT };


MAP_TILES ConsoleScreen[CONSOLE_HEIGHT][CONSOLE_WIDTH];
int map_points = 0;
char personaje = char(219);
int personaje_posicion_x = 10;
int personaje_posicion_y = 5;
int score = 0;
USER_INPUTS input = USER_INPUTS::NONE;
bool run = true;




int main()
{
	crearMapa();
	imprimirMapa();
	imprimirScore();


	while (run) {
		inputs();
		logica();
		imprimirMapa();
		imprimirScore();
		winTheGame();
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
	Sleep(100);
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

	crearPointMaps();
	crearPuertasMapa();
}


void crearPointMaps() {
	ConsoleScreen[5][71] = MAP_TILES::POINT_MAP;
	map_points++;
	ConsoleScreen[5][72] = MAP_TILES::POINT_MAP;
	map_points++;
	ConsoleScreen[5][73] = MAP_TILES::POINT_MAP;
	map_points++;
	ConsoleScreen[5][74] = MAP_TILES::POINT_MAP;
	map_points++;
	ConsoleScreen[5][75] = MAP_TILES::POINT_MAP;
	map_points++;
	ConsoleScreen[5][76] = MAP_TILES::POINT_MAP;
	map_points++;
	ConsoleScreen[5][77] = MAP_TILES::POINT_MAP;
	map_points++;
	ConsoleScreen[5][78] = MAP_TILES::POINT_MAP;
	map_points++;
	ConsoleScreen[10][71] = MAP_TILES::POINT_MAP;
	map_points++;
	ConsoleScreen[10][72] = MAP_TILES::POINT_MAP;
	map_points++;
	ConsoleScreen[10][73] = MAP_TILES::POINT_MAP;
	map_points++;
	ConsoleScreen[10][74] = MAP_TILES::POINT_MAP;
	map_points++;
	ConsoleScreen[10][75] = MAP_TILES::POINT_MAP;
	map_points++;
	ConsoleScreen[10][76] = MAP_TILES::POINT_MAP;
	map_points++;
	ConsoleScreen[10][77] = MAP_TILES::POINT_MAP;
	map_points++;
	ConsoleScreen[10][78] = MAP_TILES::POINT_MAP;
	map_points++;
	ConsoleScreen[9][40] = MAP_TILES::POINT_MAP;
	map_points++;
	ConsoleScreen[8][40] = MAP_TILES::POINT_MAP;
	map_points++;
	ConsoleScreen[7][40] = MAP_TILES::POINT_MAP;
	map_points++;
	ConsoleScreen[6][40] = MAP_TILES::POINT_MAP;
	map_points++;
	ConsoleScreen[9][50] = MAP_TILES::POINT_MAP;
	map_points++;
	ConsoleScreen[8][50] = MAP_TILES::POINT_MAP;
	map_points++;
	ConsoleScreen[7][50] = MAP_TILES::POINT_MAP;
	map_points++;
	ConsoleScreen[6][50] = MAP_TILES::POINT_MAP;
	map_points++;
}


void crearPuertasMapa() {
	ConsoleScreen[2][0] = MAP_TILES::EMPTY;
	ConsoleScreen[3][0] = MAP_TILES::EMPTY;
	ConsoleScreen[2][CONSOLE_WIDTH - 1] = MAP_TILES::EMPTY;
	ConsoleScreen[3][CONSOLE_WIDTH - 1] = MAP_TILES::EMPTY;
}


void inputs()
{
	char input_raw;
	input_raw = _getch();

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


	if (personaje_x_new < 0) {
		personaje_x_new = CONSOLE_WIDTH - 1; //ancho de la consola
	}

	if (personaje_y_new < 0) {
		personaje_y_new = CONSOLE_HEIGHT - 1;
	}
	personaje_x_new %= CONSOLE_WIDTH;
	personaje_y_new %= CONSOLE_HEIGHT;


	if (ConsoleScreen[personaje_y_new][personaje_x_new] == MAP_TILES::WALL) {
		personaje_y_new = personaje_posicion_y;
		personaje_x_new = personaje_posicion_x;
	}
	else if (ConsoleScreen[personaje_y_new][personaje_x_new] == MAP_TILES::POINT_MAP) {
		map_points--;
		score++;
		ConsoleScreen[personaje_y_new][personaje_x_new] = MAP_TILES::EMPTY;
	}
	personaje_posicion_y = personaje_y_new;
	personaje_posicion_x = personaje_x_new;
}


void imprimirScore() {
	cout << "Score: " << score; //aparecerá justo debajo del tablero
}


void winTheGame() {
	if (score == 24) {
		cout << " You win!" << endl; //aparecerá justo al lado de los puntos conseguidos
	}
}
