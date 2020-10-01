#include "Baralho.h"

void Baralho::MontaBaralho()
{

	leitor.AbreTxt();

	for (int i = 0; i < 32; i++) {

		baralhoCartas[i] = leitor.lendo();
	}

	

	leitor.AbreTxt();

}

Cartas Baralho::GetCarta(int numeroCarta)
{
	return baralhoCartas[numeroCarta];
}

void Baralho::Embaralha()
{
	for (int i = 0; i < 32; i++) {
		embaralhando[i] = i; //numera um vetor de 0 a 31 (para corresponder ao baralho
	}

	srand(time(0));

	random_shuffle(begin(embaralhando), end(embaralhando)); //embaralha os numeros

	for (int j = 0; j < 32; j++) {

		embaralhado.push(embaralhando[j]); //bota os numeros embaralhados numa pilha
	}
}

void Baralho::DivideCartas(int nbot, int nplayer) //divide os numeros da pilha embaralhada em duas listas
{

	cartasPlayer = new list<int>[nplayer];
	cartasPC = new list<int>[nbot];

	while (!embaralhado.empty())
	{
		for (int i = 0; i < nplayer; i++) {
			if (embaralhado.empty()) {
				i = nplayer;
			}
			else {
				cartasPlayer[i].push_front(embaralhado.top());
				embaralhado.pop();
			}
		}
		for (int i = 0; i < nbot; i++) {
			if (embaralhado.empty()) {
				i = nbot;
			}
			else {
				cartasPC[i].push_front(embaralhado.top());
				embaralhado.pop();
			}
		}
	}
}

void Baralho::PassaAsCartas(int indiceGanhador, bool humano, int nbot, int nplayer)
{

	if (humano) {
		for (int i = 0; i < nplayer; i++) {
			if (cartasPlayer[i].front() < 33) {
				cartasPlayer[indiceGanhador].push_back(cartasPlayer[i].front());
				cartasPlayer[i].pop_front();
			}
		}
		for (int i = 0; i < nbot; i++) {
			if (cartasPC[i].front() < 33) {
				cartasPlayer[indiceGanhador].push_back(cartasPC[i].front());
				cartasPC[i].pop_front();
			}
		}
	}
	else {
		for (int i = 0; i < nplayer; i++) {
			if (cartasPlayer[i].front() < 33) {
				cartasPC[indiceGanhador].push_back(cartasPlayer[i].front());
				cartasPlayer[i].pop_front();
			}
		}
		for (int i = 0; i < nbot; i++) {
			if (cartasPC[i].front() < 33) {
				cartasPC[indiceGanhador].push_back(cartasPC[i].front());
				cartasPC[i].pop_front();
			}
		}
	}


}


