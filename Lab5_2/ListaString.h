#pragma once
#include <iostream>
#include <vector>
#include <string>

class ListaString
{
private:
    std::vector<std::string> napisy;
public:
    ListaString() = default;
    static void rob_halas(bool) {}
    friend ListaString& operator<<(ListaString&, std::string);
    friend std::ostream& operator<<(std::ostream&, ListaString &);
    std::string operator[](unsigned int indx) const { return napisy[indx]; }
};

ListaString& operator<<(ListaString &ls, std::string str)
{
    ls.napisy.push_back(str);
    return ls;
}

std::ostream& operator<<(std::ostream& ostr, ListaString &ls)
{
    int k=1;
    for(std::string n : ls.napisy)
    {
        ostr << "   " << k++ << ". " << n << "\n";
    }
    return ostr;
}