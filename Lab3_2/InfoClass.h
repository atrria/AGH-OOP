#pragma once
#include<string>
#include<iostream>
class InfoClass
{
private:
	std::string informacja;
public:
	InfoClass(std::string n);
	~InfoClass();
	std::string info() const;
};

#pragma once
#include <iostream>
#include <string>

class InfoSmartPtr;

class InfoClass
{
    friend InfoSmartPtr;

public:

    InfoClass(std::string a) : m_info{ a }
    {
        std::cout << "++Tworze obiekt InfoClass: info = " << m_info << std::endl;
    };
    ~InfoClass()
    {
        std::cout << "++Usuwam obiekt InfoClass: info = " << m_info << std::endl;
    }
    std::string info() const
    {
        return "info = " + m_info;
    }
    void info(std::string x)
    {
        m_info = x;
    }



private:
    std::string m_info;
};