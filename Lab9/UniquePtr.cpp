#include "UniquePtr.h"

UniquePtr::UniquePtr(UniquePtr&& up): p(up.p) 
{
	up.p = nullptr;
}

UniquePtr::~UniquePtr()
{
	delete p;
}

UniquePtr::operator bool() const
{
	if (p == nullptr)
		return false;
	return true;
}

UniquePtr& UniquePtr::operator=(UniquePtr&& up)
{
	delete p;
	p = up.p;
	up.p = nullptr;
	return *this;
}

Point* UniquePtr::release()
{
	Point* temp = p;
	p = nullptr;
	return temp;
}

Point* UniquePtr::get() const
{
	return p;
}

Point& UniquePtr::operator*() const
{
	return *p;
}

Point* UniquePtr::operator->() const
{
	return get();
}
