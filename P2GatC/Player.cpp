#include "Player.h"


Player::Player(): sign(0), checks(0)
{
}


Player::~Player()
{
}

char Player::getSign() const
{
	return sign;
}

void Player::setSign(char sign)
{
	this->sign = sign;
}

string Player::getName() const
{
	return name;
}

void Player::setName(const string& name)
{
	this->name = name;
	setSign(name[0]);
}

int Player::getChecks() const
{
	return checks;
}

void Player::setChecks(int checks)
{
	this->checks = checks;
}
