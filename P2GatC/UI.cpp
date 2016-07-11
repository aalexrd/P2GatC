#include "UI.h"


UI::UI()
{
}


UI::~UI()
{
}

void UI::game()
{
	system("cls");
	system("color F6");
	cout << "Bienvenido al juego\nDigite el nombre del primer jugador: ";
	p[0].setName(getString());
	while (isdigit(p[0].getSign()))
	{
		cout << "Ingrese un nombre valido, sin números o caracteres especiales\n";
		p[0].setName(getString());
	}
	system("cls");
	cout << "Ahora que el segundo jugador digite su nombre: ";
	p[1].setName(getString());
	while (isdigit(p[1].getSign()))
	{
		cout << "Ingrese un nombre valido, sin números o caracteres especiales\n";
		p[1].setName(getString());
	}
	if (p[0].getSign() == p[1].getSign())
	{
		cout << "Ambos nombres empiezan igual, " << p[1].getName() << " usaras: \376 como tu marca.";
		p[1].setSign('\376');
		cin.get();
	}
	system("cls");
	fillGrid();
	for (int i = 0, t = 0; i < 9; i++)
	{
		printGrid();
		cout << p[t].getName() + " digite el numero de la casilla donde quiere marcar: ";
		while (!checkBox(getString()[0], p[t].getSign())) //if the box wasn't checked
			cout << "Intenta otra vez.\n";
		p[t].setChecks(p[t].getChecks() + 1); //keep track of times that player checked
		if (checkWinner(p[t]))
		{
			system("cls");
			cout << "Felicidades has ganado " << p[t].getName() << "!.";
			cin.get();
			break;
		}
		if (i == 8)
		{
			system("cls");
			cout << "Felicidades es un empate!";
			cin.get();
		}
		if (t == 1) //decide player
			t = 0;
		else
			t = 1;
		system("cls");
	}
	cout << "Gracias por jugar ;)";
	cin.get();
	cout << "Desearia jugar otra vez?\nSi o No: ";
	if (toupper(getString()[0]) == 'S')
		game();
}

string UI::getString()
{
	string i;
	getline(cin, i);
	if (i == "")
		return getString();
	return i;
}
