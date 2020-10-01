#include "Menu.h"

void Menu::Njogadores()
{

	cout << "\n\nSUPER TRUNFO\n\n";
	cout << "\nQuantos jogadores humanos serao?\n";
	cin >> nplayer;
	cout << "\nQuantos bots serao?\n";
	cin >> nbot;

	while (nplayer + nbot > 32) {

		clear();

		cout << "\n\nNumero total de jogadores ultrapassou o numero de cartas (32)\n";
		cout << "\nInsira novamente o numero de jogadores humanos:\n";
		cin >> nplayer;
		cout << "\nQuantos bots serao?\n";
		cin >> nbot;
	}

	while (nplayer + nbot == 1) {
		clear();

		cout << "\n\nNao ha jogadores suficientes, minimo 2 jogadores (somando bots e humanos)\n";
		cout << "\nInsira novamente o numero de jogadores humanos:\n";
		cin >> nplayer;
		cout << "\nQuantos bots serao?\n";
		cin >> nbot;
	}

	total = nbot + nplayer;

	cout << "Clique em qualquer tecla para continuar...";
	lixo = _getch();
	clear();

}

void Menu::clear()
{
	
		COORD topLeft = { 0, 0 };
		HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO screen;
		DWORD written;

		GetConsoleScreenBufferInfo(console, &screen);
		FillConsoleOutputCharacterA(
			console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
		);
		FillConsoleOutputAttribute(
			console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
			screen.dwSize.X * screen.dwSize.Y, topLeft, &written
		);
		SetConsoleCursorPosition(console, topLeft);
	
}

int Menu::GetNPlayer()
{
	return nplayer;
}

int Menu::GetNBot()
{
	return nbot;
}


