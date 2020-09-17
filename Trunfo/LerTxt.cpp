#include "LerTxt.h"


Cartas LerTxt::lendo()
{
	txtCartas >> temp.supertrunfo;
	txtCartas >> temp.letraID;
	txtCartas >> temp.numID;
	txtCartas >> temp.humor;
	txtCartas >> temp.esperteza;
	txtCartas >> temp.anoDeCriacao;
	txtCartas >> temp.hallDaFama;
	txtCartas >> temp.idade;
	txtCartas.ignore();
	getline(txtCartas, temp.nome);
	return temp;
}
