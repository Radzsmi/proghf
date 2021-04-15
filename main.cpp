
#include "film.h"
#include "segedfgvek.h"
#include "memtrace.h"
#include "gtest_lite.h"
#include <iostream>
#include <fstream>
/**
* @file main.cpp
* A program futasta vezenylo cpp file.
* Az ellenorzesek es a funkciok meghivasat kezeli.
*/

#define JPORTA_INPUT_SIM
using namespace std;
/**
* Ellenorzes a beolvasara.
*/
void test_0(Filmek& lista) {
    TEST(Beolvasas, Beolvasas) {
        if (lista.getMeret() != 0) {
            EXPECT_STRNE("", lista.getFilm(0).getNev().c_str()) << "HIBAS BEOLVASAS";
        }
    }END;
}
/**Ellenorzes a filmek hozzaadasara.
*/
void test_1(Filmek& lista) {
    TEST(Addolas, addolas) {
        lista.add("uj film", 1234, 1975, 'F');   //add default film
        EXPECT_EQ(lista.getFilm(lista.getMeret()-1).getNev(), "uj film") << "Nem sikerult hozzaadni";
        Film* tmp = customconst("egy uj csaladi film", 3464, 2001, 'C', "18");
        lista.add(tmp);                         //add csaladi film
        EXPECT_EQ(lista.getFilm(lista.getMeret() - 1).getPlusData(), "18") << "Nem jol adott hozza plusz adatot/filmet.";
    }END;
}
/**Ellenorzes a keresesre.
*/
void test_2(Filmek& lista) {
    TEST(Kereses, kereses) {
        Filmek tmp;
        lista.keres(tmp, "egy uj csaladi film");
        EXPECT_EQ("egy uj csaladi film", tmp.getFilm(0).getNev()) << "Hibas kereses!";
        for (int i = 0; i < tmp.getMeret(); i++) {
            tmp.setFilmPointer(i, NULL);
        }
    }END;
}
/**Ellenorzes a  torlesre.
*/
void test_3(Filmek& lista) {
    TEST(Torles, Torles) {
        Filmek tmp;
        lista.keres(tmp, "uj film");
        lista.torol(tmp.getFilm(0));
        EXPECT_EQ(lista.getFilm(lista.getMeret() - 1).getNev(), "egy uj csaladi film") << "Hibas torles";
        for (int i = 0; i < tmp.getMeret(); i++) {
            tmp.setFilmPointer(i, NULL);
        }
    }END;
}
/**Ellenorzes a modositasra.
*/
void test_4(Filmek& lista) {
    TEST(Modositas, Modositas) {
        Filmek tmp;
        lista.keres(tmp, "egy uj csaladi film");
        tmp.getFilmPointer(0)->filmModosit(1,"egy uj csaladi film 2");
        EXPECT_EQ(lista.getFilm(lista.getMeret() - 1).getNev(), "egy uj csaladi film 2") << "Hibas modositas";
        for (int i = 0; i < tmp.getMeret(); i++) {
            tmp.setFilmPointer(i, NULL);
        }
    }END;
}
/**Ellenorzes a visszairasra.
*/
void test_5(Filmek& lista) {
    TEST(Visszairas, Visszairas) {
        visszair(lista);
        EXPECT_EQ(0, lista.getMeret()) << "hibas visszairas";
        beolvas(lista);
        lista.torol(lista.getFilm(lista.getMeret() - 1));
        visszair(lista);
    }END;
}

int main() {
    Filmek lista;
    int  answer;
    cout << "1-Test,2-Hasznalat" << endl;
    beolvas(lista);
    int fut = 0;
#ifdef JPORTA_INPUT_SIM //jporta ellenorzest iranyitja.
    std::ifstream in("standard_input.txt");
    std::cin.rdbuf(in.rdbuf());
    fut = 1;
#endif // JPORTASIM
    cin >> answer;
    cout << answer;
    if (answer == 2 ) {
        do
        {
            menukiir();
            cin >> answer;
            cin.ignore();
            if (answer >= 0 && answer < 6) {
                switch (answer)
                {
                case 1:
                    lista.kilistaz();
                    clrscreen();
                    break;

                case 2:
                    lista.kereslistaz();
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
                    lista.hozzaadas();
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
        } while (answer != 0);
        visszair(lista);
    }
    if (fut == 1) {
        beolvas(lista);
        test_0(lista);
        test_1(lista);
        test_2(lista);
        test_3(lista);
        test_4(lista);
        test_5(lista);
    }
	return 0;
}