//
// Created by Kiss Gábor on 2023. 05. 14..
//

#ifndef TELEFONKONYV_STRING_H
#define TELEFONKONYV_STRING_H

#include <iostream>

class String {
    char *pData;
    size_t len;
public:

    /// Paraméter nélkül hívható konstuktor
    String();

    /// Konstruktor
    /// char* -> String konverzió
    /// @param char*
    String(const char*);

    /// Másoló konstruktor
    /// @param String - a másolandó String
    String(const String&);

    /// String destruktor
    ~String() {delete[] this->pData;}

    /// Vissza adja a String hosszát
    /// @return String tényleges hossza
    size_t size() const {return this->len;}

    /// Vissza adja a Stringet
    /// @return String karakter sorozata
    const char* c_str() const {return this->pData;}

    /// Indexelő operátor
    /// @param int - a keresett elem indexe
    /// @return az adott indexen lévő elem referenciája
    char& operator[](int);

    /// Konstans indexelő operátor
    /// @param int - a keresett elem indexe
    /// @return az adott indexen lévő elem
    const char& operator[](int) const;

    /// Értékadó operátor
    /// @param String - az új String
    /// @return a másolás után a régi String pointere
    String& operator=(const String&);

    /// Összehasonlító operátor
    /// @param String - az összehasonlítandó String
    /// @return a két String egyezési értéke
    bool operator==(const String&);

    /// Ellenőrzi tartalmazz-e a megadott karaktert
    /// @param char - az ellenőrizendő karakter
    /// @return benne van-e a karakter
    bool contains(char);

    void append(char ch) {
        char* newData = new char[len + 2];
        for (int i = 0; i < len; ++i) {
            newData[i] = pData[i];
        }
        newData[len] = ch;
        newData[len + 1] = '\0';

        delete[] pData;
        pData = newData;
        ++len;
    }
};

/// Insterter operátor Stringre
/// @param ostream - a stream melyre kiírjuk a Stringet
/// @param String - a kiirandó String
/// @return a megváltozott stream
std::ostream& operator<<(std::ostream& os, const String& str);


#endif //TELEFONKONYV_STRING_H
