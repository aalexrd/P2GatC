#pragma once
#ifndef Player_H
#define Player_H
#include <string>
using namespace std;

class Player
{
private:
	char sign;
	string name;
	int checks;
public:
	Player();
	~Player();
	char getSign() const;
	void setSign(char sign);
	string getName() const;
	void setName(const string& name);
	int getChecks() const;
	void setChecks(int checks);
};
#endif
