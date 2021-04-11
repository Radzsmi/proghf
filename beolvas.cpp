
#include <iostream>
#include <fstream>
#include <string>

#include "film.h"
#include "filmtipusok.h"
#include "segedfgvek.h"

using namespace std;

void beolvas(Filmek &lista) {
	fstream f;
	string sor;
	std::string nev="";
	int hossz;
	int kiadas;
	char jeloles;
	bool sorveg = false;
	f.open("filmlista.txt", ios::in);
	if (!f) {
		cout << "Nem sikerult megnyitni a fajlt.";
	}
	else {
		std::getline(f, sor);
		std::getline(f, sor);
		while (!f.eof())
		{
				sorveg = true;
				jeloles = sor[0];
				for (int i = 2; i<int(sor.length()); i++) nev += sor[i];
				std::getline(f, sor);
				hossz = std::atoi(sor.c_str());
				std::getline(f, sor);
				kiadas = std::atoi(sor.c_str());
				sorveg = false;
				std::getline(f, sor);
				if (jeloles != 'F') {
						Film* tmp = customconst(nev,hossz,kiadas,jeloles,sor);
						lista.add(tmp);
						std::getline(f, sor);
				}
				else {
					lista.add(nev, hossz, kiadas, jeloles);
				}
				nev = "";
				std::getline(f, sor);
		}
	}
	f.close();
}