#if !defined(_WYKLADOWCA_H)
#define _WYKLADOWCA_H
#include <string>
#include <iostream>
#include <vector>
#include "Kurs.h"
#include "Ocena.h"

class Wykladowca {
public:
    std::string name;
    std::string login;
    std::string haslo;
    std::vector <std::string> nazwyKursow;
    int liczbaKursow;
    Wykladowca();
    ~Wykladowca();

    Kurs UtworzKurs(std::string name);
    void ModyfikujKurs(Kurs& kurs);
    void WystawOcene(Kurs& kurs, int studentId, int ocena);
};

#endif  //_WYKLADOWCA_H
