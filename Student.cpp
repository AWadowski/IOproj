#include "Student.h"

Student::Student() {
}

Student::~Student() {
}

void Student::SprawdzKursy(std::vector<Kurs>& ListaKursow) {
    for(int i = 0; i < ListaKursow.size(); i++) {
        if(ListaKursow[i].studentId.size() > 0){
            for(int j = 0; j < ListaKursow[i].studentId.size(); j++){
                if(ListaKursow[i].studentId[j] == id){
                    ListaKursow[i].Wyswietl();
                }
            }
        }
    }
}

Kurs Student::ZapiszSieNaKurs(Kurs& kurs) {
    kurs.studentId.push_back(id);
    Ocena nowaOcena;
    nowaOcena.ocena = 0;
    nowaOcena.studentId = id;
    kurs.oceny.push_back(nowaOcena);
    return kurs;
}

void Student::SprawdzOceny(std::vector<Kurs>& ListaKursow) {
    for(int i = 0; i < ListaKursow.size(); i++) {
        if(ListaKursow[i].studentId.size() > 0){
            for(int j = 0; j < ListaKursow[i].studentId.size(); j++) {
                if(ListaKursow[i].studentId[j] == id && ListaKursow[i].oceny[j].ocena==0) {
                    std::cout << ListaKursow[i].Nazwa << ": BRAK OCENY" << std::endl;
                }else{
                    std::cout << ListaKursow[i].Nazwa << ": " << ListaKursow[i].oceny[j].ocena << std::endl;
                }

            }
        }
    }
}

