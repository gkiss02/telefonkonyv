//
// Created by Kiss Gábor on 2023. 05. 14..
//

#ifndef TELEFONKONYV_PERSONALCONTACT_H
#define TELEFONKONYV_PERSONALCONTACT_H

#include "Contact.h"

class PersonalContact: public Contact{
private:
    String address;
    String birthday;

public:
    /// PersonalContact konstuktor
    PersonalContact(String fName, String lName, String phoneNumber, String email, String groups, String address, String
    birthday)
    : Contact(fName, lName, phoneNumber, email, groups), address(address), birthday(birthday) {};

    /// PersonalContact destruktor
    ~PersonalContact() {};

    String getAddress() {return this->address;}
    String getBirthday() {return this->birthday;}

    void setAddress(String str) {this->address = str;}
    void setBirthday(String str) { this->birthday = str;}

    virtual void print (std::ostream& os) {
        os << this->getFName() << ";" << this->getLName() << ";" << this->getPhoneNumber() << ";" << this->getEmail()
           << ";" << this->getBirthday() << ";" << this->getBirthday() << this->getGroups() << ";\n";
    }
};


#endif //TELEFONKONYV_PERSONALCONTACT_H
