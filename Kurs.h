//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : Kurs.h
//  @ Date : 25.05.2023
//  @ Author : 
//
//


#if !defined(_KURS_H)
#define _KURS_H


#include <string>
#include <vector>
#include "Student.h"

class Kurs {
public:
    std::string Nazwa;
    std::vector<std::string> Tematy;
    std::vector<std::pair<Student*, long>> oceny; // Wskaźnik na obiekt Student i ocena
    std::vector<Student*> studenci; // Wskaźnik na obiekt Student

    void Wyswietl();
};

#endif  //_KURS_H
