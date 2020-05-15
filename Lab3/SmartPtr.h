#pragma once
#include "TestClass.h"

class SmartPtr
{
private:

    // wskaznik ptr
    TestClass* ptr;
    // licznik counter
    unsigned int* counter;

    // funkcja skladowa "kopiujaca" i zwiekszajaca licznik
    void ptr_copy(const SmartPtr&);
    // fuckcja skladowa sluzaca do usuwania wskaznika i zmniejszania licznika
    void delete_ptr();
    //funkcja skladowa zwracajaca ptr
    inline TestClass* getPtr() const { return ptr; }

public:

    // konstruktor alokujacy obiekt i ustawiajacy counter na 1
    SmartPtr(TestClass* sp_ptr) : ptr(sp_ptr), counter(new unsigned int) { *counter = 1; }
    // konstruktor wykorzystujacy funkcje ptr_copy
    SmartPtr(const SmartPtr& sptr) { ptr_copy(sptr); }
    // destruktor zmniejszajacy licznik i usuwajacy wskaznik jesli licznik  to 1
    ~SmartPtr() { delete_ptr(); }
    // przeciazenie operatora * dla wskaznika ptr
    inline TestClass& operator*() const { return *ptr; }
    // przeciazenie operatora wyluskania dla wzkaznika ptr,\
       uzywa funkcji zwracajacej wskaznik ptr
    inline TestClass* operator->() const { return this->getPtr(); }
    // przeladowany operator przypisania, wywoluje funkcje usuwajaca ptr ( badz zmniejszajaca licznik )
    SmartPtr& operator=(const SmartPtr&);
    // funkcja skladowa zwracajaca adres countera
    unsigned int* getCount() const { return counter; }
    // funkcja skladowa zwracajaca licznik
    unsigned int useCount() const { return *counter; }
};