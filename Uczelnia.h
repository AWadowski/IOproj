//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : Uczelnia.h
//  @ Date : 25.05.2023
//  @ Author : 
//
//


#if !defined(_UCZELNIA_H)
#define _UCZELNIA_H
#include <String.h>
#include "Student.h"
#include "Wykladowca.h"
#include "Kurs.h"
#include <vector>
using namespace std;

class Uczelnia {
public:
	vector<Kurs> ListaKursow;
	vector<Student> ListaStudentow;
	vector<Wykladowca> ListaWykladowcow;
    string nazwa;
	void setData(string name);
};

#endif  //_UCZELNIA_H
