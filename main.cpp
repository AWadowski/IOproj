#include <iostream>
#include "Uczelnia.h"


Student student; 

void uruchomMenuStudenta(Uczelnia& uczelnia, Student& student) {
    system("cls");
    int wybor;
    // Dodaj logikę i menu dla studenta
    while (true) {
        std::cout << "Menu studenta" << std::endl;
        std::cout << "1. Sprawdz kursy" << std::endl;
        std::cout << "2. Zapisz sie na kurs" << std::endl;
        std::cout << "3. Sprawdz oceny" << std::endl;
        std::cout << "0. Wyloguj sie" << std::endl;
        std::cin >> wybor;

        switch (wybor) {
            case 1:
                uczelnia.ListaStudentow[0].SprawdzKursy(); // Przykładowe wywołanie metody dla pierwszego studenta na liście
                break;
            case 2:
                // Zaimplementuj logikę zapisu na kurs
                break;
            case 3:
                // Zaimplementuj logikę sprawdzania ocen
                break;
            case 0:
                std::cout << "Wylogowano studenta" << std::endl;
                return;
            default:
                std::cout << "Nieprawidlowa opcja" << std::endl;
                break;
        }
    }
}

void uruchomMenuWykladowcy(Uczelnia& uczelnia) {
    system("cls");
    int wybor;
    // Dodaj logikę i menu dla wykładowcy
    while (true) {
        std::cout << "Menu wykladowcy" << std::endl;
        std::cout << "1. Dodaj kurs" << std::endl;
        std::cout << "2. Dodaj ocene" << std::endl;
        std::cout << "0. Wyloguj sie" << std::endl;
        std::cin >> wybor;

        switch (wybor) {
            case 1:
                // Zaimplementuj logikę dodawania kursu
                break;
            case 2:
                // Zaimplementuj logikę dodawania oceny
                break;
            case 0:
                std::cout << "Wylogowano wykladowce" << std::endl;
                return;
            default:
                std::cout << "Nieprawidlowa opcja" << std::endl;
                break;
        }
    }
}


Student logowanieStudenta(Uczelnia& uczelnia) {
    system("cls");
    std::string login, haslo;
    int wybor;

    std::cout << "Witaj w systemie uczelni " << uczelnia.nazwa << std::endl;
    std::cout << "Podaj dane logowania" << std::endl;
    std::cout << "Login: ";
    std::cin >> login;
    std::cout << "Haslo: ";
    std::cin >> haslo;
    std::cout << "Trwa logowanie" << std::endl;

    for (int i = 0; i < uczelnia.ListaStudentow.size(); i++) {
        if (uczelnia.ListaStudentow[i].login == login && uczelnia.ListaStudentow[i].haslo == haslo) {
            std::cout << "Poprawnie zalogowano" << std::endl;
            return uczelnia.ListaStudentow[i];
        }
    }

    std::cout << "Bledne dane logowania" << std::endl;
    return Student();
}

Wykladowca logowanieWykladowcy(Uczelnia& uczelnia) {
    system("cls");
    std::string login, haslo;
    int wybor;

    std::cout << "Witaj w systemie uczelni " << uczelnia.nazwa << std::endl;
    std::cout << "Podaj dane logowania" << std::endl;
    std::cout << "Login: ";
    std::cin >> login;
    std::cout << "Haslo: ";
    std::cin >> haslo;
    std::cout << "Trwa logowanie" << std::endl;

    for (int i = 0; i < uczelnia.ListaWykladowcow.size(); i++) {
        if (uczelnia.ListaWykladowcow[i].login == login && uczelnia.ListaWykladowcow[i].haslo == haslo) {
            std::cout << "Poprawnie zalogowano" << std::endl;
            return uczelnia.ListaWykladowcow[i];
        }
    }

    std::cout << "Bledne dane logowania" << std::endl;
    return Wykladowca();
}

void uruchomMenu(Uczelnia& uczelnia) {
    int wybor;
    system("cls");
    std::cout << "Witaj w systemie uczelni " << uczelnia.nazwa << std::endl;
    std::cout << "Wybierz opcje:" << std::endl;
    std::cout << "1. Zaloguj sie jako student" << std::endl;
    std::cout << "2. Zaloguj sie jako wykladowca" << std::endl;
    std::cout << "3. Wyjdz" << std::endl;
    std::cin >> wybor;
    Student zalogowanyStudent;
    Wykladowca zalogowanyWykladowca;
    switch (wybor) {
        case 1:
            zalogowanyStudent = logowanieStudenta(uczelnia);
            if(zalogowanyStudent.id != 0){
            uruchomMenuStudenta(uczelnia, zalogowanyStudent);
            }
            break;
        case 2:
            zalogowanyWykladowca = logowanieWykladowcy(uczelnia);
            //uruchomMenuWykladowcy(uczelnia,wykladowca);
            break;
        case 3:
            exit(0);
            break;
        default:
            std::cout << "Nie ma takiej opcji" << std::endl;
            break;
    }
}

int main() {
    Uczelnia uczelnia;
    uczelnia.setData("UMCS");

    while (true) {
        uruchomMenu(uczelnia);
    }

    return 0;
}
