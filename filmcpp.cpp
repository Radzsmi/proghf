
#include "film.h"
#include "filmtipusok.h"
#include "segedfgvek.h"
#include <string>

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
void Filmek::keres(Filmek& talalatok) {
	std::string keresendo;
	int ctr = 0;
	std::cout << "Udv a kereses menuben." << std::endl;
	std::cout << "Keress valamire: "<<std::flush;
	std::getline(std::cin, keresendo);
	for (int i = 0; i < meret; i++) {
		std::string kisbetusnev="";
		for (int f = 0; f <int( this->filmek[i]->getNev().length()); f++) kisbetusnev += tolower(this->filmek[i]->getNev()[f]);
		if (kisbetusnev.find(keresendo) != std::string::npos) {
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
	Film* filmptr = tmp.getFilmPointer(answer-1);
	filmptr->filmModosit();
	for (int i = 0; i < tmp.getMeret(); i++) tmp.setFilmPointer(i, NULL);
}
void Film::filmModosit() {
	int answer = -1;
	int ujdata;
	std::string plusdata;
	std::cout << "Mit szeretnel modositani?" << std::endl;
	std::cout << "(1) Nev" << std::endl;
	std::cout << "(2) Hossz" << std::endl;
	std::cout << "(3) Kiadas" << std::endl;
	if (this->getJel() != 'F')
		std::cout << "(4) Plusz adat" << std::endl;
	std::cin >> answer;
	std::cin.ignore();
	if ((answer < 4 && answer>0) || (answer < 5 && answer >0 && this->getJel() != 'F')) {
		std::cout << "Add meg az uj adatot!" << std::endl;
		if (answer == 2 || answer == 3) {
			std::cin >> ujdata;
			std::cin.ignore();
			if (answer == 2) this->setHossz(ujdata);
			else this->setKiadas(ujdata);
		}
		else {
			getline(std::cin, plusdata);
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