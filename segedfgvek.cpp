
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
void kereslistaz(Filmek& lista) {
	Filmek tmp;
	lista.keres(tmp);
	for (int i = 0; i < tmp.getMeret(); i++) {
		tmp.getFilm(i).kiir();
		tmp.setFilmPointer(i, NULL);
	}
}
void txtTorol() {
	std::ofstream ofs;
	ofs.open("filmlista.txt", ofstream::out | ofstream::trunc);
	ofs.close();
}
void hozzaadas(Filmek& lista) {
	std::string cim;
	int hossz = 0, hour, sec, min;
	char c, f;
	int megjeleve;
	char tipus;
	std::string plusdata;
	cout << "Udv a hozzaadas menuben" << endl;
	cout << "Add meg a film cimet!" << endl;
	getline(cin, cim);
	cout << "Add meg a hosszat (Hour:Min:Sec)" << endl;
	cin >> hour>>c>>min>>f>>sec;
	hossz = hour * 3600 + min * 60 + sec;
	cin.ignore();
	cout << "Add meg a megjelenes evet" << endl;
	megjeleve = getszam();
	cout << "Add meg a Tipusanak jelet(pl. D dokumentumfilm,F sima film)" << endl;
	tipus = getjel();
	if (tipus != 'F') {
		cout << "Add meg a plusz adatot!" << endl;
		if (tipus == 'C') plusdata = std::to_string(getszam());
		else getline(cin, plusdata);
		Film* tmp = customconst(cim, hossz, megjeleve, tipus, plusdata);
		if (tmp != NULL) lista.add(tmp);
		else {
			cout << "Ismeretlen adattipus,sima filmkent adatam hozza." << endl;
			lista.add(cim, hossz, megjeleve, 'F');
		}
	}
	else {
		lista.add(cim, hossz, megjeleve, tipus);
	}
	cout << "Sikeres hozzaadas!" << endl;
}