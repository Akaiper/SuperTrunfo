#include "Jogo.h"

void Jogo::LoopJogo()
{

	menu.Njogadores();

	nplayer = menu.GetNPlayer();
	nbot = menu.GetNBot();

	baralho.MontaBaralho();
	baralho.Embaralha();
	baralho.DivideCartas(nbot, nplayer);

	

	

	total = nplayer + nbot;

	quantosPerderam = 0;
	acabou = false;
	indiceDaVez = 0;
	eHumano = true;
	
	if (nplayer <= 0) {

		eHumano = false;
	}


	while (!acabou) {
		
		if (eHumano) {

			player = baralho.cartasPlayer[indiceDaVez];

			//baralho.GetCarta(baralho.cartasPlayer[indiceDaVez].front());

			atributo = players.EscolheAtributo(player.front(), indiceDaVez, baralho.GetCarta(baralho.cartasPlayer[indiceDaVez].front()));
		}
		else {

			bot = baralho.cartasPC[indiceDaVez];

			atributo = bots.DefineAtributo();
		}

		cout << "\n\nO atributo escolhido foi ";

		switch (atributo)
		{
		case 1:
			cout << "Humor\n";
			break;
		case 2:
			cout << "Esperteza\n";
			break;
		case 3:
			cout << "Ano de Criaçao\n";
			break;
		case 4:
			cout << "Hall da Fama\n";
			break;
		case 5:
			cout << "Idade\n";
			break;
		default:
			break;
		}

		DesenhaCarta();

		if (eHumano) {
			cout << "\n\nQuem ganhou foi o Player " << indiceDaVez + 1 << "\n";
		}
		else {
			cout << "\n\nQuem ganhou foi o Bot " << indiceDaVez + 1 << "\n";
		}

		baralho.PassaAsCartas(indiceDaVez, eHumano, nbot, nplayer);

		ContaEmpty();

		_getch();

		menu.clear();
	}
}

void Jogo::DesenhaCarta()
{
	for (int i = 0; i < nplayer; i++) {
		if (!baralho.cartasPlayer[i].empty()) {

			carta = baralho.GetCarta(baralho.cartasPlayer[i].front());

			cout << "\n\nCarta do Player " << i + 1 << ":\n";
			cout << carta.numID << carta.letraID << "   " << carta.nome;
			cout << "\nHumor (>): " << carta.humor;
			cout << "\nEsperteza (>): " << carta.esperteza;
			cout << "\nAno de Criacao (<): " << carta.anoDeCriacao;
			cout << "\nHall da Fama (>): " << carta.hallDaFama;
			cout << "\nIdade (<): " << carta.idade << "\n";

			if (i == 0) {
				eHumano = true;
				indiceDaVez = 0;

				switch (atributo)
				{
				case 1:
					atributoGanhador = carta.humor;
					break;
				case 2:
					atributoGanhador = carta.esperteza;
					break;
				case 3:
					atributoGanhador = carta.anoDeCriacao;
					break;
				case 4:
					atributoGanhador = carta.hallDaFama;
					break;
				case 5:
					atributoGanhador = carta.idade;
					break;
				default:
					break;
				}
			}
			else {

				if (atributo == 3 || atributo == 5) {

					switch (atributo)
					{
					case 3:
						if (carta.anoDeCriacao < atributoGanhador) {
							atributoGanhador = carta.anoDeCriacao;
							indiceDaVez = i;
							eHumano = true;
						}
						break;
					case 5:
						if (carta.idade < atributoGanhador) {
							atributoGanhador = carta.idade;
							indiceDaVez = i;
							eHumano = true;
						}
						break;
					default:
						break;
					}
				}
				else {
					switch (atributo)
					{
					case 1:
						if (carta.humor > atributoGanhador) {
							atributoGanhador = carta.humor;
							eHumano = true;
							indiceDaVez = i;
						}

						break;
					case 2:
						if (carta.esperteza > atributoGanhador) {
							atributoGanhador = carta.esperteza;
							eHumano = true;
							indiceDaVez = i;
						}
						break;
					case 4:
						if (carta.hallDaFama > atributoGanhador) {
							atributoGanhador = carta.hallDaFama;
							eHumano = true;
							indiceDaVez = i;
						}
						break;
					default:
						break;
					}
				}
			}
		}
	}
	for (int i = 0; i < nbot; i++) {

		if (!baralho.cartasPC[i].empty()) {

			carta = baralho.GetCarta(baralho.cartasPC[i].front());

			cout << "\n\nCarta do Bot " << i + 1 << ":\n";
			cout << carta.numID << carta.letraID << "   " << carta.nome;
			cout << "\nHumor (>): " << carta.humor;
			cout << "\nEsperteza (>): " << carta.esperteza;
			cout << "\nAno de Criacao (<): " << carta.anoDeCriacao;
			cout << "\nHall da Fama (>): " << carta.hallDaFama;
			cout << "\nIdade (<): " << carta.idade << "\n";

			if (i == 0 && nplayer <= 0) {
				eHumano = false;

				switch (atributo)
				{
				case 1:
					atributoGanhador = carta.humor;
					break;
				case 2:
					atributoGanhador = carta.esperteza;
					break;
				case 3:
					atributoGanhador = carta.anoDeCriacao;
					break;
				case 4:
					atributoGanhador = carta.hallDaFama;
					break;
				case 5:
					atributoGanhador = carta.idade;
					break;
				default:
					break;
				}
			}
			else {

				if (atributo == 3 || atributo == 5) {

					switch (atributo)
					{
					case 3:
						if (carta.anoDeCriacao < atributoGanhador) {
							atributoGanhador = carta.anoDeCriacao;
							indiceDaVez = i;
							eHumano = false;
						}
						break;
					case 5:
						if (carta.idade < atributoGanhador) {
							atributoGanhador = carta.idade;
							indiceDaVez = i;
							eHumano = false;
						}
						break;
					default:
						break;
					}
				}
				else {
					switch (atributo)
					{
					case 1:
						if (carta.humor > atributoGanhador) {
							atributoGanhador = carta.humor;
							eHumano = false;
							indiceDaVez = i;
						}
						break;
					case 2:
						if (carta.esperteza > atributoGanhador) {
							atributoGanhador = carta.esperteza;
							eHumano = false;
							indiceDaVez = i;
						}
						break;
					case 4:
						if (carta.hallDaFama > atributoGanhador) {
							atributoGanhador = carta.hallDaFama;
							eHumano = false;
							indiceDaVez = i;
						}
						break;
					default:
						break;
					}
				}
			}
		}
	}
}

void Jogo::ContaEmpty()
{
	for (int i = 0; i < nplayer; i++) {
		if (baralho.cartasPlayer[i].empty()) {

			cout << "Player " << i + 1 << " ficou sem cartas\n";
			quantosPerderam++;
		}
	}
	for (int i = 0; i < nbot; i++) {
		if (baralho.cartasPC[i].empty()) {

			cout << "Bot " << i + 1 << " ficou sem cartas\n";
			quantosPerderam++;
		}
	}

	if (quantosPerderam == total - 1) {
		for (int i = 0; i < nplayer; i++) {
			if (!baralho.cartasPlayer[i].empty()) {
				cout << "O Player " << i + 1 << " ganhou o jogo!";
				acabou = true;
			}
		}
		for (int i = 0; i < nbot; i++) {
			if (!baralho.cartasPC[i].empty()) {
				cout << "O Bot " << i + 1 << " ganhou o jogo!";
				acabou = true;
			}
		}
	}

}
