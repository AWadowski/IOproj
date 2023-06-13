//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : Student.h
//  @ Date : 25.05.2023
//  @ Author : 
//
//


#if !defined(_STUDENT_H)
#define _STUDENT_H
#include <string>
#include <iostream>
#include <vector>
#include "Kurs.h"

class Student {
public:
    std::string studentName;
    int id;
    std::string login;
    std::string haslo;
    Student();
    ~Student();
    void SprawdzKursy(std::vector<Kurs> listaKursow);
    Kurs ZapiszSieNaKurs(Kurs kurs);
    void SprawdzOceny(std::vector<Kurs> listaKursow);
};

#endif  //_STUDENT_H
