#include "SmartPtr.h"

SmartPtr& SmartPtr::operator=(const SmartPtr& sp)
{
    delete_ptr();
    ptr_copy(sp);
    return *this;
}

void SmartPtr::ptr_copy(const SmartPtr& sptr)
{
    ptr = sptr.getPtr();
    counter = sptr.getCount();
    (*counter)++;
}

void SmartPtr::delete_ptr()
{
    if (*counter == 1)
    {
        delete ptr;
        delete counter;
        return;
    }
    (*counter)--;
}
