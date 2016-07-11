#pragma once
#ifndef Grid_H
#define Grid_H
#include <iostream>
#include "Player.h"

class Grid
{
private:
	char grid[3][3];
public:
	Grid();
	~Grid();
	void fillGrid();
	void printGrid();
	bool checkBox(char n, char c);
	bool checkWinner(Player p) const;
};
#endif
