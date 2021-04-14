
#include "film.h"
#include "filmtipusok.h"
#include "segedfgvek.h"
#include <string>
using namespace std;

void Filmek::add(Film* addelement) {
	Film** uj = new Film*[this->meret+1];
	for (int i = 0; i < this->meret; i++) {
		uj[i] = this->filmek[i];
	}
	uj[this->meret] = addelement;
	this->meret++;
	if (filmek != NULL)delete[] filmek;
	this->filmek = uj;
}
void Film::kiir() {
		std::cout << this->getNev() << std::endl;
		std::cout << this->getKiirhossz() << std::endl;
		std::cout << this->getKiadas() << std::endl;
		if (this->getJel() != 'F')
			std::cout << this->getPlusData() << std::endl;
}
void Filmek::kilistaz() {
	for (int i = 0; i < this->meret; i++) {
		this->filmek[i]->kiir();
	}
}
void Filmek::torol(int f) {
	int count = 0;
	Film** uj = new Film*[this->meret - 1];
	for (int i = 0; i < this->meret; i++) {
		if (i + 1 != f) {
			uj[count] = this->filmek[i];
			count++;
		}
		else {
			delete this->filmek[i];
		}
	}
	if (filmek != NULL)delete[] filmek;
	this->filmek = uj;
	this->meret--;
}
void Filmek::setFilm(int i, Film& uj){
	this->torol(i);
	this->add(&uj);
}
void Filmek::add(std::string nev, int hossz, int kiadas, char jeloles) {
	Film* addelement = new Film(nev, hossz, kiadas, jeloles);
	Film** uj = new Film * [this->meret + 1];
	for (int i = 0; i < this->meret; i++) {
		uj[i] = this->filmek[i];
	}
	uj[this->meret] = addelement;
	this->meret++;
	if (filmek != NULL)delete[] filmek;
	this->filmek = uj;
}
std::string Film::getKiirhossz(){
	int seconds=this->getHossz(), hours, minutes;
	minutes = seconds / 60;
	hours = minutes / 60;
	std::string strtime = "";
	strtime += std::to_string(hours);
	strtime += ':';
	strtime += std::to_string(minutes%60);
	strtime += ':';
	strtime += std::to_string(seconds%60);
	return strtime;
}
void Filmek::keres(Filmek& talalatok,std::string mit) {
	int ctr = 0;
	if (mit == "") {
		std::cout << "Udv a kereses menuben." << std::endl;
		std::cout << "Keress valamire: " << std::flush;
		std::getline(std::cin, mit);
	}
	for (int i = 0; i < meret; i++) {
		std::string kisbetusnev="";
		for (int f = 0; f <int( this->filmek[i]->getNev().length()); f++) kisbetusnev += tolower(this->filmek[i]->getNev()[f]);
		if (kisbetusnev.find(mit) != std::string::npos) {
			talalatok.add(this->filmek[i]);
			ctr++;
		}
	}
	talalatok.meret = ctr;
}
void Filmek::torol(Film& torlendo) {
	for (int i = 0; i < meret; i++) {
		if (&torlendo == filmek[i]) {
			this->torol(i+1);
		}
	}
}
void Filmek::keresveTorol() {
	Filmek tmp;
	this->keres(tmp);
	int answer;
	for (int i = 0; i < tmp.getMeret(); i++) {
		std::cout << "(" << i + 1 << ") ";
		tmp.getFilm(i).kiir();
	}
	std::cout << "Hanyadik elemet toroljem?" << std::endl;
	std::cin >> answer;
	std::cin.ignore();
	if (answer <= tmp.getMeret() && answer>0) {
		this->torol(tmp.getFilm(answer-1));
		std::cout << "Sikeres torles" << std::endl;
	}
	else {
		std::cout << "Rossz adat" << std::endl;
	}
	for (int i = 0; i < tmp.getMeret(); i++) tmp.setFilmPointer(i, NULL);
	
}
void Filmek::keresveModosit() {
	Filmek tmp;
	this->keres(tmp);
	int answer;
	for (int i = 0; i < tmp.getMeret(); i++) {
		std::cout << "(" << i + 1 << ") ";
		tmp.getFilm(i).kiir();
	}
	std::cout << "Hanyadik elemet szeretned modositani? " << std::endl;
	std::cin >> answer;
	std::cin.ignore();
	if (answer <= tmp.getMeret() && answer > 0) {
		Film* filmptr = tmp.getFilmPointer(answer - 1);
		filmptr->filmModosit();
	}
	else {
		std::cout << "Rossz adat" << std::endl;
	}
	for (int i = 0; i < tmp.getMeret(); i++) tmp.setFilmPointer(i, NULL);
}
void Film::filmModosit(int answer,string megadott) {
	int ujdata;
	std::string plusdata;
	if (answer == -1) {
		std::cout << "Mit szeretnel modositani?" << std::endl;
		std::cout << "(1) Nev" << std::endl;
		std::cout << "(2) Hossz" << std::endl;
		std::cout << "(3) Kiadas" << std::endl;
		if (this->getJel() != 'F')
			std::cout << "(4) Plusz adat" << std::endl;
		std::cin >> answer;
		std::cin.ignore();
	}
	else {
		if (answer == 1) this->setNev(megadott);
		if (answer == 2) this->setHossz(std::stoi(megadott));
		if (answer == 3) this->setKiadas(std::stoi(megadott));
		if (answer == 4) this->setPlusData(megadott);
		return;
	}
	if ((answer < 4 && answer>0) || (answer < 5 && answer >0 && this->getJel() != 'F')) {
		std::cout << "Add meg az uj adatot!" << std::endl;
		if (answer == 2 || answer == 3) {
			ujdata=getszam();
			if (answer == 2) this->setHossz(ujdata);
			else this->setKiadas(ujdata);
		}
		else {
			if (this->getJel() == 'C') plusdata = std::to_string(getszam());
			else getline(std::cin, plusdata);
			if (answer == 1) this->setNev(plusdata);
			else this->setPlusData(plusdata);
		}
	}
	else
		std::cout << "Rossz valasztas!" << std::endl;
	std::cout << "Sikeres modositas!" << std::endl;
}
void Filmek::clear() {
	for (int i = 0; i < meret; i++) {
		delete filmek[i];
	}
	meret = 0;
}
void Filmek::hozzaadas() {
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
	cin >> hour >> c >> min >> f >> sec;
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
		if (tmp != NULL) this->add(tmp);
		else {
			cout << "Ismeretlen adattipus,sima filmkent adatam hozza." << endl;
			this->add(cim, hossz, megjeleve, 'F');
		}
	}
	else {
		this->add(cim, hossz, megjeleve, tipus);
	}
	cout << "Sikeres hozzaadas!" << endl;
}
void Filmek::kereslistaz() {
	Filmek tmp;
	this->keres(tmp);
	for (int i = 0; i < tmp.getMeret(); i++) {
		tmp.getFilm(i).kiir();
		tmp.setFilmPointer(i, NULL);
	}
}