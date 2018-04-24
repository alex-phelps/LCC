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
	int exit_row = -1, exit_col = -1;
	cell map[3][3];

	// Look around

	mouse_look(map);

	if (map[1][1] == CELL_EXIT) return; // We're already done

	copy[row][col] = true; // Visit current cell

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			if (map[i][j] == CELL_EXIT) // Find exit if possible
			{
				exit_row = row + (i - 1);
				exit_col = col + (j - 1);
			}
		}

	if (exit_row >= 0) // Found exit in vicinity
	{
		if (exit_row < row) // north
		{
			if (mouse_north())
			{
				row--;
				return; // move north if possible
			}
		}
		else if (exit_row > row)
		{
			if (mouse_south())
			{
				row++;
				return; // move south if possible
			}
		}

		//If you cant move b/c of wall or if exit is strictly east/west

		if (exit_col > col) //east
		{
			if (mouse_east())
			{
				col++;
				return; //move east if possible
			}
		}
		else if (exit_col < col)
		{
			if (mouse_west())
			{
				col--;
				return; // move west if possible
			}
		}


		//If it gets here, the exit is in a corner behind two walls; if so, procede with algorithm to find a detour
	}

	//Basically - move if not visited, with clockwise priority
	if (!copy[row - 1][col] && mouse_north()) // north
	{
		row--;
		return; // moved
	}
	else if (!copy[row][col + 1] && mouse_east()) // east
	{
		col++;
		return; // moved
	}
	else if (!copy[row - 1][col] && mouse_south()) // south
	{
		row++;
		return; // moved
	}
	else if (!copy[row][col - 1] && mouse_west()) //west
	{
		col--;
		return; // moved
	}



	// Random move

	/*r = rand()%4;

	if(r==0) if(mouse_north()) row--;
	if(r==1) if(mouse_south()) row++;
	if(r==2) if(mouse_east()) col++;
	if(r==3) if(mouse_west()) col--;*/
}
