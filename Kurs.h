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
class Kurs {
public:
    std::string Nazwa;
    std::vector<std::string> Tematy;
    std::vector<std::pair<int, int>> oceny;
    std::vector<int> studentId;

    void Wyswietl();
};

#endif  //_KURS_H
