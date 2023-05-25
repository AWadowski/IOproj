#include <iostream>
#include <iomanip>
#include "Student.h"
#include "Kurs.h"
#include "Wykladowca.h"
#include "Uczelnia.h"

using namespace std;

string login, haslo;


public void uruchomMenuStudenta(Uczelnia uczelnia){


}
public void logowanieStudenta(Uczelnia &uczelnia){
    int wybor;
    cout<<"Witaj w systemie uczelni "<<uczelnia.nazwa<<endl;
    cout<<"Podaj dane logowania"<<endl;
    cout<<"Login: ";
    cin>>login;
    cout<<"Hasło: ";
    cin>>haslo;
    cin>>wybor;
    cout<<"Trwa logowanie"<<endl;
    for(int i=0;i<uczelnia.ListaStudentow.size();i++)
    if(uczelnia.ListaStudentow[i].login==login && uczelnia.ListaStudentow[i].haslo==haslo){
        cout<<"Poprawnie zalogowano"<<endl;
        uruchomMenuStudenta(uczelnia);
    };
}


public void uruchomMenu(Uczelnia &uczelnia){
    int wybor;
    cout<<"Witaj w systemie uczelni "<<uczelnia.nazwa<<endl;
    cout<<"Wybierz opcje:"<<endl;
    cout<<"1. Zaloguj się jako student"<<endl;
    cout<<"2. Zaloguj się jako wykładowca"<<endl;
    cin>>wybor;
    switch(wybor){
        case 1:
            uruchomLoginStudenta(uczelnia);
            break;
        case 2:
            uruchomLoginWykladowcy(uczelnia);
            break;
        default:
            cout<<"Nie ma takiej opcji"<<endl;
            break;
    }
}


int main(){
    Uczelnia uczelnia;
    uczelnia.setData("UMCS");
    while(1){
        uruchomMenu(uczelnia);
    }


}
