#if !defined(_KURS_H)
#define _KURS_H


#include <string>
#include <vector>
#include "Ocena.h"
class Kurs {
public:
    int id;
    std::string Nazwa;
    std::vector<std::string> Tematy;
    std::vector<Ocena> oceny;
    std::vector<int> studentId;

    void Wyswietl();
};

#endif  //_KURS_H
