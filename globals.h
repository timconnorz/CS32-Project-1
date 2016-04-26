
#ifndef GLOBALS_H
#define GLOBALS_H

///////////////////////////////////////////////////////////////////////////
// Manifest constants
///////////////////////////////////////////////////////////////////////////

const int MAXROWS = 20;             // max number of rows in the arena
const int MAXCOLS = 30;             // max number of columns in the arena
const int MAXROBOTS = 100;          // max number of robots allowed
const int INITIAL_ROBOT_HEALTH = 1;//changed from 2 to 1

const int UP = 0;
const int DOWN = 1;
const int LEFT = 2;
const int RIGHT = 3;


///////////////////////////////////////////////////////////////////////////
//  Auxiliary function declarations
///////////////////////////////////////////////////////////////////////////



int decodeDirection(char dir);
int randInt(int min, int max);
void clearScreen();



#endif