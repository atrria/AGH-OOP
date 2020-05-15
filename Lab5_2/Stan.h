#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "MaszynaStanow.h"

#define STATE_TYPE(napis) class napis : public Stan

class MaszynaStanow;
class Stan 
{
protected:
    MaszynaStanow *maszyna_stanow;
public:
    Stan() : maszyna_stanow(nullptr) {}
    virtual ~Stan() = default;
    void setMS(MaszynaStanow *s) { maszyna_stanow = s; }
    virtual void operator ()() {};
    virtual const char* nazwa() const { return 0; }
    virtual void podsumowanie() const {};
};

STATE_TYPE(Podsumowanie)
{
public:
    virtual void podsumowanie() const;
    virtual const char* nazwa() const;
    virtual void operator()();
};

STATE_TYPE(ZbieranieDanych)
{
private:
    std::string adres;
public:
    ZbieranieDanych(std::string mail);
    virtual const char* nazwa() const;
    virtual void podsumowanie() const;
    virtual void operator()();
};