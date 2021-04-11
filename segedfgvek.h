#pragma once
#ifndef SEGEDFGVEK_H_INCLUDED
#define SEGEDFGVEK_H_INCLUDED
#include  "film.h"

void menukiir();
void clrscreen();
void kereslistaz(Filmek& lista);
void txtTorol();
void modositas(const Film* filmptr);
void hozzaadas(Filmek& lista);
Film* customconst(std::string, int, int, char, std::string);
int getszam();
char getjel();
#endif