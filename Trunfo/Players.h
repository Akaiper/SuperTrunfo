#pragma once
#include "Baralho.h"

class Players
{
public:
	int EscolheAtributo(int qualCarta, int player, Cartas carta);

private:
	Baralho baralho;

	

	Menu menu;

	int atributo;
};

