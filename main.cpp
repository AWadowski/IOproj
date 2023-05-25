#include <iostream>
#include "Uczelnia.h"


Student student; 

void uruchomMenuStudenta(Uczelnia& uczelnia, Student& student) {
    int wybor;
    // Dodaj logikę i menu dla studenta
    while (true) {
        
        std::cout << "Menu studenta" << std::endl;
        std::cout << "1. Sprawdz kursy" << std::endl;
        std::cout << "2. Zapisz sie na kurs" << std::endl;
        std::cout << "3. Sprawdz oceny" << std::endl;
        std::cout << "0. Wyloguj sie" << std::endl;
        std::cin >> wybor;
        system("cls");
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

void uruchomMenuWykladowcy(Uczelnia& uczelnia, Wykladowca& wykladowca) {
    system("cls");
    int wybor;
    // Dodaj logikę i menu dla wykładowcy
    while (true) {
        int ocena;
        std::string nazwaKursu;
        std::cout << "Menu wykladowcy" << std::endl;
        std::cout << "1. Dodaj kurs" << std::endl;
        std::cout << "2. Dodaj ocene" << std::endl;
        std::cout << "3. Modyfikuj kurs" << std::endl;
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
    exit(0);
    return Student();
}

Wykladowca logowanieWykladowcy(Uczelnia& uczelnia) {
    
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
    system("cls");
    std::cout << "Bledne dane logowania" << std::endl;
    exit(0);
    return Wykladowca();
}

void rejestracjaStudenta(Uczelnia& uczelnia) {
    system("cls");
    std::string studentName, login, haslo;
    std::cout << "Rejestracja studenta" << std::endl;
    std::cout << "Podaj nazwe studenta: ";
    std::cin >> studentName;
    std::cout << "Podaj login: ";
    std::cin >> login;
    std::cout << "Podaj haslo: ";
    std::cin >> haslo;
    Student nowyStudent;
    nowyStudent.studentName = studentName;
    nowyStudent.login = login;
    nowyStudent.haslo = haslo;
    nowyStudent.id = uczelnia.ListaStudentow.size();
    uczelnia.ListaStudentow.push_back(nowyStudent);
    std::cout << "Zarejestrowano nowego studenta." << std::endl;
}

void rejestracjaWykladowcy(Uczelnia& uczelnia) {
    system("cls");
    std::string name, login, haslo;
    std::cout << "Rejestracja wykladowcy" << std::endl;
    std::cout << "Podaj nazwe wykladowcy: ";
    std::cin >> name;
    std::cout << "Podaj login: ";
    std::cin >> login;
    std::cout << "Podaj haslo: ";
    std::cin >> haslo;
    Wykladowca nowyWykladowca;
    nowyWykladowca.name = name;
    nowyWykladowca.login = login;
    nowyWykladowca.haslo = haslo;
    uczelnia.ListaWykladowcow.push_back(nowyWykladowca);
    std::cout << "Zarejestrowano nowego wykladowce." << std::endl;
}

void uruchomMenu(Uczelnia& uczelnia) {
    int wybor;
    std::cout << "Witaj w systemie uczelni " << uczelnia.nazwa << std::endl;
    std::cout << "Wybierz opcje:" << std::endl;
    std::cout << "1. Zaloguj sie jako student" << std::endl;
    std::cout << "2. Zaloguj sie jako wykladowca" << std::endl;
    std::cout << "3. Zarejestruj sie jako student" << std::endl;
    std::cout << "4. Zarejestruj sie jako wykladowca" << std::endl;
    std::cout << "5. Wyjdz" << std::endl;
    std::cin >> wybor;
    Student zalogowanyStudent;
    Wykladowca zalogowanyWykladowca;
    switch (wybor) {
        case 1:
            zalogowanyStudent = logowanieStudenta(uczelnia);
            if(zalogowanyStudent.id < uczelnia.ListaStudentow.size()){
            uruchomMenuStudenta(uczelnia, zalogowanyStudent);
            }
            break;
        case 2:
            zalogowanyWykladowca = logowanieWykladowcy(uczelnia);
            uruchomMenuWykladowcy(uczelnia, zalogowanyWykladowca);
            break;
        case 3:
            rejestracjaStudenta(uczelnia);
            break;
        case 4:
            rejestracjaWykladowcy(uczelnia);
            break;
        case 5:
            exit(0);
            break;
        default:
            system("cls");
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
