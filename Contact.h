//
// Created by Kiss Gábor on 2023. 05. 14..
//

#ifndef TELEFONKONYV_CONTACT_H
#define TELEFONKONYV_CONTACT_H

#include "String.h"
#include "Vector.hpp"

class Contact {
    String fName;
    String lName;
    String phoneNumber;
    String email;
    String groups;

    /// Ellenőrzi az email cím a megfelelő formátumban van-e
    /// @param String - az ellenőrizendő email cím
    /// @return megfelelő-e a formátum
    bool checkEmail(String);

public:

    /// Ellenőrzi a telefonszám a megfelelő formátumban van-e
    /// @param String - az ellenőrizendő telefonszám
    /// @return megfelelő-e a formátum
    bool checkPhoneNumber(String);

    Contact() {};

    /// Contact konstruktor
    /// Minden paramétert inicializál
    Contact(String fName, String lName, String phoneNumber, String email, String groups = "ures");

    ///Contact destruktor
    virtual ~Contact() {};

    /// Vissza a Contact fName attrimbutumát
    /// @return fName
    String getFName() {return fName;}

    /// Visszaadja a Contact lName attribútumát
    /// @return lName
    String getLName() {return lName;}

    /// Visszaadja a Contact phoneNumber attribútumát
    /// @return phoneNumber
    String getPhoneNumber() {return phoneNumber;}

    /// Visszaadja a Contact email attribútumát
    /// @return email
    String getEmail() {return email;}

    const String &getGroups() const  {return groups; }
/*    const Vector<String> &getGroups() const {return groups;}*/

    /// Beállítja a Contact fName attribútumát
    /// @param String - az attribútum új értéke
    void setFName(String str) {this->fName = str;}

    /// Beállítja a Contact lName attribútumát
    /// @param String - az attribútum új értéke
    void setLName(String str) {this->lName = str;}

    /// Beállítja a Contact phoneNumber attribútumát
    /// @param String - az attribútum új értéke
    void setPhoneNumber(String str);

    /// Beállítja a Contact email attribútumát
    /// @param String - az attribútum új értéke
    void setEmail(String str);

    virtual void print(std::ostream&);

/*    /// Hozzáad egy Stringet a csoportokhoz
    /// @param String - a csoport neve
    void addGroups(String str) {groups.push(str);}

    /// Töröl egy elemet a csoportok közül
    /// @param String - a törlendő csoport neve
    void deleteGroups(String);*/
};


#endif //TELEFONKONYV_CONTACT_H
