#pragma once
#include "Baralho.h"
#include "Players.h"
#include "Bots.h"

class Jogo
{
public:

	void LoopJogo();


private:

	void DesenhaCarta();
	void ContaEmpty();
	void ImprimeNCartas();


	Baralho baralho;
	Menu menu;
	Cartas carta;


	Players players;
	list <int> player;

	Bots bots;
	list <int> bot;


	int atributo;
	int atributoGanhador;

	int quantosPerderam = 0;

	bool acabou = false;

	bool eHumano = true;
	int indiceDaVez = 0;

	int nbot, nplayer, total;

	int *quemJaPerdeu;
	int indicePerdeu;


};

