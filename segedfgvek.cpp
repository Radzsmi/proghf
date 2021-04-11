
#include <iostream>
#include <fstream>
#include<string>
#include "segedfgvek.h"
#include  "film.h"
#include "filmtipusok.h"
using namespace std;

Film* customconst(std::string nev, int hossz, int kiadas, char jel, std::string sor) {
	if (jel == 'D') {
		return new DokumentumFilm(nev, hossz, kiadas, jel, sor);
	}
	if (jel == 'C') {
		return new CsaladiFilm(nev, hossz, kiadas, jel, sor);
	}
	return NULL;
}
char getjel() {
	string mystr;
	getline(cin, mystr);
	while (mystr.c_str()[1] != '\0') {
		cout << "Nem jo adat!\nAddj meg egy ujat:" << endl;
		getline(cin, mystr);
	}
	return mystr[0];
}
int getszam() {
	string mystr;
	getline(cin, mystr);
	bool onlydigit = (mystr.find_first_not_of("0123456789") == std::string::npos);
	while (!onlydigit) {
		cout << "Nem jo adat!\nAddj meg egy ujat:" << endl;
		getline(cin, mystr);
		onlydigit = (mystr.find_first_not_of("0123456789") == std::string::npos);
	}
	return stoi(mystr);
}

void menukiir() {
	cout << "Udvozollek a menuben" << endl;
	cout << "Valassz az alabbiak kozul:" << endl;
	cout << "(1) Filmek listazasa" << endl;
	cout << "(2) Filmek keresese" << endl;
	cout << "(3) Filmek torlese" << endl;
	cout << "(4) Film adatainak modositasa" << endl;
	cout << "(5) Uj film hozzaadasa" << endl;
	cout << "A valasztasod: "<< flush;
}
void clrscreen() {
	cout << "Press Enter to Continue";
	cin.ignore();
	cout << "\033[2J\033[1;1H";
}
void txtTorol() {
	std::ofstream ofs;
	ofs.open("filmlista.txt", ofstream::out | ofstream::trunc);
	ofs.close();
}
void beolvas(Filmek& lista) {
	fstream f;
	string sor;
	std::string nev = "";
	int hossz;
	int kiadas;
	char jeloles;
	bool sorveg = false;
	f.open("filmlista.txt", ios::in);
	if (!f) {
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
				Film* tmp = customconst(nev, hossz, kiadas, jeloles, sor);
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
void visszair(Filmek& lista) {
	txtTorol();
	ofstream myfile;
	myfile.open("filmlista.txt");
	myfile << "-\n";
	for (int i = 0; i < lista.getMeret(); i++) {
		Film* tmp = lista.getFilmPointer(i);
		myfile << tmp->getJel() << ':' << tmp->getNev() << '\n';
		myfile << tmp->getHossz() << '\n' << tmp->getKiadas() << '\n';
		if (tmp->getJel() != 'F') {
			myfile << tmp->getPlusData() << '\n';
		}
		myfile << "-\n";
	}
	myfile.close();
	lista.clear();
}