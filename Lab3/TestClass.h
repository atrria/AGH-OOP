#pragma once
#include <iostream>
#include <string>

class TestClass
{
private:

    // zmienna skladowa, lancuch przechowujacy nazwe obiektu
    std::string str;

public:

    //konstruktor wpisujacy nazwe t obiektu do zmiennej skladowej str i wypisujacy komunikat o utworzeniu obiektu o danej nazwie
    TestClass(const char* t) : str(std::string(t)) {  std::cout << "++ Tworze obiekt TestClass: " << str << std::endl; }
    //destruktor wypisujacy komunikat o usunieciu obiektu o nazwie str
    ~TestClass();
    //funkcja skladowa zwracajaca zmienna skladowa str
    const std::string info() const;
    //funkcja skladowa przypisujaca nazwe s do zmiennej skladowej str
    void set_info(const std::string& s);
};