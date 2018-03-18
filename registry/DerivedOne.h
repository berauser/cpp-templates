
#ifndef _SRC_DERIVEDONE_H_
#define _SRC_DERIVEDONE_H_

#include "Base.h"

class DerivedOne : public Base 
{
public:
    DerivedOne() : Base()
    {
        std::cout << "DerivedOne::DerivedOne()" << std::endl;
    }
    
    DerivedOne(int var_arg) : Base(var_arg)
    {
        std::cout << "DerivedOne::DerivedOne(" << _var << ")" << std::endl;
    }
    
    virtual ~DerivedOne()
    {
    }
    
    virtual void print( int i )
    {
        std::cout << "DerivedOne(" << _var << ") : " << i << std::endl;
    }
};

#endif /* _SRC_DERIVEDONE_H_ */
