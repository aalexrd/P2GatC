#pragma once
#ifndef UI_H
#define UI_H
#include "Grid.h"

class UI : public Grid
{
private:
	Player p[2];
public:
	UI();
	~UI();
	void game();
	static string getString();
};
#endif
