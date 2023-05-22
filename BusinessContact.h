//
// Created by Kiss Gábor on 2023. 05. 14..
//

#ifndef TELEFONKONYV_BUSINESSCONTACT_H
#define TELEFONKONYV_BUSINESSCONTACT_H

#include "Contact.h"

class BusinessContact: public Contact {
private:
    String companyPhone;
    String office;
public:
    BusinessContact(String fName, String lName, String phoneNumber, String email, String groups, String companyPhone,
                    String office)
    : Contact(fName, lName, phoneNumber, email, groups) {
        if (!checkPhoneNumber(companyPhone)) throw "Hibas formatum";
        this->companyPhone = companyPhone;
        this->office = office;
    };

    ~BusinessContact() {};

    String getCompanyPhone() { return this->companyPhone;}
    String getOffice() {return this->office;}

    void setCompanyPhone(String str) {
        if (checkPhoneNumber(str)) throw "Nem megfelelő formátum";
        this->companyPhone = str;
    };

    void setOffice(String str) {this->office = str;}

    virtual void print (std::ostream& os) {
        os << this->getFName() << ";" << this->getLName() << ";" << this->getPhoneNumber() << ";" << this->getEmail()
        << ";" << this->getCompanyPhone() << ";" << this->getOffice() << this->getGroups() << ";\n";
    }
};



#endif //TELEFONKONYV_BUSINESSCONTACT_H
