#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Cartas.h"

using namespace std;

class LerTxt
{
public:

	Cartas lendo();

	bool abriu = false;
	

private:

	Cartas temp;

	ifstream txtCartas;
};

