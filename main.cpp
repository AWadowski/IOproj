#include <iostream>
#include "Uczelnia.h"

void uruchomMenuStudenta(Uczelnia& uczelnia) {
    int wybor;
    // Dodaj logikę i menu dla studenta
    while (true) {
        std::cout << "Menu studenta" << std::endl;
        std::cout << "1. Sprawdź kursy" << std::endl;
        std::cout << "2. Zapisz się na kurs" << std::endl;
        std::cout << "3. Sprawdź oceny" << std::endl;
        std::cout << "0. Wyloguj się" << std::endl;
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
                std::cout << "Nieprawidłowa opcja" << std::endl;
                break;
        }
    }
}

void uruchomMenuWykladowcy(Uczelnia& uczelnia) {
    int wybor;
    // Dodaj logikę i menu dla wykładowcy
    while (true) {
        std::cout << "Menu wykładowcy" << std::endl;
        std::cout << "1. Dodaj kurs" << std::endl;
        std::cout << "2. Dodaj ocenę" << std::endl;
        std::cout << "0. Wyloguj się" << std::endl;
        std::cin >> wybor;

        switch (wybor) {
            case 1:
                // Zaimplementuj logikę dodawania kursu
                break;
            case 2:
                // Zaimplementuj logikę dodawania oceny
                break;
            case 0:
                std::cout << "Wylogowano wykładowcę" << std::endl;
                return;
            default:
                std::cout << "Nieprawidłowa opcja" << std::endl;
                break;
        }
    }
}


void logowanieStudenta(Uczelnia& uczelnia) {
    std::string login, haslo;
    int wybor;

    std::cout << "Witaj w systemie uczelni " << uczelnia.nazwa << std::endl;
    std::cout << "Podaj dane logowania" << std::endl;
    std::cout << "Login: ";
    std::cin >> login;
    std::cout << "Hasło: ";
    std::cin >> haslo;
    std::cout << "Trwa logowanie" << std::endl;

    for (int i = 0; i < uczelnia.ListaStudentow.size(); i++) {
        if (uczelnia.ListaStudentow[i].login == login && uczelnia.ListaStudentow[i].haslo == haslo) {
            std::cout << "Poprawnie zalogowano" << std::endl;
            uruchomMenuStudenta(uczelnia);
            return;
        }
    }

    std::cout << "Błędne dane logowania" << std::endl;
}

void uruchomMenu(Uczelnia& uczelnia) {
    int wybor;

    std::cout << "Witaj w systemie uczelni " << uczelnia.nazwa << std::endl;
    std::cout << "Wybierz opcję:" << std::endl;
    std::cout << "1. Zaloguj się jako student" << std::endl;
    std::cout << "2. Zaloguj się jako wykładowca" << std::endl;
    std::cin >> wybor;

    switch (wybor) {
        case 1:
            logowanieStudenta(uczelnia);
            break;
        case 2:
            // uruchomLoginWykladowcy(uczelnia); // Dodaj implementację dla wykładowcy
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
