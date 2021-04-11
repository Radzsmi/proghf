#pragma once
#ifndef SEGEDFGVEK_H_INCLUDED
#define SEGEDFGVEK_H_INCLUDED
#include  "film.h"


void menukiir();
void clrscreen();
void txtTorol();
Film* customconst(std::string, int, int, char, std::string);
int getszam();
char getjel();
void beolvas(Filmek& lista);
void visszair(Filmek& lista);
#endif