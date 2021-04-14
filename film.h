#pragma once
#ifndef FILM_H_INCLUDED
#define FILM_H_INCLUDED

#include <iostream>

/** @brief Ez a film osztaly.Innen szarmaznak le a kulonbozo filmtipusok,filmek adatait tarolja.
*/
class Film
{
	std::string nev;
	int hossz;
	int kiadas;
	char jeloles = 'F';
public:
	/** Default konstruktor.
*/
	Film() :nev(""),hossz(0),kiadas(0) {};
	/** Konstruktor amely a bekert adatokbol hoz letre egy uj filmet.
*/
	Film(std::string nev,int hossz,int kiadas,char jeloles) :nev(nev),hossz(hossz),kiadas(kiadas),jeloles(jeloles) {}
	/** Getter a nev lekerdezesere.
*/
	std::string getNev() { return nev; }
	/** Setter a nev valtoztatasara.
*/
	void setNev(std::string& ujnev) { nev = ujnev; }
	/** Getter a hossz lekerdezesere.
*/
	int getHossz() { return hossz; }
	/** Setter a hossz valtozatasara.
*/
	void setHossz(int ujhossz) { hossz = ujhossz; }
	/** A hosszt stringkent adja vissza a megfelelo HH:MM:SS formatumban.
*/
	std::string getKiirhossz();
	/** Getter a kiadas evere.
*/
	int getKiadas() { return kiadas; }
	/** Setter a kiadas evenek valtoztatasara.
*/
	void setKiadas(int ujkiadas) { kiadas = ujkiadas; }
	/** Getter a filmhez tartozo jelolesre.
*/
	char getJel() { return jeloles; }
	/** Setter a filmhez tartozo jeloles valtoztatasra.
*/
	void setJel(char ujjel) { jeloles = ujjel; }
	/** Kiirja a film adatait.
*/
	void kiir();
	/** Virtualis fuggveny amely a film plusz adatat adja vissza.
*/
	virtual std::string getPlusData() { return "Nincsen plusz adatom"; }
	/**  Virtualis fuggveny amely a film plusz adatat valtoztatja(mivel a filmnek nincsen ezert itt ures).
*/
	virtual void setPlusData(std::string uj) {};
	/** Fuggveny amely a modosito menut hozza elo,melynek segitsegevel lehet modositani a filmek adatait.
*/
	void filmModosit(int answer=-1, std::string megadott="");
	/** Virtualis destruktor a film szamara.
*/
	virtual ~Film() {};
};
/** @brief Filmek osztaly a filmek tarolasara.Film pointereket tarol dinamikusan. 
*/
class Filmek {
	Film ** filmek;
	int meret = 0;
	Filmek(const Filmek&);
	Filmek& operator=(const Filmek& rhs);
public:
	/** Default konstruktor.
*/
	Filmek() :filmek(NULL),meret(0){}
	/** Getter a filmek szamara.
*/
	int getMeret() { return meret; }
	/** Getter amely az i. filmet adja vissza.
*/
	Film& getFilm(int i) { return *filmek[i]; }
	/** Getter amely az i. film pointerevel ter vissza.
*/
	Film* getFilmPointer(int i) { return filmek[i]; }
	/** Setter amely az i. film pointeret beallitja a megadott film pointerre.
*/
	void setFilmPointer(int i, Film* mivel) { filmek[i] = mivel; }
	/** Getter amely visszater a filmek pointerevel.
*/
	Film* getFilmekPointer(){return *filmek;}
	/** Setter amely az i. filmet toroli es hozzaadja helyette az uj megadott filmet.
*/
	void setFilm(int i, Film& uj);
	/** Torli az i. filmet a listabol.
*/
	void torol(int i);
	/** Torli a megadott filmet a listabol.
*/
	void torol(Film& torlendo);
	/** Hozzaadja a listahoz egy filmet amelyre a megadott pointer mutat.
*/
	void add(Film* addelement);
	/** A megadott adatok alapjan letrehoz egy filmet amit hozzaad a filmek listajahoz.
*/
	void add(std::string nev, int hossz, int kiadas, char jeloles);
	/** Kiirja a tarolt filmeket.
*/
	void kilistaz();
	/** Kereses funkciot valositja meg,a talalatokat a megadott Filmek objektumba helyezi el.Lehetoseg van a keresett szot is megadni.
*/
	void keres(Filmek& talalatok,std::string mit="");
	/** Kereses funkciot valostija meg,a vegen a talalatok kozuli torlessel.
*/
	void keresveTorol();
	/** Kereses utan a talalatok kozul lehetoseg ad a fuggveny a film adatainak modositasara.
*/
	void keresveModosit();
	/** Torli a tarolt filmeket,a meretet nullazza.
*/
	void clear();
	/** Uj film adatainak bekerese utan uj filmet hoz letre amit a tarolt filmek koze helyez.
*/
	void hozzaadas();
	/** Keresest valosit meg a tarolt filmek kozott es kiirja az eredmenyeket.
*/
	void kereslistaz();
	/** Destruktor a filmekhez.
*/
	~Filmek() { 
		clear();
		delete[] filmek;
	}
};
#endif