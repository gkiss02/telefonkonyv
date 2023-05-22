//
// Created by Kiss Gábor on 2023. 05. 14..
//

#include "String.h"

String::String() {
    this->len = 0;
    this->pData = new char[len + 1];
    pData[0] = '\0';
}

String::String(const char *c) {
    this->len = strlen(c);
    this->pData = new char[len + 1];
    strcpy(this->pData, c);
}

String::String(const String &str) {
    len = str.len;
    pData = new char[len + 1];
    strcpy(pData, str.pData);
    pData[len] = '\0';
}

char& String::operator[](int idx) {
    if (idx >= this->len) throw "String: indexelesi hiba";
    return pData[idx];
}

const char& String::operator[](int idx) const {
    if (idx >= len) throw "String: indexelesi hiba";
    return pData[idx];
}

String &String::operator=(const String &str) {
    if (this != &str) {
        this->len = str.len;
        delete[] this->pData;
        pData = new char[len + 1];
        strcpy(this->pData, str.pData);
    }
    return *this;
}

bool String::operator==(const String &str) {
    if (this->len != str.len) return false;

    for (int i = 0; i < this->len; ++i) {
        if (this->pData[i] != str.pData[i]) return false;
    }

    return true;
}

bool String::contains(char c) {
    for (int i = 0; this->pData[i] != '\0'; ++i) {
        if (this->pData[i] == c) return true;
    }
    return false;
}

std::ostream& operator<<(std::ostream& os, const String& kiir) {
    os << kiir.c_str();
    return os;
}

