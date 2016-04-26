
#include <random>
#include <string>
#include <iostream>
#include "game.h"
#include "globals.h"
#include "Arena.h"
#include "Player.h"
using namespace std;



///////////////////////////////////////////////////////////////////////////
//  Game implementations
///////////////////////////////////////////////////////////////////////////

Game::Game(int rows, int cols, int nRobots)
{
	if (nRobots < 0)
	{
		cout << "***** Cannot create Game with negative number of robots!" << endl;
		exit(1);
	}
	if (nRobots > MAXROBOTS)
	{
		cout << "***** Trying to create Game with " << nRobots
			<< " robots; only " << MAXROBOTS << " are allowed!" << endl;
		exit(1);
	}
	if (rows == 1 && cols == 1 && nRobots > 0)
	{
		cout << "***** Cannot create Game with nowhere to place the robots!" << endl;
		exit(1);
	}

	// Create arena
	m_arena = new Arena(rows, cols);

	// Add player
	int rPlayer = randInt(1, rows);
	int cPlayer = randInt(1, cols);
	m_arena->addPlayer(rPlayer, cPlayer);

	// Populate with robots
	while (nRobots > 0)
	{
		int r = randInt(1, rows);
		int c = randInt(1, cols);
		// Don't put a robot where the player is
		if (r == rPlayer  &&  c == cPlayer)
			continue;
		m_arena->addRobot(r, c);
		nRobots--;
	}
}

Game::~Game()
{
	delete m_arena;
}

void Game::play()
{
	Player* p = m_arena->player();
	if (p == nullptr)
	{
		m_arena->display();
		return;
	}
	do
	{
		m_arena->display();
		cout << endl;
		cout << "Move (u/d/l/r/h/q): ";
		string action;
		getline(cin, action);
		if (action.size() == 0)  // player stands
			p->stand();
		else
		{
			switch (action[0])
			{
			default:   // if bad move, nobody moves
				cout << '\a' << endl;  // beep
				continue;
			case 'q':
				return;
			case 'h':
				m_arena->history().display();
				cout << endl << "Press Enter to Continue";
				cin.ignore(10000, '\n');
				m_arena->display();
				break;
			case 'u':
			case 'd':
			case 'l':
			case 'r':
				p->moveOrAttack(decodeDirection(action[0]));
				m_arena->moveRobots();
				break;
			}
		}
		//m_arena->moveRobots();
	} while (!m_arena->player()->isDead() && m_arena->robotCount() > 0);
	m_arena->display();
}

// Return a random int from min to max, inclusive
int randInt(int min, int max)
{
	if (max < min)
		swap(max, min);
	static random_device rd;
	static mt19937 generator(rd());
	uniform_int_distribution<> distro(min, max);
	return distro(generator);
}

