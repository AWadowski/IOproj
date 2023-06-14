#include <iostream>
#include "Uczelnia.h"
#include <algorithm>
#include <vector>
#include "Student.h"
#include "Wykladowca.h"
#include "Kurs.h"
#include "Ocena.h"

void zapisNaKurs(Uczelnia& uczelnia, Student& student){
    if(uczelnia.ListaKursow.empty()==false) {
        int wyborKursu;
        std::cout << "Wybierz kurs: " << std::endl;
        for (int i = 0; i < uczelnia.ListaKursow.size(); i++) {
            std::cout << i + 1 << ". " << uczelnia.ListaKursow[i].Nazwa << std::endl;
        }
        std::cin >> wyborKursu;
        wyborKursu--;
        if(wyborKursu>=0 && wyborKursu<uczelnia.ListaKursow.size()){
        Kurs kurs = uczelnia.ListaKursow[wyborKursu];
        student.ZapiszSieNaKurs(kurs);
        uczelnia.ListaKursow[wyborKursu] = kurs;
        }else{
            std::cout<<"Nieprawidlowa wartosc"<<std::endl;
        }
    }else{
        std::cout<<"Aktualnie brak kursow do ktorych mozesz dolaczyc"<<std::endl;
    }
}

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
                student.SprawdzKursy(uczelnia.ListaKursow);
                break;
            case 2:
                zapisNaKurs(uczelnia, student);
                break;
            case 3:
                student.SprawdzOceny(uczelnia.ListaKursow);
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

void wystawianieOceny(Uczelnia& uczelnia, Wykladowca& wykladowca){
    if(uczelnia.ListaKursow.empty()==false) {
        std::vector<Kurs> kursyWykladowcy;
        for (int i = 0; i < uczelnia.ListaKursow.size(); i++) {
            for (int j = 0; j < wykladowca.nazwyKursow.size(); j++) {
                if (uczelnia.ListaKursow[i].Nazwa == wykladowca.nazwyKursow[j]) {
                    kursyWykladowcy.push_back(uczelnia.ListaKursow[i]);
                    uczelnia.ListaKursow.erase(uczelnia.ListaKursow.begin() + i);
                }
            }
        }
        std::cout << "Wybierz kurs: " << std::endl;
        for (int i = 0; i < kursyWykladowcy.size(); i++) {
            std::cout << i + 1 << ". ";
            kursyWykladowcy[i].Wyswietl();
        }
        int wybor;
        std::cin >> wybor;
        wybor--;
        system("cls");
        if(uczelnia.ListaStudentow.empty()==false) {
            std::cout << "Wybierz studenta: " << std::endl;
            for (int i = 0; i < uczelnia.ListaKursow[wybor].studentId.size(); i++) {
                for (int j = 0; j < uczelnia.ListaStudentow.size(); j++) {
                    if (kursyWykladowcy[wybor].studentId[i] == uczelnia.ListaStudentow[j].id) {
                        std::cout << i + 1 << ". " << uczelnia.ListaStudentow[j].studentName << std::endl;
                    }
                }
            }
            int wyborStudenta;
            std::cin >> wyborStudenta;
            wyborStudenta--;
            std::cout << "Podaj ocene: " << std::endl;
            int ocenaNowa;
            std::cin >> ocenaNowa;
            wykladowca.WystawOcene(kursyWykladowcy[wybor], kursyWykladowcy[wybor].studentId[wyborStudenta], ocenaNowa);
            system("cls");
            for (int i = 0; i < kursyWykladowcy.size(); i++) {
                uczelnia.ListaKursow.push_back(kursyWykladowcy[i]);
            }
        }else{
            for (int i = 0; i < kursyWykladowcy.size(); i++) {
                uczelnia.ListaKursow.push_back(kursyWykladowcy[i]);
            }
            std::cout<<"Brak studentow w wybranym kursie"<<std::endl;
        }
    }else{
        std::cout<<"Brak kursow"<<std::endl;
    }
}

