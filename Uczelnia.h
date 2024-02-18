#if !defined(_UCZELNIA_H)
#define _UCZELNIA_H
#include <string>
#include <vector>
#include "Kurs.h"
#include "Student.h"
#include "Wykladowca.h"

class Uczelnia {
public:
    std::vector<Kurs> ListaKursow;
    std::vector<Student> ListaStudentow;
    std::vector<Wykladowca> ListaWykladowcow;
    std::string nazwa;
    void setData(const std::string& name);
};

#endif  //_UCZELNIA_H
