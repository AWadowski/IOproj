#include "Kurs.h"
#include <iostream>

void Kurs::Wyswietl() {
    std::cout << "Nazwa kursu: " << Nazwa << std::endl;
    for(int i=0;i<Tematy.size();i++){
        std::cout <<i + ". "  + Tematy[i] << std::endl;
    }
}

