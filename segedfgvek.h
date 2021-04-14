#pragma once
#ifndef SEGEDFGVEK_H_INCLUDED
#define SEGEDFGVEK_H_INCLUDED
#include  "film.h"

/** @brief Ez a .h file a segedfuggvenyeket tarolja az elegansabb kod erdekeben.
*/

/** Ez a fuggveny a menu kiiratasat vegzi el.
*/
void menukiir();
/** Ez a fuggveny enter hatasara torli a kepernyot.
*/
void clrscreen();
/** Ez a fuggveny torli a txt-t amennyiben letezik.
*/
void txtTorol();
/** Ez a fuggveny meghivja a megfelelo konstruktort a megfelelo film tipushoz.
*/
Film* customconst(std::string, int, int, char, std::string);
/** Ez a fuggveny egy szamot olvas be,hibas adat megadasakor ujboli bekerest kezdemenyez.
*/
int getszam();
/** Ez a fuggveny egy chart olvas be,ha hibas ujboli bekerest kezdemenyez.
*/
char getjel();
/** Ez a fuggveny beolvassa a filmeket egy Filmek objektumba.
*/
void beolvas(Filmek& lista);
/** Ez a fuggveny felulirja az eddigi "filmlista.txt"-t es belehelyezi a jelenlegi lista tartalmat.
*/
void visszair(Filmek& lista);
#endif