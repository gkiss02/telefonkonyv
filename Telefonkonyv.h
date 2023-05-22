//
// Created by Kiss Gábor on 2023. 05. 21..
//

#ifndef TELEFONKONYV_TELEFONKONYV_H
#define TELEFONKONYV_TELEFONKONYV_H

#include "Vector.hpp"
#include "Contact.h"
#include "String.h"
#include "PersonalContact.h"
#include "BusinessContact.h"

class Telefonkonyv {
    Vector<Contact*> tomb;
public:

    const Vector<Contact *> &getTomb() const { return tomb; }

    /// Fileból beolvassa a megfelelő adatokat
    void readFile();

    /// Fileba ír
    void writeFile();

    /// Hozzáad egy új contacot a tömbhöz
    /// @param Contact - az új Contact
    void add (Contact *contact) { tomb.push(contact); }

    /// Törli az adott contactot
    /// @param Contact - a törlendő contact
    void deleteContact (Contact *contact);

    /// Kiírja minden kontakt vezeték és keresztnevét
    void printAll();

    /// Vezetéknév alapján keres
    /// @param String - keresett vezetéknév
    /// @return keresett vezetéknév indexe. Nem létező esetén -1
    int searchlName(String);

    /// Keresztnév alapján keres
    /// @param String - keresett vezetéknév
    /// @return keresett vezetéknév indexe. Nem létező esetén -1
    int searchfName(String);

    /// Destruktor
    ~Telefonkonyv();
};


#endif //TELEFONKONYV_TELEFONKONYV_H
