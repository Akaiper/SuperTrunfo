#pragma once
#include "LerTxt.h"
#include <algorithm>
#include <stack>
#include <list>
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand

using namespace std;


class Baralho
{
public:

	Cartas cartasTemp;

	list <int> cartasPlayer;
	list <int> cartasPC;

	void MontaBaralho();

	void Embaralha();

	void DivideCartas();

	LerTxt leitor;

private:
	Cartas baralho[32];

	

	stack <int> embaralhado;

	int embaralhando[32];

	ifstream txtCartas;

	float random;

	//blabla



	
	
};

