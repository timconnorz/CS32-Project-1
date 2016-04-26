
#include "history.h"
#include "Arena.h"
#include <iostream>

using namespace std;


History::History(int nRows, int nCols) 
{
	h_rows = nRows;
	h_cols = nCols;

	for (int i = 0; i < h_rows; i++) 
	{
		for (int j = 0; j < h_cols; j++) 
		{
			grid[i][j] = 0;						// sets the whole grid to zeros
		}
	}
}

bool History::record(int r, int c)	//updates the history_arena
{
	if (r > h_rows || c > h_cols || r < 1 || c < 1)
	{
		return 0;
	}
	grid[r - 1][c - 1]++;
	return 1;
}

void History::display() const
{ 
	// Draw the grid
	clearScreen();
	for (int i = 0; i < h_rows; i++)
	{
		for (int j = 0; j < h_cols; j++)
		{
			if (grid[i][j] == 0)
			{
				cout << ".";
			}
			else
			{
				//cout << "grid[i][j] = " << grid[i][j];
				cout << (char) (grid[i][j] + 64);
			}
		}
		cout << endl;
		
	}
}

