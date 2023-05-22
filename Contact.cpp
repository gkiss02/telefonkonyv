//
// Created by Kiss Gábor on 2023. 05. 14..
//

#include <fstream>
#include "Contact.h"

bool Contact::checkPhoneNumber(String str) {
    if (str.size() != 11) return false;

    for (int i = 0; i < 11; ++i) {
        if (!(str[i] >= '0' && str[i] <= '9')) return false;
    }
    return true;
}

bool Contact::checkEmail(String str) {
    if (str.size() == 0) return false;
    if (!str.contains('@')) return false;
    if (!str.contains('.')) return false;
    return true;
}

Contact::Contact(String fName, String lName, String phoneNumber, String email, String groups) {
    this->fName = fName;
    this->lName = lName;
    if (!checkPhoneNumber(phoneNumber)) throw "Hibás formátum";
    this->phoneNumber = phoneNumber;
    this->email = email;
    this->groups = groups;
}

void Contact::setPhoneNumber(String str) {
    if (checkPhoneNumber(str)) throw "Nem megfelelő formátum";
    this->phoneNumber = str;
}

void Contact::setEmail(String str) {
    if (checkEmail(str)) throw "Nem megfelelő formátum";
    this->email = str;
}

void Contact::print(std::ostream& os) {
    os << this->getFName() << ";" << this->getLName() << ";" << this->getPhoneNumber() << ";" << this->getEmail() <<
    ";" << this->getGroups() << ";\n";
}

/*void Contact::deleteGroups(String str) {
    for (int i = 0; i < groups.getSize(); ++i) {
        if (str == groups[i]) groups.pop(i);
    }
}*/
