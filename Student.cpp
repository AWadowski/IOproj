//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : Student.cpp
//  @ Date : 25.05.2023
//  @ Author : 
//
//


#include "Student.h"

Student::Student() {

}

Student::~Student() {

}

void Student::SprawdzKursy(std::vector<Kurs>& ListaKursow) {
    for(int i = 0; i < ListaKursow.size(); i++) {
        std::cout << ListaKursow[i].Nazwa << std::endl;
    }
}

Kurs Student::ZapiszSieNaKurs(Kurs& kurs) {
    kurs.studentId.push_back(id);
    return kurs;
}

void Student::SprawdzOceny(std::vector<Kurs>& ListaKursow) {
    for(int i = 0; i < ListaKursow.size(); i++) {
        for(int j = 0; j < ListaKursow[i].studentId.size(); j++) {
            if(ListaKursow[i].studentId[j] == id) {
                std::cout << ListaKursow[i].Nazwa << ": " << ListaKursow[i].oceny[j].ocena << std::endl;
            }
        }
    }
}

