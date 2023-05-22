#include <iostream>

#ifndef TELEFONKONYV_VECTOR_HPP
#define TELEFONKONYV_VECTOR_HPP

template <typename T>
class Vector {
    size_t n;
    T *arr;
public:

    /// Paraméter hívható Vector konstruktor
    Vector(): n(0), arr(new T[n]) {};

    /// Vector másoló konstruktor
    Vector(const Vector& v) :arr(NULL) { *this = v;}

    /// Vector destruktor
    ~Vector() {delete[] this->arr;}

    /// Visszaadja a Vector méretét
    /// @return Vector tényleges hossza
    size_t getSize() {return n;}

    /// Visszaadja a Vector tömböt
    /// @return tömbre mutató pointer
    T getTomb() {return this->arr;}

    /// Konstans indexelő operátor
    /// @param i - a lekért elem indexe
    /// @return adott indexen lévő elem
    T operator[](int i) const {return arr[i];}

    /// Indexelő operátor
    /// @param i - a lekért elem indexe
    /// @return adott indexen lévő elem referenciája
    T& operator[](int i) {return arr[i];}

    /// A tömb végére teszi az elemet
    /// @param t - a beszúrandó elem
    void push(T t) {
        T *nArr = new T[n + 1];

        for (int i = 0; i < n; ++i) {
            nArr[i] = arr[i];
        }

        nArr[n] = t;
        delete[] arr;
        arr = nArr;
        n++;
    }

    /// Kitörli az adott indexen lévő elemet
    /// @param index - a törlendő elem indexe
    void pop(int index) {
        if (index < 0 || index >= n) throw "Érvénytelen index";

        T *nArr = new T[n - 1];

        for (int i = 0, j = 0; i < n; ++i) {
            if (i != index) {
                nArr[j] = arr[i];
                ++j;
            }
        }

        delete[] arr;
        arr = nArr;
        --n;
    }

    /// Értékadó operátor
    /// @param Vector - az új String
    /// @return a másolás után a régi Vector pointere
    Vector& operator=(const Vector& v) {
        if (this != &v) {
            delete[] arr;
            n = v.n;
            arr = new T[n];
            for (size_t i = 0; i < n; i++)
                arr[i] = v.arr[i];
        }
        return *this;
    }
};


#endif //TELEFONKONYV_VECTOR_HPP