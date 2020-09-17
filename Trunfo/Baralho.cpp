#include "Baralho.h"

void Baralho::MontaBaralho()
{

	txtCartas.open("CartasTdM.txt");

	for (int i = 0; i < 32; i++) {

		baralho[i] = leitor.lendo();

	}

	txtCartas.close();
	
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
	for (int j = 0; j < 32; j++) {

		cout << embaralhando[j] << endl; //bota os numeros embaralhados numa pilha
	}
}

void Baralho::DivideCartas() //divide os numeros da pilha embaralhada em duas listas
{

	for (int i = 0; i < 16; i++) {
		cartasPC.push_front(embaralhado.top());
		embaralhado.pop();
		cartasPlayer.push_front(embaralhado.top());
		embaralhado.pop();
	}
}