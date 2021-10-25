#include <iostream>
using namespace std;

//podemos usar MACROS para buscar y reemplazar:
#define CONSOLE_HEIGHT 29
#define CONSOLE_WIDTH 119
#define BORDER_X 3
#define BORDER_Y 4

int main()
{
	char ConsoleScreen[CONSOLE_HEIGHT][CONSOLE_WIDTH];
	int personaje_x = 10;
	int personaje_y = 5;

	for (int i = 0; i < CONSOLE_HEIGHT; i++)
	{
		for (int j = 0; j < CONSOLE_WIDTH; j++)
		{
			// BORDER_TOP = i < BORDER_X
			// BORDER_BOTTOM = i >= CONSOLE_HEIGHT - BORDER_X
			// BORDER_LEFT = j < BORDER_Y
			// BORDER_RIGHT = j >= CONSOLE_WIDTH - BORDER_Y
			if (i < BORDER_X || i >= CONSOLE_HEIGHT - BORDER_X || j < BORDER_Y || j >= CONSOLE_WIDTH - BORDER_Y) {

				ConsoleScreen[i][j] = '#';
			}
			else {
				//Acceder a los elementos del array
				ConsoleScreen[i][j] = '-';
			}
		}
	}

	for (int i = 0; i < CONSOLE_HEIGHT; i++)
	{
		for (int j = 0; j < CONSOLE_WIDTH; j++)
		{
			cout << ConsoleScreen[i][j];
		}
		cout << endl;

	}

}

