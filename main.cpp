#include <iostream>
#include <fstream>

#include "Vector.hpp"
#include "Telefonkonyv.h"
#include "Contact.h"
#include "PersonalContact.h"
#include "BusinessContact.h"

int main() {
    //TESZT ESETEK
    //filebol olvasas
    //fileba iras
    //contact letrehozasa
    //contact adatainak kiirasa
    //contact adatainak szerkeztese
    //csoportok kiirasa
    //csoport letrehozasa
    //csoport torlese
    //contact lista tesztelese

    Telefonkonyv telefonkonyv;
    telefonkonyv.readFile();
    telefonkonyv.writeFile();
}
