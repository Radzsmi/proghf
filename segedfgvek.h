#pragma once
#ifndef SEGEDFGVEK_H_INCLUDED
#define SEGEDFGVEK_H_INCLUDED
#include  "film.h"
#include "filmtipusok.h"

/**@file segedfgvek.h
* This header contains the functions wich is to help the other functions.
*/

/** Function to display the menu.
*/
void menukiir();
/** Function to clear the screen.
*/
void clrscreen();
/** This function is to delete the txt file if it exsits.
*/
void txtTorol();
/** This function is to decide witch constructor to call.
*/
Film* customconst(std::string, int, int, char, std::string);
/** This is a safe input for numbers,if the input is invalid then another entering is called.
*/
int getszam();
/** This function is to read in a char,if the input is invalid then another entering is called.
*/
char getjel();
/** This function is to read all the movies and store them in the given Filmek object.
*/
void beolvas(Filmek& lista);
/** This function is to overwrite the "filmlista.txt",and write all the stored movies into it.
*/
void visszair(Filmek& lista);
#endif