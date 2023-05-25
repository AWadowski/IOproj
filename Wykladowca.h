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
#include "Kurs.h"
#include "Student.h"
#include "Wykladowca.h"
#include <string.h>
#include <iostream>
using namespace std;

class Wykladowca {
public:
	string Name;
	string login;
	string haslo;
	Wykladowca();
	~Wykladowca();
	void UtworzKurs(string name);
	void ModyfikujKurs(Kurs kurs);
	void WystawOcene(Kurs kurs, int studentId, int ocena);
	void DodajDoKursu(Kurs kurs, Student student);
};

#endif  //_WYKLADOWCA_H
