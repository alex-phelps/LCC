#include "Program08.h"
#include "Program08.h2"

/**************************************************************
 * mouse_init()
 * This function is called each time a maze map is loaded.
 **************************************************************/
void mouse_init(int x,int y)
{ 
	int i, j;

	// Set mouse position

	col = x;
	row = y;

	for (i = 0; i < MAZE_ROWS; i++) // Pre-pop copy array
		for (j = 0; j < MAZE_COLS; j++)
			copy[i][j] = CELL_WALL;
}

/**************************************************************
 * mouse_move()
 * This function is called each timer tick.
 **************************************************************/
void mouse_move()
{ 
	int i, j;
	cell map[3][3];

	// Look around

	mouse_look(map);

	for (i = 0; i < 3; i++) // Copy look array into copy
		for (j = 0; j < 3; j++)
			if (map[i][j] != CELL_WALL && copy[row + (i - 1)][col + (j - 1)] != CELL_VISITED) // skip walls (from prepop) and visited (dont override visited with opens)
				copy[row + (i - 1)][col + (j - 1)] = map[i][j];





	// Random move

	/*r = rand()%4;

	if(r==0) if(mouse_north()) row--;
	if(r==1) if(mouse_south()) row++;
	if(r==2) if(mouse_east()) col++;
	if(r==3) if(mouse_west()) col--;*/
}
