#pragma once
#ifndef FILMTIPUSOK_H_INCLUDED
#define FILMTIPUSOK_H_INCLUDED
#include "film.h"
#include <string>
/** @brief DokumentumFilm osztaly,film leszarmazottja egy plusz adatot tarol.Jelolese:D
*/
class DokumentumFilm :public Film {
	std::string leiras;
public:
	/** Konstruktor a DokumentumFilmhez.Egy filmbol hoz letre dokumentumfilmet.
	*/
	DokumentumFilm(Film& myfilm) :Film(myfilm) { leiras = ""; this->setJel('D'); }
	/** Konstruktor a DokmumentumFilmhez.A megadott adatok alapjan hoz letre egy dokumentumfilmet.
	*/
	DokumentumFilm(std::string nev,int hossz,int kiadas,char jeloles,std::string plusdata)
		:Film(nev, hossz, kiadas, jeloles) { leiras = plusdata; this->setJel('D'); }
	/** Getter a dokumentumfilmek plusz adatahoz.
*/
	std::string getPlusData() { return leiras; }
	/** Setter a dokumentumfilmek plusz adatahoz.
*/
	void setPlusData(std::string uj) { leiras = uj; }
};
/** @ brief CsaladiFilm osztaly,film leszarmazottja tarolja a korhatart is.Jelolese:C
*/
class CsaladiFilm :public Film {
	int korhatar;
public:
	/** Konstruktor a CsaladiFilmhez.Egy filmbol hoz letre dokumentumfilmet.
	*/
	CsaladiFilm(Film& myfilm) :Film(myfilm) { korhatar = 0; this->setJel('C'); }
	/** Konstruktor a CsaladiFilmhez.A megadott adatok alapjan hoz letre egy dokumentumfilmet.
*/
	CsaladiFilm(std::string nev, int hossz, int kiadas, char jeloles, std::string plusdata)
		:Film(nev, hossz, kiadas, jeloles) { korhatar = std::stoi(plusdata); this->setJel('C'); }
	/** Getter a csaladifilmek plusz adatahoz,stringgel ter vissza.
*/
	std::string getPlusData() { return std::to_string(korhatar); }
	/** Setter a csaladifilmek plusz adatahoz,string bemenetet allit be korhatarnak.
*/
	void setPlusData(std::string uj) { korhatar = std::stoi(uj); }
};
#endif