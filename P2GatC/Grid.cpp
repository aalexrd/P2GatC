#include "Grid.h"


Grid::Grid()
{
}


Grid::~Grid()
{
}

void Grid::fillGrid()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			grid[i][j] = char('1' + i * 3 + j);
}

void Grid::printGrid()
{
	for (int i = 0; i < 3; i++)
	{
		if (i == 0)
			for (int p = 0; p < 3; p++)
			{
				if (p == 0)
					cout << "\332";
				cout << "\304\304\304";
				if (p == 2)
					cout << "\277\n";
				else
					cout << "\302";
			}
		if (0 < i && i < 3)
			for (int p = 0; p < 3; p++)
			{
				if (p == 0)
					cout << "\303";
				cout << "\304\304\304";
				if (p == 2)
					cout << "\264\n";
				else
					cout << "\305";
			}
		for (int p = 0; p < 3; p++)
		{
			cout << "\263 " << grid[i][p] << " ";
			if (p == 2)
				cout << "\263\n";
		}
		if (i == 2)
		{
			for (int p = 0; p < 3; p++)
			{
				if (p == 0)
					cout << "\300";
				cout << "\304\304\304";
				if (p == 2)
					cout << "\331\n";
				else
					cout << "\301";
			}
		}
	}
}

bool Grid::checkBox(char n, char c)
{
	if (n <= '9')
	{
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				if (grid[i][j] == n)
				{
					grid[i][j] = c;
					return true;
				}
		return false;
	}
	return false;
}

bool Grid::checkWinner(Player p) const
{
	int k = 0;
	while (p.getChecks() >= 3 && k < 3)
	{
		int cont[] = {0, 0, 0, 0};
		for (int i = 0; i < 3 && k < 3; i++)
		{
			if (grid[i][k] == p.getSign()) //columns
			{
				++cont[0];
				if (cont[0] == 3)
					return true;
			}
			if (grid[k][i] == p.getSign()) //rows
			{
				++cont[1];
				if (cont[1] == 3)
					return true;
			}
			if (grid[i][i] == p.getSign()) //diagonal
			{
				++cont[2];
				if (cont[2] == 3)
					return true;
			}
			if (grid[i][2 - i] == p.getSign()) //inverse diagonal
			{
				++cont[3];
				if (cont[3] == 3)
					return true;
			}
		}
		k++;
	}
	return false;
}
