#pragma once
#include "LerTxt.h"
#include "Menu.h"
#include <algorithm>
#include <stack>
#include <list>
#include <ctime>        // std::time
#include <stdlib.h> // std::rand, std::srand

using namespace std;


class Baralho
{
public:

	Cartas cartasTemp;

	list <int> *cartasPlayer;
	list <int> *cartasPC;

	void MontaBaralho();

	void Embaralha();

	void DivideCartas(int nbot, int nplayer);

	void PassaAsCartas(int indiceGanhador, bool humano, int nbot, int nplayer);

	Cartas GetCarta(int numeroCarta);

	LerTxt leitor;

private:

	Menu menu;

	Cartas baralhoCartas[32];

	stack <int> embaralhado;

	int embaralhando[32];

	ifstream txtCartas;

	float random;



	
	
};

