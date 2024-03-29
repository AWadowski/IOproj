#include "Wykladowca.h"

Wykladowca::Wykladowca() {
    name = "null";
    login = "null";
    haslo = "null";
}

Wykladowca::~Wykladowca() {

}

Kurs Wykladowca::UtworzKurs(std::string name) {
    Kurs nowyKurs;
    nowyKurs.Nazwa = name;
    liczbaKursow++;
    nowyKurs.id = liczbaKursow;
    std::cout << "Utworzono nowy kurs: " << name << std::endl;
    nazwyKursow.push_back(name);
    return nowyKurs;
}

void Wykladowca::ModyfikujKurs(Kurs& kurs) {
    std::string newName;
    std::vector<std::string> newTematy;
    std::cout<<"Czy chcesz zmienic nazwe kursu T/N?"<<std::endl;
    std::string zmiana;
    std::cin>>zmiana;
    if(zmiana == "T" || zmiana == "t") {
        std::cout<<"Podaj nową nazwę kursu: "<<std::endl;
        std::cin>>newName;
    }
    if (!newName.empty()) {
        kurs.Nazwa = newName;
        std::cout << "Zmieniono nazwe kursu na: " << newName << std::endl;
        nazwyKursow.push_back(newName);
    }
    std::cout<<"Czy chcesz zmienic tematy kursu T/N?"<<std::endl;
    std::cin>>zmiana;
    if(zmiana == "T" || zmiana == "t") {
        kurs.Tematy.clear();
        std::cout<<"Podaj nowe tematy kursu: "<<std::endl;
        std::string temat;
        while(temat != "0") {
            std::cin>>temat;
            if(temat != "0") {
                newTematy.push_back(temat);
            }
        }
        kurs.Tematy=newTematy;
    }
}


void Wykladowca::WystawOcene(Kurs& kurs, int studentId, int ocena) {
    std::cout<<"Wystawianie oceny: "<<std::endl;
    for (int student : kurs.studentId) {
        if (student == studentId) {
            Ocena nowaOcena;
            nowaOcena.ocena = ocena;
            nowaOcena.studentId = studentId;
            kurs.oceny.pop_back();
            kurs.oceny.push_back(nowaOcena); 
            std::cout << "Wystawiono ocenę " << ocena << " dla studenta o ID: " << studentId << " w kursie " << kurs.Nazwa << std::endl;
        }
        else std::cout << "Nie znaleziono studenta o ID: " << studentId << " w kursie " << kurs.Nazwa << std::endl;

    }
}



