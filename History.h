
#ifndef HISTORY_H
#define HISTORY_H

class Arena;
#include "globals.h"

using namespace std;

class History
{
public:
	History(int nRows, int nCols);
	bool record(int r, int c);
	void display() const;
private:
	Arena* history_arena;
	int h_rows;
	int h_cols;
	int grid[MAXROWS][MAXCOLS];
};

#endif