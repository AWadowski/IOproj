//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : Wykladowca.h
//  @ Date : 25.05.2023
//  @ Author : 
//
//


#if !defined(_WYKLADOWCA_H)
#define _WYKLADOWCA_H
#include <string>
#include <iostream>
#include <vector>
#include "Kurs.h"

class Wykladowca {
public:
    std::string name;
    std::string login;
    std::string haslo;
    std::vector <std::string> nazwyKursow;

    Wykladowca();
    ~Wykladowca();

    Kurs UtworzKurs(const std::string& name);
    void ModyfikujKurs(Kurs kurs);
    void WystawOcene(Kurs kurs, int studentId, int ocena);
};

#endif  //_WYKLADOWCA_H
