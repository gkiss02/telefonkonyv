//
// Created by Kiss Gábor on 2023. 05. 21..
//
#include <fstream>

#include "Telefonkonyv.h"

void Telefonkonyv::readFile() {
    String currentString;

    std::ifstream file("../contact.txt");
    if (!file.is_open()) {
        std::cout << "Hiba a fájl megnyitásakor!" << std::endl;
    }

    char ch;
    Vector<String> seged;
    int count = 0;
    while (file.get(ch)) {
        if (ch == '\n') {
            if (seged.getSize() == 5) {
                for (int i = 0; i < seged.getSize(); i += 5) {
                    tomb.push(new Contact(seged[i], seged[i + 1], seged[i + 2], seged[i + 3], seged[i + 4]));
                }
            } else if (seged.getSize() == 7) {
                if (Contact().checkPhoneNumber(seged[5])) {
                    for (int i = seged.getSize() - 7; i < seged.getSize(); i += 7) {
                        tomb.push(new BusinessContact(seged[i], seged[i + 1], seged[i + 2], seged[i + 3], seged[i + 4],
                                                      seged[i + 5], seged[i + 6]));
                    }
                } else {
                    for (int i = seged.getSize() - 7; i < seged.getSize(); i += 7) {
                        tomb.push(new PersonalContact(seged[i], seged[i + 1], seged[i + 2], seged[i + 3], seged[i + 4],
                                                      seged[i + 5], seged[i + 6]));
                    }
                }
            }
            std::cout << seged[0] << std::endl;
            seged = Vector<String>();
            count = 0;
        } else {
            if (ch == ';') {
                seged.push(currentString);
                currentString = String();
                count++;
                std::cout << count;
            } else {
                currentString.append(ch);
            }
        }
    }

    file.close();
}

void Telefonkonyv::writeFile() {
    std::ofstream file("../contact.txt");
    if (!file.is_open()) {
        std::cout << "Hiba a fájl megnyitásakor!" << std::endl;
        return;
    }

    for (int i = 0; i < tomb.getSize(); ++i) {
        tomb[i]->print(file);
    }

    file.close();
}

void Telefonkonyv::deleteContact(Contact *contact) {
    for (int i = 0; i < tomb.getSize(); ++i) {
        if (contact == tomb[i]) {
            delete tomb[i];
            tomb.pop(i);
        }
    }
}


void Telefonkonyv::printAll() {
    for (int i = 0; i < tomb.getSize(); ++i) {
        std::cout << tomb[i]->getFName() << " " << tomb[i]->getLName() << std::endl;
    }
}

int Telefonkonyv::searchlName(String str) {
    for (int i = 0; i < tomb.getSize(); ++i) {
        if (tomb[i]->getLName() == str) return i;
    }
    return -1;
}

int Telefonkonyv::searchfName(String str) {
    for (int i = 0; i < tomb.getSize(); ++i) {
        if (tomb[i]->getFName() == str) return i;
    }
    return -1;
}

Telefonkonyv::~Telefonkonyv() {
    for (size_t i = 0; i < tomb.getSize(); i++) {
        delete tomb[i];
    }
}