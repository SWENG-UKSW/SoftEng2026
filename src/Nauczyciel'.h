#ifndef _NAUCZYCIEL'_H
#define _NAUCZYCIEL'_H


#include <string>
using namespace std;

class Harmonogram;
class Nieobecnosc;
class Zastepstwo;

class Nauczyciel' {
  private:
    int id;

    string imie;

    string nazwisko;


  public:
    bool sprawdzDostepnosc();


  private:
    Harmonogram * ;

    Nieobecnosc * ;

    Zastepstwo * ;

};
#endif
