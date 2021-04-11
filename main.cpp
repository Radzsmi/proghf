
#define _CRTDBG_MAP_ALLOC


#include "film.h"
#include "beolvas.h"
#include "segedfgvek.h"
#include "fajlkezeles.h"
#include "memtrace.h"
#include <crtdbg.h>
using namespace std;

int main() {
	Filmek lista;
	int  answer;
	beolvas(lista);
    do
    {
        menukiir();
        cin >> answer;
        cin.ignore();
        if (answer>=0 && answer<6) {
            switch (answer)
            {
            case 1:
                lista.kilistaz();
                clrscreen();
                break;

            case 2:
                kereslistaz(lista);
                clrscreen();
                break;

            case 3:
                lista.keresveTorol();
                clrscreen();
                break;

            case 4:
                lista.keresveModosit();
                clrscreen();
                break;
            case 5:
                hozzaadas(lista);
                clrscreen();
                break;

            default:
                cout << "Kilepes sikeres.";
            }
        }
        else
        {
            cout << "Bad choice! Please try again later.\n";
            clrscreen();
        }
    } while (answer!=0);
   visszair(lista);
	return 0;
}