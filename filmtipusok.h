#pragma once
#ifndef FILMTIPUSOK_H_INCLUDED
#define FILMTIPUSOK_H_INCLUDED
#include "film.h"
#include <string>

class DokumentumFilm :public Film {
	std::string leiras;
	//jelolese D
public:
	DokumentumFilm(Film& myfilm) :Film(myfilm) { leiras = ""; this->setJel('D'); }
	DokumentumFilm(std::string nev,int hossz,int kiadas,char jeloles,std::string plusdata)
		:Film(nev, hossz, kiadas, jeloles) { leiras = plusdata; this->setJel('D'); }
	std::string getPlusData() { return leiras; }
	void setPlusData(std::string uj) { leiras = uj; }
};
class CsaladiFilm :public Film {
	int korhatar;
	//jelolese C
public:
	CsaladiFilm(Film& myfilm) :Film(myfilm) { korhatar = 0; this->setJel('C'); }
	CsaladiFilm(std::string nev, int hossz, int kiadas, char jeloles, std::string plusdata)
		:Film(nev, hossz, kiadas, jeloles) { korhatar = std::stoi(plusdata); this->setJel('C'); }
	std::string getPlusData() { return std::to_string(korhatar); }
	void setPlusData(std::string uj) { korhatar = std::stoi(uj); }
};
#endif