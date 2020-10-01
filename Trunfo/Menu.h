#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <conio.h>
using namespace std;

class Menu
{
public:
	void Njogadores();
	void clear();

	int GetNPlayer();
	int GetNBot();

	

private:

	string lixo;
	int nplayer, nbot, total;
};

