
#include "fajlkezeles.h"
#include "segedfgvek.h"
#include <iostream>
#include <fstream>
using namespace std;

void visszair(Filmek& lista) {
	txtTorol();
	ofstream myfile;
	myfile.open("filmlista.txt");
	myfile << "-\n";
	for (int i = 0; i < lista.getMeret(); i++) {
		Film *tmp = lista.getFilmPointer(i);
		myfile  << tmp->getJel() << ':' << tmp->getNev() << '\n';
		myfile << tmp->getHossz() << '\n' << tmp->getKiadas() << '\n';
		if (tmp->getJel() != 'F') {
			myfile << tmp->getPlusData()<< '\n';
		}
		myfile <<"-\n";
	}
	myfile.close();
}