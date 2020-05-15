#pragma once
#include <iostream>
#include <string>

class Operation
{
public:
    ~Operation() {}
    friend void operator >>= (const std::string&, const Operation&);
    virtual void print() const {}
    virtual double eval() const { return 0.0; }
};
