#pragma once
#ifndef FILM_H_INCLUDED
#define FILM_H_INCLUDED

#include <iostream>
class Film
{
	std::string nev;
	int hossz;
	int kiadas;
	char jeloles = 'F';
public:
	Film() :nev(""),hossz(0),kiadas(0) {};
	Film(std::string nev,int hossz,int kiadas,char jeloles) :nev(nev),hossz(hossz),kiadas(kiadas),jeloles(jeloles) {}
	std::string getNev() { return nev; }
	void setNev(std::string& ujnev) { nev = ujnev; }
	int getHossz() { return hossz; }
	void setHossz(int ujhossz) { hossz = ujhossz; }
	std::string getKiirhossz();
	int getKiadas() { return kiadas; }
	void setKiadas(int ujkiadas) { kiadas = ujkiadas; }
	char getJel() { return jeloles; }
	void setJel(char ujjel) { jeloles = ujjel; }
	void kiir();
	virtual std::string getPlusData() { return "Nincsen plusz adatom"; }
	virtual void setPlusData(std::string uj) {};
	void filmModosit(int answer=-1, std::string megadott="");
	virtual ~Film() {};
};
class Filmek {
	Film ** filmek;
	int meret = 0;
	Filmek(const Filmek&);
	Filmek& operator=(const Filmek& rhs);
public:
	Filmek() :filmek(NULL),meret(0){}
	int getMeret() { return meret; }
	Film& getFilm(int i) { return *filmek[i]; }
	Film* getFilmPointer(int i) { return filmek[i]; }
	void setFilmPointer(int i, Film* mivel) { filmek[i] = mivel; }
	Film* getFilmekPointer(){return *filmek;}
	void setFilm(int i, Film& uj);
	void torol(int i);
	void torol(Film& torlendo);
	void add(Film* addelement);
	void add(std::string nev, int hossz, int kiadas, char jeloles);
	void kilistaz();
	void keres(Filmek& talalatok,std::string mit="");
	void keresveTorol();
	void keresveModosit();
	void clear();
	void hozzaadas();
	void kereslistaz();
	~Filmek() { 
		clear();
		delete[] filmek;
	}
};
#endif