void modyfikujKurs(Uczelnia& uczelnia, Wykladowca& wykladowca){
    if(uczelnia.ListaKursow.empty()==false) {
    std::vector<Kurs> kursyWykladowcy;
    for(int i=0;i<uczelnia.ListaKursow.size();i++){
        for(int j=0;j<wykladowca.nazwyKursow.size();j++){
            if(uczelnia.ListaKursow[i].Nazwa==wykladowca.nazwyKursow[j]){
                kursyWykladowcy.push_back(uczelnia.ListaKursow[i]);
                uczelnia.ListaKursow.erase(uczelnia.ListaKursow.begin()+i); 
                }
        }
    }
    std::cout<<"Wybierz kurs: "<<std::endl;
    for(int i=0;i<kursyWykladowcy.size();i++){
        std::cout<<i+1<<". "<<kursyWykladowcy[i].Nazwa<<std::endl;
    }
    int wybor;
    std::cin>>wybor;
    system("cls");
    if(wybor>=0&&wybor<=kursyWykladowcy.size()){
    wykladowca.ModyfikujKurs(kursyWykladowcy[wybor-1]);
    for(int i=0 ; i<uczelnia.ListaWykladowcow.size(); i++){
        if(uczelnia.ListaWykladowcow[i].name==wykladowca.name){
            uczelnia.ListaWykladowcow[i]=wykladowca;
        }
    }
    for(int i=0 ; i<kursyWykladowcy.size();i++){
        std::cout<<"Zwrocono kurs"<<std::endl;
        uczelnia.ListaKursow.push_back(kursyWykladowcy[i]);
    }
    }else{
        for(int i=0 ; i<uczelnia.ListaWykladowcow.size(); i++){
            if(uczelnia.ListaWykladowcow[i].name==wykladowca.name){
                uczelnia.ListaWykladowcow[i]=wykladowca;
            }
        }
        for(int i=0 ; i<kursyWykladowcy.size();i++){
            std::cout<<"Zwrocono kurs"<<std::endl;
            uczelnia.ListaKursow.push_back(kursyWykladowcy[i]);
        }
        system("cls");
        std::cout<<"Nieprawidlowa wartosc"<<std::endl;
    }
    }else{
        system("cls");
        std::cout<<"Brak kursow do modyfikacji."<<std::endl;
    }

}

void uruchomMenuWykladowcy(Uczelnia& uczelnia, Wykladowca& wykladowca) {

    int wybor;
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
                system("cls");
                std::cout<<"Podaj nazwe kursu: "<<std::endl;
                std::cin>>nazwaKursu;
                uczelnia.ListaKursow.push_back(wykladowca.UtworzKurs(nazwaKursu));
                system("cls");
                for(int i=0;i<uczelnia.ListaWykladowcow.size();i++){
                    if(uczelnia.ListaWykladowcow[i].name==wykladowca.name){
                        uczelnia.ListaWykladowcow[i].nazwyKursow.push_back(nazwaKursu);
                    }
                }
                break;
            case 2:
                system("cls");
                wystawianieOceny(uczelnia, wykladowca);
                break;
            case 3:
                system("cls");
                modyfikujKurs(uczelnia, wykladowca);
                break;
            case 0:
                system("cls");
                std::cout << "Wylogowano wykladowce" << std::endl;
                return;
            default:
                system("cls");
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
    system("cls");
    std::cout << "Bledne dane logowania" << std::endl;
    //exit(0);
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
    system("cls");
    std::cout << "Trwa logowanie" << std::endl;

    for (int i = 0; i < uczelnia.ListaWykladowcow.size(); i++) {
        if (uczelnia.ListaWykladowcow[i].login == login && uczelnia.ListaWykladowcow[i].haslo == haslo) {
            std::cout << "Poprawnie zalogowano" << std::endl;
            return uczelnia.ListaWykladowcow[i];
        }
    }
    system("cls");
    std::cout << "Bledne dane logowania" << std::endl;
    //exit(0);
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
    nowyStudent.id = uczelnia.ListaStudentow.size()+1;
    uczelnia.ListaStudentow.push_back(nowyStudent);
    system("cls");
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
    system("cls");
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
            if(zalogowanyStudent.id <= uczelnia.ListaStudentow.size()){system("cls");
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
