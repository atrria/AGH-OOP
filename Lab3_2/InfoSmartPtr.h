#pragma once
#include <memory>
#include "InfoClass.h"
class InfoClass;
class InfoSmartPtr
{
private:
	std::shared_ptr<InfoClass> pb = make_unique<InfoSmartPtr>();
public:
	InfoSmartPtr()
	{

	}
};

#pragma once
#include "InfoClass.h"
class InfoSmartPtr
{
public:

    InfoSmartPtr(InfoClass* x)
    {
        m_ptr = x;
    }

    InfoClass operator* () const
    {
        return *m_ptr;
    }

    void operator= (InfoSmartPtr x)
    {
        delete m_ptr;
        m_ptr = x.m_ptr;
    }

    InfoClass* operator-> () const
    {
        return m_ptr;
    }


private:

    InfoClass* m_ptr;
};

class InfoSuperClass : public InfoClass
{
public:

    InfoSuperClass(std::string a, int b) : InfoClass{ a }, m_num{ b }
    {
        //m_ptr
    };

private:

    int m_num;

};