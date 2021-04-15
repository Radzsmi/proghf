# proghf



Fimtár

A feladatom:

A feladatomnak a "Filmtár" nevű programot válaszotta a feladatötleketből,egy nyivántartó renszert fogok létrehozni amiben filmeket tárolok.Minden film rendelkezik majd címmel,lejátszási idővel és kiadási évvel.Továbbá filmeket meg lehet majd különböztetni kategória alapján.(pl.családi,dokumentum)Ezek bónusz adatokkal is rendelkeznek.

Funkciók:
  -Listázás
  -Hozzáadás
  -Keresés
  -Törlés
 
 A nyilvántartásra használt program működését egy konzolos feöleten lehet majd irányítani,számokat megadva az egyes funkciók eléréséhez,más adatot nem fogad el a program.
 
 A programot egy menüben lehet majd irányítani ahova minden művelet után visszadob a rendszer,onnan lehet majd kiválasztani a következő lépést.
 
 A tesztelést listázásra,keresésre,törlésre fogom kipróbálni.


Pontosított feladatspecifikáció

A feladat egy nyilvántartó program megírása amely megnyitáskor a forrás szöveges fájlból olvassa ki az adatokat,és dinamikusan tárolja őket objektumokba rendezve a program futásának végéig amikor visszaírja őket a szöveges fájlba.
Minden műveletet (módosítás,törlés,hozzáadás) ezen a dinamikusan foglalt objektumon hajt végre a program.
Az adatok megadásánál a megfelelő adattípúsoknak megfelelően kell adatokat megadni,vagyis például a megjelenés évének csak számokat fogad el a program.
Amennyiben nem létezik/üres a txt file,abban az esetben a program létrehozza a futásának végén.

Objektum terv

Az adatok tárolását a Filmek osztály egyik objektumában fogom megvalósítani.Minden filmet vagy sima,családi vagy dokumentumfilmként fog tárolni a program.A Filmek osztály tároljak az elemek számát így könnyebb kezelni a dinamikus foglalásokat és az adatok hozzáadását.
A program elkészítése során igyekszem minnél könnyebben bővíthető objektumszerkezetet létrehozni,ennek érdekében egy új objektum megírásához mindössze konstruktor és getter,setter lesz szükséges,és 1 sor változtatás a kódban. 

Algoritmusok

A feladatom egyik legösszetettebb algoritmusa az adatok beolvasása amit egy külön föggvény fog megvalósítani.A függvény argumentuma egy filmek objektum amit a mainben hoz létre a program.
A beolvasás a txtfájl mintája szerint fog történni és annak egyedi mintája szerint minden sorból kiolvassa az odaillő elemeket.Minden beolvasás elején a txtfájlban van egy betű ami a film típúsára utal,ennek megfelelően megtudja a program határozni az egyes filmekhez tartozó adatok számát.
A filmek bekérése az  eof-ig történik.Addig minden filmből objektumot hoz létre a program amit behelyez a mainből kapott filmek típusú objektumba.
A keresés filmek címei között zajlik,amelyekből azokat tekinti találatnak melyekben szerepel ugyanaz a részlet,kis és nagybetűket egyként kezeli.


A tesztprogram működése

A tesztprogram egy előre elkészített eseménysorozatot fog lejátszani és ezek helyességét fogja kiértékelni.A tesztesetek a program működését fogják szimulálni,mivel az adatok beolvasása nem kivételt hanem újbóli bekérést eredményez ezért azokra nem terjed ki.(viszont ezeket is megvalósítja a program)
A tesztet a jporta definiálásával lehet elindítani de lehetőség lesz a program kipróbálásra is.

A tesztprogram lefuttat a lehető legtöbb esetet,de g_test segítségével csak az előre megírt tesztesetek futnak.Viszont a nem ellenőrzött tesztesetek eredménye az hogy a program majdnem minden függvénye meghívódik és a filmlista.txt változatlan marad hiszen a teszt a törlést is meghívja.(Erre a hibás bekérések miatti ellenőrzésre van szükség.)

A dokumentáció

A doxygen program segítségével.Ékezetek nélkül,mivel különböző karaktereket nem jelenít meg a program.

Bővíthetőség

A program bővítéséhez a filmtipusok.h-ban kell egy új classt definiálni getter,setter,konstruktorral és a segedfgvek.cpp-ben a custromconst fgvben beleírni hogy a megfelelő jelnél a jó konstruktor hívódjon meg.
