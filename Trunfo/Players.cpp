#include "Players.h"

int Players::EscolheAtributo(int qualCarta, int player, Cartas carta)
{

	cout << "\nVEZ DO PLAYER " << player + 1 << endl;
	 _getch();

	menu.clear();

	cout << "\nSua carta:\n";
	cout << carta.numID << carta.letraID << "   " << carta.nome;
	cout << "\n1 - Humor (>): " << carta.humor;
	cout << "\n2 - Esperteza (>): "<< carta.esperteza;
	cout << "\n3 - Ano de Criacao (<): "<< carta.anoDeCriacao;
	cout << "\n4 - Hall da Fama (>): " << carta.hallDaFama;
	cout << "\n5 - Idade (<): " << carta.idade;

	if (carta.supertrunfo)
		cout << "\n\nSua Carta e o Super Trunfo!";

	cout << "\n\nQue atributo voce quer?\n";
	cin >> atributo;

	menu.clear();

	return atributo;
}
